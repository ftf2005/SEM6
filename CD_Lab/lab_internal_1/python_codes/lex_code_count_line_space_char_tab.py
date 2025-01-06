import re

def main():
    text = input("Enter the Sentence: ")
    
    # Initialize counters
    lc = text.count('\n')
    sc = text.count(' ')
    tc = text.count('\t')
    wc = len(re.findall(r'\S+', text))  # Count non-whitespace words
    ch = len(text)  # Count total characters
    
    # Print results
    print(f"Number of lines: {lc}")
    print(f"Number of spaces: {sc}")
    print(f"Number of tabs, words, chars: {tc}, {wc}, {ch}")

if __name__ == "__main__":
    main()
