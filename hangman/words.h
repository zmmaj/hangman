
/** @addtogroup hangman
 * @{
 */
/** @file
 */
// Struct to hold a word and its hint
struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};


    // Array of words with hints
 struct WordWithHint wordList[] = {
        { "geeksforgeeks", "Computer coding" },
        { "elephant", "A large mammal with a trunk" },
        { "pizza", "A popular Italian dish" },
        { "beach", "Sandy shore by the sea" },
        // Change and / or Add more words and hints here
    };


    /** @}
 */
