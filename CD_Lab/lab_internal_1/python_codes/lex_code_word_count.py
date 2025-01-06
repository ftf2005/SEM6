import re

def count_words():
    text = input("Enter the text: ")
    
    # Count the words using regex
    words = re.findall(r'\b\w+\b', text)  # Matches words consisting of alphanumeric characters
    
    print(f"Number of words: {len(words)}")

if __name__ == "__main__":
    count_words()
