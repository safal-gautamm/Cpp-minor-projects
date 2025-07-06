#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#define True 1
using namespace std;

string to_lower(string str)
{
    for (char &c : str)
        c = tolower(c);
    return str;
}

string get_computer_choice()
{
    int rand_num = rand() % 3 + 1;
    switch (rand_num)
    {
    case 1:
        return "rock";
    case 2:
        return "paper";
    case 3:
        return "scissors";
    default:
        return "rock"; // default fallback
    }
}

string get_user_input()
{
    string users;
    while (True)
    {
        cout << "\nChoose [Rock, Paper, Scissors, exit]: ";
        cin >> users;
    
        users = to_lower(users);
    
        if (users == "rock" || users == "r")
            return "rock";
        else if (users == "paper" || users == "p")
            return "paper";
        else if (users == "scissors" || users == "s")
            return "scissors";
        else if (users == "exit" || users == "e")
            return "exit";
        else {
            cout << "Invalid input! Try again.\n";
            return get_user_input();
        }

    }
}


int main()
{
    srand(time(NULL));

    cout << "Welcome to Rock, Paper, Scissors!\n";
    int score = 0;
    while (True)
    {
        string user_choice = get_user_input();
        if(user_choice == "exit")
        {
            cout << "You scored:" << score << endl; 
            break;
        }
        string comp_choice = get_computer_choice();

        cout << "You chose: " << user_choice << endl;
        cout << "Computer chose: " << comp_choice << endl;

        // Determine winner
        if (user_choice == comp_choice) {
            cout << "It's a draw!\n";
        } else if (
            (user_choice == "rock" && comp_choice == "scissors") ||
            (user_choice == "paper" && comp_choice == "rock") ||
            (user_choice == "scissors" && comp_choice == "paper")
        ) {
            cout << "You win!\n";
            score++;
        } else {
            cout << "Computer wins!\n";
        }
    }
    

    return 0;
}
