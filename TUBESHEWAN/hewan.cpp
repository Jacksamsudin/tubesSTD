#include "hewan.h"
#include <iostream>

using namespace std;
    // ========== PRIMITIF DASAR ==========
void createTree(address &root) {
    root = nullptr;
}

address alokasi(Hewan data) {
    address P = new NodeHewan;
    P->info = data;
    P->left = nullptr;
    P->right = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

bool isEmpty(address root) {
    return root == nullptr;
}
    // ========== OPERASI INSERT ==========
void insertHewan(address &root, Hewan data) {
    if (isEmpty(root)) {
        root = alokasi(data);
    } else {
        if (data.beratBadan < root->info.beratBadan) {
            insertHewan(root->left, data);
        }else if (data.beratBadan > root->info.beratBadan) {
            insertHewan(root->right, data);
        }else {
            cout << "Hewan dengan berat " << data.beratBadan
            << " kg sudah ada!" << endl;
        }
    }
}
    // ========== OPERASI TRAVERSAL ==========
void printInOrder(address root) {
    if (root != nullptr) {
        printInOrder(root->left);
        printHewan(root->info);
        printInOrder(root->right);
    }
}

void printPreOrder(address root) {
    if (root != nullptr) {
        printHewan(root->info);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != nullptr) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        printHewan(root->info);
    }
}

address searchByBerat(address root, int berat) {
    if (root == nullptr || root->info.beratBadan == berat) {
        return root;
    }

    if (berat < root->info.beratBadan) {
        return searchByBerat(root->left, berat);
    } else {
        return searchByBerat(root->right, berat);
    }
}

void printByHabitat(address root, string habitat) {
    if (root != nullptr) {
        printByHabitat(root->left, habitat);
        if (root->info.habitat == habitat) {
            printHewan(root->info);
        }
        printByHabitat(root->right, habitat);
    }
}

void printDilindungi(address root) {
    if (root != nullptr) {
        printDilindungi(root->left);
        if (root->info.dilindungi) {
            printHewan(root->info);
        }
        printDilindungi(root->right);
    }
}
    // ========== OPERASI PENGHAPUSAN ==========
address findMin(address root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->left == nullptr) {
        return root;
    }
    return findMin(root->left);
}

address findMax(address root) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->right == nullptr) {
        return root;
    }
    return findMax(root->right);
}

void deleteHewan(address &root, int berat) {
    if (root == nullptr) {
        cout << "Hewan dengan berat " << berat << " kg tidak ditemukan!" << endl;
        return;
    }
    if (berat < root->info.beratBadan) {
        deleteHewan(root->left, berat);
    } else if (berat > root->info.beratBadan) {
        deleteHewan(root->right, berat);
    } else {
            // Node ditemukan
        if (root->left == nullptr && root->right == nullptr) {
                // Node leaf
            dealokasi(root);
        } else if (root->left == nullptr) {
                // Node dengan 1 child (kanan)
            address temp = root;
            root = root->right;
            dealokasi(temp);
        } else if (root->right == nullptr) {
                // Node dengan 1 child (kiri)
            address temp = root;
            root = root->left;
            dealokasi(temp);
        } else {
                // Node dengan 2 children
            address successor = findMin(root->right);
            root->info = successor->info;
            deleteHewan(root->right, successor->info.beratBadan);
        }
        cout << "Hewan berhasil dihapus\n";
    }
}
    // ========== OPERASI ANALISIS ==========
int countHewan(address root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countHewan(root->left) + countHewan(root->right);
}

int hitungKedalaman(address root) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = hitungKedalaman(root->left);
    int rightHeight = hitungKedalaman(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int totalBerat(address root) {
    if (root == nullptr) {
        return 0;
    }
    return root->info.beratBadan + totalBerat(root->left) + totalBerat(root->right);
}

address cariTerberat(address root) {
    return findMax(root);
}

address cariTeringan(address root) {
    return findMin(root);
}

int countDilindungi(address root) {
    if (root == nullptr) {
        return 0;
    }
    int count = root->info.dilindungi ? 1 : 0;
    return count + countDilindungi(root->left) + countDilindungi(root->right);
}
    // ========== MENU ==========
void tampilkanMenu() {
    cout << " " << endl;
    cout << "             MENU UTAMA\n";
    cout << "-----------------------------------------\n";
    cout << "1.  Tambah Hewan Baru\n";
    cout << "2.  Tampilkan Semua (In-Order)\n";
    cout << "3.  Tampilkan Pre-Order\n";
    cout << "4.  Tampilkan Post-Order\n";
    cout << "5.  Cari Hewan (Berat)\n";
    cout << "6.  Tampilkan Per Habitat\n";
    cout << "7.  Hewan yang Dilindungi\n";
    cout << "9.  Hapus Hewan\n";
    cout << "9. Statistik\n";
    cout << "0.  Keluar\n";
    cout << "-----------------------------------------\n";
}

void inputHewan(address &root) {
    Hewan h;
    char pilih;

    cout << "\n=== TAMBAH HEWAN ===\n";

    cout << "Nama hewan: ";
    cin >> ws;
    getline(cin, h.nama);

    cout << "Berat badan (kg): ";
    h.beratBadan = inputBeratBadan();

        // VALIDASI HABITAT
    do{
        cout << "Habitat (Darat/Air/Udara/Amfibi): ";
        cin >> ws;
        getline(cin, h.habitat);

        if (!habitatValid(h.habitat)) {
            cout << "Habitat tidak valid!\n";
        }
    }while (!habitatValid(h.habitat));

        // VALIDASI DILINDUNGI
    do{
        cout << "Dilindungi? (y/n): ";
        cin >> pilih;

        if (!dilindungiValid(pilih)) {
            cout << "Input harus y atau n!\n";
        }
    }while (!dilindungiValid(pilih));
    h.dilindungi = (pilih == 'y' || pilih == 'Y');
    insertHewan(root, h);
    cout << "Hewan berhasil ditambahkan\n";
}

int inputBeratBadan() {
    int berat;
        // Selama input bukan angka, ulangi terus
    while (!(cin >> berat)) {
        cout << "Input salah! Masukkan angka untuk berat: ";
        cin.clear();
        string sampah;
        cin >> sampah; // Membuang input teks yang salah
    }
    return berat;
}

bool habitatValid(string habitat) {
    return habitat == "Darat" ||
            habitat == "Air" ||
            habitat == "Udara" ||
            habitat == "Amfibi";
}

bool dilindungiValid(char pilih) {
    return pilih == 'y' || pilih == 'Y' ||
            pilih == 'n' || pilih == 'N';
}

void printHewan(Hewan h) {
    cout << "Nama Hewan   : " << h.nama << endl;
    cout << "Berat Badan  : " << h.beratBadan << " kg" << endl;
    cout << "Habitat     : " << h.habitat << endl;
    cout << "Dilindungi  : " << (h.dilindungi ? "Ya" : "Tidak") << endl;
    cout << "-----------------------------" << endl;
}
