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
    cout << "3. Mencari data"<< endl;
    cout << "4. Exit"<< endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    string jawaban;
    switch (pilihan){
    case 1:
       clear();
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
                clear();
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
                clear();
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
                clear();
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
                   
                    cout << "Masukkan nomor menu yang ingin dipesan:(0 berhenti) ";
                    int nomorMenu;
                    cin >> nomorMenu;
                    while (nomorMenu != 0 ){
                        adrMenu M = searchMenu(Lmenu, nomorMenu);
                        if (M == NULL){
                            cout << "Menu tidak ditemukan" << endl;
                            break;
                        }
                        adrPesanan Pp = buatPesanan(M, P);
                        insertPesanan(&Lpesanan, Pp);
                        cout << "Pesanan berhasil ditambahkan" << endl;
                        cout << "Masukkan nomor menu yang ingin dipesan:(0 berhenti) ";
                        cin >> nomorMenu;
                    }
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
                    while (nomorMenu != 0){
                        adrMenu M = searchMenu(Lmenu, nomorMenu);
                        if (M == NULL){
                            cout << "Menu tidak ditemukan" << endl;
                            break;
                        }
                        adrPesanan Pp = buatPesanan(M, P);
                        insertPesanan(&Lpesanan, Pp);
                        cout << "Pesanan berhasil ditambahkan" << endl;
                        cout << "Masukkan nomor menu yang ingin dipesan:(0 berhenti) ";
                        cin >> nomorMenu;
                    }
                }
                break;
            }
        }
       break;
    case 2: {
        clear();
        cout << "pengen print paan ?" << endl;
        cout << "1. Menu" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "3. Pesanan" << endl;
        cout << "Pilihan: ";
        int PilihPrint;
        cin >> PilihPrint;
        switch (PilihPrint){
            case 1: {
                clear();
                printMenu(Lmenu);
                break;
            }
            case 2: {
                clear();
                printPelanggan(Lpelanggan);
                break;
            }
            case 3: {
                clear();
                printPesanan(Lpesanan);
                break;
            }
            break;
        }
        break;
    }

    case 3: {
        clear();
        cout << "Mau cari apa ?" << endl;
        cout << "1. Menu" << endl;
        cout << "2. Pelanggan" << endl;
        cout << "Pilihan: ";
        int PilihCari;
        cin >> PilihCari;
        switch (PilihCari){
            case 1 :{
                clear();
                cout << "ingin mencari menu berdasrkan apa ?" << endl;
                cout << "1. Nama" << endl;
                cout << "2. harga " << endl;
                cout << "3. menu yang di pesan oleh pelanggan atas nama siapa gitu" << endl;
                cout << "Pilihan: ";
                int PilihCariMenu;
                cin >> PilihCariMenu;
                switch (PilihCariMenu){
                    case 1:{
                        clear();
                        cout << "Masukkan nama menu yang ingin dicari: ";
                        string namaMenu;
                        cin >> namaMenu;
                        adrMenu M = cariMenu(Lmenu, namaMenu);
                        if (M == NULL){
                            cout << "Menu tidak ditemukan" << endl;
                            break;
                        }else {
                            cout << "Menu ditemukan" << endl;
                            cout << "Nama: " << M->Nama << endl;
                            cout << "Harga: " << M->harga << endl;
                        }
                        break;
                    }
                    case 2:{
                        clear();
                        cout << "Masukkan harga menu yang ingin dicari: ";
                        int hargaMenu;
                        cin >> hargaMenu;
                        carimenuHarga(Lmenu, hargaMenu);
                        break; 
                    }
                    case 3:{
                        clear();
                        cout << "Masukkan nama pelanggan: ";
                        string namaPelanggan;
                        cin >> namaPelanggan;
                        adrPelanggan P = searchPelanggan(Lpelanggan, namaPelanggan);
                        if (P == NULL){
                            cout << "Pelanggan tidak ditemukan" << endl;
                            break;
                        }else {
                            cariMenuPelanggan(Lpesanan, P);
                        }
                        break;
                    }
                    break; 
                }
                break;
            }
            case 2 :{
                clear();
                cout << "ingin mencari pelanggan berdasrkan apa ?" << endl;
                cout << "1. Nama" << endl;
                cout << "2. Total Harga" << endl;
                cout << "3. Menu yang dipesan" << endl;
                cout << "Pilihan: ";
                int PilihCariPelanggan; 
                cin >> PilihCariPelanggan;
                switch(PilihCariPelanggan){
                    case 1: {
                        clear();
                        cout << "Masukkan nama pelanggan yang ingin dicari: ";
                        string namaPelanggan;
                        cin >> namaPelanggan;
                        adrPelanggan P = searchPelanggan(Lpelanggan, namaPelanggan);
                        if (P == NULL){
                            cout << "Pelanggan tidak ditemukan" << endl;
                            break;
                        }else {
                            cout << "Pelanggan ditemukan" << endl;
                            cout << "Nama: " << P->nama << endl;
                            cout << "Total Harga: " << P->totalHarga << endl;
                        }
                        break; 
                    }
                    case 2: {
                        clear();
                        cout << "Masukkan total harga pelanggan yang ingin dicari: ";
                        int totalHarga;
                        cin >> totalHarga;
                        cariHargaPelanggan(Lpelanggan, totalHarga);
                        break;

                    }
                    case 3: {
                        clear();
                        printMenu(Lmenu);
                        cout << "Masukan nama Menu: ";
                        string namaMenu;
                        cin >> namaMenu;
                        adrMenu M = cariMenu(Lmenu, namaMenu);
                        if (M == NULL){
                            cout << "Menu tidak ditemukan" << endl;
                            break;
                        }else {
                            cariMenuPelanggan(Lpesanan, M);
                        }
                        break;
                    }
                    break; 
                }
                break;
            }
            break;
        }
        break;
    }
    default:
        cout << "Pilihan tidak ada" << endl; 
        break;
        }
   }while (pilihan != 4);
    return 0;
}
