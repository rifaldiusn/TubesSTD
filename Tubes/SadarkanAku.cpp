#include <iostream>
#include "HeadTubes.h"
using namespace std;

//Menu ========================================================================

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
    int nomor = 1;
    cout << "+----+----------------------+-------+" << endl;
    cout << "| No | Nama Menu            | Harga |" << endl;
    cout << "+----+----------------------+-------+" << endl;
    while (M != nullptr) {
        cout << "| " << nomor;
        for (int i = to_string(nomor).length(); i < 3; i++) {
            cout << " ";
        }
        cout << "| " << M->Nama;
        for (int i = M->Nama.length(); i < 21; i++) {
            cout << " ";
        }
        cout << "| " << M->harga;
        for (int i = to_string(M->harga).length(); i < 6; i++) {
            cout << " ";
        }
        cout << "|" << endl;
        M = M->nextMenu;
        nomor++;
    }
    cout << "+----+----------------------+-------+" << endl;
}

adrMenu searchMenu(ListMenu L, int nomor) {
     adrMenu M = L.firstMenu;
    int i = 1;
    while (M != NULL) {
        if (i == nomor) {
            return M;
        }
        M = M->nextMenu;
        i++;
    }
    cout << "Menu dengan nomor " << nomor << " tidak ditemukan." << endl;
    return NULL;
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
//pelanggan ========================================================================
adrPelanggan buatPelanggan(string namaPelanggan, int harga)
{
    adrPelanggan Pp = new Pelanggan;
    Pp->nama = namaPelanggan;
    Pp->totalHarga = harga;
    Pp->nextPelanggan = NULL;
    Pp->prevPelanggan = NULL;
    return Pp;
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

adrPelanggan searchPelanggan(ListPelanggan L, string nama) {
    adrPelanggan P = L.firstPelanggan;
    while (P != NULL) {
        if (P->nama == nama) {
            return P;
        }
        P = P->nextPelanggan;
    }
    return NULL;
}

//pesanan ========================================================================

adrPesanan buatPesanan(adrMenu M, adrPelanggan P){
    adrPesanan Ps = new Pesanan;
    Ps->nextPesanan = NULL;
    Ps->Menu = M;
    Ps->Pelanggan = P;
    Ps->Pelanggan->totalHarga += M->harga;
    return Ps;
}

void buatListPesanan(ListPesanan *P){
    P->firstPesanan = NULL;
}

void insertPesanan(ListPesanan *L, adrPesanan P){
    if (L->firstPesanan == NULL){
        L->firstPesanan = P;
    }else{
        adrPesanan Q = L->firstPesanan;
        while (Q->nextPesanan != NULL){
            Q = Q->nextPesanan;
        }
        Q->nextPesanan = P;
    }
}

void printPesanan(ListPesanan L){
    adrPesanan P1 = L.firstPesanan;
    adrPesanan cek = L.firstPesanan;
    while (P1 != NULL){

        //masih ngebug gak tau wan harus beres ma maneh urang dah males
            if (cek != P1){

                anakPrintPesanan(L, P1->Pelanggan->nama);
            }else {
                cek = cek->nextPesanan;
            }
        P1 = P1->nextPesanan;
    }

}

void anakPrintPesanan(ListPesanan L, string namaPelanggan) {
   adrPesanan P = L.firstPesanan;
    bool found = false;
    cout << "Pesanan untuk pelanggan dengan nama " << namaPelanggan << ":" << endl;
    while (P != nullptr) {
        if (P->Pelanggan->nama == namaPelanggan) {
            found = true;
            cout << "Nama Menu: " << P->Menu->Nama << ", Harga: " << P->Menu->harga << endl;
        }
        cout << endl;
        P = P->nextPesanan;
    }
    if (!found) {
        cout << "Pesanan untuk pelanggan dengan nama " << namaPelanggan << " tidak ditemukan." << endl;
    }
}