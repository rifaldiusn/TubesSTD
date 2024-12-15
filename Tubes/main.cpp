#include <iostream>
#include "HeadTubes.h"
using namespace std;

int main()
{
    ListMenu Lmenu;
    buatListMenu(&Lmenu);
    isiMenu(&Lmenu);
    printMenu(Lmenu);
    cout << "atas nama siapa ? ";
    string nama;
    cin >> nama;
    cout << "ingin memesan apa ? ";
    int noPesanan;
    cin >> noPesanan;
    ListPelanggan Lpelanggan;
    buatListPelanggan(&Lpelanggan);
    adrPelanggan Pel = buatPelanggan(nama, 0);
    adrMenu M = searchMenu(Lmenu, noPesanan);
    ListPesanan Lpesanan;
    buatListPesanan(&Lpesanan);
    adrPesanan P = buatPesanan(M, Pel);
    cout << M->Nama<< " " << Pel->nama << " " << P->Menu->harga << endl;
}
