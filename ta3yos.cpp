#include <iostream>
#include <string>

using namespace std;

int sequentialSearch(string arr[], int size, const string& target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1; // Nama tidak ditemukan
}

int main() {
    const int size = 6;
    string daftarMahasiswa[size] = {
        "Yostiar",
        "Bintang",
        "Arqan",
        "Made",
        "Faqih",
        "Kadek"
    };

    string namaCari;
    
    cout << "Daftar Mahasiswa:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ". " << daftarMahasiswa[i] << endl;
    }

    cout << "Masukkan nama mahasiswa yang ingin dicari: ";
    getline(cin, namaCari);

    int hasilIndeks = sequentialSearch(daftarMahasiswa, size, namaCari);

    if (hasilIndeks != -1) {
        cout << "\nNAMA DITEMUKAN!" << endl;
        cout << "Nama '" << namaCari << "' berada pada indeks ke-" << hasilIndeks << "." << endl;
    } else {
        cout << "\nNAMA TIDAK DITEMUKAN." << endl;
    }

    return 0;
}

