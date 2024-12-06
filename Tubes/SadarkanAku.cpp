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
    P = new pelanggan;
    P->nama = nama;
    P->totalHarga = 0;
    P->nextPelanggan = NULL;
    P->firstPesanan = NULL;
}