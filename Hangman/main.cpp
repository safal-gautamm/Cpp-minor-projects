#include <iostream>
#include <ctime>

using namespace std;

const int max_misses = 6;

class Message {
public:

    void greet() {
        cout << "------------------------------" << endl;
        cout << "\t\tH A N G M A N" << endl;
        cout << "------------------------------" << endl;
        cout << "Guess the Word" << endl << endl;
    }


    void display_misses(int misses) {

        switch (misses) {

            case 0:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 1:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 2:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << "  |   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 3:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 4:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|\\  | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 5:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|\\  | " << endl;
                cout << " /    | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            case 6:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|\\  | " << endl;
                cout << " / \\  | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;
        }
    }


    void display_incorrect_guesses(string incorrect) {
        cout << "Incorrect Guesses: " << incorrect << endl;
    }
    
    void display_user_answer(string user_answer) {
        cout << "Your Answer: ";
        for (char c: user_answer) {
            cout << c << " ";
        }

        cout << endl;
    }

    void invalid_character_message() {
        cout << "\nInvalid character!" << endl;
        cout << "Input must be an alphabet!" << endl;
    }

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

    void final_result(string user_answer, string word) {
        cout << "Your Answer: ";
        for (char c: user_answer) {
            cout << c << " ";
        }

        cout << endl << endl;

        if (user_answer == word) {
            cout << "-----------------------------------------------" << endl;
            cout << "\t\t\t\tY O U  W I N" << endl;
            cout << "-----------------------------------------------" << endl;
        }

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

    Game(string chosen_word) {
        word = chosen_word;
        incorrect = "";
        entered_characters = "";
        misses = 0;

        for (int i = 0; i < word.length(); ++i) {
            user_answer += "_";
        }
    }

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

    bool is_game_over() {
        if (user_answer == word || misses >= max_misses) {
            return true;
        }
        return false;
    }

    void display_game_status() {
        message.display_misses(misses);
        message.display_incorrect_guesses(incorrect);
        message.display_user_answer(user_answer);
    }

    void display_final_result() {
        message.display_misses(misses);
        message.final_result(user_answer, word);
    }
};

int main() {

    string library[] = { 
        "ALGORITHM", 
        "AUTOPSY", 
        "DATABASE", 
        "UBIQUITOUS", 
        "TANTALIZING", 
        "REVELATION", 
        "SPORADIC", 
        "DISCRETE", 
        "ANALYSIS", 
        "CALCULUS" 
    };

    srand(time(0));
    int index = rand() % 10;

    string chosen_word = library[index];

    char letter;
    
    Message message;
    Game game(chosen_word);

    message.greet();

    while (!game.is_game_over()) {

        game.display_game_status();

        cout << "\nPlease enter your guess: ";

        cin >> letter;
        letter = toupper(letter);

        if (game.is_guess_valid(letter)) {

            game.is_guess_correct(letter);
        }
    }

    game.display_final_result();

    return 0;
}