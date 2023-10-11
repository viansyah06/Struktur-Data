#include <iostream>
#include <map>

using namespace std;

map<string, string> dataAkun;

// Hash Function
int hashFunction(const string& password)
{
  int hash = 0;
  for (char c : password) {
    hash += int(c);
  }
  return hash % 100; // Gunakan modulo agar hasilnya dalam rentang tertentu
}

void registerAkun()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  dataAkun[hash_key] = username;
}

void loginAkun()
{
  string username, password;
  cout << "Masukkan Username: " << endl;
  cin >> username;
  cout << "Masukkan Password: " << endl;
  cin >> password;

  string hash_key = to_string(hashFunction(password));

  cout << endl;
  if (dataAkun.find(hash_key) != dataAkun.end() && dataAkun[hash_key] == username)
  {
    cout << "Login berhasil!" << endl << endl;
    cout << "Selamat datang " << dataAkun[hash_key] << "!!" << endl;
  }
  else
  {
    cout << "Login gagal!" << endl << endl;
  }
}

void printAkun()
{
  cout << endl;
  for (auto i = dataAkun.begin(); i != dataAkun.end(); i++)
  {
    cout << "Key: " << i->first << "\t"
         << " Username: " << i->second << endl;
  }
}

// Menu
void menu()
{
  while (true)
  {
    int input_user;

    cout << endl;
    cout << "==== MENU ====" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << "3. Exit" << endl;

    cout << endl;
    cout << "Pilih Menu: " << endl;
    cin >> input_user;

    if (input_user == 1)
    {
      registerAkun();
    }
    else if (input_user == 2)
    {
      loginAkun();
    }
    else if (input_user == 3)
    {
      printAkun();
      break;
    }
    else
    {
      cout << "Invalid!" << endl;
    }
  }
}

int main()
{
  menu();
}
