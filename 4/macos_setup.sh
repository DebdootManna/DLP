#!/bin/bash

# MacOS Quick Setup Script for LEX Practical
# This script automates the entire setup process for Mac users

echo "╔════════════════════════════════════════╗"
echo "║  LEX Practical - MacOS Setup Script   ║"
echo "╔════════════════════════════════════════╗"
echo ""

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m'

# Function to check if a command exists
command_exists() {
    command -v "$1" >/dev/null 2>&1
}

# Step 1: Check Xcode Command Line Tools
echo -e "${BLUE}[1/5] Checking Xcode Command Line Tools...${NC}"
if xcode-select -p &>/dev/null; then
    echo -e "${GREEN}✓ Xcode Command Line Tools installed${NC}"
else
    echo -e "${YELLOW}⚠ Installing Xcode Command Line Tools...${NC}"
    echo "Please click 'Install' in the popup window and wait for completion."
    xcode-select --install
    echo "Press Enter after installation completes..."
    read
fi
echo ""

# Step 2: Check Homebrew
echo -e "${BLUE}[2/5] Checking Homebrew...${NC}"
if command_exists brew; then
    echo -e "${GREEN}✓ Homebrew installed${NC}"
    brew_version=$(brew --version | head -n1)
    echo "  $brew_version"
else
    echo -e "${YELLOW}⚠ Homebrew not found. Installing...${NC}"
    echo "This may take a few minutes..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    
    # Add Homebrew to PATH based on architecture
    if [[ $(uname -m) == "arm64" ]]; then
        echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zshrc
        eval "$(/opt/homebrew/bin/brew shellenv)"
    else
        echo 'eval "$(/usr/local/bin/brew shellenv)"' >> ~/.zshrc
        eval "$(/usr/local/bin/brew shellenv)"
    fi
    
    echo -e "${GREEN}✓ Homebrew installed successfully${NC}"
fi
echo ""

# Step 3: Check flex
echo -e "${BLUE}[3/5] Checking flex...${NC}"
if command_exists flex; then
    echo -e "${GREEN}✓ flex installed${NC}"
    flex_version=$(flex --version)
    echo "  $flex_version"
else
    echo -e "${YELLOW}⚠ flex not found. Installing...${NC}"
    brew install flex
    echo -e "${GREEN}✓ flex installed successfully${NC}"
fi
echo ""

# Step 4: Check GCC
echo -e "${BLUE}[4/5] Checking GCC/Clang...${NC}"
if command_exists gcc; then
    echo -e "${GREEN}✓ GCC/Clang installed${NC}"
    gcc_version=$(gcc --version | head -n1)
    echo "  $gcc_version"
else
    echo -e "${RED}✗ GCC not found. Please install Xcode Command Line Tools.${NC}"
    exit 1
fi
echo ""

# Step 5: Compile programs
echo -e "${BLUE}[5/5] Compiling programs...${NC}"
if [ -f "compile.sh" ]; then
    chmod +x compile.sh
    ./compile.sh
else
    echo -e "${YELLOW}⚠ compile.sh not found. Compiling manually...${NC}"
    
    for i in {1..4}; do
        if [ -f "objective${i}.l" ]; then
            echo "Compiling objective${i}..."
            flex "objective${i}.l"
            if gcc lex.yy.c -o "objective${i}" -ll 2>/dev/null; then
                echo -e "${GREEN}✓ objective${i} compiled${NC}"
            else
                echo -e "${RED}✗ Failed to compile objective${i}${NC}"
            fi
        fi
    done
    rm -f lex.yy.c
fi
echo ""

# Summary
echo "╔════════════════════════════════════════╗"
echo "║           Setup Complete! 🎉          ║"
echo "╔════════════════════════════════════════╗"
echo ""
echo -e "${GREEN}All tools installed and programs compiled!${NC}"
echo ""
echo "Quick Test Commands:"
echo "  echo 'a1b22c3' | ./objective1"
echo "  echo 'This is charusat.' | ./objective2"
echo "  echo 'The 45 is odd number.' > test.txt && ./objective3 test.txt"
echo "  echo 'Passw0rd@123' | ./objective4"
echo ""
echo "For more help, read MACOS_GUIDE.md"
echo ""
