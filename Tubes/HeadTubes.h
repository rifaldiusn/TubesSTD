#ifndef HEADTUBES_H_INCLUDED
#define HEADTUBES_H_INCLUDED
#include <iostream>
using namespace std; 

typedef struct Pelanggan *adrPelanggan;
typedef struct Pesanan *adrPesanan;
typedef struct Menu *adrMenu;

struct Pesanan
{
    adrPesanan nextPesanan;
    adrMenu Menu; 
    adrPelanggan Pelanggan;
};

struct  ListPesanan
{
    adrPesanan firstPesanan;
};


struct Pelanggan
{
    string nama;
    int totalHarga; 
    adrPelanggan nextPelanggan;
    adrPelanggan prevPelanggan;

};

struct ListPelanggan
{
    adrPelanggan firstPelanggan;
    adrPelanggan LastPelanggan;
};


struct Menu
{
    string Nama;
    int harga; 
    adrMenu nextMenu; 
};

struct ListMenu{
    adrMenu firstMenu; 
};



adrMenu buatMenu(string NamaMenu, int harga);
void buatListMenu(ListMenu *P);
void insertMenu(ListMenu *L, adrMenu M);
void isiMenu(ListMenu *L);
void printMenu(ListMenu L);
adrMenu searchMenu(ListMenu L, int nomor);
adrMenu cariMenu(ListMenu L, string nama);
void carimenuHarga(ListMenu L, int harga);
void cariMenuPelanggan(ListPesanan L, adrPelanggan P);
void hapusMenuFirst(ListMenu *L);
void hapusMenuLast(ListMenu *L);
void hapusMenuAfter(ListMenu *L, adrMenu M);
void hapusMenu(ListMenu *L, adrMenu M, ListPesanan *Lpesanan);
void hapusMenuPesanan(ListPesanan *L, adrMenu M);
void cariMenudiPelangganTertentu(ListPesanan L, adrPelanggan P, adrMenu M);
int banyakPesananPelanggan(ListPesanan L, adrPelanggan P);


adrPelanggan buatPelanggan(string namaPelanggan,int Harga);
void buatListPelanggan(ListPelanggan *P);
void insertPelanggan(ListPelanggan *L,adrPelanggan P);
void printPelanggan(ListPelanggan L, ListPesanan Lpesanan);
adrPelanggan searchPelanggan(ListPelanggan L, string nama);
void cariHargaPelanggan(ListPelanggan L, int harga);
void cariMenuPelanggan(ListPesanan L, adrMenu M);
void hapusPelangganFirst(ListPelanggan *L);
void hapusPelangganLast(ListPelanggan *L);
void hapusPelangganAfter(ListPelanggan *L, adrPelanggan P);
void hapusPelanggan(ListPelanggan *L, adrPelanggan P, ListPesanan *Lpesanan);

adrPesanan buatPesanan(adrMenu M, adrPelanggan P);
void buatListPesanan(ListPesanan *P);
void insertPesanan(ListPesanan *L, adrPesanan P);
void printPesanan(ListPesanan L);
void hapusPesananPelanggan(ListPesanan *L, adrPelanggan P);
void hapusPesananMenu(ListPesanan *L, adrMenu M, adrPelanggan P);

void clear();
void tunggu();

#endif // HEADTUBES_H_INCLUDED
