#include "functionsandclasses.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <ctime>
using namespace std;

void pincheck(string apin, string pin, string aname, string accNum){
    bool locked;
    if(apin == pin){
            locked = false;
        }else{ 
            locked = true;
        }
    

   while(locked == true){ 
        system("clear");
        cout << "     Welcome to Snip Banking "<< aname << "\n";
        cout << "\n";
        cout << "           Account Balance Inquiry\n";
        cout << "\n\n";
        cout << "              Wrong PIN" <<endl;
        cout << "Enter Account Number: " + accNum << endl;
        cout << "Enter PIN: ";
        cin >> apin;

        if(apin == pin){
            locked = false;
        }
    }

    system("clear");
}

void accNA(string username){
    string e;
    cout << "\n\nError: Account not found :( \n\n" << endl;
    cout << "Press any key and then the enter button to return to Menu ";
    cin >> e;
    Menu(username);
}