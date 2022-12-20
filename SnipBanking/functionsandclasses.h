#include <string>
#include <fstream> 
using std::string;

int signup();
int Menu(string username);
void Login();
bool IsLoggedIn();
void loginMenu();
void pincheck(string apin, string pin, string aname, string accnum);
void accNA(string username);
void nAccount(string username, string name);
void deposit(string username, string name);
void withDraw(string username, string name);
void balance(string username, string name);
void transfer(string username, string name);