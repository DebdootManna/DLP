#!/bin/bash

# LEX Practical Compilation Script
# This script compiles all 4 objectives automatically

echo "=================================="
echo "LEX Practical Compilation Script"
echo "=================================="
echo ""

# Color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Check if flex is installed
if ! command -v flex &> /dev/null; then
    echo -e "${RED}Error: flex is not installed!${NC}"
    echo "Please install flex using: sudo apt-get install flex"
    exit 1
fi

# Check if gcc is installed
if ! command -v gcc &> /dev/null; then
    echo -e "${RED}Error: gcc is not installed!${NC}"
    echo "Please install gcc using: sudo apt-get install gcc"
    exit 1
fi

echo -e "${GREEN}✓ Prerequisites check passed!${NC}"
echo ""

# Function to compile a single objective
compile_objective() {
    local obj_num=$1
    local obj_name="objective${obj_num}"
    
    echo "Compiling ${obj_name}..."
    
    # Generate C code from Lex file
    if flex "${obj_name}.l" 2>/dev/null; then
        # Try compiling with -lfl first
        if gcc lex.yy.c -o "${obj_name}" -lfl 2>/dev/null; then
            echo -e "${GREEN}✓ ${obj_name} compiled successfully!${NC}"
            return 0
        # If -lfl fails, try -ll
        elif gcc lex.yy.c -o "${obj_name}" -ll 2>/dev/null; then
            echo -e "${GREEN}✓ ${obj_name} compiled successfully!${NC}"
            return 0
        # If both fail, try without library
        elif gcc lex.yy.c -o "${obj_name}" 2>/dev/null; then
            echo -e "${GREEN}✓ ${obj_name} compiled successfully!${NC}"
            return 0
        else
            echo -e "${RED}✗ Failed to compile ${obj_name}${NC}"
            return 1
        fi
    else
        echo -e "${RED}✗ Failed to generate C code for ${obj_name}${NC}"
        return 1
    fi
}

# Compile all objectives
success_count=0
fail_count=0

for i in {1..4}; do
    if compile_objective $i; then
        ((success_count++))
    else
        ((fail_count++))
    fi
    echo ""
done

# Summary
echo "=================================="
echo "Compilation Summary"
echo "=================================="
echo -e "${GREEN}Successful: ${success_count}${NC}"
if [ $fail_count -gt 0 ]; then
    echo -e "${RED}Failed: ${fail_count}${NC}"
fi
echo ""

# Clean up intermediate files
if [ -f "lex.yy.c" ]; then
    rm lex.yy.c
    echo "Cleaned up intermediate files."
fi

if [ $success_count -eq 4 ]; then
    echo -e "${GREEN}🎉 All objectives compiled successfully!${NC}"
    echo ""
    echo "You can now run the programs:"
    echo "  ./objective1  (Extract numbers)"
    echo "  ./objective2  (Replace charusat)"
    echo "  ./objective3 <file>  (Count chars/words/lines)"
    echo "  ./objective4  (Validate password)"
else
    echo -e "${YELLOW}⚠ Some objectives failed to compile. Check errors above.${NC}"
fi

echo ""
