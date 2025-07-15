#include <iostream>
using std::cin, std::cout, std::endl, std::string;

const int max_misses = 6;

class Message {
public:

    // method to greet the player
    void greet() {
        cout << "------------------------------" << endl;
        cout << "\t\tH A N G M A N" << endl;
        cout << "------------------------------" << endl;
        cout << "Guess the Word" << endl << endl;
    }

    // method to display the number of misses
    void display_misses(int misses) {
        cout << "Remaining misses: "<< max_misses - misses << endl << endl;
    }

    // method to display the incorrect guesses
    void display_incorrect_guesses(string incorrect) {
        cout << "Incorrect Guesses: " << incorrect << endl;
    }
    
    // method to display the user answer
    void display_user_answer(string user_answer) {
        cout << "Your Answer: ";

        for (char c: user_answer) {
            cout << c << " ";
        }

        cout << endl;
    }

    // method to call when the user
    // enters non-alphabetic character
    void invalid_character_message() {
        cout << "\nInvalid character!" << endl;
        cout << "Input must be an alphabet!" << endl;
    }

    // method to call when the user enters a
    // character that has already been entered
    void already_entered_message() {
        cout << "\nYou have already entered this letter!" << endl;
        cout << "Enter another letter!" << endl;
    }

    void correct_message() {
        cout << "\nCorrect!" << endl;
    }

    void incorrect_message() {
        cout << "\nIncorrect!" << endl;
    }

    // print win or loss message
    void final_result(string user_answer, string word) {

        cout << "Your Answer: ";

        for (char c: user_answer) {
            cout << c << " ";
        }

        cout << endl << endl;

        // print win message
        if (user_answer == word) {
            cout << "-----------------------------------------------" << endl;
            cout << "\t\t\t\tY O U  W I N" << endl;
            cout << "-----------------------------------------------" << endl;
        }

        // print loss message
        else {
            cout << "The correct answer is: " << word << endl << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "\t\t\t\tY O U  L O S E" << endl;
            cout << "-----------------------------------------------" << endl;
        }
    }
};
class Game {
private:

    string word;
    string user_answer;
    string incorrect;
    string entered_characters;
    int misses;
    Message message;

public:

    // constructor to initialize attributes
    Game(string chosen_word) {
        word = chosen_word;
        incorrect = "";
        entered_characters = "";
        misses = 0;

        for (int i = 0; i < word.length(); ++i) {
            user_answer += "_";
        }
    }

    // method to ensure that user input is
    // an alphabet and not a previous input
    bool is_guess_valid(char letter) {

        if (!isalpha(letter)) {
            message.invalid_character_message();
            return false;
        }

        for (int i = 0; i < entered_characters.length(); ++i) {            
            if (letter == entered_characters[i]) {
                message.already_entered_message();
                return false;
            }
        }

        return true;
    }

    // method to check if guess is correct
    void is_guess_correct(char letter) {

        bool guess = false;

        for (int i = 0; i < word.length(); i++) {
            if (letter == word[i]) {
                user_answer[i] = letter;
                guess = true;
            }
        }

        if (guess) {
            message.correct_message();
        }
        else {
            message.incorrect_message();
            incorrect += letter;
            incorrect += ", ";
            ++misses;
        }

        entered_characters += letter;
    }

    // method to check if the game is over
    bool is_game_over() {
        if (user_answer == word || misses >= max_misses) {
            return true;
        }
        return false;
    }

    // method to display the game status
    void display_game_status() {
        message.display_incorrect_guesses(incorrect);
        message.display_user_answer(user_answer);
        message.display_misses(misses);
    }

    // method to display the final result
    void display_final_result() {
        message.final_result(user_answer, word);
    }
};

int main()
{

    return 0;
}