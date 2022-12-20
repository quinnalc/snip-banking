#include "functionsandclasses.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <ctime>
using namespace std;


int Menu(string username){
    system("clear");
    string un, pwd,fname, lname, name;

    ifstream read("/Users/quinn/Desktop/Programs/cpp/banking/User Data/login_" + username + ".txt"); 
    getline (read, un);
    getline (read, pwd);
    getline (read, fname);
    getline (read, lname);
    name = fname + " " + lname;


    int option;
    cout << "     Welcome to Snip Banking "<< name << "\n";
    cout << "\n";
    cout << "           Main Menu\n";
    cout << "\n";
    cout << "1. New Account\n";
    cout << "2. Deposit Amount\n";
    cout << "3. Withdraw Amount\n";
    cout << "4. Balance Enquiry\n";
    cout << "5. Transfer\n";
    cout << "6. Log Out\n";
    cout << "\n";
    cout << "Enter Your Option (1-6): ";
    cin >> option;

    if(option == 1){
        nAccount(un, name);
    } else if(option == 2){ 
        deposit(un, name);
    } else if(option == 3){ 
        withDraw(un, name);
    } else if(option == 4){
        balance(un, name);
    }
    else if (option == 5){ 
        transfer(un, name);
    }else if (option == 6){
        Login();
    }

    return 0;
}

void nAccount(string username, string aname){
    system("clear");
    bool create;
    int select, iaccNum;
    double balance = 0.00;
    string fname, lname, acctype, accNum, e, pin, name;
    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Wizard\n";
    cout << "\n";
    cout << "Customer First Name: ";
    cin >> fname;
    cout << "Customer Last Name: ";
    cin >> lname;
    cout << "4 digit PIN: ";
    cin >> pin;
    cout << "Account Type: "<< endl;
    cout << "1. Savings"<< endl;
    cout << "2. Checkings" << endl;
    cout << "Select an Option (1-2): ";
    cin >> select;
    bool selections;
    if(select == 1 || select == 2){
        selections = true;
    }else{ 
        selections = false;
    }

    while(selections == false){ 
        cout << "     Welcome to Snip Banking "<< aname << "\n";
        cout << "\n";
        cout << "           Account Wizard\n";
        cout << "\n";
        cout << "Account Type: " << endl;
        cout << "1. Savings" << endl;
        cout << "2. Checkings" << endl;
        cout << "Select an Option (1-2): ";
        cin >> select;
        bool selections;
        if(select == 1 || select == 2){
            selections = true;
        }else{ 
            selections = false;
        }
    }

    if(select == 1){ 
        acctype = "Savings";
    }else if(select == 2){ 
        acctype = "Checkings";
    }

    cout << "To create a " << acctype <<" Account for " << fname << " " << lname << ", enter 1 for yes or 2 for no: ";
    cin >> select;

    

    if(select == 1){
        srand( time(NULL) );
        iaccNum = rand() % 10000;
        if (iaccNum < 1000){
            iaccNum += 1000;
        }else if(iaccNum > 9999){
            iaccNum -= 1000;
        }
        accNum = to_string(iaccNum);

        ofstream file;
        file.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt");

        file << accNum << endl << balance << endl << pin << endl << acctype << endl << fname   << endl << lname << endl;

        file.close();
        create = true;
        cout << "Account Created\n\n";
        cout << "The Account Number is: " << accNum << endl;
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);
        
    }else if (select == 2){
        create = false;
        
        cout << "\n\n";
        cout << "Account Wizard Closed\n\n";
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);
    }

}

void deposit(string username, string aname){
    system("clear");
    int select;
    double balance, newbal, depositamt;
    string name, fname, lname, acctype, accNum, reason, e, pin;

    cout << "     Welcome to Snip Banking "<< aname<< "\n";
    cout << "\n";
    cout << "        Account Deposit\n";
    cout << "\n";
    cout << "Enter Account Number of Recieving Account: ";
    cin >> accNum;
    system("clear");
    ifstream file_("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt"); 
    
    if(file_.is_open()){
        file_ >> accNum >> balance >> pin >> acctype >> fname >> lname;
        file_.close();
        name = fname + " " + lname;
    }else{ 
        accNA(username);
    }




    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Deposit\n";
    cout << "\n";
    cout << "     " << name << "'s Account\n";
    cout << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "\n";
    cout << "Account Type: " << acctype << endl;
    cout << "\n";
    cout << "Reason for Depositing Money: "; 
    cin >> reason;
    cout << "\nDesposit Amount: "; 
    cin >> depositamt;

    cout << "Confirm Deposit of  $" << depositamt << " for " << reason << " enter 1 for yes or 0 for no: ";
    cin >> select;

    if(select == 1){
        newbal = balance + depositamt;
        ofstream file2;
        file2.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt");
        file2 << accNum << endl << fixed << setprecision(2) << newbal << endl << pin << endl << acctype << endl << fname << endl << lname << endl;
        file2.close();

        ofstream file3;
        file3.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_deposit_"+ accNum + ".txt");
        file3 << fixed << setprecision(2) << depositamt << endl << reason << endl;
        file3.close();

        cout << "\n\nDeposit Successfull\n\n";
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);

        
    }else if (select == 0){
        
        cout << "\n\n";
        cout << "Account Deposit Closed\n\n";
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);
    }



}

void withDraw(string username, string aname){
     system("clear");
    int select;
    double balance, newbal, withdrawal;
    string name, fname, lname, acctype, accNum, e, pin, apin;

    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Withdrawal\n";
    cout << "\n";
    cout << "Enter Account Number: ";
    cin >> accNum;
    ifstream file_("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt"); 
    
    if(file_.is_open()){
        file_ >> accNum >> balance >> pin >> acctype >> fname >>lname;
        file_.close();
        name = fname + " " + lname;
    }else{ 
        accNA(username);
    }

    cout << "Enter PIN: ";
    cin >> apin;

    pincheck(apin, pin, aname, accNum);
    
    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Withdrawal\n";
    cout << "\n";
    cout << "     " << name << "'s Account\n";
    cout << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "\n";
    cout << "Account Type: " << acctype << endl;
    cout << "\n";
    cout << "Withdrawal Amount: "; 
    cin >> withdrawal;
    bool overdraft;
    if(withdrawal > balance){ 
            withdrawal = 0;
            cout << endl;
            cout << "\n\nError: You are overdrafting your account!\n\n" << endl;
            cout << endl;
            cout << "Press any key and then the enter button to redo ";
            cin >> e;
            overdraft = true;
        }else {
            overdraft = false;
        }
    
    while (overdraft == true){ 
        system("clear");

    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Withdrawal\n";
    cout << "\n";
    cout << "     " << name << "'s Account\n";
    cout << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "\n";
    cout << "Account Type: " << acctype << endl;
    cout << "\n";
    cout << "Withdrawal Amount: "; 
    cin >> withdrawal;
    if(withdrawal > balance){ 
            withdrawal = 0;
            cout << endl;
            cout << "\n\nError: You are overdrafting your account!\n\n" << endl;
            cout << endl;
            cout << "Press any key and then the enter button to redo ";
            cin >> e;
            overdraft = true;
        }else if(withdrawal <= balance){
            overdraft = false;
        }
    }

    cout << "Confirm Withdrawal of  $" << fixed << setprecision(2) << withdrawal << " enter 1 for yes or 0 for no: ";
    cin >> select;

    if(select == 1){
        newbal = balance - withdrawal;
        ofstream file2;
        file2.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt");
        file2 << accNum << endl << fixed << setprecision(2) << newbal << endl << pin << endl << acctype << endl << fname << endl << lname << endl;
        file2.close();

        ofstream file3;
        file3.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_withdrawal_"+ accNum + ".txt");
        file3 << fixed << setprecision(2) << withdrawal << endl;
        file3.close();

        cout << "\n\nWithdrawal Successfull\n\n";
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);

        
    }else if (select == 0){
        
        cout << "\n\n";
        cout << "Account Withdrawal Closed\n\n";
        cout << "Press any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);
    }

}

void balance(string username, string aname){
    system("clear");
    int select;
    bool locked = true;
    double balance, newbal, withdrawal, deposit;
    string name, fname, lname, acctype, accNum, e, pin, apin;

    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Balance Inquiry\n";
    cout << "\n";
    cout << "Enter Account Number: ";
    cin >> accNum;
    ifstream file_("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt"); 
    
    if(file_.is_open()){
        file_ >> accNum >> balance >> pin >> acctype >> fname >> lname;
        file_.close();
        name = fname + " " + lname;
    }else{ 
        accNA(username);
    }

    cout << "Enter PIN: ";
    cin >> apin;

    pincheck(apin, pin, aname, accNum);
    

    ifstream file1("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_deposit_" + accNum + ".txt"); 
    
    if(file1.is_open()){
        file1 >> deposit;
        file1.close();
    }else{ 
        deposit = 0.00;
    }

    ifstream file2("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_withdrawal_" + accNum + ".txt"); 
    
    if(file2.is_open()){
        file2 >> withdrawal;
        file2.close();
    }else{ 
        withdrawal = 0.00;
    }

    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "           Account Balance Inquiry\n";
    cout << "\n";
    cout << "     " << name << "'s Account\n";
    cout << "\n";
    cout << "Most Recent Deposit: $"<< fixed << setprecision(2) << deposit << endl;
    cout << "\n";
    cout << "Most Recent Withdrawal: $"<< fixed << setprecision(2) << withdrawal << endl;
    cout << "\n";
    cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    cout << "\n\n";
    
    cout << "Press any key and then the enter button to return to Menu ";
    cin >> e;
    Menu(username);

}

void transfer(string username, string aname){
    system("clear");
    bool locked;
    int select;
    double balance, transferAMT, rBal;
    string name, fname, lname, acctype, accNum, e, pin, apin, rAccNum, rpin, pAcctype, rfname, rlname;
    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "        Transfer Wizard\n";
    cout << "\n";
    cout << "Enter Sending Account Number: ";
    cin >> accNum;
    ifstream file_("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt"); 
    
    if(file_.is_open()){
        file_ >> accNum >> balance >> pin >> acctype >> fname >> lname;
        file_.close();
        name = fname + " " + lname;
    }else{ 
        accNA(username);
    }

    cout << "\nEnter Recieving Account Number: ";
    cin >> rAccNum;

    ifstream file0("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + rAccNum + ".txt"); 
    
    if(file0.is_open()){
        file0 >> rAccNum >> rBal >> rpin >> pAcctype >> rfname >> rlname;
        file0.close();
    }else{ 
        accNA(username);
    }

    
    cout << "Enter PIN of Sending Account: ";
    cin >> apin;
    
    pincheck(apin, pin, aname, accNum);

    cout << "     Welcome to Snip Banking "<< aname << "\n";
    cout << "\n";
    cout << "        Transfer Wizard\n";
    cout << "\n";
    cout << "Transfer Amount: ";
    cin >> transferAMT;
    cout << "\n";
    
    bool transfer;
    
    if(transferAMT > balance){
        transfer = false;
        while(transfer == false){ 
            system("clear");
            cout << "     Welcome to Snip Banking "<< aname << "\n";
            cout << "\n";
            cout << "             Transfer Wizard\n";
            cout << "  Please Enter an Amount within Your Reach\n";
            cout << "Transfer Amount: ";
            cin >> transferAMT;
            if(transferAMT > balance){
                transfer = false;
            }else{ 
                transfer = true;
            }
        }
    }else{ 
        transfer = true;
    }

    cout << "To Confirm Transfer, Please enter 1 or 0 to return to exit";
    cin >> select;

    if (select == 1){ 
        
        balance -= transferAMT;
        rBal += transferAMT;

        time_t tt;
        struct tm * ti;
        time(&tt);
        ti =localtime(&tt);
    
        ofstream file2;
        file2.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_" + accNum + ".txt");
        file2 << accNum << endl << fixed << setprecision(2) << balance << endl << pin << endl << acctype << endl << fname << endl << lname << endl;
        file2.close();

        ofstream file3;
        file3.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_client_"+ rAccNum + ".txt");
        file3 << rAccNum << endl << fixed << setprecision(2) << rBal << endl << rpin << endl << pAcctype << endl << rfname << endl << rlname << endl;
        file3.close();

        ofstream file4;
        file4.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_notification_"+ rAccNum + ".txt");
        file4 << asctime(ti) << ": Recieved $" << fixed << setprecision(2) << transferAMT << " from " << accNum << endl; 
        file4.close();
        
        ofstream file5;
        file5.open("/Users/quinn/Desktop/Programs/cpp/banking/User Data/account_" + username + "_notification_"+ accNum + ".txt");
        file5 << asctime(ti) <<": Sent $" << fixed << setprecision(2) << transferAMT << " to " << rAccNum << endl; 
        file5.close();

        cout << "\nTransfer to " << rAccNum << " Completed\n";
        cout << "\nPress any key and then the enter button to return to Menu ";
        cin >> e;
        Menu(username);
        
    }else{ 
        Menu(username);
    }

}
