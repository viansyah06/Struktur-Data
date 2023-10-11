#include <iostream>
using namespace std;

//deklarasi single linked list
struct Buku
{
    string judul, pengarang;
    int tahunterbit;

    Buku *next;
};

Buku *head, *tail, *cur, *newNode;

void createSingleLinkedList(string judul, string pengarang, int tB)
{
    head = new Buku();
    head->judul = judul; 
    head->pengarang = pengarang;
    head->tahunterbit = tB;
    head->next = NULL;
    tail = head;
}

//tambah di awal single linked list
void addFirst(string judul, string pengarang, int tB)
{
    newNode = new Buku();
    newNode->judul = judul; 
    newNode->pengarang = pengarang;
    newNode->tahunterbit = tB;
    newNode->next = head;
    head = newNode;
}

void printSingleLinkedList()
{
    cur = head; //mulai darimana
    while( cur != NULL )
    {
        cout << "Judul Buku = " << cur->judul << endl;
        cout << "Pengarang Buku = " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku = " << cur->tahunterbit << endl;

        cur = cur->next;
    }
}

int main()
{
    cout << "======BEFORE======\n"; 
    createSingleLinkedList("Harry Potter", "JK Rowling", 1997);
   
    printSingleLinkedList();
    cout << "\n\n";
    
    cout << "======AFTER======\n";
    addFirst("Lord of The Rings", "J.R.R Tolkien", 1936);

    printSingleLinkedList();
    cout << "\n\n";
    
    
    return 0;
}