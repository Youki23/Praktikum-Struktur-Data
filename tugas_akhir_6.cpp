#include <iostream>
using namespace std;

const int SIZE = 10;

struct Node {
    string nama;
    Node* next;
};

int hashFunction(string key) {
    int totalAscii = 0;
    for (int i = 0; i < key.length(); i++) {
        totalAscii += key[i];
    }
    return (totalAscii % SIZE + SIZE) % SIZE;
}

void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

void insert(Node* table[], string nama) {
    int index = hashFunction(nama);
    Node* current = table[index];
    while (current != nullptr) {
        if (current->nama == nama) {
            cout << "Info: Nama '" << nama << "' sudah ada di tabel.\n";
            return;
        }
        current = current->next;
    }
    
    Node* baru = new Node;
    baru->nama = nama;

    baru->next = table[index];
    table[index] = baru;
}

void display(Node* table[]) {
    cout << "\n--- Isi Hash Map Mahasiswa (Separate Chaining) ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Index " << i << ": ";
        
        Node* temp = table[i];
        
        if (temp == nullptr) {
            cout << "[ KOSONG ]";
        }

        while (temp != nullptr) {
            cout << temp->nama;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << "\n";
    }
    cout << "--------------------------------------------------\n";
}

int main() {
    Node* table[SIZE];
    initTable(table);

    cout << "Memasukkan data mahasiswa...\n";

    insert(table, "Andi");
    insert(table, "Budi");
    insert(table, "Cinta");
    insert(table, "Dina");
    insert(table, "Elisa");
    insert(table, "Fajar");
    insert(table, "Gita");
    insert(table, "Sinta");
    insert(table, "Rudi");

    display(table);

    insert(table, "Andi");

    return 0;
}