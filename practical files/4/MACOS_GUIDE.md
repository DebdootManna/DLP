# LEX Practical - MacOS Setup Guide 🍎

## 🎯 Quick Start for MacOS Users

### ⚡ TL;DR - Super Quick Setup
```bash
# 1. Install Homebrew (if not already installed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# 2. Install flex
brew install flex

# 3. Make scripts executable
chmod +x compile.sh test.sh

# 4. Compile everything
./compile.sh

# 5. Run programs
echo "a1b22c3" | ./objective1
```

---

## 📦 Prerequisites for MacOS

### Check What You Already Have

```bash
# Check if Xcode Command Line Tools are installed
xcode-select -p

# Check if Homebrew is installed
brew --version

# Check if flex is installed
flex --version

# Check if gcc is available
gcc --version
```

---

## 🔧 Installation Steps for MacOS

### Step 1: Install Xcode Command Line Tools

**Why?** This gives you `gcc` and other development tools.

```bash
xcode-select --install
```

A popup will appear - click "Install" and wait for completion (5-10 minutes).

**Verify Installation:**
```bash
gcc --version
# Should show: Apple clang version...
```

---

### Step 2: Install Homebrew (if not installed)

**What is Homebrew?** It's the package manager for MacOS (like `apt` on Ubuntu).

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

**Follow the on-screen instructions!** After installation, you might need to run:
```bash
# For Apple Silicon (M1/M2/M3)
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zshrc
eval "$(/opt/homebrew/bin/brew shellenv)"

# For Intel Macs
echo 'eval "$(/usr/local/bin/brew shellenv)"' >> ~/.zshrc
eval "$(/usr/local/bin/brew shellenv)"
```

**Verify Installation:**
```bash
brew --version
# Should show: Homebrew 4.x.x
```

---

### Step 3: Install Flex

```bash
brew install flex
```

**Verify Installation:**
```bash
flex --version
# Should show: flex 2.6.4 or higher

which flex
# Should show: /opt/homebrew/bin/flex (M1/M2/M3)
#          or: /usr/local/bin/flex (Intel)
```

---

## ⚙️ MacOS-Specific Compilation

### Option 1: Using the Provided Script (Recommended)

```bash
# Make the script executable
chmod +x compile.sh

# Run it
./compile.sh
```

---

### Option 2: Manual Compilation

For each objective, run these commands:

```bash
# Objective 1
flex objective1.l
gcc lex.yy.c -o objective1 -ll

# Objective 2
flex objective2.l
gcc lex.yy.c -o objective2 -ll

# Objective 3
flex objective3.l
gcc lex.yy.c -o objective3 -ll

# Objective 4
flex objective4.l
gcc lex.yy.c -o objective4 -ll
```

**Note:** On MacOS, use `-ll` instead of `-lfl` for linking.

---

### Option 3: One-Liner for Each Objective

```bash
flex objective1.l && gcc lex.yy.c -o objective1 -ll
flex objective2.l && gcc lex.yy.c -o objective2 -ll
flex objective3.l && gcc lex.yy.c -o objective3 -ll
flex objective4.l && gcc lex.yy.c -o objective4 -ll
```

---

## 🚀 Running Programs on MacOS

All programs work the same way on MacOS!

### Objective 1: Extract Numbers
```bash
./objective1
# Type: a1b22c3
# Press Enter
# Output: 1, 22, 3 (each on new line)
```

**Or use echo:**
```bash
echo "a1b22c3" | ./objective1
```

---

### Objective 2: Replace String
```bash
echo "This is charusat." | ./objective2
# Output: This is university.
```

---

### Objective 3: Count Characters/Words/Lines
```bash
# Create test file
echo "The 45 is odd number." > test.txt

# Run program
./objective3 test.txt

# Output:
# Characters : 22
# Words : 5
# Line : 1
```

---

### Objective 4: Password Validation
```bash
echo "Passw0rd@123" | ./objective4
# Output: Valid password

echo "short" | ./objective4
# Output: Invalid password
```

---

## 🐛 MacOS-Specific Troubleshooting

### Issue 1: "ld: library not found for -lfl"

**Solution:** Use `-ll` instead of `-lfl`
```bash
gcc lex.yy.c -o program -ll
```

**Permanent Fix:** Edit `compile.sh` and change all `-lfl` to `-ll`

---

### Issue 2: "xcrun: error: invalid active developer path"

**Problem:** Xcode Command Line Tools not installed or outdated.

**Solution:**
```bash
xcode-select --install
```

---

### Issue 3: "zsh: permission denied: ./compile.sh"

**Problem:** Script doesn't have execute permissions.

**Solution:**
```bash
chmod +x compile.sh test.sh
```

---

### Issue 4: "command not found: brew"

**Problem:** Homebrew not in PATH.

**Solution for M1/M2/M3 (Apple Silicon):**
```bash
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zshrc
source ~/.zshrc
```

**Solution for Intel Macs:**
```bash
echo 'eval "$(/usr/local/bin/brew shellenv)"' >> ~/.zshrc
source ~/.zshrc
```

---

### Issue 5: Programs compile but don't run

**Check permissions:**
```bash
ls -la objective*
chmod +x objective1 objective2 objective3 objective4
```

**Run with explicit path:**
```bash
./objective1  # Not just: objective1
```

---

## 📂 MacOS File Locations

### Where are things installed?

| Item | Apple Silicon (M1/M2/M3) | Intel Mac |
|------|--------------------------|-----------|
| Homebrew | `/opt/homebrew` | `/usr/local` |
| flex | `/opt/homebrew/bin/flex` | `/usr/local/bin/flex` |
| Your files | `~/Downloads` or wherever you saved them | Same |

---

## 🎨 MacOS Terminal Tips

### Using Terminal on Mac

**Method 1: Spotlight**
- Press `Cmd + Space`
- Type "Terminal"
- Press Enter

**Method 2: Applications**
- Go to Applications → Utilities → Terminal

**Method 3: Use iTerm2 (Better)**
```bash
brew install --cask iterm2
```

---

### Navigate to Your Files

```bash
# Go to Downloads folder
cd ~/Downloads

# Or drag folder into Terminal
cd [drag folder here]

# List files
ls -la

# Show current directory
pwd
```

---

## 🔑 Essential MacOS Commands

| Command | Purpose | Example |
|---------|---------|---------|
| `ls` | List files | `ls -la` |
| `cd` | Change directory | `cd ~/Downloads` |
| `pwd` | Print working directory | `pwd` |
| `cat` | View file contents | `cat objective1.l` |
| `nano` | Edit file | `nano objective1.l` |
| `chmod` | Change permissions | `chmod +x script.sh` |
| `./program` | Run program | `./objective1` |
| `clear` | Clear screen | `clear` or `Cmd+K` |

---

## ✅ Complete Setup Checklist for MacOS

```bash
# 1. Install Xcode Command Line Tools
xcode-select --install

# 2. Install Homebrew (if needed)
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# 3. Add Homebrew to PATH (M1/M2/M3)
echo 'eval "$(/opt/homebrew/bin/brew shellenv)"' >> ~/.zshrc
source ~/.zshrc

# 4. Install flex
brew install flex

# 5. Verify installations
flex --version
gcc --version

# 6. Navigate to your project folder
cd ~/Downloads/lex-practical  # or wherever you saved files

# 7. Make scripts executable
chmod +x compile.sh test.sh

# 8. Compile all programs
./compile.sh

# 9. Test programs
./test.sh

# 10. Run individual programs
echo "a1b22c3" | ./objective1
```

---

## 📱 MacOS Alternative: Visual Studio Code

Want a better coding experience?

### Install VS Code
```bash
brew install --cask visual-studio-code
```

### Open your project
```bash
code .
```

### Use integrated terminal
- Press `` Ctrl + ` `` (backtick) to open terminal in VS Code
- Run all commands from there!

---

## 🎓 MacOS-Specific Tips

### 1. Use Tab Completion
```bash
# Type partial name and press Tab
./obj[Tab]  # Autocompletes to ./objective
```

### 2. View Previous Commands
```bash
# Press Up Arrow to cycle through previous commands
# Or search history:
history | grep flex
```

### 3. Copy Output
```bash
# Run program and copy output to clipboard
./objective1 | pbcopy
```

### 4. Create Aliases (Optional)
Add to `~/.zshrc`:
```bash
alias compile='./compile.sh'
alias test='./test.sh'
```

Then just type:
```bash
compile  # Instead of ./compile.sh
test     # Instead of ./test.sh
```

---

## 🔥 Quick Test - Make Sure Everything Works

Run this complete test:

```bash
# 1. Check tools
flex --version && gcc --version && echo "✓ Tools installed!"

# 2. Compile
./compile.sh

# 3. Quick test
echo "a1b22c3" | ./objective1
echo "This is charusat." | ./objective2
echo "Test@Pass123" | ./objective4

# 4. If all above work, you're good! 🎉
```

---

## 📞 Still Having Issues?

### Check System Version
```bash
sw_vers
# ProductName: macOS
# ProductVersion: 14.x.x (or your version)
```

### Check Architecture
```bash
uname -m
# arm64 → Apple Silicon (M1/M2/M3)
# x86_64 → Intel Mac
```

### Get Help
1. Check error messages carefully
2. Google the exact error message + "macos"
3. Ask ChatGPT/Claude with the error message
4. Check Stack Overflow
5. Ask your instructor/peers

---

## 🌟 MacOS Advantages

✅ Clean, Unix-based system  
✅ Great for development  
✅ Excellent terminal (or use iTerm2)  
✅ Easy package management with Homebrew  
✅ Native support for C/C++ development  

---

## 🎉 You're All Set!

Your MacOS is now ready for Lex programming! The programs work identically on Mac and Linux - just remember to use `-ll` instead of `-lfl` when compiling.

**Happy Coding! 🚀**

---

## 📚 Additional MacOS Resources

- **Homebrew Docs:** https://docs.brew.sh
- **MacOS Terminal Guide:** https://support.apple.com/guide/terminal
- **iTerm2:** https://iterm2.com
- **Oh My Zsh:** https://ohmyz.sh (makes terminal prettier)

---

**Last Updated:** January 2026  
**Tested On:** MacOS Sonoma 14.x, MacOS Ventura 13.x  
**Architecture:** Both Apple Silicon (M1/M2/M3) and Intel
