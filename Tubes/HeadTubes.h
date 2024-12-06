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

struct pelanggan
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


#endif // HEADTUBES_H_INCLUDED
