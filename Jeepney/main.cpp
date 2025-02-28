#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "jeepney.h"

using namespace std;

void startGame();
void playGame(Jeepney& jeepney1);

int main() {
    startGame();
    return 0;
}

void startGame() {
    string playerChoice;

    Jeepney jeepney1("Gabbi", "DXY-789", 400, 30, 0);

    while(true) {
        system("cls");
        cout << "Do you want to play the Jeepney Simulator Game? y / n : ";
        getline(cin, playerChoice);

        if (playerChoice == "y" || playerChoice == "Y") {
            break;
        } else if (playerChoice == "n" || playerChoice == "N"){
            cout << "Maybe next time ! ! !" << endl;
            return;
        } else {
            cout << "Please enter a valid character." << endl;
        }
    }
    cout << endl;

    system("cls");
    gameTitle();

    playGame(jeepney1);
}

void playGame(Jeepney& jeepney1) {

    string playerChoice;
    int numChoice;

    while(true) {
        cout << "- Money: P" << jeepney1.jeepMoney << endl;
        cout << "- Gas: " << jeepney1.gas << "%" << endl << endl;
        cout << "Drive? y / n : ";
        getline(cin, playerChoice);

        if (playerChoice == "y" || playerChoice == "Y") {
            break;
        } else if (playerChoice == "n" || playerChoice == "N"){
            cout << "Maybe next time ! ! !" << endl;
            return;
        } else {
            cout << endl << "Please enter a valid character." << endl << endl;
        }
    }

    system("cls");

    while(true) {
        gameTitle();
        jeepney1.trafficCondition();

        if (jeepney1.gas <= 0) {
            jeepney1.gameOver();
            return;
        }

        cout << endl << "- Gas: " << jeepney1.gas << "% ";
        jeepney1.gasStatus();
        cout << "- Money: P" << jeepney1.jeepMoney << endl;

        cout << "1. Pick up passenger" << endl;
        cout << "2. Go to a gas station" << endl << endl;
        cout << "Your choice: ";
        cin >> numChoice;

        switch(numChoice) {
            case 1:
                jeepney1.passengerDestination();
                break;
            case 2:
                jeepney1.enterGasolineStation();
                break;
            default:
                cout << endl << "Enter a valid Number." << endl << endl;
                mediumDelay();
                system("cls");
                break;
        }

        if (jeepney1.gas <= 0) {
            jeepney1.gameOver();
            return;
        }
    }
}
