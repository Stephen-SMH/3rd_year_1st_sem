def find_word_positions(word, list_of_words):
    # Convert the word to lower case for case-insensitive comparison
    word_lower = word.lower()
    
    # Initialize a list to store the positions
    positions = []
    
    # Iterate over the list and check for matches
    for index, current_word in enumerate(list_of_words):
        if current_word.lower() == word_lower:
            positions.append(index)
    
    # Return the positions list if not empty, otherwise return 0
    return positions if positions else 0

# Example usage
print(find_word_positions("Python", ["python", "java", "c", "PYTHON", "Prolog"]))  # Output: [0, 3]
print(find_word_positions("iOS", ["Windows", "macOS", "Linux"]))                  # Output: 0
