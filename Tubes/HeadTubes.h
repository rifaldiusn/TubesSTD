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

adrPelanggan buatPelanggan(string namaPelanggan,int Harga);
void buatListPelanggan(ListPelanggan *P);
void insertPelanggan(ListPelanggan *L,adrPelanggan P);
void printPelanggan(ListPelanggan L);
void deleteFirstPelanggan(ListPelanggan *L);
adrPelanggan searchPelanggan(ListPelanggan L, string nama);
void cariHargaPelanggan(ListPelanggan L, int harga);
void cariMenuPelanggan(ListPesanan L, adrMenu M);


adrPesanan buatPesanan(adrMenu M, adrPelanggan P);
void buatListPesanan(ListPesanan *P);
void insertPesanan(ListPesanan *L, adrPesanan P);
void printPesanan(ListPesanan L);

void clear();
void tunggu();

#endif // HEADTUBES_H_INCLUDED
