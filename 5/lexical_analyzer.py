#!/usr/bin/env python3
"""
Lexical Analyzer for C Language
Tokenizes C source code into keywords, identifiers, constants, strings, punctuation, and operators
"""

import re
import sys

# C Language Keywords
KEYWORDS = {
    'auto', 'break', 'case', 'char', 'const', 'continue', 'default', 'do',
    'double', 'else', 'enum', 'extern', 'float', 'for', 'goto', 'if',
    'int', 'long', 'register', 'return', 'short', 'signed', 'sizeof', 'static',
    'struct', 'switch', 'typedef', 'union', 'unsigned', 'void', 'volatile', 'while'
}

# Token patterns using regex
TOKEN_PATTERNS = [
    ('COMMENT_MULTI', r'/\*([^*]|\*+[^*/])*\*+/'),
    ('COMMENT_SINGLE', r'//.*'),
    ('STRING', r'"([^"\\]|\\.)*"'),
    ('CHAR', r"'([^'\\]|\\.)'"),
    ('FLOAT', r'\d+\.\d+'),
    ('INTEGER', r'\d+'),
    ('IDENTIFIER', r'[a-zA-Z_][a-zA-Z0-9_]*'),
    ('OPERATOR', r'(\+\+|--|<<|>>|<=|>=|==|!=|&&|\|\||->|\+=|-=|\*=|/=|%=|&=|\|=|\^=|<<=|>>=|[+\-*/%=<>!&|^~.?:])'),
    ('PUNCTUATION', r'[(){}\[\];,#]'),
    ('WHITESPACE', r'[ \t]+'),
    ('NEWLINE', r'\n'),
    ('UNKNOWN', r'.')
]

class LexicalAnalyzer:
    def __init__(self, source_code):
        self.source_code = source_code
        self.tokens = []
        self.line_number = 1
        
    def tokenize(self):
        """Tokenize the source code"""
        position = 0
        
        while position < len(self.source_code):
            match_found = False
            
            for token_type, pattern in TOKEN_PATTERNS:
                regex = re.compile(pattern)
                match = regex.match(self.source_code, position)
                
                if match:
                    value = match.group(0)
                    
                    if token_type == 'IDENTIFIER':
                        # Check if it's a keyword
                        if value in KEYWORDS:
                            self.tokens.append(('Keyword', value))
                        else:
                            self.tokens.append(('Identifier', value))
                    
                    elif token_type == 'INTEGER' or token_type == 'FLOAT':
                        self.tokens.append(('Constant', value))
                    
                    elif token_type == 'STRING' or token_type == 'CHAR':
                        self.tokens.append(('String', value))
                    
                    elif token_type == 'OPERATOR':
                        self.tokens.append(('Operator', value))
                    
                    elif token_type == 'PUNCTUATION':
                        self.tokens.append(('Punctuation', value))
                    
                    elif token_type == 'NEWLINE':
                        self.line_number += 1
                    
                    elif token_type == 'COMMENT_MULTI':
                        # Count newlines in multi-line comments
                        self.line_number += value.count('\n')
                    
                    elif token_type == 'COMMENT_SINGLE':
                        # Single line comment
                        pass
                    
                    elif token_type == 'WHITESPACE':
                        # Ignore whitespace
                        pass
                    
                    elif token_type == 'UNKNOWN':
                        print(f"Lexical Error: Unrecognized character '{value}' at line {self.line_number}")
                    
                    position = match.end()
                    match_found = True
                    break
            
            if not match_found:
                position += 1
        
        return self.tokens
    
    def print_tokens(self):
        """Print all tokens"""
        print("TOKENS")
        for token_type, token_value in self.tokens:
            print(f"{token_type}: {token_value}")

def main():
    if len(sys.argv) < 2:
        print("Usage: python3 lexical_analyzer.py <input_file>")
        sys.exit(1)
    
    try:
        with open(sys.argv[1], 'r') as f:
            source_code = f.read()
        
        analyzer = LexicalAnalyzer(source_code)
        analyzer.tokenize()
        analyzer.print_tokens()
        
    except FileNotFoundError:
        print(f"Error: Could not open file {sys.argv[1]}")
        sys.exit(1)
    except Exception as e:
        print(f"Error: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
