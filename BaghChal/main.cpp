#include <iostream>
using std::cout, std::endl;

class Board
{
    public:
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

    void display()
    {
        cout << board[0] << "------------" << board[1] << "------------" << board[2] << endl;
        cout << " " << "|\\          " << "|" << "         / |" << " " << endl;
        cout << " " << "|  \\        " << "|" << "        /  |" << " " << endl;
        cout << " " << "|    \\      " << "|" << "      /    |" << " " << endl;
        cout << " " << "|      \\    " << "|" << "    /      |" << " " << endl;
        cout << " " << "|        \\  " << "|" << "  /        |" << " " << endl;
        cout << " " << "|          \\" << "|" << "/          |" << " " << endl;
        cout << " " << board[3] << "-----------" << board[4] << "----------" << board[5] << endl;
        cout << " " << "|          /" << "|" << "\\          |" << " " << endl;
        cout << " " << "|        /  " << "|" << "  \\        |" << " " << endl;
        cout << " " << "|      /    " << "|" << "    \\      |" << " " << endl;
        cout << " " << "|    /      " << "|" << "      \\    |" << " " << endl;
        cout << " " << "|  /        " << "|" << "        \\  |" << " " << endl;
        cout << " " << "|/          " << "|" << "          \\|" << " " << endl;
        cout << board[6] << "------------" << board[7] << "------------" << board[8] << endl;
    }
};

int main() {
    Board board;
    board.display();
}
