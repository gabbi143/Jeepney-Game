#ifndef JEEPNEY_H_INCLUDED
#define JEEPNEY_H_INCLUDED

using namespace std;

void lightDelay();
void mediumDelay();
void longDelay();

void startGame();
void gameTitle();
int main();


class Jeepney{
    public:
        string driverName;
        string license;
        double jeepMoney;
        int gas;
        int money;

        Jeepney(string dn, string l, double m, int g, int mo) {
            driverName = dn;
            license = l;
            jeepMoney = m;
            gas = g;
        }

        void displayJeepInfo() {
            cout << "Driver`s Name: " << driverName << endl;
            cout << "Drivers License: " << license << endl;
            cout << "Money: P" << jeepMoney << endl;
            cout << "Gas: " << gas << "%" << endl;

        }

        void trafficCondition();
        void passengerDestination();
        void gasStatus();
        void gasChecker();
        void gameOptions();
        void gameOver();
        void playAgain();
        void enterGasolineStation();
        void gastyShone();
        void playGame();

};


class Passenger {
public:
    string name;
    string destination;
    double passengerMoney;

    Passenger(string n, string d, double m) {
        name = n;
        destination = d;
        passengerMoney = m;
    }

    void displayPassengerInfo() {
        cout << "Passenger Info:" << endl;
        cout << "Name: " << name << endl;
        cout << "Destination: " << destination << endl;
        cout << "Money: P" << passengerMoney << endl;
    }
};






































#endif // JEEPNEY_H_INCLUDED

