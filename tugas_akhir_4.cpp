#include <iostream>
using namespace std;

const int MAX_SIZE = 5; // Ukuran maksimum stack
int arr[MAX_SIZE];      // Array sebagai penyimpan data
int top = -1;           // Penanda posisi teratas, -1 berarti kosong

void push(int data);
void pop();
void peek();
void display();
bool isEmpty();

int main() {
    int pilihan, nilai;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Tambah nilai mahasiswa" << endl;
        cout << "2. Hapus nilai yang terakhir masuk" << endl;
        cout << "3. Lihat nilai yang terakhir masuk" << endl;
        cout << "4. Tampilkan semua nilai" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai mahasiswa : ";
                cin >> nilai;
                push(nilai);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);

    return 0;
}


// Fungsi untuk memeriksa apakah stack kosong
bool isEmpty() {
    return (top < 0);
}

// Fungsi untuk menambahkan elemen (push)
void push(int data) {
    if (top >= MAX_SIZE - 1) {
        cout << "Gagal. Stack nilai penuh (Overflow)." << endl;
        return;
    }
    // Naikkan top, lalu masukkan data
    arr[++top] = data; 
    cout << data << " berhasil ditambahkan." << endl;
}

// Fungsi untuk menghapus elemen (pop)
void pop() {
    if (isEmpty()) {
        cout << "Gagal. Stack nilai kosong (Underflow)." << endl;
        return;
    }
    // Turunkan top setelah menampilkan elemen yang dihapus
    cout << arr[top--] << " berhasil dihapus." << endl; 
}

// Fungsi untuk melihat elemen teratas (peek)
void peek() {
    if (isEmpty()) {
        cout << "Stack nilai kosong." << endl;
    } else {
        cout << "Nilai terakhir yang masuk: " << arr[top] << endl;
    }
}

// Fungsi untuk menampilkan semua elemen
void display() {
    if (isEmpty()) {
        cout << "Stack nilai kosong." << endl;
        return;
    }
    cout << "--- Isi Stack Nilai Mahasiswa ---" << endl;
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << endl;
    }
    cout << "-----------------" << endl;
}