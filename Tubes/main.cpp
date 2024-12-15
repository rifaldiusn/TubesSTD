#include <iostream>
#include "HeadTubes.h"
using namespace std;

int main()
{
    ListMenu Lmenu;
    buatListMenu(&Lmenu);
    

    ListPelanggan Lpelanggan;
    buatListPelanggan(&Lpelanggan);

    ListPesanan Lpesanan;
    buatListPesanan(&Lpesanan);

    isiMenu(&Lmenu);



   int pilihan; 
    do{
    cout << "================================" << endl;
    cout << "Selamat Datang di Kisah Kopi"<< endl;
    cout << "================================"<< endl;
    cout << "1. Menambah Pesanan"<< endl;
    cout << "2. Lihat Pesanan"<< endl;
    cout << "3. Hapus Pesanan"<< endl;
    cout << "4. Exit"<< endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    string jawaban;
    switch (pilihan){
    case 1:
        printMenu(Lmenu);
        cout << "pesanan atas nama orang baru atau enggak? (y/n)"<< endl;
        cin >> jawaban;
        if (jawaban == "y"){
            string nama;
            cout << "Masukkan nama pelanggan: ";
            cin >> nama;

            adrPelanggan Pel = buatPelanggan(nama,0);
            insertPelanggan(&Lpelanggan,Pel);

            cout << "Masukkan nomor menu(0 buat kalo selesai): ";
            int pilihanMenu;
            cin >> pilihanMenu;

            while (pilihanMenu != 0){
                adrMenu M = searchMenu(Lmenu,pilihanMenu);
                adrPesanan P = buatPesanan(M,Pel);
                insertPesanan(&Lpesanan,P);
                cout << "Masukkan nomor menu(0 buat kalo selesai): ";
                cin >> pilihanMenu;
            }

            cout << "Pesanan berhasil ditambahkan" << endl;
            cout << "total harga " << Pel->totalHarga << endl;
        } else {
            cout << "masukan nama pelanggan" << endl;
            string namaPel;
            cin >> namaPel;
            adrPelanggan Pel = searchPelanggan(Lpelanggan,namaPel);
            if (Pel == NULL){
                cout << "Pelanggan tidak ditemukan" << endl;
            } else {
                cout << "Masukkan nomor menu(0 buat kalo selesai): ";
                int pilihanMenu;
                cin >> pilihanMenu;

                while (pilihanMenu != 0){
                    adrMenu M = searchMenu(Lmenu,pilihanMenu);
                    adrPesanan P = buatPesanan(M,Pel);
                    insertPesanan(&Lpesanan,P);
                    cout << "Masukkan nomor menu(0 buat kalo selesai): ";
                    cin >> pilihanMenu;
                }

                cout << "Pesanan berhasil ditambahkan" << endl;
                cout << "total harga " << Pel->totalHarga << endl;
            }
        }
        break;
    case 2: {
        adrPesanan P = Lpesanan.firstPesanan;
        if (P == NULL){
            cout << "Tidak ada pesanan" << endl;
        } else {
            printPesanan(Lpesanan);
        }
        break;
    }

    case 3: {
        printPelanggan(Lpelanggan);
    }
    default:
        cout << "Pilihan tidak ada" << endl; 
        break;
        }
   }while (pilihan != 4);
    return 0;
}
