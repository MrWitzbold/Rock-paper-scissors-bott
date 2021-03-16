#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int user_move;
int previous_user_move;
int bot_move;
int wins = 0;
int losses = 0;

bool playing = true;
bool played_once = false;
string struser_move = "";
string strbot_move = "";
int random(int min, int max)
{
    srand(time(0));
    return rand() % (max - min) + min; 
}
int main()
{
    while(playing == true)
    {
        cout << "Type rock, paper or scissors: ";
        cin >> struser_move;
        if (struser_move == "rock") 
        {
            user_move = 1;
        }
        if (struser_move == "paper") 
        {
            user_move = 2;
        }
        if (struser_move == "scissors") 
        {
            user_move = 3;
        }
        if (played_once == false)
        {
            bot_move = random(1, 3);
        }
        if (played_once == true) 
        {
            if (random(1, 4) == 2) 
            {
                bot_move = random(1, 3);
            }
            else 
            {
                switch(previous_user_move) 
                {
                    case 1: 
                    {
                        bot_move = 2;
                        break;
                    }
                    case 2:
                    {
                        bot_move = 3;
                        break;
                    }
                    case 3:
                    {
                        bot_move = 1;
                        break;
                    }
                }
            }
        }
        previous_user_move = user_move;
        switch(bot_move) 
        {
            case 1: 
            {
                strbot_move = "Rock";
                break;
            }
            case 2: 
            {
                strbot_move = "Paper";
                break;
            }
            case 3: 
            {
                strbot_move = "Scissors";
                break;
            }
        }
        cout << "\nBot: " << strbot_move << "\n";
        cout << "===========================================================\n";
        if (bot_move == user_move) 
        {
            cout << "TIE\n";
            cout << "Game is at: " << wins << "/" << losses << "\n";
        }
        else 
        {
            // Wins
            if ((bot_move == 1) && (user_move == 2))
            {
                cout << "YOU WIN\n";
                wins += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            if ((bot_move == 2) && (user_move == 3))
            {
                cout << "YOU WIN\n";
                wins += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            if ((bot_move == 3) && (user_move == 1))
            {
                cout << "YOU WIN\n";
                wins += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            // Losses
            if ((bot_move == 1) && (user_move != 2))
            {
                cout << "You lost >: (\n";
                losses += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            if ((bot_move == 2) && (user_move != 3))
            {
                cout << "You lost >: (\n";
                losses += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            if ((bot_move == 3) && (user_move != 1))
            {
                cout << "You lost >: (\n";
                losses += 1;
                cout << "Game is at: " << wins << "/" << losses << "\n";
            }
            cout << "===========================================================\n";
        }
    }
}
