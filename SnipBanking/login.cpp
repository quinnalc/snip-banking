#include "functionsandclasses.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <stdio.h>
using namespace std;


void Login()
{
    system("clear");
    int logOption;
    bool correct = false;
    cout << "     Snip Banking     \n";
    cout << "\n";
    cout << "     Admin Login\n";
    cout << "\n";
    cout << "1. Login\n";
    cout << "2. SignUp\n";
    cout << "\n";
    cout << "Select Your Option (1-2): ";
    cin >> logOption;

    if(logOption == 1 || logOption == 2){
            correct = true;
        }else{
            correct = false;
        }

    while(correct == false){ 
            if(logOption == 1 || logOption == 2){
            correct = true;
        }else{
            correct = false;
            Login();
        }
    }
        if(logOption == 1 ){
                loginMenu();

            }else if (logOption == 2){ 
                system("clear");
                signup();
            }
    
}
                
bool IsLoggedIn(string username, string password){

    string un, pwd;

    ifstream read("/Users/quinn/Desktop/Programs/cpp/banking/User Data/login_" + username + ".txt"); 
    getline (read, un);
    getline (read, pwd);

    if (un == username && pwd == password){
        return true;
    }else{ 
        return false;
    }
}



int signup(){
    bool passcorrect , logincorrect ;
    string username, fname, lname, password, passAtempt, userAtempt;
    cout << "     Snip Banking     \n";
    cout << "\n";
    cout << "      Sign Up\n";
    cout << "\n";
    cout << "Username: ";
    cin >> username;
    cout << "\n";
    cout << "First Name: ";
    cin >> fname;
    cout << "\n";
    cout << "Last Name: ";
    cin >> lname;
    cout << "\n";
    cout << "Password: ";
    cin >> password;

    system("clear");
    cout << "     Snip Banking     \n";
    cout << "\n";
    cout << "      Sign Up\n";
    cout << "\n";
    cout << "Confirm Password: ";
    cin >> passAtempt;

    if(passAtempt == password){
            passcorrect = true;
            
        }else{ 
            passcorrect = false;
        }

    while(passcorrect == false){ 
        system("clear");
        cout << "     Snip Banking     \n";
        cout << "\n";
        cout << "      You entered the wrong password\n";
        cout << "\n";
        cout << "Confirm Password: ";
        cin >> passAtempt;

        if(passAtempt == password){
            passcorrect = true;
        }else{ 
            passcorrect = false;
        }

    }

    ofstream file;
    file.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/login_" + username + ".txt");

    file << username << endl << password << endl << fname   << " " << lname << endl;

    file.close();

    loginMenu();
    return 0;
}

int userReal(string username){
    ifstream ifile;
    ifile.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/login_" + username + ".txt");
    if(ifile) {   
        ifile.close();
        return 0;
    } else {
        cout<<"\n\n\n\n\n";
        string e;
        cout << "This username does not belong to an account at Snip Banking. \n";
        cout << "Press any key and then the enter button to return to Login/Signup Portal ";
        cin >> e;
        Login();
        return 0;
    }
}

void loginMenu(){
    string userAtempt, passAtempt;
    system("clear");
    cout << "     Snip Banking     \n";
    cout << "\n";
    cout << "      Login \n";
    cout << "\n";
    cout << "Username: ";
    cin >> userAtempt;
    userReal(userAtempt);
    cout << "Password: ";
    cin >> passAtempt;
    
    bool logincorrect = IsLoggedIn(userAtempt, passAtempt);
        
    while(logincorrect == false){
            string un, pwd;
            system("clear");
            ifstream read("/Users/quinn/Desktop/Programs/cpp/banking/User Data/login_" + userAtempt + ".txt"); 
            getline (read, un);
            getline (read, pwd);
            cout << "     Snip Banking     \n";
            cout << "\n";
            cout << "      Login \n";
            cout << "\n";
            cout << "Wrong Username or Password\nHere is a hint for your password: It is " << pwd.length() << " characters long and the beginning 2 characters are " << pwd.substr(0, 2) << endl;
            cout << "\n";
            cout << "\n";
            cout << "Username: ";
            cin >> userAtempt;
            userReal(userAtempt);
            cout << "Password: ";
            cin >> passAtempt;
            logincorrect = IsLoggedIn(userAtempt, passAtempt);
            
    }
    Menu(userAtempt);

}
