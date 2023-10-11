#include <iostream>
using namespace std;

const int SIZE_ARR = 26;

struct Hashtable
{
    string username, password;
} dataAkun[SIZE_ARR];

//function hash
int HashFunction(string password){
    return tolower(password[0]) - 97;
}

//function print all hash table
void printAll()
{
    for(int i; i<SIZE_ARR; i++){
        cout << i << "[" dataAkun[i].username << " - " << dataAkun[i].password << " ]" << endl;
    }
}

void Menu()
{
    while (true){
        int input_user;
        cout << "========MENU========";
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl << endl;
        cin >> input_user;

        if (input_user == 1)
        {
            string username, password;
            cout << "Masukkan Username: ";
            cin >> username;
            cout << "Masukkan Password: ";
            cin >> password;

            int index = HashFunction(password);
            dataAkun[index].username = username;
            dataAkun[index].password = password;
         }
        else if (input_user == 2)
        {
            cout << "Menu Login\n";
        }
        else if (input_user == 3)
        {
            printAll();
            break;
        }
        else 
        {
            cout << "ERROR!! Invalid Input";
        }
    }
}

int main()
{
    string password = "Vian";
    cout << HashFunction(password) << endl;
}