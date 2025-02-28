#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include "jeepney.h"

using namespace std;

void lightDelay() {
    this_thread::sleep_for(chrono::milliseconds(50));
}

void mediumDelay() {
    this_thread::sleep_for(chrono::seconds(2));
}
void longDelay() {
    this_thread::sleep_for(chrono::seconds(4));
}
void gameTitle() {
    cout << "  _____  ___    ___    ___    _   _  ___    _     _     ___    _        \n";
    lightDelay();
    cout << " (___  )(  _ \\ (  _ \\ (  _ \\ ( ) ( )(  _ \\ ( )   ( )   (  _ \\ (_)/ \\_/ \\ \n";
    lightDelay();
    cout << "     | || (_(_)| (_(_)| |_) )|  \\| || (_(_) \\ \\_/ /    | (_(_)| ||     | \n";
    lightDelay();
    cout << "  _  | ||  _)_ |  _)_ |  __/ |     ||  _)_    \\ /       \\__ \\ | || (_) | \n";
    lightDelay();
    cout << " ( )_| || (_( )| (_( )| |    | | \\ || (_( )   | |      ( )_) || || | | | \n";
    lightDelay();
    cout << "  \\___/ (____/ (____/ (_)    (() (_)(____/    (_)       \\(___)(_)(_) (_) \n";
    lightDelay();
    cout << "                             (_)                        (_)             \n";
}

void Jeepney::trafficCondition() {
    srand(time(0));
    int traffic = rand() % 3 + 1;

    switch (traffic) {
        case 1:
            cout << "               Rush Hour. Significant gas consumption." << endl;
            gas -= 15;
            break;
        case 2:
            cout << "                 Mild Traffic. Moderate gas consumption." << endl;
            gas -= 10;
            break;
        case 3:
            cout << "                 Light Traffic. Minimal gas consumption." << endl;
            gas -= 5;
            break;
    }
}

int passengerMoney() {
    srand(time(0));
    int randomMoney = rand() % 3 + 1;

    switch (randomMoney) {
        case 1:
            return 100;
            break;
        case 2:
            return 200;
            break;
        case 3:
            return 50;
            break;
    }
}

void Jeepney::passengerDestination() {
    srand(time(0));
    int destination = rand() % 2 + 1;
    int correctChange;
    int playerInputChange;
    int passengerMon = passengerMoney();

    switch (destination) {
        case 1:

            cout << endl <<"- P A S S E N G E R: Uhh... I will go to Wanker Town... Is that far..." << endl;
            mediumDelay();
            cout << "- Y O U: I`ll take ye ass to that funny town. Don`t worry. It`ll be Php 50.00."<< endl;
            mediumDelay();
            cout << endl <<"He handed you P" << passengerMon << "." << endl << endl;
            mediumDelay();
            correctChange = passengerMon - 50;

            while(true) {
                cout << "Passenger`s Change: ";
                cin >> playerInputChange;

                if (playerInputChange == correctChange) {
                    cout << endl <<"- P A S S E N G E R: I really miss my hometown... Thank you..." << endl << endl;
                    jeepMoney += 50;
                    longDelay();
                    system("cls");
                    break;
                } else {
                    cout << endl << "- P A S S E N G E R: Uhh.. Mister... I think you are wrong..." << endl << endl;
                }
            }
            break;
        case 2:
            cout << endl <<"- P A S S E N G E R: Take me home. It`s called Country Roads." << endl;
            mediumDelay();
            cout << "- Y O U: I can drive for Php 40.00, old timer."<< endl;
            mediumDelay();
            cout << endl << "He handed you P" << passengerMon << "." << endl << endl;
            mediumDelay();
            correctChange = passengerMon - 40;

            while(true) {
                cout << "Passenger`s Change: ";
                cin >> playerInputChange;

                if (playerInputChange == correctChange) {
                    cout << endl <<"- P A S S E N G E R: Thanks, young blood." << endl << endl;
                    jeepMoney += 40;
                    longDelay();
                    system("cls");
                    break;
                } else {
                    cout << endl << "- P A S S E N G E R: You suck at mathematics don`t ya?" << endl << endl;
                }
            }
            break;
    }
}

void Jeepney::gasStatus() {
    int lowGas = 40;
    if (gas < 0) {
        gas = 0;
    }
    if (gas == 0){
        cout << "( !!!WARNING!!! : You have no gas, you cant drive. You need to gas up.)" << endl;
    } else if (gas <= lowGas) {
        cout << "( !Warning! : You`re low on gas. )" << endl;
    } else {
        cout << "( Gas is fine. )" << endl;
    }
}

void Jeepney::playAgain() {
    string playerChoice;
    while(true) {
        cout << "Wanna play again? y / n : ";
        cin >> playerChoice;
        if (playerChoice == "y" || playerChoice == "Y") {
            jeepMoney = 0;
            gas = 100;
            system("cls");
            main();
            break;
        } else if (playerChoice == "n" || playerChoice == "N"){
            cout << "Maybe next time ! ! !" << endl;
            exit(0);
        } else {
            cout << "Please enter a valid character." << endl;
        }
    }
}

void Jeepney::gameOver() {
    cout << "          ___  ___  __  __  ___         ___  __   __ ___  ___ \n";
    cout << "         / __|/   \\|  \\/  || __|       / _ \\ \\ \\ / /| __|| _ \\\n";
    cout << "        | (_ || - || |\\/| || _|       | (_) | \\   / | _| |   /\n";
    cout << "         \\___||_|_||_|  |_||___|       \\___/   \\_/  |___||_|_\\\n";

    cout << endl << "            (You ran out of gas in the middle of the road.)" << endl;
    cout << "                         You earned: Php " << jeepMoney << endl << endl;
    playAgain();
}
void Jeepney::gastyShone() {

    system("cls");
    cout << "  ___  ___  ___  _____ __   __       ___  _  _   ___   _  _  ___ \n";
    lightDelay();
    cout << " / __|/   \\/ __||_   _|\\ \\ / /      / __|| || | / _ \\ | \\| || __|\n";
    lightDelay();
    cout << "| (_ || - |\\__ \\  | |   \\   /       \\__ \\| __ || (_) || .  || _| \n";
    lightDelay();
    cout << " \\___||_|_||___/  |_|    |_|        |___/|_||_| \\___/ |_|\\_||___|\n";
    lightDelay();

    cout << endl << "You";
    lightDelay();
    cout << " entered ";
    lightDelay();
    cout << "a ";
    lightDelay();
    cout << "Gasoline ";
    lightDelay();
    cout << "Station." << endl << endl;
    lightDelay();

    cout << "- Money: P" << jeepMoney << endl;
    cout << "- Gas: " << gas << "% " << endl << endl;

    cout << "Choose a gas: " << endl;
    cout << "1. Mini Gas Can - Php 25 (adds 15 to your Gas.)" << endl;
    cout << "2. Medium Gas Can - Php 40 (adds 30 to your Gas.)" << endl;
    cout << "3. Large Gas Can - Php 70 (adds 50 to your Gas.)" << endl;
    cout << "4. Return to the road" << endl << endl;
}

void Jeepney::enterGasolineStation() {
    int gasChoice;
    system("cls");

    while(true) {
            gastyShone();

            cout << "- S T A F F : What do you want to buy?: ";
            cin >> gasChoice;

            switch(gasChoice){
                case 1:
                    cout << "- Y O U : Mini ";
                    lightDelay();
                    cout << "Gas ";
                    lightDelay();
                    cout << "Can ";
                    lightDelay();
                    cout << "please." << endl;

                    if (jeepMoney <= 25) {
                        lightDelay();
                        cout << "- S T A F F : You don`t have enough money at the moment." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } else if (gas >= 85) {
                        cout << "- S T A F F : Are you kidding me? You have enough gas." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } else {
                        cout << "- S T A F F : Here`s ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "Item. ( Mini Gas Can )" << endl << endl;
                        mediumDelay();

                            jeepMoney -= 25;
                            gas += 15;

                        cout << "( You ";
                        lightDelay();
                        cout << "filled ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "gas ";
                        lightDelay();
                        cout << "tank )" << endl << endl;
                        mediumDelay();
                        system("cls");
                    }

                    break;
                case 2:

                    cout << "- Y O U : Medium ";
                    lightDelay();
                    cout << "Gas ";
                    lightDelay();
                    cout << "Can ";
                    lightDelay();
                    cout << "please." << endl;

                    if (jeepMoney <= 40) {
                        lightDelay();
                        cout << "- S T A F F : You don`t have enough money at the moment." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } else if (gas >= 70) {
                        cout << "- S T A F F : Are you kidding me? You have enough gas." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } else {
                        cout << "- S T A F F : Here`s ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "Item.( Medium Gas Can )" << endl << endl;
                        mediumDelay();

                            jeepMoney -= 40;
                            gas += 30;

                        cout << "( You ";
                        lightDelay();
                        cout << "filled ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "gas ";
                        lightDelay();
                        cout << "tank )" << endl << endl;
                        mediumDelay();
                        system("cls");
                    }

                    break;
                case 3:

                    cout << "- Y O U : Large ";
                    lightDelay();
                    cout << "Gas ";
                    lightDelay();
                    cout << "Can ";
                    lightDelay();
                    cout << "please." << endl;

                    if (jeepMoney <= 70) {
                        lightDelay();
                        cout << "- S T A F F : You don`t have enough money at the moment." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } if (gas >= 50) {
                        cout << "- S T A F F : Are you kidding me? You have enough gas." << endl;
                        mediumDelay();
                        system("cls");
                        break;
                    } else {
                        cout << "- S T A F F : Here`s ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "Item.( Large Gas Can )" << endl << endl;
                        mediumDelay();

                            jeepMoney -= 70;
                            gas += 50;

                        cout << "( You ";
                        lightDelay();
                        cout << "filled ";
                        lightDelay();
                        cout << "your ";
                        lightDelay();
                        cout << "gas ";
                        lightDelay();
                        cout << "tank )" << endl << endl;
                        mediumDelay();
                        system("cls");
                    }
                    break;

                case 4:
                    cout << endl << "- S T A F F : Okay have a safe ride." << endl;
                    mediumDelay();
                    system("cls");
                    break;
                }
        break;
    }
}



























