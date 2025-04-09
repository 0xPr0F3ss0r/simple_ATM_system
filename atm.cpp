// atm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <iostream>
using namespace std;
string password= "pass";
void process(double *balance);
void Choice(int *choice,double *balance);
int main()
{    
    double balance = 10000;
    process(&balance);
    return 0;
}   


void showChoices() {
     cout << "1-....balance...!\n";
     cout << "2-....diposit...!\n";
     cout << "3-....withdraw...!\n";
}
void process(double *balance) {
    int choice;
    string pass;
    cout << "enter your password: \n";
    cin >> pass;
    while (pass != password) {
        char answer='k';
        cout << "password is incorrect , You want to try [Y] OR [N] \n";
        cin >> answer;
        if (answer == 'N' or answer == 'n') {
            return;
        }
        else {
            cout << "enter your password: \n";
            cin >> pass;
        }
    }
    if (pass == password) {
        showChoices();
        cout << "select one option :\n";
        cin >> choice;
        while (choice == NULL) {
            cout << "select one option :\n";
            cin >> choice;
        }
        Choice(&choice,balance);
    }
}

void Choice(int *choice,double *balance) {
    //int* balance = balance;
    int deposit;
    int withdraw;
    int* userChoice = choice;
   /* cout << "start choice  function " << *userChoice << endl;*/
    if (*userChoice == 1) {
        cout << "your balance is " << *balance << endl;
        showChoices();
    }
    else if (*userChoice == 2) {
        cout << "enter your amount you want to deposit: \n";
        cin >> deposit;
        *balance += deposit;
        cout << "your balance now is " << *balance << endl;
    }
    else if (*userChoice == 3) {
        cout << "your balance is: " << *balance << endl;
        cout << "enter your amount you want to withdraw: \n";
        cin >> withdraw;
        while (withdraw > *balance) {
            char answer;
            cout << "you can't withdraw this amount , please try again ..![Y] or [N]: \n";
            cin >> answer;
            if (answer == 'N' or answer == 'n') {
                return;
            }
            else{
                cout << "enter your amount you want to withdraw: \n";
                cin >> withdraw;
            }
        }
        *balance -= withdraw;
        cout << "your balance now is " << *balance << endl;
    }
    else {
        cout << "invalid command ..!\n";
    }
}