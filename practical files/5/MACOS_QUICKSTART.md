# Quick Start Guide for macOS

## Lexical Analyzer - macOS Setup & Execution

---

## Prerequisites Check

### 1. Verify Python Installation
```bash
python3 --version
```
Expected: `Python 3.x.x`

### 2. Verify Terminal
- Open **Terminal** app (Applications > Utilities > Terminal)
- Or use **iTerm2** if you have it

---

## 5-Minute Setup

### Step 1: Create Project Folder
```bash
mkdir ~/compiler-lab
cd ~/compiler-lab
```

### Step 2: Copy All Files
Copy these files to your `~/compiler-lab` folder:
- `lexical_analyzer.py`
- `test1.c`
- `test2.c`
- `test3.c`
- `README.md`
- `PRACTICAL_GUIDE.md`
- `MACOS_QUICKSTART.md` (this file)

### Step 3: Make Python Script Executable (Optional)
```bash
chmod +x lexical_analyzer.py
```

---

## Running the Lexical Analyzer

### Quick Test
```bash
cd ~/compiler-lab
python3 lexical_analyzer.py test1.c
```

### Expected Output
```
TOKENS
Keyword: int
Identifier: main
Punctuation: (
Punctuation: )
Punctuation: {
Keyword: int
Identifier: a
Operator: =
Constant: 5
...
```

---

## Running All Tests

### Option 1: Manual Execution
```bash
python3 lexical_analyzer.py test1.c
python3 lexical_analyzer.py test2.c
python3 lexical_analyzer.py test3.c
```

### Option 2: Automated Testing (One Command)
```bash
for test in test*.c; do
    echo "═══════════════════════════════════"
    echo "Testing: $test"
    echo "═══════════════════════════════════"
    python3 lexical_analyzer.py "$test"
    echo
done
```

### Option 3: Save Outputs
```bash
python3 lexical_analyzer.py test1.c > test1_output.txt
python3 lexical_analyzer.py test2.c > test2_output.txt
python3 lexical_analyzer.py test3.c > test3_output.txt

# View saved output
cat test1_output.txt
```

---

## Creating Your Own Test

### Quick Method
```bash
cat > my_test.c << 'EOF'
int main() {
    int x = 10;
    int y = 20;
    return x + y;
}
EOF

python3 lexical_analyzer.py my_test.c
```

### Using Text Editor
```bash
# Using nano (terminal editor)
nano my_test.c
# Type your C code, then Ctrl+X, Y, Enter to save

# Using TextEdit (GUI)
open -a TextEdit my_test.c
# Make sure Format > Make Plain Text is selected

# Using VS Code (if installed)
code my_test.c

# Then run
python3 lexical_analyzer.py my_test.c
```

---

## macOS-Specific Tips

### Opening Files from Finder
1. Navigate to your project folder in Finder
2. Right-click on `test1.c`
3. Select **Open With** > **TextEdit** or **Other** > **VS Code**

### Using Spotlight
- Press `Cmd + Space`
- Type "Terminal"
- Press Enter

### Viewing Hidden Files in Finder
```bash
# Show hidden files
defaults write com.apple.finder AppleShowAllFiles YES
killall Finder

# Hide hidden files again
defaults write com.apple.finder AppleShowAllFiles NO
killall Finder
```

### File Paths
- Use `~/` for home directory: `~/compiler-lab/test1.c`
- Or full path: `/Users/yourusername/compiler-lab/test1.c`

---

## Common macOS Issues & Solutions

### Issue 1: "python3: command not found"
**Solution:**
```bash
# Install Homebrew first (if not installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Then install Python
brew install python3
```

### Issue 2: Permission Denied
**Solution:**
```bash
chmod +x lexical_analyzer.py
```

### Issue 3: Cannot Open File
Check if you're in the right directory:
```bash
pwd                    # Print current directory
ls                     # List files
cd ~/compiler-lab      # Navigate to project folder
```

### Issue 4: Line Ending Issues (Rare)
If you copied files from Windows:
```bash
brew install dos2unix
dos2unix test1.c
```

---

## Alternative: Using Lex/Flex on macOS

### Install Flex
```bash
brew install flex
```

### Compile Lex File
```bash
flex lexical_analyzer.l
gcc lex.yy.c -o lexer -ll
./lexer test1.c
```

**Note:** This method requires installation and compilation. The Python method is recommended for simplicity.

---

## Using Different Python Editors on Mac

### 1. IDLE (Comes with Python)
```bash
python3 -m idlelib lexical_analyzer.py
```

### 2. VS Code
```bash
# Install VS Code first from https://code.visualstudio.com
code lexical_analyzer.py
```

### 3. PyCharm (Community Edition)
```bash
# Download from https://www.jetbrains.com/pycharm/
# Open project folder in PyCharm
```

### 4. Jupyter Notebook (For Interactive Testing)
```bash
pip3 install jupyter
jupyter notebook
# Create new Python 3 notebook
# Copy code and test interactively
```

---

## Terminal Shortcuts (macOS)

| Shortcut | Action |
|----------|--------|
| `Cmd + T` | New terminal tab |
| `Cmd + K` | Clear screen |
| `Cmd + C` | Copy (in terminal: stop program) |
| `Cmd + V` | Paste |
| `Ctrl + C` | Stop running program |
| `Ctrl + D` | Exit/logout |
| `↑` / `↓` | Navigate command history |
| `Tab` | Auto-complete file names |

---

## Project Structure Visualization

```
~/compiler-lab/
│
├── lexical_analyzer.py       # Main program
├── lexical_analyzer.l        # Lex version (optional)
│
├── test1.c                   # Test input 1
├── test2.c                   # Test input 2
├── test3.c                   # Test input 3
│
├── test1_output.txt          # Output 1 (generated)
├── test2_output.txt          # Output 2 (generated)
├── test3_output.txt          # Output 3 (generated)
│
├── README.md                 # Full documentation
├── PRACTICAL_GUIDE.md        # Step-by-step guide
└── MACOS_QUICKSTART.md       # This file
```

---

## Taking Screenshots (for Lab Report)

### Method 1: Using Screenshot App
1. Press `Cmd + Shift + 5`
2. Select capture mode
3. Click terminal window

### Method 2: Keyboard Shortcuts
- `Cmd + Shift + 3` - Full screen
- `Cmd + Shift + 4` - Select area
- `Cmd + Shift + 4` then `Space` - Capture specific window

### Method 3: Terminal Command
```bash
# Capture entire screen
screencapture ~/Desktop/screenshot.png

# Capture after 5 seconds
screencapture -T 5 ~/Desktop/screenshot.png

# Interactive selection
screencapture -i ~/Desktop/screenshot.png
```

Screenshots are saved to Desktop by default.

---

## Copying Output for Report

### Method 1: Select and Copy
1. Run the command
2. Select output text in terminal
3. Press `Cmd + C`

### Method 2: Save to File
```bash
python3 lexical_analyzer.py test1.c > output.txt
open output.txt  # Opens in default text editor
```

### Method 3: Pipe to Clipboard
```bash
python3 lexical_analyzer.py test1.c | pbcopy
# Now paste with Cmd+V anywhere
```

---

## Performance Comparison

### Test File Sizes & Execution Times

| Test | Lines | Tokens | Time (Python) | Time (Lex) |
|------|-------|--------|---------------|------------|
| test1.c | 8 | ~20 | ~0.01s | ~0.001s |
| test2.c | 36 | ~150 | ~0.02s | ~0.002s |
| test3.c | 13 | ~30 | ~0.01s | ~0.001s |

**Note:** Times are approximate on modern MacBook

---

## Using with GitHub

### Initialize Git Repository
```bash
cd ~/compiler-lab
git init
git add .
git commit -m "Initial commit - Lexical Analyzer"
```

### Create .gitignore
```bash
cat > .gitignore << 'EOF'
*.pyc
__pycache__/
*.o
lex.yy.c
lexer
*.txt
EOF
```

### Push to GitHub
```bash
git remote add origin https://github.com/yourusername/compiler-lab.git
git push -u origin main
```

---

## Troubleshooting Decision Tree

```
Is Python installed?
├─ No  → Install via Homebrew: brew install python3
└─ Yes → Are you in correct directory?
    ├─ No  → cd ~/compiler-lab
    └─ Yes → Do files exist?
        ├─ No  → Copy files to directory
        └─ Yes → Can you run script?
            ├─ No  → Check permissions: chmod +x lexical_analyzer.py
            └─ Yes → Are outputs correct?
                ├─ No  → Check input file format
                └─ Yes → Success! ✓
```

---

## Additional Resources for Mac Users

### Terminal Customization
```bash
# Add to ~/.zshrc (or ~/.bash_profile for older macOS)
echo 'alias lex="python3 ~/compiler-lab/lexical_analyzer.py"' >> ~/.zshrc
source ~/.zshrc

# Now you can just type:
lex test1.c
```

### Oh My Zsh (Terminal Enhancement)
```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

### iTerm2 (Better Terminal)
Download from: https://iterm2.com

---

## Lab Submission Checklist (macOS)

- [ ] All test files run successfully
- [ ] Screenshots taken and saved
- [ ] Code properly formatted
- [ ] Report written (Pages or Word)
- [ ] PDF exported for submission
- [ ] Files organized in folder
- [ ] Backup created

### Creating PDF Report (macOS)
1. Write report in Pages or Word
2. File > Export to > PDF
3. Or: File > Print > Save as PDF

---

## Time-Saving Tips

### Create Alias for Quick Testing
```bash
# Add to ~/.zshrc
alias t1='cd ~/compiler-lab && python3 lexical_analyzer.py test1.c'
alias t2='cd ~/compiler-lab && python3 lexical_analyzer.py test2.c'
alias t3='cd ~/compiler-lab && python3 lexical_analyzer.py test3.c'

# Usage:
t1    # Runs test1.c
t2    # Runs test2.c
t3    # Runs test3.c
```

### Create Testing Script
```bash
cat > test_all.sh << 'EOF'
#!/bin/bash
echo "Running all tests..."
for test in test*.c; do
    echo "━━━━━━━━━━━━━━━━━━━━━━━"
    echo "Test: $test"
    echo "━━━━━━━━━━━━━━━━━━━━━━━"
    python3 lexical_analyzer.py "$test"
    echo
done
echo "All tests complete!"
EOF

chmod +x test_all.sh
./test_all.sh
```

---

## Need Help?

### Built-in Help
```bash
python3 lexical_analyzer.py
# Shows usage message
```

### Check Documentation
```bash
open README.md              # Opens in default app
open PRACTICAL_GUIDE.md     # Step-by-step guide
```

### Python Documentation
```bash
python3 -m pydoc re         # Regular expressions
python3 -m pydoc sys        # System functions
```

---

## Success Indicators

Your setup is working correctly when:

✅ `python3 --version` shows Python 3.x  
✅ You can navigate to project folder  
✅ Files are visible with `ls` command  
✅ Script runs without errors  
✅ Output shows "TOKENS" header  
✅ Token categories are correct  

---

## Final Commands to Remember

```bash
# Navigate
cd ~/compiler-lab

# Test basic
python3 lexical_analyzer.py test1.c

# Test all
for t in test*.c; do python3 lexical_analyzer.py "$t"; done

# Save output
python3 lexical_analyzer.py test1.c > output.txt

# View file
cat test1.c

# Edit file
nano test1.c
```

---

**You're all set! Start with `test1.c` and work your way through the examples.** 🚀

For detailed explanations, see:
- `README.md` - Complete documentation
- `PRACTICAL_GUIDE.md` - Step-by-step tutorial

**Happy Coding!** 💻
