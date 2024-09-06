#include <iostream>
#include <vector>
#include <unordered_set>

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

void playGame(string word, string &progress, unordered_set<char> letters, unordered_set<char> &lettersUsed, int &lives)
{
    while (lives != 0)
    {
        printProgress(progress, lives, lettersUsed);
        char guess;
        cout << "Guess a letter: ";
        cin >> guess;
        while (!validateGuess(guess, lettersUsed))
        {
            cout << "Invalid letter ! Guess a letter: ";
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
            cout << "Player 2 wins !!\n\n";
            return;
        }
        if (lives == 0)
        {
            printProgress(progress, lives, lettersUsed);
            cout << "\nWord was : " << word;
        } 
    }
    cout << "\n\nPlayer 1 wins !!\n\n";
}


int main()
{
    string word;
    cout << "Player 1 please enter the word for player 2 to guess: ";
    cin >> word;
    while (!isValid(word))
    {
        cout << "Invalid Word ! Player 1 please re-enter the word for player 2 to guess: ";
        cin >> word;
    }
    unordered_set<char> letters {word.begin(), word.end()};
    string progress (word.size(), '_');
    unordered_set<char> lettersUsed;
    int lives = 7;
    playGame(word, progress, letters, lettersUsed, lives);

}