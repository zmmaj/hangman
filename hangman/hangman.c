/** @addtogroup hangman
 * @{
 */
/**
 * @file
 */

// C program to implement hangman game
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <str.h>

#include "main.h"

#include <time.h>
#include <getopt.h>
#include <stdbool.h>
#include <async.h>
#include <io/style.h>
#include <io/console.h>
#include <types/common.h>



#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6
#include "words.h"

#define FLUSH fflush(stdin)
console_ctrl_t *console;
//static int curscore;
static int curscore;

int Rows;
int Cols;

// Function to display the current state of the word
void displayWord(const char word[], const bool guessed[], int wordLength);
void scr_clear(void);
// Function to draw the hangman
void drawHangman(int tries);
void play(void);
void game_over( void );
void play_again( void );
static void resume_normal(void)
{
	console_flush(console);
	console_set_style(console, STYLE_NORMAL);
}
/*
 * Clear the screen, forgetting the current contents in the process.
 */
void scr_clear(void)
{
	resume_normal();
	console_clear(console);
	curscore = -1;
	
}
void scr_init(void)
{
	console_cursor_visibility(console, 0);
	resume_normal();
	scr_clear();
}
void moveto(sysarg_t r, sysarg_t c)
{
	console_flush(console);
	console_set_pos(console, c, r);
}

void play_again( void )                                 // Gives the user the option to play again
{
    char option[2];
    printf("\n\t\tWould you like to play again(Y/N)?:");
    scanf("%c", &option[0]);
      if (getchar()){                 
    FLUSH;
    if((option[0] == 'Y') || (option[0] == 'y'))        // Restarts the program from after the welcome message
    {
        play();
    }
    else if( (option[0] == 'N') || (option[0] == 'n'))
    {
        game_over();
    }
    else
    {
        printf("\nPlease enter either Y or N");
     if (getchar()){
        FLUSH;
        play_again();
     }
    }
    }

}
void play(){
    // Select a random word from the list
    int wordIndex = rand() % 4;

    const char* secretWord = wordList[wordIndex].word;
    //const char* secretWord_blank=secretWord;
    const char* hint = wordList[wordIndex].hint;
    char guessedWord[MAX_WORD_LENGTH] = {0};
    // English version is
  //int wordLength = str_length(secretWord);
  //So please change it, or you will have compilation error
    int wordLength = стр_дужина(secretWord);
    for (int i = 0; i < wordLength; i++){
    guessedWord[i]='_';
    }
   
    bool guessedLetters[26] = { false };

    int tries = 0;
scr_clear();
 moveto(0,0);
    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", hint);
    printf("\n");
    while (tries < MAX_TRIES) {
        moveto(6,0);
        displayWord(guessedWord, guessedLetters,wordLength);
        drawHangman(tries);

        char guess;
        printf("Enter a letter: ");
    
        scanf(" %c", &guess);
               if (getchar()){                 
    FLUSH;
        guess = tolower(guess);

        if (guessedLetters[guess - 'a']) {
            printf("You've already guessed that letter. "
                   "Try again.\n");

            continue;
             FLUSH;
        }

        guessedLetters[guess - 'a'] = true;

        bool found = false;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                found = true;
                guessedWord[i] = guess;
            }
        }

        if (found) {
            printf("   Good guess!\n");
             FLUSH;
        }
        else {
            printf("   Sorry, the letter '%c' is not in the "
                   "word.\n",
                   guess);
            tries++;
             FLUSH;
        }

        if (str_cmp(secretWord, guessedWord) == 0) {
          scr_clear();
            printf("\nCongratulations! You've guessed the "
                   "word: %s\n",
                   secretWord);
                    FLUSH;
                    play_again();
           // break;
        }
           
    }

    if (tries >= MAX_TRIES) {
        scr_clear();

            printf("\n\n\t\tSorry, you've run out of tries.\n\t\tYOU LOSE!!!!");
            printf("\n\n\t\tThe word was: %s\n",secretWord);
            printf("\n\n\t\tFOR NEXT PRESS ANY KEY.");
            if (getchar()){
            FLUSH;
            play_again();
                          }
    }
    }
}

/*
 * End screen mode.
 */
void scr_end(void)
{
	console_cursor_visibility(console, 1);
}


void game_over( void )                                  // Ends the program
{
    printf("\n\n\t\tGame Over");
     printf("\n\n\t\tFOR NEXT PRESS ANY KEY.");
     if (getchar()){
        FLUSH;
    scr_end();
    printf("\n");
     exit(0);
     }
}
// driver code
int main() 
{
      console = console_init(stdin, stdout);
    scr_init();
    // Seed the random number generator with the current
    // time
    srand(time(NULL));

console_set_style(console, STYLE_NORMAL);

    play();
    return 0;
}



void displayWord(const char word[], const bool guessed[], int wordLength)
{  
    //int wordLength = стр_дужина( secretWord);
    printf("Word: ");
 
       for (int t = 0; t < wordLength; ++t)
   printf("%c", word[t]);


    printf("\n");
    curscore = -1;
     FLUSH;
}

void drawHangman(int tries)
{
    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
     FLUSH;
}

/** @}
 */