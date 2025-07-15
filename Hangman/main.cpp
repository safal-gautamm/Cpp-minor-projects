#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <ncurses.h>
#include <cctype>
#include <string>

using namespace std;

const int max_misses = 6;

class Message {
public:
    void greet() {
        clear();
        printw("------------------------------\n");
        printw("          H A N G M A N\n");
        printw("------------------------------\n");
        printw("Guess the Word\n\n");
        refresh();
    }

    void display_misses(int misses) {
        const char* stages[] = {
            "  +---+ \n  |   | \n      | \n      | \n      | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n      | \n      | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n  |   | \n      | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n /|   | \n      | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n /|\\  | \n      | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n /|\\  | \n /    | \n      | \n=========\n",
            "  +---+ \n  |   | \n  O   | \n /|\\  | \n / \\  | \n      | \n=========\n"
        };
        mvprintw(1, 0, "%s", stages[misses]);
    }

    void display_incorrect_guesses(string incorrect) {
        mvprintw(9, 0, "Incorrect Guesses: %s", incorrect.c_str());
    }

    void display_user_answer(string user_answer) {
        mvprintw(11, 0, "Your Answer: ");
        for (char c : user_answer) {
            printw("%c ", c);
        }
    }

    void invalid_character_message() {
        mvprintw(13, 0, "Invalid character! Input must be an alphabet!");
    }

    void already_entered_message() {
        mvprintw(13, 0, "You have already entered this letter! Enter another letter!");
    }

    void correct_message() {
        mvprintw(13, 0, "Correct!                                    ");
    }

    void incorrect_message() {
        mvprintw(13, 0, "Incorrect!                                  ");
    }

    void final_result(string user_answer, string word) {
        clear();
        display_misses((user_answer == word) ? 0 : max_misses);
        mvprintw(8, 0, "Your Answer: ");
        for (char c : user_answer) {
            printw("%c ", c);
        }
        printw("\n\n");

        if (user_answer == word) {
            printw("---------------------------------------------\n");
            printw("                 Y O U  W I N !\n");
            printw("---------------------------------------------\n");
        }
        else {
            printw("The correct answer is: %s\n\n", word.c_str());
            printw("---------------------------------------------\n");
            printw("                 Y O U  L O S E !\n");
            printw("---------------------------------------------\n");
        }
        refresh();
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
        user_answer = string(word.length(), '_');
    }

    bool is_guess_valid(char letter) {
        if (!isalpha(letter)) {
            message.invalid_character_message();
            refresh();
            return false;
        }
        for (char c : entered_characters) {
            if (letter == c) {
                message.already_entered_message();
                refresh();
                return false;
            }
        }
        return true;
    }

    void is_guess_correct(char letter) {
        bool guess = false;
        for (size_t i = 0; i < word.length(); i++) {
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
        refresh();
    }

    bool is_game_over() {
        return (user_answer == word || misses >= max_misses);
    }

    void display_game_status() {
        clear();
        message.display_misses(misses);
        message.display_incorrect_guesses(incorrect);
        message.display_user_answer(user_answer);
        refresh();
    }

    void display_final_result() {
        message.final_result(user_answer, word);
    }
};

int main() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    string content;
    vector<string> library;

    ifstream file("vocab.txt");
    while (getline(file, content)) {
        if (!content.empty()) {
            library.push_back(content);
        }
    }
    file.close();

    srand(static_cast<unsigned>(time(0)));
    int index = rand() % library.size();

    string chosen_word = library[index];
    for (auto& ch : chosen_word) {
        ch = toupper(ch);
    }

    Message message;
    Game game(chosen_word);

    message.greet();

    int ch;
    while (!game.is_game_over()) {
        game.display_game_status();

        mvprintw(13, 0, "Please enter your guess: ");
        refresh();

        ch = getch();
        ch = toupper(static_cast<unsigned char>(ch));

        if (game.is_guess_valid(ch)) {
            game.is_guess_correct(ch);
        }
    }

    game.display_final_result();

    mvprintw(15, 0, "Press any key to exit...");
    refresh();
    getch();

    endwin();
    return 0;
}
