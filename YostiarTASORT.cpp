#include <iostream>
using namespace std;
// Yostiar Aminudin 2415061016 (Calon Menteri Pendidikan Indonesia)
struct Pemain {
    string nama;
    int skor;
};

void bubbleSort(Pemain arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].skor < arr[j+1].skor) {
                // Tukar posisi
                Pemain temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Masukkan jumlah pemain: ";
    cin >> n;

    Pemain arr[n];

    // Input data pemain
    for (int i = 0; i < n; i++) {
        cout << "Nama pemain ke-" << i+1 << ": ";
          cin >> arr[i].nama;
        cout << "Skor: ";
        cin >> arr[i].skor;
    }

    // Sorting dengan Bubble Sort
    bubbleSort(arr, n);

    // Tampilkan hasil ranking
    cout << "\n=== Leaderboard Conflict x Crisis  ===\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << arr[i].nama << " - " << arr[i].skor << endl;
    }

    return 0;
}
