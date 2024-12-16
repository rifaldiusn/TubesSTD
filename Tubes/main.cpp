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
    cout << "1. Menambah data"<< endl;
    cout << "2. Print data"<< endl;
    cout << "3. Hapus Pesanan"<< endl;
    cout << "4. Exit"<< endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    string jawaban;
    switch (pilihan){
    case 1:
        cout << "ingin menambahkan data apa ?" << endl;
        cout << "1. Menu" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "3. Pesanan" << endl;
        cout << "Pilihan: ";
        int PilihNambah;
        cin >> PilihNambah;
        cout << endl;
        switch (PilihNambah){
            case 1:{
                string NamaMenu;
                int hargaMenu;
                cout << "Masukkan Nama Menu: ";
                cin >> NamaMenu;
                cout << "Masukkan Harga Menu: ";
                cin >> hargaMenu;
                if (cariMenu(Lmenu, NamaMenu) != NULL){
                    cout << "Menu sudah ada" << endl;
                    break;
                }
                adrMenu M = buatMenu(NamaMenu, hargaMenu);
                insertMenu(&Lmenu, M);
                cout << "Menu berhasil ditambahkan" << endl;
                break;
            }
            case 2:{
                string namaPelanggan;
                cout << "Masukkan Nama Pelanggan: ";
                cin >> namaPelanggan;
                searchPelanggan(Lpelanggan, namaPelanggan);
                if (searchPelanggan(Lpelanggan, namaPelanggan) != NULL){
                    cout << "Pelanggan sudah ada" << endl;
                    break;
                }
                adrPelanggan P = buatPelanggan(namaPelanggan, 0);
                insertPelanggan(&Lpelanggan, P);
                cout << "Pelanggan berhasil ditambahkan" << endl;
                break;
            }
            case 3:{
                printMenu(Lmenu);
                cout << "ini orang baru atau bukan yang pesen ?(y/n)" << endl;
                string answerMe;
                cin >> answerMe;
                if (answerMe == "y"){
                    string namaPelanggan;
                    cout << "Masukkan Nama Pelanggan: ";
                    cin >> namaPelanggan;

                    adrPelanggan P = buatPelanggan(namaPelanggan, 0);
                    insertPelanggan(&Lpelanggan, P);
                   
                    cout << "Masukkan nomor menu yang ingin dipesan: ";
                    int nomorMenu;
                    cin >> nomorMenu;
                    adrMenu M = searchMenu(Lmenu, nomorMenu);
                    if (M == NULL){
                        cout << "Menu tidak ditemukan" << endl;
                        break;
                    }
                    adrPesanan Pp = buatPesanan(M, P);
                    insertPesanan(&Lpesanan, Pp);
                    cout << "Pesanan berhasil ditambahkan" << endl;
                }else {
                    printPelanggan(Lpelanggan);
                    cout << "Masukkan nama pelanggan yang sudah ada: ";
                    string namaPelanggan;
                    cin >> namaPelanggan;
                    adrPelanggan P = searchPelanggan(Lpelanggan, namaPelanggan);
                    if (P == NULL){
                        cout << "Pelanggan tidak ditemukan" << endl;
                        break;
                    }
                    cout << "Masukkan nomor menu yang ingin dipesan: ";
                    int nomorMenu;
                    cin >> nomorMenu;
                    adrMenu M = searchMenu(Lmenu, nomorMenu);
                    if (M == NULL){
                        cout << "Menu tidak ditemukan" << endl;
                        break;
                    }
                    adrPesanan Pp = buatPesanan(M, P);
                    insertPesanan(&Lpesanan, Pp);
                    cout << "Pesanan berhasil ditambahkan" << endl;
                }
                break;
            }
        }
       break;
    case 2: {
        cout << "pengen print paan ?" << endl;
        cout << "1. Menu" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "3. Pesanan" << endl;
        cout << "Pilihan: ";
        int PilihPrint;
        cin >> PilihPrint;
        switch (PilihPrint){
            case 1: {
                printMenu(Lmenu);
                break;
            }
            case 2: {
                printPelanggan(Lpelanggan);
                break;
            }
            case 3: {
                printPesanan(Lpesanan);
                break;
            }
            break;
        }

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
