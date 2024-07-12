#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>
#include <conio.h>
#include <algorithm>
#include <Windows.h>
#include <fstream>

using namespace std;

bool transfer;
class up7down7;

bool play_or_not()
{
    string yes_no;
    cout << "DO YOU WANNA PLAY AGAIN (yes/no): ";
    cin >> yes_no;
    for (char& c : yes_no)
    {
        c = toupper(c);
    }
    while (yes_no != "YES" && yes_no != "NO")
    {
        cout << "    *-* Enter again *-*         " << endl;
        cout << "DO YOU WANNA PLAY AGAIN (yes/no): ";
        cin >> yes_no;
        for (char& c : yes_no)
        {
            c = toupper(c);
        }
    }
    system("cls");
    return (yes_no == "YES");
}

class Game {
protected:
    string* path;
    string name;
    char choose;
public:
    virtual void display() = 0;
    void get_path(string p)
    {
        path = new string;
        *path = p;
        

    }

    void play_instructions()
    {
        system("cls");
        cout << "\t\t\t\t\t\t\t" << "   ________________________________________________________________________________ " << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                                                                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                ______   __         ______     __  __                           |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |               /\\  == \\ /\\ \\       /\\  __ \\   /\\ \\_\\ \\                          |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |               \\ \\  _-/ \\ \\ \\____  \\ \\  __ \\  \\ \\____ \\                         |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                \\ \\_\\    \\ \\_____\\  \\ \\_\\ \\_\\  \\/\\_____\\                        |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                 \\/_/     \\/_____/   \\/_/\\/_/   \\/_____/                        |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                                                                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                 ____  ____                                     |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                / __ \\/ __ \\                                    |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                               / / / / /_/ /                                    |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                              / /_/ / _, _/                                     |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                              \\____/_/ |_|                                      |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                                                                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                     __  ___  __        __  ___    __        __                 |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |             | |\\ | /__`  |  |__) |  | /  `  |  | /  \\ |\\ | /__`                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |             | | \\| .__/  |  |  \\ \\__/ \\__,  |  | \\__/ | \\| .__/                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                                                                                |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |                  Press P to Play and I for instructions                        |" << endl;
        cout << "\t\t\t\t\t\t\t" << "  |________________________________________________________________________________|" << endl;

        cout << endl;
        cout << setw(106) << "Enter your choice: ";
        cin >> choose;
        choose = toupper(choose);

        while (choose != 'P' && choose != 'I')
        {
            cout << setw(106) << "Enter your choice: ";
            cin >> choose;
            choose = toupper(choose);

        }
        system("cls");
        if (choose == 'P')
        {
            return;
        }
        else
        {
            
            ifstream name;
            char txt;
            name.open(*path);
            while (!name.eof())
            {
                txt = name.get();
                cout << txt;
            }
            name.close();
            cout << endl << endl;

            cout << "Press Enter To Start the Game.... ";
            cin.get();
            cin.ignore();
            system("cls");
        }
    }

    ~Game()
    {
        delete path;
    }
};

class r_p_s;

class up7down7 {
private:
    int dice1;
    int dice2;
    string result;

    string dice_faces[6] = {
        " -------\n|       |\n|   *   |\n|       |\n -------\n",
        " -------\n| *     |\n|       |\n|     * |\n -------\n",
        " -------\n| *     |\n|   *   |\n|     * |\n -------\n",
        " -------\n| *   * |\n|       |\n| *   * |\n -------\n",
        " -------\n| *   * |\n|   *   |\n| *   * |\n -------\n",
        " -------\n| *   * |\n| *   * |\n| *   * |\n -------\n"
    };
    int sum;

public:
    void user_guess()
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << " _________________________ " << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|                         |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|          7 UP           |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|         7 DOWN          |" << endl;
        cout << "\t\t\t\t\t\t\t\t\t\t\t" << "|_________________________|" << endl;
        string choice;
        cout << endl;
        cout << setw(115) << "Enter your choice (up/down): ";
        cin >> choice;
        for (char& c : choice)
        {
            c = toupper(c);
        }

        while (!(choice == "UP" || choice == "DOWN"))
        {
            cout << setw(122) << "Re-Enter your choice (upper/lower case): ";
            cin >> choice;
            for (char& c : choice)
            {
                c = toupper(c);
            }
        }
        system("cls");
        bool temp = win_lose(choice);
        display(temp);
    }

    int Dice()
    {
        return rand() % 6 + 1;
    }

    void assign_values()
    {
        dice1 = Dice();
        dice2 = Dice();
        sum = dice1 + dice2;
    }

    void display_dice()
    {
        cout << "Value of dice 1: " << endl;
        cout << dice_faces[dice1 - 1];
        cout << "Value of dice 2:" << endl;
        cout << dice_faces[dice2 - 1];
        cout << endl << endl;
        cout << "Sum of both values = " << sum << endl;
        cout << "Press Enter To see the result.... ";
        cin.ignore();
        cin.get();
        system("cls");
    }


    bool win_lose(string g)
    {
        if ((sum >= 7) && (g == "UP") || (sum < 7) && (g == "DOWN"))
        {
            result = "You Win";
            return true;
        }
        else
        {
            result = "You Lose";
            return false;
        }
    }

    void display(bool temp)
    {
        display_dice();
        if (temp)
        {
            cout << " _________________________________________________________" << endl;
            cout << "|                             ________                    |" << endl;
            cout << "|    |     |       |      |      ||       |\\   |          |" << endl;
            cout << "|    |     |       |  /\\  |      ||       | \\  |          |" << endl;
            cout << "|    |     |       | /  \\ |      ||       |  \\ |          |" << endl;
            cout << "|    |_____|       |/    \\|   ___||___    |   \\|          |" << endl;
            cout << "|_________________________________________________________|" << endl;
        }
        else
        {
            cout << " _____________________________________________________________ " << endl;
            cout << "|                            ______     ______     ______     |" << endl;
            cout << "|    |     |       |        |      |   |          |           |" << endl;
            cout << "|    |     |       |        |      |   |______    |_____      |" << endl;
            cout << "|    |     |       |        |      |          |   |           |" << endl;
            cout << "|    |_____|       |_____   |______|    ______|   |______     |" << endl;
            cout << "|_____________________________________________________________|" << endl;
        }
        cout << endl;
    }

    friend void save_record(up7down7 g2, r_p_s g3);
};

class r_p_s {
private:
    string result;
public:
    int generate_comp_choice()
    {
        return rand() % 3 + 1;
    }

    int input_user_choice()
    {
        int choice;
        cout << "Choose your move:\n";
        cout << "1. Rock\n";
        cout << "2. Paper\n";
        cout << "3. Scissors\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        while (choice > 3 || choice < 1)
        {
            cout << "Invalid Choice! Enter again (1-3): ";
            cin >> choice;
        }
        cout << endl;
        return choice;
    }

    void Winner(int user_c, int computer_c)
    {
        cout << "Computer's choice: ";
        switch (computer_c)
        {
        case 1: cout << "Rock\n"; break;
        case 2: cout << "Paper\n"; break;
        case 3: cout << "Scissors\n"; break;
        }

        cout << "Your choice: ";
        switch (user_c)
        {
        case 1: cout << "Rock\n"; break;
        case 2: cout << "Paper\n"; break;
        case 3: cout << "Scissors\n"; break;
        }

        if (user_c == computer_c)
        {
            cout << "\nIt's a tie! Play again to determine the winner.\n";
            result = "Tie";
        }
        else if ((user_c == 1 && computer_c == 3) || (user_c == 2 && computer_c == 1) || (user_c == 3 && computer_c == 2))
        {
            cout << "\nCONGRATS AND CELEBRATIONS :) !! YOU WIN !!\n";
            result = "You Win";
        }
        else
        {
            cout << "\nComputer wins! Better luck next time.\n";
            result = "Computer Win";
        }
    }

    friend void save_record(up7down7 g2, r_p_s g3);
};

void save_record(up7down7 g2, r_p_s g3)
{
    static int up_down_rounds;
    static int r_p_s_rounds;
    ofstream os;
    os.open("C:\\Users\\LENOVO\\Desktop\\record.txt", ios_base::app);
    if (transfer == false)
    {
        up_down_rounds++;
        os << "\n \t\t ~~ Wins Record of 7 UP 7 DOWN ~~" << endl << endl;
        os << "Round " << up_down_rounds << " " << g2.result << endl;
    }
    else if(transfer == true)
    {
        r_p_s_rounds++;
        os << "\n \t\t ~~ Wins Record of Rock, Paper & Scissor ~~" << endl << endl;
        os << "Round " << r_p_s_rounds << " " << g3.result << endl;
    }
}

class gerangelo {
private:
    char level;
    string easy[20] = { "DOG", "CAT", "BAT", "CAR", "JAM", "SUN", "HAT", "PEN", "BOX", "CUP",
                          "BED", "FAN", "CAR", "BUS", "EGG", "RUG", "KEY", "LEG", "ARM", "TOY" };

    string medium[20] = { "BIRD", "TREE", "LAMP", "CAKE", "DUCK", "CHAIR", "HORSE", "SNAKE",
                         "APPLE", "TABLE", "PHONE", "TIGER", "RABBIT", "MOUSE", "BREAD",
                         "WATER", "LEMON", "BEACH", "SMILE", "HOUSE" };

    string hard[20] = { "BICYCLE", "BACKPACK", "ELEPHANT", "BEDROOM", "NECKLACE",
                         "MOSQUITO", "SANDWICH", "MOUNTAIN", "RAINBOW", "SUITCASE",
                         "PANCAKE", "KEYBOARD", "BALLOON", "GIRAFFE", "OCTAGON",
                         "WHISTLE", "EYEBROW", "TREASURE", "CUPBOARD", "UMBRELLA" };

public:
    void display()
    {
        cout << "Levels:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Hard" << endl;

        
        cout << "Select the level: ";
        cin >> level;
        while (!(level == '1' || level == '2' || level == '3'))
        {
            cout << "Invalid Input! Enter again (1-3): ";
            cin >> level;
        }
        play_game();
    }

    string shuffle_word(string word)
    {
        string shuffle = word;
        int len = word.length();
        srand(time(0));
        while (word == shuffle)
        {
            for (int i = len - 1; i > 0; i--)
            {
                int j = rand() % (i + 1);
                swap(shuffle[i], shuffle[j]);
            }
        }
        return shuffle;
    }


    void play_game()
    {
        string shuffle;
        int moves = 3;
        string chosen_word;
        int x = rand() % 20;

        if (level == '1')
        {
            chosen_word = easy[x];
        }
        else if (level == '2')
        {
            chosen_word = medium[x];
        }
        else if (level == '3')
        {
            chosen_word = hard[x];
        }

        shuffle = shuffle_word(chosen_word);

        bool flag = false;
        while (moves > 0)
        {
            system("cls");
            cout << "GRANGELO" << setw(175) << "Moves Left: " << moves << endl;
            display_word(shuffle);

            cout << endl << endl;
            cout << setw(185) << "Enter E to Exit" << endl;

            if (level == '3')
            {
                cout << endl;
                cout << setw(185) << "Enter H to Get Hint" << endl;
            }

            string guess;
            cout << "\nEnter your guess: ";
            cin >> guess;

            for (char& c : guess)
            {
                c = toupper(c);
            }

            if (guess == "E")
            {
                return;
            }
            if (guess == "H")
            {
                if (level == '3')
                {
                    ifstream file("C:\\Users\\LENOVO\\Desktop\\Hints.txt");
                    if (file.is_open())
                    {
                        int line_num = x + 1;
                        int current_line = 1;
                        string line;
                        while (getline(file, line))
                        {
                            if (current_line == line_num)
                            {
                                cout << "Hint: " << line << endl;
                                break;
                            }
                            current_line++;
                        }
                        file.close();
                    }
                    else
                    {
                        cout << "Hint file not found." << endl;
                    }
                }
                else
                {
                    cout << "Hints are only available for the hard level." << endl;
                }
                cout << "Press any key to continue.... ";
                cin.ignore();
                cin.get();
                continue;
            }

            if (guess == chosen_word)
            {
                cout << "CONGRATULATIONS!! YOU GUESSED IT RIGHT" << endl;
                flag = true;
                break;
            }
            else
            {
                cout << "Your guess is Wrong -_- " << endl;
                cout << "Press any key to continue.... ";
                cin.ignore();
                cin.get();
                moves--;
            }
        }
        if (flag==false)
        {
            cout << "You FAILED~~ >.<" << endl;
        }
    }

    void display_word(string word)
    {
        int len = word.length();
        for (int i = 0; i < len; i++)
        {
            cout << " _______________\t";
        }
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            cout << "|               |\t";
        }
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            cout << "|       " << word[i] << "       |\t";
        }
        cout << endl;
        for (int i = 0; i < len; i++)
        {
            cout << "|_______________|\t";
        }
        cout << endl;
    }

 
};


class SOS {
private:
    char board[4][3];
public:
    int player_wins;

    SOS()
    {
        // for (int i = 0; i < 3; i++)
        // {
        //     for (int j = 0; j < 3; j++)
        //     {
        //         board[i][j] = '*';
        //     }
        // }
    }

    void set_board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = '*';
            }
        }
    }

    void display_board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int n = 0; n < 3; n++)
            {
                if (n == 1)
                {
                    cout << "\t" << board[i][0] << "  \t | \t " << board[i][1] << "  \t | \t  " << board[i][2] << "  \t  " << endl;
                }
                else
                {
                    cout << "\t   \t | \t   \t | \t   \t  " << endl;
                }
            }
            if (i != 2)
            {
                cout << "-----------------------------------------------------" << endl;
            }
        }
    }

    string move_cursor(int user_no)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        GetConsoleCursorInfo(hConsole, &info);
        info.bVisible = false; // Hide cursor
        SetConsoleCursorInfo(hConsole, &info);

        short int x = 2, y = 8;

        while (true)
        {
            system("cls");
            cout << "Player " << user_no << setw(185) << "Enter E to Exit" << endl;
            display_board();
            SetConsoleCursorPosition(hConsole, { SHORT(y), SHORT(x) });
            cout << "X";

            int key = _getch();

            if (key == 0 || key == 224)
            { // Arrow key
                key = _getch();
                switch (key)
                {
                case 72: // Up arrow
                    if (x > 2) x -= 4;
                    break;
                case 80: // Down arrow
                    if (x < 10) x += 4;
                    break;
                case 75: // Left arrow
                    if (y > 8) y -= 17;
                    break;
                case 77: // Right arrow
                    if (y < 42) y += 17;
                    break;
                }
            }
            else if (key == 's' || key == 'S' || key == 'o' || key == 'O')
            {
                int row = x / 4;
                int col = y / 17;
                if (board[row][col] == '*')
                {
                    board[row][col] = toupper(key);
                    break;
                }
            }
            else if (key == 'E' || key == 'e')
            {
                system("cls");
                return "E";
            }
        }
        return "0";
    }

    bool check_board()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][i] == '*')
                {
                    return false;
                }
            }
        }
        return true;
    }

    void operator = (const SOS& t)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = t.board[i][j];
            }
        }
    }

    bool check_compl()
    {
        for (int r = 0; r < 3; r++)
        {
            if (board[r][0] == 'S' && board[r][1] == 'O' && board[r][2] == 'S')
            {
                return true;
            }
            if (board[0][r] == 'S' && board[1][r] == 'O' && board[2][r] == 'S')
            {
                return true;
            }
        }

        if (board[0][0] == 'S' && board[1][1] == 'O' && board[2][2] == 'S')
        {
            return true;
        }
        if (board[0][2] == 'S' && board[1][1] == 'O' && board[2][0] == 'S')
        {
            return true;
        }
        return false;
    }
};

class Game_manager : public Game {
private:
    bool chk;
    string temp;
    char choice;
    bool condition = true;
    int user_choice, computer_choice;
public:

    gerangelo game1;
    up7down7 game2;
    r_p_s game3;
    SOS obj1, obj2;

    void display()
    {

        cout << "\t\t\t\t\t\t\t\t" << "    ________           _        __      __     ________        " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "   /  ______\\         / \\      |  \\    /  |   |   _____|    " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  /  /   _____       / _ \\     |   \\  /   |   |  |___        " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  |  |  |___  |     / /_\\ \\    | |\\ \\/ /| |   |   ___|     " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  \\  \\______| |    / _____ \\   | | \\__/ | |   |  |_____    " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "   \\_______/|_|   /_/     \\_\\  |_|      |_|   |________|    " << endl;

        cout << endl << endl;

        cout << "\t\t\t\t\t\t\t\t" << "   ________        ________     __      __     ________        " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  |  ____  \\      /  ____  \\   |  \\    /  |   |   _____|    " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  | |    \\  \\    /  /    \\  \\  |   \\  /   |   |  |___     " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  | |     |  |  |  |      |  | | |\\ \\/ /| |   |   ___|       " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  | |____/  /    \\  \\____/  /  | | \\__/ | |   |  |_____     " << endl;
        cout << "\t\t\t\t\t\t\t\t" << "  |________/      \\________/   |_|      |_|   |________|      " << endl;

        cout << endl << endl;

        cout << setw(107) << "Press Enter To Start... ";
        cin.get();
        system("cls");

        const string loading_chars = "|/-\\";

        for (int i = 0; i < 14; i++)
        {
            cout << endl;
        }
        for (int i = 0; i < 20; i++) {
            cout << setw(95) << " " << "Loading " << loading_chars[i % 4] << "\r" << flush;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        system("cls");

        games_menu();
    }
        
    void games_menu()
    {
        while (condition)
        {
            cout << "\t\t\t\t\t\t\t" << " ___________________________________________________________________________________ " << endl;
            cout << "\t\t\t\t\t\t\t" << "|_________________________________SELECT_THE_GAME___________________________________|" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                                                                                   |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                              1. Gerangelo                                         |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                              2. 7 Up & 7 Down                                     |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                              3. Rock, Paper & Scissor                             |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                              4. SOS                                               |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|                              5. Exit                                              |" << endl;
            cout << "\t\t\t\t\t\t\t" << "|___________________________________________________________________________________|" << endl << endl;


            cout << setw(105) << "Enter Your Choice: ";
            cin >> choice;
            cin.ignore();
            while (!(choice == '1' || choice == '2' ||choice == '3' ||choice == '4' ||choice == '5'))
            {
                cout << setw(108) << " -_- Re-Enter Your Choice: ";
                cin >> choice;
            }
            chk = true;
            system("cls");

            switch (choice)
            {
            case '1':
                while (chk == true)
                {
                    get_path("C:\\Users\\LENOVO\\Desktop\\gerangelo.txt");
                    play_instructions();
                    //gerangelo game1;
                    game1.display();
                    chk = play_or_not();
                }
                break;

            case '2':
                while (chk == true)
                {
                    get_path("C:\\Users\\LENOVO\\Desktop\\7up7down.txt");
                    play_instructions();
                    // up7down7 game2;
                    game2.assign_values();
                    game2.user_guess();
                    transfer = false;
                    save_record(game2, game3);
                    chk = play_or_not();
                }
                break;

            case '3':
                while (chk == true)
                {
                    get_path("C:\\Users\\LENOVO\\Desktop\\r_p_s.txt");
                    play_instructions();
                    //r_p_s game3;
                    computer_choice = game3.generate_comp_choice();
                    user_choice = game3.input_user_choice();
                    game3.Winner(user_choice, computer_choice);
                    cout << endl;
                    transfer = true;
                    save_record(game2, game3);
                    chk = play_or_not();
                }
                break;

            case '4':

                obj1.player_wins = 0;
                obj2.player_wins = 0;
                while (chk == true)
                {
                    ofstream os;
                    os.open("C:\\Users\\LENOVO\\Desktop\\record.txt", ios_base::app);
                    os << "\n \t\t ~~ Wins Record of SOS ~~" << endl << endl;

                    get_path("C:\\Users\\LENOVO\\Desktop\\sos.txt");
                    play_instructions();
                    int rounds;
                    cout << "Enter the number of rounds you want to play (1, 3, or 5): ";
                    cin >> rounds;
                    while (rounds != 1 && rounds != 3 && rounds != 5)
                    {
                        cout << "Invalid number of rounds. Please enter 1, 3, or 5: ";
                        cin >> rounds;
                    }

                    for (int i = 1; i <= rounds; i++)
                    {
                        //SOS obj1, obj2;
                        obj1.set_board();
                        obj2.set_board();

                        bool flag = true;
                        while (flag)
                        {
                            if (obj1.move_cursor(1) == "E")
                            {
                                flag = false;
                                break;
                            }
                            if (obj1.check_compl())
                            {
                                system("cls");
                                cout << "PLAYER 1 WON ROUND " << i << endl;
                                os << "Round " << i << " Won by Player: 1" << endl;

                                obj1.player_wins++;
                                flag = false;
                                break;
                            }
                            if (obj1.check_board())
                            {
                                system("cls");
                                cout << "THIS ROUND IS A DRAW" << endl;
                                Sleep(3000);

                                flag = false;
                                break;
                            }

                            obj2 = obj1;
                            if (obj2.move_cursor(2) == "E")
                            {
                                flag = false;
                                break;
                            }
                            if (obj2.check_compl())
                            {
                                system("cls");
                                cout << "PLAYER 2 WON ROUND " << i << endl;
                                os << "Round " << i << " Won by Player: 2" << endl;

                                obj2.player_wins++;
                                flag = false;
                                break;
                            }
                            if (obj2.check_board())
                            {
                                system("cls");
                                cout << "THIS ROUND IS A DRAW" << endl;
                                Sleep(3000);

                                flag = false;
                                break;
                            }
                            obj1 = obj2;
                        }
                        if (i < rounds)
                        {
                            cout << "Round " << i << " completed. Next round will start soon..." << endl;
                            Sleep(3000);
                        }
                    }

                    system("cls");
                    cout << "OUTCOME OF MATCHES:" << endl;
                    cout << "WINS OF PLAYER 1: " << obj1.player_wins << endl;
                    cout << "WINS OF PLAYER 2: " << obj2.player_wins << endl;
                    chk = play_or_not();
                }
                break;

            case '5':
                cout << setw(120) << "EEEEEEEEEE   N       N  DDDDDDDDD" << endl;
                cout << setw(120) << "EE           NN      N  D         D" << endl;
                cout << setw(120) << "EE           N N     N  D          D" << endl;
                cout << setw(120) << "EE           N  N    N  D          D" << endl;
                cout << setw(120) << "EEEEEEE      N   N   N  D          D" << endl;
                cout << setw(120) << "EE           N    N  N  D          D" << endl;
                cout << setw(120) << "EE           N     N N  D         D" << endl;
                cout << setw(120) << "EEEEEEEEEE   N      NN  DDDDDDDDD" << endl;

                condition = false;
                break;
            }
        }
    }

};

int main()
{
    srand(time(0));
    Game* G;
    Game_manager obj;
    G = &obj;
    G->display();
    return 0;
}
