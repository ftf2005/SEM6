import re

def count_vowels_consonants():
    text = input("Enter the string of vowels and consonants: ")

    # Initialize counts
    vow_count = len(re.findall(r'[aeiouAEIOU]', text))  # Count vowels
    const_count = len(re.findall(r'[a-zA-Z]', text)) - vow_count  # Count consonants (subtract vowels from total alphabetic characters)
    
    print(f"Number of vowels: {vow_count}")
    print(f"Number of consonants: {const_count}")

if __name__ == "__main__":
    count_vowels_consonants()
