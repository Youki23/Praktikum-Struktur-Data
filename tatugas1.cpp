#include <iostream>
#include <vector>
// Yostiar Aminudin PSTI-D Calon Fullstack Web
// Menggunakan namespace std agar tidak perlu menulis std::
using namespace std;

int main() {
    // =======================================================
    // Percobaan 1: DATA STATIS (Array)
    // =======================================================
    cout << "## Percobaan Data Statis (Array) ##" << endl;

    // Ukuran array tetap 5 dan tidak bisa diubah.
    const int UKURAN_STATIS = 5;
    int staticArray[UKURAN_STATIS];

    cout << "Array statis dibuat dengan ukuran tetap: " << UKURAN_STATIS << endl;

    // Mengisi dan menampilkan array
    cout << "Isi Array Statis: ";
    for (int i = 0; i < UKURAN_STATIS; ++i) {
        staticArray[i] = (i + 1) * 10; // Mengisi 10, 20, 30, 40, 50
        cout << staticArray[i] << " ";
    }
    cout << "\n\n";


    // =======================================================
    // Percobaan 2: DATA DINAMIS (Vector)
    // =======================================================
    cout << "## Percobaan Data Dinamis (Vector) ##" << endl;

    // Vector dibuat dengan ukuran awal 0.
    vector<int> dynamicVector;
    cout << "Vector dinamis dibuat. Ukuran awal: " << dynamicVector.size() << endl;

    // Menambah 3 elemen. Ukuran vector akan bertambah.
    cout << "Menambahkan 3 elemen..." << endl;
    dynamicVector.push_back(11);
    dynamicVector.push_back(22);
    dynamicVector.push_back(33);

    cout << "Isi Vector Dinamis: ";
    for (int value : dynamicVector) {
        cout << value << " ";
    }
    cout << "\nUkuran sekarang: " << dynamicVector.size() << endl;

    // Menghapus elemen terakhir. Ukuran vector akan berkurang.
    cout << "\nMenghapus 1 elemen terakhir..." << endl;
    dynamicVector.pop_back();

    cout << "Isi Vector Dinamis: ";
    for (int value : dynamicVector) {
        cout << value << " ";
    }
    cout << "\nUkuran akhir: " << dynamicVector.size() << endl;

    return 0;
}