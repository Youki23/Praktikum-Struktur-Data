#include <iostream>
#include <string>

using namespace std;

struct Node {
    int absen;
    string nama;
    Node* left;
    Node* right;
    Node(int a, string n) : absen(a), nama(n), left(nullptr), right(nullptr) {}
};

Node* insertNode(Node* root, int absen, string nama) {
    if (!root) {
        return new Node(absen, nama);
    }

    if (absen < root->absen) {
        root->left = insertNode(root->left, absen, nama);
    } else if (absen > root->absen) {
        root->right = insertNode(root->right, absen, nama);
    }

    return root;
}

Node* searchNode(Node* root, int absen) {
    if (!root || root->absen == absen) {
        return root;
    }

    if (absen < root->absen) {
        return searchNode(root->left, absen);
    }

    return searchNode(root->right, absen);
}

void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << "Absen " << root->absen << " Nama " << root->nama << "\n";
    inorderTraversal(root->right);
}

int main() {
    Node* root = nullptr;
    int pilih, absen;
    string nama;

    do {
        cout << "\n=== Manajemen Absen Mahasiswa (BST) ===\n";
        cout << "1. Tambah Mahasiswa (Insert)\n";
        cout << "2. Cari Mahasiswa (Search)\n";
        cout << "3. Tampilkan Daftar Absen Terurut (Inorder)\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            cout << "Masukkan Nomor Absen: ";
            cin >> absen;
            cout << "Masukkan Nama Mahasiswa: ";
            cin >> nama;
            root = insertNode(root, absen, nama);
            cout << "Mahasiswa berhasil ditambahkan\n";
        } else if (pilih == 2) {
            cout << "Masukkan Nomor Absen yang dicari: ";
            cin >> absen;
            Node* result = searchNode(root, absen);
            if (result) {
                cout << "Ditemukan Absen " << result->absen << " Nama " << result->nama << "\n";
            } else {
                cout << "Nomor absen " << absen << " tidak ditemukan\n";
            }
        } else if (pilih == 3) {
            cout << "\n--- Daftar Absen Terurut ---\n";
            inorderTraversal(root);
            if (!root) cout << "Daftar kosong\n";
        }

    } while (pilih != 4);

    return 0;
}