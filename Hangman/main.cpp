#include <iostream>
#include <ctime>

using namespace std;

const int max_misses = 6;

// message class for displaying messages and design
class Message {
public:

    // method to greet the player
    void greet() {
        cout << "------------------------------" << endl;
        cout << "\t\tH A N G M A N" << endl;
        cout << "------------------------------" << endl;
        cout << "Guess the Word" << endl << endl;
    }


    void display_misses(int misses) {

        // add the body parts of the Hangman
        // according to the number of misses
        switch (misses) {

            // display an empty gallows when misses = 0
            case 0:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's head
            case 1:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's torso
            case 2:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << "  |   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's right arm
            case 3:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|   | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's left arm
            case 4:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|\\  | " << endl;
                cout << "      | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's left leg
            case 5:
                cout << "  +---+ " << endl;
                cout << "  |   | " << endl;
                cout << "  O   | " << endl;
                cout << " /|\\  | " << endl;
                cout << " /    | " << endl;
                cout << "      | " << endl;
                cout << "=========" << endl;
                break;

            // draw the Hangman's right leg
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

// Game class to code the game logic
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
        message.display_misses(misses);
        message.display_incorrect_guesses(incorrect);
        message.display_user_answer(user_answer);
    }

    // method to display the final result
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

    // generate random numbers between 0 and 9
    srand(time(0));
    int index = rand() % 10;

    // choose the mystery word
    // based on the random number
    string chosen_word = library[index];

    // variable to take user input
    char letter;
    
    Message message;
    Game game(chosen_word);

    // greet the player
    message.greet();

    // play game until victory or loss
    while (!game.is_game_over()) {

        // display the game status
        game.display_game_status();

        cout << "\nPlease enter your guess: ";

        // get user input and convert it to uppercase
        cin >> letter;
        letter = toupper(letter);

        // check if input is an alphabet
        if (game.is_guess_valid(letter)) {

            // if input is valid, check if guess is correct
            game.is_guess_correct(letter);
        }
    }

    game.display_final_result();

    return 0;
}