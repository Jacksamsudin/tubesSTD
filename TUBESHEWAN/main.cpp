#include "hewan.h"
#include <iostream>
using namespace std;

int main() {
    address root;
    createTree(root);

    int pilihan;
    string nama, habitat;
    int berat;
    address hasil;

    cout << "SISTEM KLASIFIKASI HEWAN" << endl;
    cout << "BST Berdasarkan Berat";
    cout << " " << endl;

    do {
        tampilkanMenu();
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        cout << "\n";

        switch (pilihan) {
        case 1:
            inputHewan(root);
            break;

        case 2:
            cout << "\n=== DAFTAR HEWAN (IN-ORDER) ===\n";
            printInOrder(root);
            cout << "Total: " << countHewan(root) << endl;
            break;

        case 3:
            cout << "\n=== PRE-ORDER ===\n";
            printPreOrder(root);
            break;

        case 4:
            cout << "\n=== POST-ORDER ===\n";
            printPostOrder(root);
            break;

        case 5:
            cout << "Nama hewan: ";
            cin >> ws;
            getline(cin, nama);
            hasil = searchByName(root, nama);
            if (hasil)
                printHewan(hasil->info);
            else
                cout << "Tidak ditemukan\n";
            break;

        case 6:
            cout << "Berat: ";
            cin >> berat;
            hasil = searchByBerat(root, berat);
            if (hasil)
                printHewan(hasil->info);
            else
                cout << "Tidak ditemukan\n";
            break;

        case 7:
            cout << "Habitat: ";
            cin >> ws;
            getline(cin, habitat);
            printByHabitat(root, habitat);
            break;

        case 8:
            printDilindungi(root);
            break;

        case 9:
            cout << "Berat yang dihapus: ";
            cin >> berat;
            deleteHewan(root, berat);
            break;
        case 10:
                cout << "\n=== STATISTIK HEWAN ===" << endl;
                cout << "Total hewan          : " << countHewan(root) << endl;
                cout << "Kedalaman tree       : " << hitungKedalaman(root) << endl;
                cout << "Total berat semua    : " << totalBerat(root) << " kg" << endl;

                hasil = cariTerberat(root);
                if (hasil != NULL) {
                    cout << "Hewan terberat       : " << hasil->info.nama
                         << " (" << hasil->info.beratBadan << " kg)" << endl;
                }

                hasil = cariTeringan(root);
                if (hasil != NULL) {
                    cout << "Hewan teringan       : " << hasil->info.nama
                         << " (" << hasil->info.beratBadan << " kg)" << endl;
                }

                cout << "Hewan dilindungi     : " << countDilindungi(root) << endl;
                break;


        case 0:
            cout << "Terima kasih\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}
