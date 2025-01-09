#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
char arr[9][9];
string name1, name2;                                              // here declare global variable
bool draw_mode();                                                 // here prototype of function tell
int draw_count = 0, draw_count2 = 0;                              // here declare and intialize global varible for counting of draw match
char marker = '*', current_marker, player_marker, player_marker2; // Here declare global variable and initialize
int current_player;                                               // here declare global variable
// This Funtion store "*" in board of 8X8
void board2()
{
    for (int i = 1; i <= 8; ++i) // external loop execute 1 to 8
    {
        for (int j = 1; j <= 8; ++j) // internal loop execute 1 to 8
        {
            arr[i][j] = marker; // here store "*" in arr[i][j]
        }
    }
}
// This function Print board which  already fill with "*"
void display2()
{
    for (int i = 1; i <= 8; ++i) // external loop execute 1 to 8
    {
        cout << "                           ";
        for (int j = 1; j <= 8; ++j) // internal loop execute 1 to 8
        {
            cout << " " << arr[i][j]; // here display array
        }
        cout << endl;
    }
}
// This function  replace "*" with player attack marker on enter a coulm and this is for 4X4 board
bool place_marker1(int slot)
{
    int row = 0, col; // declare and intialize variable
    col = slot;       // here store user select coulm means attack in "coulm" variable
    row = 4;          // here initilize row with 4
    bool flag = 1;    // here take bool variable
    while (flag)      // here loop execute when flag variable is true
    {
        if (arr[row][col] == player_marker || arr[row][col] == player_marker2)
        {          // this check for decrease length or row if players marker already on it
            --row; // here decrease length or row
        }
        else if (arr[row][col] == marker && arr[row][col] != player_marker && arr[row][col] != player_marker2) // Here check if "*" is present on player selected coulm than replace with player mark
        {
            arr[row][col] = current_marker; // here replace with player mark
            return true;                    // and return true
        }
        else
        {
            return false; // otherwise return false
        }
    }
}
// This function  replace "*" with player attack marker on enter a coulm and this is for 8X8 board
bool place_marker2(int slot)
{
    int row = 0, col; // declare and intialize variable
    col = slot;       // here store user select coulm means attack in "coulm" variable
    row = 8;          // here intialize row with 8
    bool flag = 1;    // here take bool variable
    while (flag)      // hereloop execute when flag is true
    {
        if (arr[row][col] == player_marker || arr[row][col] == player_marker2)
        {          // this check for decrease length or row if players marker already on it
            --row; // Here decrease length or row
        }
        else if (arr[row][col] == marker && arr[row][col] != player_marker && arr[row][col] != player_marker2) // Here check if "*" is present on player selected coulm than replace with player mark
        {
            arr[row][col] = current_marker; // here replace with player mark
            return true;                    // and return true
        }
        else
        {
            return false; // otherwise return false
        }
    }
}
// This function is for toss b/w two players
bool toss()
{
    int x; // here declare variable
    cout << " Enter any Number for toss is:";
    cin >> x; // here take any number from user for toss
    if (x % 2 == 0)
    {                                               // here check if mod is zero
        cout << " Player 1 Won the toss !" << endl; // than display player 1 won toss
        current_player = 2;                         // and store 2 in current_player
        return false;                               // and return false
    }
    else
    {
        cout << " Player 2 Won the toss !" << endl; // otherwise display these statement
        current_player = 1;                         // and store 1 in current_player
        return true;                                // return and false
    }
}
// This Function is for replacing turn and marker on every player turn
void swap_player_turn()
{
    if (current_marker == player_marker)
    {                                    // check if curent_marker which already store in main is equal to enter player_marker
        current_marker = player_marker2; // than replace marker with marker2 which take in main
    }
    else
    {
        current_marker = player_marker; // otherwise become or store playe_marker
    }
    if (current_player == 1)
    {                       // check if current player is 1 than current player replace with 2 actually swap on every turn
        current_player = 2; // here become player2
    }
    else
    {
        current_player = 1; // become player1
    }
}
// This is board of 4X4 which strting initialize with "*"
void board1()
{
    for (int i = 1; i <= 4; ++i)
    { // loop execute 1 to 4
        for (int j = 1; j <= 4; ++j)
        {                       // loop execute 1 to 4
            arr[i][j] = marker; // here initialize with "*"
        }
    }
}
// This function Display board of 4X4 on screen
void display1()
{
    for (int i = 1; i <= 4; ++i)
    { // loop execute 1 to 4
        cout << "                           ";
        for (int j = 1; j <= 4; ++j)
        {                             // here loop execute 1 to 4
            cout << " " << arr[i][j]; // here display board on screen means value of arr[i][j]
        }
        cout << endl;
    }
}
// This Function Check Winner in 4X4 board
bool win1()
{
    for (int i = 1; i <= 4; ++i)
    { // loop execute 1 to 4
        if ((arr[i][1] == player_marker) && (arr[i][2] == arr[i][1]) && (arr[i][3] == arr[i][2]) && (arr[i][4] == arr[i][3]))
        { // check for row if same 4 are met than return false
            if (current_player == 2)
            {                       // here check if above condition is fill than next player turn become or reverse player1
                current_player = 1; // here replace player 2 with 1
            }
            else
            {
                current_player = 2; // otherwise replace with player2
            }
            cout << " Player " << current_player << " Won the game!" << endl; // Display these message on screen
            return false;                                                     // and return false
        }
        else if ((arr[1][i] == player_marker) && (arr[2][i] == arr[1][i]) && (arr[3][i] == arr[2][i]) && (arr[4][i] == arr[3][i]))
        { // check for coulm if same 4 are met than return false
            if (current_player == 2)
            {                       // here check if above condition is fill than next player turn become or reverse player1
                current_player = 1; // here player 2 become 1
            }
            else
            {
                current_player = 2; // otherwise become 2
            }
            cout << " Player " << current_player << " Won the game!" << endl; // display these message on screen
            return false;                                                     // and return false
        }
    }
    if (draw_mode() == false)
    { // check for draw games
        cout << " Draw the game !" << endl;
        ++draw_count; // count for daw games
        return false; // and return false
    }
    if ((arr[1][1] == player_marker) && (arr[2][2] == arr[1][1]) && (arr[3][3] == arr[2][2]) && (arr[4][4] == arr[3][3]))
    { // check for Diagonal if same 4 are met than return false
        if (current_player == 2)
        {                       // here check if above condition is fill than next player turn become or reverse player1
            current_player = 1; // here replace player 2 with 1
        }
        else
        {
            current_player = 2; // else replace with 2
        }
        cout << " Player " << current_player << " Won the game!" << endl; // here display these message
        return false;                                                     // and return false
    }
    else if ((arr[1][4] == player_marker) && (arr[2][3] == arr[1][4]) && (arr[3][2] == arr[2][3]) && (arr[4][1] == arr[3][2]))
    { // check for Diagonal if same 4 are met than return false
        if (current_player == 2)
        {                       // here check if above condition is fill than next player turn become or reverse player1
            current_player = 1; // here replace player 2 with 1
        }
        else
        {
            current_player = 2; // else replace with 2
        }
        cout << " Player " << current_player << " Won the game!" << endl; // display these message
        return false;                                                     // and return false
    }
    for (int i = 1; i <= 4; ++i)
    {
        if ((arr[i][1] == player_marker2) && (arr[i][2] == arr[i][1]) && (arr[i][3] == arr[i][2]) && (arr[i][4] == arr[i][3]))
        { // check for row if same 4 of mark name "player_marker2" are met than return false
            if (current_player == 2)
            {                       // here check if above condition is fill than next player turn become or reverse player1
                current_player = 1; // here replace player 2 with 1
            }
            else
            {
                current_player = 2; // else replace with 2
            }
            cout << " Player " << current_player << " Won the game!" << endl; // display these message
            return false;                                                     // and return false
        }
        else if ((arr[1][i] == player_marker2) && (arr[2][i] == arr[1][i]) && (arr[3][i] == arr[2][i]) && (arr[4][i] == arr[3][i]))
        { // check for coulm if same 4 of mark name "player_marker2" are met than return false
            if (current_player == 2)
            {                       // here check if above condition is fill than next player turn become or reverse player1
                current_player = 1; // here replace player 2 with 1
            }
            else
            {
                current_player = 2; // otherwise replace with 2
            }
            cout << " Player " << current_player << " Won the game!" << endl; // here display these message on screen
            return false;                                                     // otherwise return false
        }
    }
    if ((arr[1][1] == player_marker2) && (arr[2][2] == arr[1][1]) && (arr[3][3] == arr[2][2]) && (arr[4][4] == arr[3][3]))
    { // check for Diagonal if same 4 of mark name "player_marker2" are met than return false
        if (current_player == 2)
        {                       // here check if above condition is fill than next player turn become or reverse player1
            current_player = 1; // player 2 become 1
        }
        else
        {
            current_player = 2; // here player become 2 if condition wrong
        }
        cout << " Player " << current_player << " Won the game!" << endl; // here display these message
        return false;                                                     // otherwise return false
    }
    else if ((arr[1][4] == player_marker2) && (arr[2][3] == arr[1][4]) && (arr[3][2] == arr[2][3]) && (arr[4][1] == arr[3][2]))
    { // check for Diagonal if same 4 of mark name "player_marker2" are met than return false
        if (current_player == 2)
        {                       // here check if above condition is fill than next player turn become or reverse player1
            current_player = 1; // player 2 becomec 1
        }
        else
        {
            current_player = 2; // otherwise player become 2
        }
        cout << " Player " << current_player << " Won the game!" << endl; // display these message
        return false;                                                     // and return false
    }
    else
        return true; // otherwise return true
}
// This function is Check Winner in board of 8X8
bool win2()
{
    int c = 0; // here declare and intialize c with "0"
    for (int i = 8; i >= 1; --i)
    { // loop execute 8 to 1
        for (int j = 1; j <= 8; ++j)
        { // loop execute 1 to 8
            if (arr[i][j] == player_marker && arr[i - 1][j] == player_marker && arr[i - 2][j] == player_marker && arr[i - 3][j] == player_marker)
            {          // check for coulm if same 4 of marker name "player_marker" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
            else if (arr[i][j] == player_marker && arr[i][j + 1] == player_marker && arr[i][j + 2] == player_marker && arr[i][j + 3] == player_marker)
            {          // check for row if same 4 of marker name "player_marker" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
            else if (arr[i][j] == player_marker && arr[i - 1][j + 1] == player_marker && arr[i - 2][j + 2] == player_marker && arr[i - 3][j + 3] == player_marker)
            {          // check for Diagonal if same 8 of mark name "player_marker" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
        }
    }
    if (draw_mode() == false)
    {                  // check for draw games
        ++draw_count2; // count draw games
        return false;  // return false
    }
    for (int i = 8; i >= 1; --i)
    { // loop execute 8 to 1
        for (int j = 1; j <= 8; ++j)
        { // loop execute 1 to 8
            if (arr[i][j] == player_marker2 && arr[i - 1][j] == player_marker2 && arr[i - 2][j] == player_marker2 && arr[i - 3][j] == player_marker2)
            {          // check for coulm if same 4 of marker name "player_marker2" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
            else if (arr[i][j] == player_marker2 && arr[i][j + 1] == player_marker2 && arr[i][j + 2] == player_marker2 && arr[i][j + 3] == player_marker2)
            {          // check for row if same 4 of marker name "player_marker2" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
            else if (arr[i][j] == player_marker2 && arr[i - 1][j + 1] == player_marker2 && arr[i - 2][j + 2] == player_marker2 && arr[i - 3][j + 3] == player_marker2)
            {          // check for Diagonal if same 4 of marker name "player_marker2" are met than store 1 in "c"
                c = 1; // here store 1 in "c"
            }
        }
    }
    for (int i = 1; i <= 8; ++i)
    { // loop execute from 1 to 8
        for (int j = 1; j <= 8; ++j)
        { // loop execute from 1 to 8
            if (arr[i][j] == player_marker && arr[i + 1][j + 1] == player_marker && arr[i + 2][j + 2] == player_marker && arr[i + 3][j + 3] == player_marker)
            {          // check for diagonal when 4 met same marker than strore 1 in c
                c = 1; // store 1 in c
            }
            else if (arr[i][j] == player_marker2 && arr[i + 1][j + 1] == player_marker2 && arr[i + 2][j + 2] == player_marker2 && arr[i + 3][j + 3] == player_marker2)
            {          // check for diagonal when 4 met same marker than store 1 in c
                c = 1; // store 1 in c
            }
        }
    }
    if (c == 1)
    { // Check if above coondition is true and receive 1 in "c" than
        if (current_player == 2)
        {                       // check player is 2 than it become 1
            current_player = 1; // here current player become 1
        }
        else
        {
            current_player = 2; // here player become 2
        }
        cout << " Player " << current_player << " Won the Game !" << endl; // display these message
        return false;                                                      // and return false
    }
}
// This Function show whose Game Developer
void credits()
{
    cout << "                                           ------------------------------------------" << endl;
    cout << "                                          |           Developed By Samiullah           |" << endl;
    cout << "                                           ------------------------------------------" << endl;
}
// This Function Display Instruction or Rules of Games
void Rules()
{
    cout << "                                      --------------------------------------------------------" << endl;
    cout << "                                     | 1) This  game  is  only  for   two    players .       | " << endl;
    cout << "                                     | 2)  Game   consist   on   two   modes .               | " << endl;
    cout << "                                     | 3) Game is End When 4 same marker connect .           | " << endl;
    cout << "                                      --------------------------------------------------------" << endl;
}
// This Function take names of Players
void player_name()
{
    cout << " Enter a player 1 name is:";
    cin >> name1; // here enter one player name
    cout << " Enter a player 2 name is:";
    cin >> name2; // here enter a player 2 name
}
// This function check for draw games
bool draw_mode()
{
    // check for draw in easy mode
    if ((arr[1][1] == player_marker || player_marker && arr[1][1] != marker) && (arr[1][2] == player_marker || player_marker && arr[1][2] != marker) && (arr[1][3] == player_marker || player_marker && arr[1][3] != marker) && (arr[1][4] == player_marker || player_marker && arr[1][4] != marker))
    {
        return false; // and return false
    }
    // check draw in hard mode
    else if ((arr[1][1] == player_marker || player_marker && arr[1][1] != marker) && (arr[1][2] == player_marker || player_marker && arr[1][2] != marker) && (arr[1][3] == player_marker || player_marker && arr[1][3] != marker) && (arr[1][4] == player_marker || player_marker && arr[1][4] != marker) && (arr[1][5] == player_marker || player_marker && arr[1][5] != marker) && (arr[1][6] == player_marker || player_marker && arr[1][6] != marker) && (arr[1][7] == player_marker || player_marker && arr[1][7] != marker) && (arr[1][8] == player_marker || player_marker && arr[1][8] != marker))
    {
        return false; // return false
    }
    else
        return true; // otherwise return true
}
// This function exit for exit the game and print below message
void exit()
{
    cout << " Good Bye ! And Your Score is:" << endl;
}
int main()
{

    system("color B5"); // This is use for color background and text on screen
    // here disply starting menu
    cout << "                                                        -----------------" << endl;
    cout << "                                                       | Connect 4 GAME  |" << endl;
    cout << "                                                        -----------------" << endl;
    cout << "                                                       | 1: CREDITS      |" << endl;
    cout << "                                                        -----------------" << endl;
    cout << "                                                        -----------------" << endl;
    cout << "                                                       | 2: INSTRUCTION  |" << endl;
    cout << "                                                        -----------------" << endl;
    cout << "                                                       | 3: PLAY  GAME   |" << endl;
    cout << "                                                        -----------------" << endl;
    cout << "                                                       | 4: Exit GAME    |" << endl;
    cout << "                                                        -----------------" << endl;
    int count = 0, count1 = 0, count2 = 0, count3 = 0; // here decalre and intialize variable
    int ch;
    do
    {
        cout << " Enter a choice is:";
        cin >> ch; // here user enter  a choice
        if (ch == 1)
        {
            credits(); // check to show developer name
        }
        else if (ch == 2)
        {
            Rules(); // check for show instruction of games
        }
        else if (ch == 3)
        {               // check for playing game
            char alpha; // here declare variable
            do
            {
                int choice; // here declare variable
                cout << "\n"
                     << "\n"
                     << "             | Hello Guys! This is Connect 4 Game Which Module You Want to Play |" << "\n"
                     << endl;                                // Display these on screen
                cout << " Enter 1 for Easy and 2 for Hard:"; // display these message on screen
                cin >> choice;                               // here take choice which mode you want to play
                switch (choice)
                {

                case 1:
                {
                    int slot; // here declare variable of slot
                    board1(); // here call of board1 function which store "*" in strting
                    cout << "\n"
                         << "                       Welcome to Connnect 4 !          " << "\n"
                         << endl; // disply these on screen
                    display1();   // here call display1 function which display board on screen
                    cout << endl;
                    player_name(); // here call credit function which take name of player
                    if (toss() == false)
                    { // here call of toss function and check if function is  false than player 1 win toss and choose marker
                        cout << " Enter a Player 1 Mark is:";
                        current_player = 1;   // here store 1 in current player
                        cin >> player_marker; // here take marker of player 1
                        cout << " Enter a Player marker 2 is:";
                        cin >> player_marker2;           // here take marker of player 2
                        current_marker = player_marker2; // here store playermarker2 in current marker
                    }
                    else
                    {
                        cout << " Enter a Player 2 Mark is:";
                        current_player = 2;    // else store 2 in current player
                        cin >> player_marker2; // here take player 2 marker
                        cout << " Enter a Player marker 1 is:";
                        cin >> player_marker;           // here enter player 1 marker
                        current_marker = player_marker; // here stote player 1 marker in current marker
                    }
                    bool w = true; // here take bool variable
                    do
                    {
                        w = win1(); // here win function store in "w"
                        cout << "Enter the column of player " << current_player << " is:";
                        cin >> slot; // here enter a player coulm
                        if (arr[1][slot] == player_marker || arr[1][slot] == player_marker2)
                        { // Check if coulm is fill
                            do
                            {
                                cout << " Coulm is fill enter again:";
                                cin >> slot; // here take again coulm
                            } while (arr[1][slot] != marker); // loop execute untill user enter correct coulm which is not fill
                        }
                        if (slot < 1 || slot > 4)
                        { // Check for coulm is greater than 4
                            cout << " Please Enter a Coulm between 1 to 4:";
                            do
                            {
                                cin >> slot; // here take agin coulm
                            } while (slot < 1 || slot > 4); // loop execute untill user enter coulm in range
                        }
                        swap_player_turn();  // here call swap_player_marker which swap marker and player on every turn
                        place_marker1(slot); // here call place_marker which replace marker on enter coulm
                        system("cls");       // this system show board once and changing appears in this board
                        display1();          // here disply board after attack
                        if (win1() == false)
                        {              // here check if win1 function is false
                            w = false; // than store false in "w"
                        }
                        else if (win1() == true)
                        {             // else if win1 is true
                            w = true; // than store true in "w"
                        }
                    } while (w != false); // loop execute when "w" is true
                    if (current_player == 1)
                    {
                        ++count; // here count Score of player 1 in easy mode
                    }
                    else
                    {
                        ++count1; // here count score of player2 in easy mode
                    }
                    break;
                }
                case 2:
                {
                    int slot; // here declare slot varibale
                    board2(); // this function call and store "*"
                    cout << "\n"
                         << "                       Welcome to Connnect 4 !            " << "\n"
                         << endl;
                    display2(); // here strting show board on screen
                    cout << endl;
                    player_name(); // here this function call and take name of player
                    if (toss() == false)
                    { // check if toss funtion is false
                        cout << " Enter a Player 1 Mark is:";
                        current_player = 1;   // here store 1 in current player
                        cin >> player_marker; // here take player marker 1
                        cout << " Enter a Player marker 2 is:";
                        cin >> player_marker2;           // here take player marker 2
                        current_marker = player_marker2; // here current_marker store player_marker2
                    }
                    else
                    {
                        cout << " Enter a Player 2 Mark is:";
                        current_player = 2;    // here store 2 in current _plaayer
                        cin >> player_marker2; // here take player 2 marker
                        cout << " Enter a Player marker 1 is:";
                        cin >> player_marker;           // here take player 1 marker
                        current_marker = player_marker; // here current marker is player marker
                    }
                    bool n = true; // here take bool variable
                    do
                    {
                        cout << "Enter the column of player " << current_player << " is:";
                        cin >> slot; // here take coulm
                        if (arr[1][slot] == player_marker || arr[1][slot] == player_marker2)
                        { // check if coulm is fill
                            do
                            {
                                cout << " Row is fill enter again:";
                                cin >> slot; // here take coulm
                            } while (arr[1][slot] != marker); // execute untill you enter a new coulm
                        }
                        if (slot < 1 || slot > 8)
                        { // check for coulm is in range
                            cout << " Please Enter a Coulm between 1 to 8:";
                            do
                            {
                                cin >> slot; // here take coulm
                            } while (slot < 1 || slot > 8); // here execute untill user enter in range
                        }
                        swap_player_turn();  // here this function call and use for swap player and marker on every turn
                        place_marker2(slot); // here place_mark function replace with player_marker
                        system("cls");       // system take change in 1 board not show multiple board
                        display2();          // here disply board agin after replacement with mark
                        if (win2() == false)
                        {              // here check if win2 function is false
                            n = false; // and n become false
                        }
                        else
                        {
                            n = true; // otherwise "n" is true
                        }
                    } while (n != false); // loop execute when n is true
                    if (current_player == 1)
                    {
                        ++count2; // here count score of player1 hard mode
                    }
                    else
                    {
                        ++count3; // here count score of player 2 in hard mode
                    }
                    break;
                }
                default:
                {
                    cout << " Invalid Input" << endl; // if choice is not range than disply this message
                }
                }
                cout << " Enter any character for Playagain and 'n' for not:";
                cin >> alpha; // here take character from user
            } while (alpha != 'n'); // loop execute untill user enter "n"
        }
        else if (ch == 4)
        {           // check if user choice is 4
            exit(); // this function display message
        }
    } while (ch != 4); // execute untill you enter 4 for exit
    cout << " Player 1 " << name1 << " Won Games in Easy mode is:" << count << endl;  // here disply score of easy mode
    cout << " Player 2 " << name2 << " Won Games in Easy mode is:" << count1 << endl; // here disply score of easy mode
    cout << " Player 1 " << name1 << " Won Games in Hard mode is:" << count2 << endl; // here disply score on screen
    cout << " Player 2 " << name2 << " Won Games in Hard mode is:" << count3 << endl; // here disply score on screen
    cout << " Draw games b/w two players in Easy mode is:" << draw_count << endl;     // here dsiplay draw games in easy mode
    cout << " Draw games b/w two players in Hard mode is:" << draw_count2 << endl;    // here display draw games in hard mode
    system("pause");
}
