#include <iostream>
#include "HeadTubes.h"
using namespace std;

void createAntrian(antrian &Q)
{
    Q.headPelanggan = NULL;
    Q.tailPelanggan = NULL;
}

void createPelanggan(adrPelanggan &P, string nama)
{
    P = new Pelanggan;
    P->nama = nama;
    P->totalHarga = 0;
    P->nextPelanggan = NULL;
    P->firstPesanan = NULL;
}

void createPesanan(adrPesanan &P, string namaPesanan, int harga)
{
    P = new Pesanan;
    P->namaPesanan = namaPesanan;
    P->harga = harga;
    P->nextPesanan = NULL;
}

void createMenuMakanan(adrMenuMakanan &P, string namaMenu, int harga)
{
    P = new MenuMakanan;
    P->namaMenu = namaMenu;
    P->harga = harga;
    P->nextMakanan = NULL;
}

void createMenuMinuman(adrMenuMinuman &P, string namaMenu, int harga)
{
    P = new MenuMinuman;
    P->namaMenu = namaMenu;
    P->harga = harga;
    P->nextMinuman = NULL;
}

void createMenu(Menu &M)
{
    M.firstMakanan = NULL;
    M.firstMinuman = NULL;
}

void insertMenuMakanan(Menu &M, string namaMenu, int harga)
{
    adrMenuMakanan P;
    createMenuMakanan(P, namaMenu, harga);
    if (M.firstMakanan == NULL)
    {
        M.firstMakanan = P;
    }else {
        adrMenuMakanan Q = M.firstMakanan;
        while (Q->nextMakanan != NULL)
        {
            Q = Q->nextMakanan;
        }
        Q->nextMakanan = P;
    }
}

void insertMenuMinuman(Menu &M, string namaMenu, int harga)
{
    adrMenuMinuman P;
    createMenuMinuman(P, namaMenu, harga);
    if (M.firstMinuman == NULL)
    {
        M.firstMinuman = P;
    }else {
        adrMenuMinuman Q = M.firstMinuman;
        while (Q->nextMinuman != NULL)
        {
            Q = Q->nextMinuman;
        }
        Q->nextMinuman = P;
    }
}
void isiMenu(Menu &M)
{
    adrMenuMakanan Makanan;
    adrMenuMinuman Minuman;

    insertMenuMakanan(M, "Nasi Goreng", 15000);
    insertMenuMakanan(M, "Mie Goreng", 15000);
    insertMenuMinuman(M, "Es Teh", 5000);
}

void mainMenu(){
    cout << "========================";
    cout << "        M E N U         ";
    cout << "Restaurant Kuy Makan Kuy";
    cout << "========================";

}