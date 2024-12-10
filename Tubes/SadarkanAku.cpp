#include <iostream>
#include "HeadTubes.h"
using namespace std;

void buatMenu(adrMenu M,string NamaMenu, int harga){
    M = new Menu; 
    M->Nama = NamaMenu;
    M->harga = harga; 
    M->nextMenu = NULL; 
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
       
        P->nextPelanggan = L->firstPelanggan;
        L->firstPelanggan->prevPelanggan = P;
        L->firstPelanggan = P;
        P->prevPelanggan = NULL;
    }
}

void deleteFirstPelanggan(ListPelanggan *L) {
    if (L->firstPelanggan == NULL) {
        // Jika list kosong, tidak ada yang dihapus
        return;
    } else if (L->firstPelanggan == L->LastPelanggan) {
        // Jika list hanya memiliki satu node, maka hapus node tersebut
        L->firstPelanggan = NULL;
        L->LastPelanggan = NULL;
    } else {
        // Jika list memiliki lebih dari satu node, maka hapus node pertama
        adrPelanggan P = L->firstPelanggan;
        L->firstPelanggan = L->firstPelanggan->nextPelanggan;
        L->firstPelanggan->prevPelanggan = NULL;
        P->nextPelanggan = NULL;
        delete P; // Hapus node yang telah dihapus
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