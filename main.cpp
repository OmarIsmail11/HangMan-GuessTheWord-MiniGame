#include <iostream>
#include <vector>

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
    cout << word;
}