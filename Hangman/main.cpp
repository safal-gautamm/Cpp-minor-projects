#include <iostream>
using std::cin, std::cout, std::endl, std::string;

const int max_misses = 6;
string word;
string incorrect;
string entered_characters;
string user_answer;
int misses;


class Message
{
public:

    void greet()
    {
        cout << "+---------------------------------------------+" << endl;
        cout << "|               H A N G M A N                 |" << endl;
        cout << "+---------------------------------------------+" << endl;
        cout << "Guess the Word:" << endl;
    }
    void display_misses(int misses)
    {
        cout << "Remaining misses : " << max_misses - misses << endl << endl;
    }
    void display_incorrect_message(string incorrect)
    {
        cout << "Incorrect Guesses: " << incorrect << endl;
    }
    void display_user_answer(string user_answer)
    {
        cout << "Your Answer : ";
        for (char ch : user_answer)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
    void invalid_character_message()
    {
        cout << "\nInvalid character!" << endl;
        cout << "Input must be an alphabet!" << endl;
    }
    void already_entered_message()
    {
        cout << "\nYou have already entered this letter!" << endl;
        cout << "Enter another letter!" << endl;
    }
    void correct_message()
    {
        cout << "\nCorrect!" << endl;
    }
    void incorrect_message()
    {
        cout << "\nIncorrect!" << endl;
    }
    void final_result(string user_answer, string word)
    {
        cout << "Your Answer: ";
        for (char ch : user_answer)
        {
            cout << ch << " ";
        }
        cout << endl << endl;

        if (user_answer == word)
        {
            cout << "+---------------------------------------------+" << endl;
            cout << "|                Y O U W I N !                |" << endl;
            cout << "+---------------------------------------------+" << endl;
        }

        else
        {
            cout << "The correct answer is: " << word << endl
                 << endl;
            cout << "+---------------------------------------------+" << endl;
            cout << "|               Y O U L O S E !               |" << endl;
            cout << "+---------------------------------------------+" << endl;
        }
    }
};

class Game
{
    public:
    Game(string choosen_word)
    {
        word = choosen_word;
        incorrect = "";

        for (int i = 0; i < word.length(); ++i) 
        {
        user_answer += "_";
        }
    }
};

int main()
{

    return 0;
}