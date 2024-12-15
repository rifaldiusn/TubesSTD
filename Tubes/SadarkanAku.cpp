#include <iostream>
#include "HeadTubes.h"
using namespace std;

adrMenu buatMenu(string NamaMenu, int harga){
   adrMenu M = new Menu; 
    M->Nama = NamaMenu;
    M->harga = harga; 
    M->nextMenu = NULL; 
    return M;
}

void buatListMenu(ListMenu *P){
    P->firstMenu = NULL;
}

void insertMenu(ListMenu *L, adrMenu M){
    if (L->firstMenu == NULL){
        L->firstMenu = M;
    }else{
        adrMenu Q = L->firstMenu; 
        while (Q->nextMenu != NULL){
            Q = Q->nextMenu; 
        }
        Q->nextMenu = M;
    }
}

void isiMenu(ListMenu *L){
    adrMenu M;
    M = buatMenu("kopi kisah asmara", 30000);
    insertMenu(L,M);
    M = buatMenu("kopi kisah manis", 27000);
    insertMenu(L,M);
    M = buatMenu("kopi kisah aren", 25000);
    insertMenu(L,M);
    M = buatMenu("golden latte", 33000);
    insertMenu(L,M);
    M = buatMenu("bajigur latte", 33000);
    insertMenu(L,M);
    M = buatMenu("kopi susu lokal", 23000);

}

void printMenu(ListMenu L) {
    adrMenu M = L.firstMenu;
    cout << "+--------------------+--------+" << endl;
    cout << "| Nama Menu          | Harga  |" << endl;
    cout << "+--------------------+--------+" << endl;
    while (M != nullptr) {
        cout << "| " << M->Nama;
        for (int i = M->Nama.length(); i < 21; i++) {
            cout << " ";
        }
        cout << "| " << M->harga;
        for (int i = to_string(M->harga).length(); i < 7; i++) {
            cout << " ";
        }
        cout << "|" << endl;
        M = M->nextMenu;
    }
    cout << "+--------------------+--------+" << endl;
}



void deleteFirst(ListMenu *L) {
    if (L->firstMenu == NULL) {
        // Jika list kosong, tidak ada yang dihapus
        return;
    } else if (L->firstMenu->nextMenu == NULL) {
        // Jika list hanya memiliki satu node, maka hapus node tersebut
        delete L->firstMenu;
        L->firstMenu = NULL;
    } else {
        // Jika list memiliki lebih dari satu node, maka hapus node pertama
        adrMenu P = L->firstMenu;
        L->firstMenu = P->nextMenu;
        delete P;
    }
}

void buatPelanggan(adrPelanggan P,string namaPelanggan,int harga )
{
    P = new Pelanggan;
    P->nama = namaPelanggan;
    P->totalHarga = harga;
    P->nextPelanggan = NULL;
    P->prevPelanggan = NULL;
}

void buatListPelanggan(ListPelanggan *P)
{
    P->firstPelanggan = NULL;
    P->LastPelanggan = NULL;
}

void insertPelanggan(ListPelanggan *L, adrPelanggan P) {
    if (L->firstPelanggan == NULL) {
        
        L->firstPelanggan = P;
        L->LastPelanggan = P;
        P->prevPelanggan = NULL;
        P->nextPelanggan = NULL;
    } else {
       
        L->LastPelanggan->nextPelanggan = P;
        P->prevPelanggan = L->LastPelanggan;
        L->LastPelanggan = P;
        P->nextPelanggan = NULL;
    }
}

void deleteFirstPelanggan(ListPelanggan *L) {
    if (L->firstPelanggan == NULL) {
        return;
    } else if (L->firstPelanggan == L->LastPelanggan) {
        L->firstPelanggan = NULL;
        L->LastPelanggan = NULL;
    } else {
        adrPelanggan P = L->firstPelanggan;
        L->firstPelanggan = L->firstPelanggan->nextPelanggan;
        L->firstPelanggan->prevPelanggan = NULL;
        P->nextPelanggan = NULL;
        delete P; 
    }
}

void printPelanggan(ListPelanggan L) {
    adrPelanggan P = L.firstPelanggan;
    while (P != NULL) {
        cout << "Nama Pelanggan: " << P->nama << endl;
        cout << "Total Harga: " << P->totalHarga << endl;
        cout << endl;
        P = P->nextPelanggan;
    }
}

void buatPesanan(adrPesanan P){
    P = new Pesanan;
    P->nextPesanan = NULL;
    P->Menu = NULL;
    P->Pelanggan = NULL;
}

void buatListPesanan(ListPesanan *P){
    P->firstPesanan = NULL;
}
