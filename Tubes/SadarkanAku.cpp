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
    M = buatMenu("kopi", 30000);
    insertMenu(L,M);
    M = buatMenu("teh", 27000);
    insertMenu(L,M);
    M = buatMenu("roti", 25000);
    insertMenu(L,M);
    M = buatMenu("kopsu", 33000);
    insertMenu(L,M);
    M = buatMenu("josu", 33000);
    insertMenu(L,M);
    M = buatMenu("mie", 23000);

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

adrMenu cariMenu(ListMenu L, string nama) {
    adrMenu M = L.firstMenu;
    while (M != NULL) {
        if (M->Nama == nama) {
            return M;
        }
        M = M->nextMenu;
    }
    return NULL;
}

void carimenuHarga(ListMenu L, int harga) {
    adrMenu M = L.firstMenu;
    while (M != NULL) {
        if (M->harga == harga) {
            cout << "Nama Menu: " << M->Nama << endl;
            cout << "Harga: " << M->harga << endl;
        }
        M = M->nextMenu;
    }
}

void cariMenuPelanggan(ListPesanan L, adrPelanggan P){
    adrPesanan Ps = L.firstPesanan;
    while (Ps != NULL){
        if (Ps->Pelanggan == P){
            cout << "Nama Menu: " << Ps->Menu->Nama << endl;
            cout << "Harga: " << Ps->Menu->harga << endl;
        }
        Ps = Ps->nextPesanan;
    }
}

void hapusMenuFirst(ListMenu *L) {
    if (L->firstMenu == NULL) {
        return;
    } else if (L->firstMenu->nextMenu == NULL) {
        delete L->firstMenu;
        L->firstMenu = NULL;
    } else {
        adrMenu P = L->firstMenu;
        L->firstMenu = P->nextMenu;
    }
}

void hapusMenuLast(ListMenu *L) {
    if (L->firstMenu == NULL) {
        return;
    } else if (L->firstMenu->nextMenu == NULL) {
        delete L->firstMenu;
        L->firstMenu = NULL;
    } else {
        adrMenu P = L->firstMenu;
        while (P->nextMenu->nextMenu != NULL) {
            P = P->nextMenu;
        }
        delete P->nextMenu;
        P->nextMenu = NULL;
    }
}

void hapusMenuAfter(ListMenu *L, adrMenu M) {
        adrMenu P = L->firstMenu;
        while (P->nextMenu != M) {
            P = P->nextMenu;
        }
        P->nextMenu = M->nextMenu;
}

void hapusMenu(ListMenu *L, adrMenu M, ListPesanan *Lpesanan) {
    if (M == NULL) {
        return;
    } else if (M == L->firstMenu) {
        hapusMenuFirst(L);
    } else if (M->nextMenu == NULL) {
        hapusMenuLast(L);
    } else {
        hapusMenuAfter(L, M);
    }
    hapusMenuPesanan(Lpesanan, M);
}

void hapusMenuPesanan(ListPesanan *L, adrMenu M){
    adrPesanan current = L->firstPesanan;
    adrPesanan prev = NULL;

    while (current != NULL) {
        if (current->Menu == M) {
            current->Pelanggan->totalHarga -= M->harga;
            if (prev == NULL) {
                L->firstPesanan = current->nextPesanan;
            } else {
                prev->nextPesanan = current->nextPesanan;
            }
            adrPesanan temp = current;
            current = current->nextPesanan;
            temp->nextPesanan = NULL;
        } else {
            prev = current;
            current = current->nextPesanan;
        }
    }
}

void cariMenudiPelangganTertentu(ListPesanan L, adrPelanggan P, adrMenu M){
    adrPesanan Ps = L.firstPesanan;
    int i = 1;
    while (Ps != NULL){
        if (Ps->Pelanggan == P && Ps->Menu == M){
            cout << Ps->Pelanggan->nama << " memesan " << Ps->Menu->Nama << endl;
            i = 0;
        }
        Ps = Ps->nextPesanan;
    }
    if (i == 1){
       cout << "Pelanggan tidak memesan menu tersebut" << endl;
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


void printPelanggan(ListPelanggan L, ListPesanan Lpesanan) {
    adrPelanggan P = L.firstPelanggan;
    if (P == NULL) {
        cout << "Tidak ada pelanggan" << endl;
    }else {
        while (P != NULL) {
            cout << "Nama Pelanggan: " << P->nama << endl;
            cout << "Total Harga: " << P->totalHarga << endl;
            int i = banyakPesananPelanggan(Lpesanan, P);
            cout << "Banyak Pesanan: " << i << endl;
            cout << endl;
        P = P->nextPelanggan;
        }

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

void cariHargaPelanggan(ListPelanggan L, int harga) {
    adrPelanggan P = L.firstPelanggan;
    while (P != NULL) {
        if (P->totalHarga == harga) {
            cout << "Nama Pelanggan: " << P->nama << endl;
            cout << "Total Harga: " << P->totalHarga << endl;
        }
        P = P->nextPelanggan;
    }
}

void cariMenuPelanggan(ListPesanan L, adrMenu M) {
    adrPesanan Ps = L.firstPesanan;
    while (Ps != NULL) {
        if (Ps->Menu == M) {
            cout << "Nama Pelanggan: " << Ps->Pelanggan->nama << endl;
            cout << "Total Harga: " << Ps->Pelanggan->totalHarga << endl;
        }
        Ps = Ps->nextPesanan;
    }
}
void hapusPelangganFirst(ListPelanggan *L) {
    if (L->firstPelanggan == NULL) {
        return;
    } else if (L->firstPelanggan == L->LastPelanggan) {
        L->firstPelanggan = NULL;
        L->LastPelanggan = NULL;
    } else {
        adrPelanggan P = L->firstPelanggan;
        L->firstPelanggan = P->nextPelanggan;
        L->firstPelanggan->prevPelanggan = NULL;
        P->nextPelanggan = NULL;
    }
}

void hapusPelangganLast(ListPelanggan *L) {
    if (L->firstPelanggan == NULL) {
        return;
    } else if (L->firstPelanggan == L->LastPelanggan) {
        L->firstPelanggan = NULL;
        L->LastPelanggan = NULL;
    } else {
        adrPelanggan P = L->LastPelanggan;
        L->LastPelanggan = P->prevPelanggan;
        L->LastPelanggan->nextPelanggan = NULL;
        P->prevPelanggan = NULL;
    }
}

void hapusPelangganAfter(ListPelanggan *L, adrPelanggan P) {
        adrPelanggan Q = P->prevPelanggan;
        adrPelanggan R = P->nextPelanggan;
        Q->nextPelanggan = R;
        R->prevPelanggan = Q;
        P->nextPelanggan = NULL;
        P->prevPelanggan = NULL;
}

void hapusPelanggan(ListPelanggan *L, adrPelanggan P, ListPesanan *Lpesanan) {
    if (P == NULL) {
        return;
    } else if (P == L->firstPelanggan) {
        hapusPelangganFirst(L);
    } else if (P == L->LastPelanggan) {
        hapusPelangganLast(L);
    } else {
        hapusPelangganAfter(L, P);
    }
    hapusPesananPelanggan(Lpesanan, P);
}

int banyakPesananPelanggan(ListPesanan L, adrPelanggan P){
    adrPesanan Ps = L.firstPesanan;
    int i = 0;
    while (Ps != NULL){
        if (Ps->Pelanggan == P){
            i++;
        }
        Ps = Ps->nextPesanan;
    }
    return i;
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
    if (P1 == NULL) {
        cout << "Tidak ada pesanan" << endl;
    }else{
        cout << "Pesanan yang ada: " << endl;
        while (P1 != NULL) {
            cout << "Nama Pelanggan: " << P1->Pelanggan->nama << endl;
            adrPesanan P2 = L.firstPesanan;
            while (P2 != NULL) {
                if (P1->Pelanggan->nama == P2->Pelanggan->nama) {
                    cout << "  Nama Menu: " << P2->Menu->Nama << ", Harga: " << P2->Menu->harga << endl;
                }
                P2 = P2->nextPesanan;
            }
            string Temp = P1->Pelanggan->nama;
            while (P1 != NULL && P1->Pelanggan->nama == Temp) {
                P1 = P1->nextPesanan;
            }
        }
    }
}

void hapusPesananPelanggan(ListPesanan *L, adrPelanggan P){
    adrPesanan current = L->firstPesanan;
    adrPesanan prev = NULL;

    while (current != NULL) {
        if (current->Pelanggan == P) {
            if (prev == NULL) {
                L->firstPesanan = current->nextPesanan;
            } else {
                prev->nextPesanan = current->nextPesanan;
            }
            adrPesanan temp = current;
            current = current->nextPesanan;
            temp->nextPesanan = NULL;
        } else {
            prev = current;
            current = current->nextPesanan;
        }
    }
}

void hapusPesananMenu(ListPesanan *L, adrMenu M, adrPelanggan P){
    adrPesanan current = L->firstPesanan;
    adrPesanan prev = NULL;

    while (current != NULL) {
        if (current->Menu == M && current->Pelanggan == P) {
            current->Pelanggan->totalHarga -= M->harga;
            if (prev == NULL) {
                L->firstPesanan = current->nextPesanan;
            } else {
                prev->nextPesanan = current->nextPesanan;
            }
            adrPesanan temp = current;
            current = current->nextPesanan;
            temp->nextPesanan = NULL;
        } else {
            prev = current;
            current = current->nextPesanan;
        }
    }
}

void clear(){
     cout << "\033[2J\033[1;1H";
}

void tunggu(){
    cout << "Tekan apa saja untuk melanjutkan";
    cin.ignore();
    cin.get();
}