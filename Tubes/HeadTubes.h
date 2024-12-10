#ifndef HEADTUBES_H_INCLUDED
#define HEADTUBES_H_INCLUDED
#include <iostream>
using namespace std; 

typedef struct Pelanggan *adrPelanggan;
typedef struct Pesanan *adrPesanan;
typedef struct Menu *adrMenu;

struct Pesanan
{
    string namaPesanan;
    int harga;
    adrPesanan nextPesanan;
    adrMenu ListMenu; 
    adrPelanggan customer; 
};

struct Pelanggan
{
    string nama;
    int totalHarga; 
    adrPelanggan nextPelanggan;
    adrPelanggan prevPelanggan;
    adrPesanan firstPesanan;
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

struct ListPelanggan
{
    adrPelanggan firstPelanggan;
    adrPelanggan LastPelanggan;
};

void buatMenu(adrMenu M,string NamaMenu, int harga);
void buatListMenu(ListMenu P);
void insertMenu(ListMenu L, adrMenu M);

void buatPelanggan(adrPelanggan P,string namaPelanggan,int Harga);
void buatListPelanggan(ListPelanggan P);
void insertPelanggan(ListPelanggan L,adrPelanggan P);

void buatPesanan();

#endif // HEADTUBES_H_INCLUDED
