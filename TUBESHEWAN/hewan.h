#ifndef HEWAN_H
#define HEWAN_H
#include <iostream>
#include <string>
using namespace std;

struct Hewan {
    string nama;
    int beratBadan;
    string habitat;
    bool dilindungi;
};

typedef struct NodeHewan* address;

struct NodeHewan {
    Hewan info;
    address left;
    address right;
};

// ===== PROTOTYPE BST =====
void createTree(address &root);
address alokasi(Hewan data);
void dealokasi(address &P);
bool isEmpty(address root);

void insertHewan(address &root, Hewan data);
void deleteHewan(address &root, int berat);

void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

address searchByName(address root, string nama);
address searchByBerat(address root, int berat);
void printByHabitat(address root, string habitat);
void printDilindungi(address root);

int countHewan(address root);
int hitungKedalaman(address root);
int totalBerat(address root);
int countDilindungi(address root);

address findMax(address root);
address findMin(address root);

// ===== MENU & INPUT =====
void tampilkanMenu();
void inputHewan(address &root);
void tampilkanStatistik(address root);

// ===== VALIDASI =====
int inputBeratBadan();

// ===== UTILITAS =====
void printHewan(Hewan h);

#endif
