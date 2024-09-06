#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdlib.h>

using namespace std;

bool isValid(string s)
{
    if (s.size() > 10) return false;
    for (char letter: s)
    {
        if (!isalpha(letter) || isupper(letter)) return false;
    }
    return true;
}

void printProgress(string progress, int lives, unordered_set<char> lettersUsed)
{
    cout << "Lives Left : " << lives << endl;
    cout << "Letters used: [ ";
    vector<char> temp (lettersUsed.begin(), lettersUsed.end());
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i];
        if (i != temp.size() - 1) cout << ", ";
    }
    cout << " ]\n";
    cout << "Current word: ";
    for (char letter: progress) cout << letter << " ";
    cout << endl;
}

bool validateGuess(char letter, unordered_set<char> lettersUsed)
{
    if (!isalpha(letter) || isupper(letter)) return false;
    if (lettersUsed.count(letter)) return false;
    return true;
}

bool checkWin(string progress)
{
    for (char letter: progress) if (letter == '_') return false;
    return true;
}

void playGame(string word, string &progress, unordered_set<char> letters, unordered_set<char> &lettersUsed, int &lives, string player1, string player2)
{
    while (lives != 0)
    {
        printProgress(progress, lives, lettersUsed);
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        while (!validateGuess(guess, lettersUsed))
        {
            cout << "Invalid letter ! Please re-guess a letter: ";
            cin >> guess;
        }
        if (letters.count(guess))
        {
            for (int i = 0; i < word.size(); i++)
            {
                if (guess == word[i])
                {
                    progress[i] = word[i];
                    lettersUsed.insert(word[i]);
                }
            }
            cout << "\nYou guessed a letter correctly !\n\n";
        }
        else
        {
            cout << "\nUnlucky! Incorrect Guess !\n\n";
            lives--;
            lettersUsed.insert(guess);
        }
        if (checkWin(progress))
        {
            printProgress(progress, lives, lettersUsed);
            cout << "You guessed the word corectly !!\n\n";
            cout << "!! "<< player2 << " wins !!\n\n";
            return;
        }
        if (lives == 0)
        {
            printProgress(progress, lives, lettersUsed);
            cout << player2 << " wasn't able to guess the word correctly !!\n";
            cout << "Word was : " << word;
        } 
    }
    cout << "\n\n!! " << player1 << " wins !!\n\n";
}


int main()
{
    system("CLS");
    cout << "                           Welcome to HangMan Word Guessing Game !\n";
    cout << "\nRules:\n";
    cout << "1) Player 1 enters the word for player 2 to guess.\n";
    cout << "2) Word should have at max 10 letters & consisting only of small letters.\n";
    cout << "3) Player 2 has 7 lives and which incorrect guess the amount decreases by 1.\n";
    cout << "4) Player 2 wins if he/she guesses the word correctly.\n";
    cout << "5) Player 1 wins if player 2 fails to guess the word correctly and has no more lives.\n";
    cout << "\n\n                      !! Now you are ready to play !!\n";
    cout << "\n\nPress Enter to Continue";
    cin.ignore();
    system("CLS");
    string word, player1, player2;
    cout << "Player 1 please enter your name: "; cin >> player1;
    cout << "Player 2 please enter your name: "; cin >> player2;
    system("CLS");
    cout << player1 << " please enter the word for " << player2 << " to guess: ";
    cin >> word;
    system("CLS");
    while (!isValid(word))
    {
        cout << "Invalid Word ! Player 1 please re-enter the word for player 2 to guess: ";
        cin >> word;
        system("CLS");
    }
    cout << player2 << "s Turn !\n\n";
    unordered_set<char> letters {word.begin(), word.end()};
    string progress (word.size(), '_');
    unordered_set<char> lettersUsed;
    int lives = 7;
    playGame(word, progress, letters, lettersUsed, lives, player1, player2);

}