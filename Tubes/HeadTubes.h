#ifndef HEADTUBES_H_INCLUDED
#define HEADTUBES_H_INCLUDED
#include <iostream>
using namespace std; 

typedef struct Pelanggan *adrPelanggan;
typedef struct Pesanan *adrPesanan;
typedef struct MenuMakanan *adrMenuMakanan;
typedef struct MenuMinuman *adrMenuMinuman;

struct antrian
{
    adrPelanggan headPelanggan;
    adrPelanggan tailPelanggan;
};

struct Pesanan
{
    string namaPesanan;
    int harga;
    adrPesanan nextPesanan;
};

struct Pelanggan
{
    string nama;
    int totalHarga; 
    adrPelanggan nextPelanggan;
    adrPesanan firstPesanan;
};

struct MenuMakanan
{
    string namaMenu;
    int harga;
    adrMenuMakanan nextMakanan;
};

struct MenuMinuman
{
    string namaMenu;
    int harga;
    adrMenuMinuman nextMinuman;
};

struct Menu
{
    adrMenuMakanan firstMakanan;
    adrMenuMinuman firstMinuman;
};

void createAntrian(antrian &Q);
void createPelanggan(adrPelanggan &P, string nama);
void createPesanan(adrPesanan &P, string namaPesanan, int harga);
void createMenuMakanan(adrMenuMakanan &P, string namaMenu, int harga);
void createMenuMinuman(adrMenuMinuman &P, string namaMenu, int harga);
void createMenu(Menu &M);

void Mainmenu();
void isiMenu(Menu &M);

void insertMenuMakanan(Menu &M, string namaMenu, int harga);
void insertMenuMinuman(Menu &M, string namaMenu, int harga);



#endif // HEADTUBES_H_INCLUDED
