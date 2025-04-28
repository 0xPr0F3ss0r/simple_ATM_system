// atm.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <cmath>
#include <iostream>
#include <windows.h>
using namespace std;
string password = "";
string name = "";
void process(double *balance);
void Choice(int *choice, double *balance);
int main()
{
    double balance = 10000;
    process(&balance);
    return 0;
}

void showChoices()
{
    cout << "1-....balance...!\n";
    cout << "2-....diposit...!\n";
    cout << "3-....withdraw...!\n";
}
void process(double *balance)
{
    int choice;
    string pass;
    char have_account = 'N';
    cout << "do you have an account Y or N: \n";
    cin >> have_account;
    cout << &have_account;
    if (have_account == 'N')
    {
        cout << "start create account ..\n";
        cout << "type your name: \n";
        cin >> name;
        cout << "type your password: \n";
        cin >> password;
        cout << "You have Been create account successfully \n";
        system("cls");
    }
    string user_name;
    string user_password;
    cout << "enter your name: \n";
    cin >> user_name;
    cout << "enter your password: \n";
    cin >> user_password;
    while (user_password != password)
    {
        char answer = 'k';
        cout << user_name << "your password is incorrect , You want to try [Y] OR [N] \n";
        cin >> answer;
        if (answer == 'N' || answer == 'n')
        {
            return;
        }
        else
        {
            cout << "enter your password: \n";
            cin >> pass;
        }
    }
    if (user_password == password)
    {
        while (choice != 0)
        {
            system("cls");
            showChoices();
            cout << "select one option or 0 if you want to exit:\n";
            cin >> choice;
            Choice(&choice, balance);
        }
    }
}

void Choice(int *choice, double *balance)
{
    int deposit;
    int withdraw;
    int *userChoice = choice;
    if (*userChoice == 1)
    {
        cout << "your balance is " << *balance << endl;
        Sleep(5000);
    }
    else if (*userChoice == 2)
    {
        cout << "enter your amount you want to deposit: \n";
        cin >> deposit;
        *balance += deposit;
        cout << "your balance now is " << *balance << endl;
        Sleep(5000);
    }
    else if (*userChoice == 3)
    {
        cout << "your balance is: " << *balance << endl;
        cout << "enter your amount you want to withdraw: \n";
        cin >> withdraw;
        while (withdraw > *balance)
        {
            char answer;
            cout << "you can't withdraw this amount , please try again ..![Y] or [N]: \n";
            cin >> answer;
            if (answer == 'N' || answer == 'n')
            {
                return;
            }
            else
            {
                cout << "enter your amount you want to withdraw: \n";
                cin >> withdraw;
            }
        }
        *balance -= withdraw;
        cout << "your balance now is " << *balance << endl;
        Sleep(5000);
    }
    else if (*userChoice == 0)
    {
        system("cls");
        system("exit");
    }
    else
    {
        cout << "invalid command ..!\n";
        Sleep(5000);
    }
}