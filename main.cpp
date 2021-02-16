#include <iostream>

using namespace std;

int DoubleLossBet(int &flipCount, int &balance, const int &startingBet);
int DoubleLossBetHelper(int currentBet, int &flipCount, int &balance, const int &startingBet, int headCount, int tailCount, int largestBet);

int main() {
    int balance;
    int startingGold;
    int flipCount;
    int algo;

    cout << "Enter starting balance: ";
    cin >> balance;

    cout << "Enter bet incriment: ";
    cin >> startingGold;

    cout << "Enter amount of coin flips: ";
    cin >> flipCount;

    cout << "Select algorithm: ";
    cin >> algo;

    switch (algo) {
        case 0:
        cout << DoubleLossBet(flipCount, balance, startingGold) << endl;
        break;
    }
}



//------------------Functions------------------



int DoubleLossBet(int &flipCount, int &balance, const int &startingBet){
    return DoubleLossBetHelper(startingBet, flipCount, balance, startingBet, 0, 0, 0);
}

int DoubleLossBetHelper(int currentBet, int &flipCount, int &balance, const int &startingBet, int headCount, int tailCount, int largestBet){
    if(flipCount == 0 || balance < 1){ // Need to compensate better for negative or 0 balance.
        int temp = largestBet;
        int lossStreakCount = 0;
        while(temp != startingBet){
            temp = temp / 2;
            ++lossStreakCount;
        }

        cout << "H:" << headCount << " T:" << tailCount << endl
             << "Largest bet was: " << largestBet << endl
             << "Longest loss streak: " << lossStreakCount << endl
             << "You're final balance is: ";
        return balance;
    }else{
        int coin = rand()%2; // Flips coin.
        flipCount--;

        if(coin == 0){ // Gain
            balance += currentBet;
            cout << flipCount + 1 << ": Heads. You won $" << currentBet << ", your balance is " << balance << "." << endl;
            currentBet = startingBet;
            ++headCount;
        }else{ // Loss.
            balance -= currentBet;
            cout << flipCount + 1 << ": Tails. You lost $" << currentBet << ", your balance is " << balance << "." << endl;
            currentBet = currentBet * 2;
            ++tailCount;
        }

        if(currentBet > largestBet)
            largestBet = currentBet;

        return DoubleLossBetHelper(currentBet, flipCount, balance, startingBet, headCount, tailCount, largestBet);
    }
}
