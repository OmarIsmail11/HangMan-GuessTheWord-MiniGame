#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isValid(string s)
{
    if (s.size() > 10) return false;
    for (char letter: s)
    {
        if (!isalpha(letter) ) return false;
    }
    return true;
}

unordered_set<char> storeWordData(string word)
{
    unordered_set<char> letters;
    for (char letter: word) letters.insert(letter);
    return letters;
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
    unordered_set<char> letters = storeWordData(word);
    string progress (word.size(), '_');
    unordered_set<char> lettersUsed{'a', 'b', 'C', 'd', 'E'};
    printProgress(progress, 7, lettersUsed);
}