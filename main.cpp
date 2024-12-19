//
//  main.cpp
//  Tubes_STD
//
//

#include <iostream>
#include "MLL.h"

int main() {
    listPr L;
    int n;
    int pilihan;
    string merek;

    pilihan = 1;
    while (pilihan <= 10) {
        tampilanmenu();
        cin >> pilihan;
        cout << endl;
        
        if (pilihan == 1) {
            pilihInsertPr();
            cin >> pilihan;
            cout << endl;
            while (pilihan > 2){
                cout << "Pilih 1 atau 2" << endl;
                cin >> pilihan;
            }
            
            createListPr(L);
            cout << "------------------------------------------" << endl;
            cout << "Masukkan jumlah Printer : ";
            cin >> n;

            if (pilihan == 1) {
                for (int i = 0; i < n; i++) {
                    infotypePr data;
                    cout << "Masukkan data Printer ke-" << (i + 1) << endl;
                    cin >> data.merek;

                    adrPr P = createElemenPr(data);
                    insertFirstP(L, P);
                    cout << endl;
                }
            } else if (pilihan == 2){
                for (int i = 0; i < n; i++) {
                    infotypePr data;
                    cout << "Masukkan data Printer ke-" << (i + 1) << endl;
                    cin >> data.merek;

                    adrPr P = createElemenPr(data);
                    insertLastP(L, P);
                    cout << endl;
                }
            }
            cout << "Data printer berhasil dimasukkan " << endl;
            cout << "------------------------------------------" << endl;
            cout << endl;
            
        } else if (pilihan == 2) {
            showPr(L);
            cout << endl;
            
        } else if (pilihan == 3) {
            adrPr cari;
            showPr(L);
            cout << "Pilih nama printer yang ingin dihapus " << endl;
            cin >> merek;
            cari = findParent(L, merek);
            if (cari != nullptr) {
                deleteParent(L, merek);
                cout << "Printer dengan merek " << merek << " berhasil dihapus" << endl;
            } else {
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            }
            cout << "------------------------------------------" << endl;
            cout << endl;
            
        } else if (pilihan == 4) {
            adrPr cari;
            cout << "------------------------------------------" << endl;
            cout << "Masukkan merek printer yang ingin dicari " << endl;
            cin >> merek;
            cari = findParent(L, merek);
            if (cari != nullptr) {
                cout << "Printer dengan merek " << merek << " ditemukan" << endl;
            } else {
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            }
            cout << "------------------------------------------" << endl;
            cout << endl;
            
        } else if (pilihan == 5) {
            adrPr cari;
            showPr(L);
            cout << "Pilih printer yang diinginkan " << endl;
            cin >> merek;
            cout << endl;
            cari = findParent(L, merek);
            if (cari != nullptr) {
                cout << "------------------------------------------" << endl;
                cout << "Masukkan jumlah file : ";
                cin >> n;
                cout << "------------------------------------------" << endl;
                cout << endl;
                
                for (int i = 0; i < n; i++) {
                    infotypeAnak data;
                    cout << "------------------------------------------" << endl;
                    cout << "Masukkan file ke-" << (i + 1) << endl;
                    cout << "Masukkan nama file" << endl;
                    cin >> data.nama_file;
                    cout << "Masukkan tipe file" << endl;
                    cin >> data.tipe_file;
                    cout << "Masukkan jumlah halaman file" << endl;
                    cin >> data.jumlah_halaman;
                    cout << "------------------------------------------" << endl;
                    
                    insertChild(cari, data);
                    cout << endl;
                }
                cout << "Data file berhasil dimasukkan" << endl;
            } else {
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            }
            cout << "------------------------------------------" << endl;
            cout << endl;
            
        } else if (pilihan == 6) {
            adrPr cariPr;
            adrAnak cariAnak;
            string newNamaFile, newTipeFile;
            int newJumlahHalaman;
            
            showAll(L);
            cout << "Pilih printer yang ingin diubah " << endl;
            cin >> merek;
            cout << endl;
            cariPr = findParent(L, merek);
            
            if (cariPr == nullptr){
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            } else {
                cout << "------------------------------------------" << endl;
                cout << "Apakah ingin mengubah data printer        " << endl;
                cout << "1. Ya                                     " << endl;
                cout << "2. Tidak                                  " << endl;
                cout << "------------------------------------------" << endl;
                cin >> pilihan;
                cout << endl;
                
                if (pilihan == 1) {
                    cout << "------------------------------------------" << endl;
                    cout << "Masukkan data printer baru " << endl;
                    cin >> merek;
                    updateParent(cariPr, merek);
                    cout << "Data printer berhasil diubah " << endl;
                    cout << "------------------------------------------" << endl;
                    cout << endl;
                }
                
                cout << "------------------------------------------" << endl;
                cout << "Apakah ingin mengubah data file           " << endl;
                cout << "1. Ya                                     " << endl;
                cout << "2. Tidak                                  " << endl;
                cout << "------------------------------------------" << endl;
                cin >> pilihan;
                cout << endl;
                
                if (pilihan == 1) {
                    cout << "------------------------------------------" << endl;
                    cout << "Masukkan nama file yang ingin diubah" << endl;
                    cin >> merek;
                    cout << endl;
                    cariAnak = findChild(cariPr, merek);
                    
                    if (cariAnak != nullptr) {
                        cout << "Masukkan nama file baru" << endl;
                        cin >> newNamaFile;
                        cout << "Masukkan tipe file baru" << endl;
                        cin >> newTipeFile;
                        cout << "Masukkan jumlah halaman file baru" << endl;
                        cin >> newJumlahHalaman;
                        updateChild(cariAnak, newNamaFile, newTipeFile, newJumlahHalaman);
                        cout << "Data tugas printer berhasil diubah " << endl;
                    } else {
                        cout << "File dengan nama " << merek << " tidak ditemukan" << endl;
                    }
            }
        }
            cout << "------------------------------------------" << endl;
            cout << endl;
            
        } else if (pilihan == 7) {
            showAll(L);
            cout << endl;
            
        } else if (pilihan == 8) {
            adrPr cariPr;
            adrAnak cariAnak;
            string carifile;
            
            showPr(L);
            cout << "Pilih printer yang ingin dicari tugasnya " << endl;
            cin >> merek;
            cout << endl;
            cariPr = findParent(L, merek);
            
            if (cariPr == nullptr){
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            } else {
                cout << "Masukkan nama file yang ingin dicari " << endl;
                cin >> carifile;
                cout << endl;
                cariAnak = findChild(cariPr, carifile);
                if (cariAnak != nullptr) {
                    cout << "------------------------------------------" << endl;
                    cout << "File " << carifile << " ditemukan dalam printer " << merek << endl;
                    cout << "Nama File      : " << info(cariAnak).nama_file << endl;
                    cout << "Tipe FIle      : " << info(cariAnak).tipe_file << endl;
                    cout << "Jumlah Halaman : " << info(cariAnak).jumlah_halaman << endl;
                } else {
                    cout << "File " << carifile << " tidak ditemukan dalam printer " << merek << endl;
                }
            }
            cout << "------------------------------------------" << endl;
            cout << endl;
            
            
        } else if (pilihan == 9) {
            adrPr cariPr;
            adrAnak cariAnak;
            string carifile;
            
            showAll(L);
            cout << "Pilih printer yang ingin dihapus tugasnya " << endl;
            cin >> merek;
            cout << endl;
            cariPr = findParent(L, merek);
            
            if (cariPr == nullptr) {
                cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
            } else {
                cout << "Masukkan nama file yang ingin dihapus " << endl;
                cin >> carifile;
                cout << endl;
                cariAnak = findChild(cariPr, carifile);
                if (cariAnak != nullptr) {
                    deleteChild(cariPr, carifile);
                    cout << "File berhasil dihapus" << endl;
                } else {
                    cout << "File " << carifile << " tidak ditemukan dalam printer " << merek << endl;
                }
                cout << "------------------------------------------" << endl;
                cout << endl;
            }
            
        } else if (pilihan == 10) {
            adrPr cari;
            int tp;
            showPr(L);
            cout << "------------------------------------------" << endl;
            cout << "1. Hitung semua page di semua printer" << endl;
            cout << "2. Hitung semua page di printer tertentu" << endl;
            cout << "------------------------------------------" << endl;
            cin >> pilihan;
            cout << endl;
            
            if (pilihan == 1){
                cout << "Total lembar yang dicetak adalah : ";
                tp = countPages(L);
                cout << tp << endl;
            } else if (pilihan == 2) {
                cout << "Pilih printer yang diinginkan " << endl;
                cin >> merek;
                cout << endl;
                cari = findParent(L, merek);
                
                if (cari != nullptr) {
                    cout << "Printer " << merek << " mencetak : ";
                    tp = countPagesPr(L, cari);
                    cout << tp << " Pages" << endl;
                } else {
                    cout << "Printer dengan merek " << merek << " tidak ditemukan" << endl;
                }
            }
            cout << "------------------------------------------" << endl;
        }
    }
}


