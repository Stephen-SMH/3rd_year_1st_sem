def to_lowercase(s):
    # Convert a string to lowercase manually
    lower_s = ""
    for char in s:
        # Check if the character is an uppercase letter
        if 'A' <= char <= 'Z':
            # Convert to lowercase by adding the difference between 'a' and 'A'
            lower_s += chr(ord(char) + (ord('a') - ord('A')))
        else:
            lower_s += char
    return lower_s

def compare_case_insensitive(str1, str2):
    # Compare two strings for equality, ignoring case
    if len(str1) != len(str2):
        return False
    for char1, char2 in zip(str1, str2):
        if to_lowercase(char1) != to_lowercase(char2):
            return False
    return True

def find_word_positions(word, list_of_words):
    # Convert the word to lowercase for case-insensitive comparison
    word_lower = to_lowercase(word)
    
    # Initialize a list to store the positions
    positions = []
    
    # Iterate over the list and check for matches
    for index, current_word in enumerate(list_of_words):
        if compare_case_insensitive(current_word, word_lower):
            positions.append(index)
    
    # Return the positions list if not empty, otherwise return 0
    return positions if positions else 0

# Example usage
print(find_word_positions("Python", ["python", "java", "c", "PYTHON", "Prolog"]))  # Output: [0, 3]
print(find_word_positions("iOS", ["Windows", "macOS", "Linux"]))                  # Output: 0
