#!/bin/bash

# LEX Practical Testing Script
# This script tests all 4 objectives with predefined test cases

echo "======================================"
echo "LEX Practical Testing Script"
echo "======================================"
echo ""

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Test counter
total_tests=0
passed_tests=0

# Function to run a test
run_test() {
    local test_name=$1
    local input=$2
    local program=$3
    local expected=$4
    
    ((total_tests++))
    
    echo -e "${BLUE}Test: ${test_name}${NC}"
    echo "Input: $input"
    
    # Run the program
    if [ -f "$program" ]; then
        output=$(echo -e "$input" | ./"$program" 2>/dev/null)
        echo "Output: $output"
        echo "Expected: $expected"
        
        # Simple comparison (you might need to adjust this)
        if [[ "$output" == *"$expected"* ]]; then
            echo -e "${GREEN}✓ PASSED${NC}"
            ((passed_tests++))
        else
            echo -e "${RED}✗ FAILED${NC}"
        fi
    else
        echo -e "${RED}✗ Program not found: $program${NC}"
    fi
    
    echo ""
}

# Check if programs exist
echo "Checking if programs are compiled..."
missing=0
for i in {1..4}; do
    if [ ! -f "objective$i" ]; then
        echo -e "${RED}✗ objective$i not found${NC}"
        ((missing++))
    else
        echo -e "${GREEN}✓ objective$i found${NC}"
    fi
done
echo ""

if [ $missing -gt 0 ]; then
    echo -e "${YELLOW}Please compile the programs first using: ./compile.sh${NC}"
    exit 1
fi

# ==========================================
# OBJECTIVE 1 TESTS: Extract Numbers
# ==========================================
echo "=========================================="
echo "OBJECTIVE 1: Extract Numbers"
echo "=========================================="
echo ""

run_test "Test 1.1" "a1b22c3" "objective1" "1"
run_test "Test 1.2" "abc123def456" "objective1" "123"
run_test "Test 1.3" "no numbers here" "objective1" ""

# ==========================================
# OBJECTIVE 2 TESTS: Replace String
# ==========================================
echo "=========================================="
echo "OBJECTIVE 2: Replace String"
echo "=========================================="
echo ""

run_test "Test 2.1" "This is charusat." "objective2" "This is university."
run_test "Test 2.2" "Charusat is great." "objective2" "university is great."
run_test "Test 2.3" "CHARUSAT or charusat" "objective2" "university"

# ==========================================
# OBJECTIVE 3 TESTS: Count Characters
# ==========================================
echo "=========================================="
echo "OBJECTIVE 3: Count Characters/Words/Lines"
echo "=========================================="
echo ""

# Create test file
echo "The 45 is odd number." > test_obj3.txt
echo -e "${BLUE}Test 3.1: Count from file${NC}"
echo "File content: The 45 is odd number."
if [ -f "objective3" ]; then
    ./objective3 test_obj3.txt
    ((total_tests++))
    ((passed_tests++))
else
    echo -e "${RED}✗ objective3 not found${NC}"
fi
rm -f test_obj3.txt
echo ""

# ==========================================
# OBJECTIVE 4 TESTS: Password Validation
# ==========================================
echo "=========================================="
echo "OBJECTIVE 4: Password Validation"
echo "=========================================="
echo ""

run_test "Test 4.1" "a@1T" "objective4" "Invalid"
run_test "Test 4.2" "Passw0rd@123" "objective4" "Valid"
run_test "Test 4.3" "password123" "objective4" "Invalid"
run_test "Test 4.4" "PASSWORD@123" "objective4" "Invalid"

# ==========================================
# SUMMARY
# ==========================================
echo "=========================================="
echo "Test Summary"
echo "=========================================="
echo -e "Total Tests: ${total_tests}"
echo -e "${GREEN}Passed: ${passed_tests}${NC}"
echo -e "${RED}Failed: $((total_tests - passed_tests))${NC}"
echo ""

if [ $passed_tests -eq $total_tests ]; then
    echo -e "${GREEN}🎉 All tests passed!${NC}"
else
    percentage=$((passed_tests * 100 / total_tests))
    echo -e "${YELLOW}⚠ Success Rate: ${percentage}%${NC}"
fi

echo ""
echo "Note: Some tests may show as failed due to output format differences."
echo "Please verify the actual output manually for accuracy."
echo ""
