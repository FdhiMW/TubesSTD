//
//  MLL.cpp
//  Tubes_STD
//
//

#include <stdio.h>
#include "MLL.h"

void tampilanmenu(){
    cout << "------------------------------------------" << endl;
    cout << "1. Masukkan data printer                  " << endl;
    cout << "2. Tampilkan data printer                 " << endl;
    cout << "3. Hapus data printer                     " << endl;
    cout << "4. Mencari Printer                        " << endl;
    cout << "5. Masukkan data tugas printer            " << endl;
    cout << "6. Ubah data printer / file               " << endl;
    cout << "7. Tenampilkan seluruh data               " << endl;
    cout << "8. Mencari file pada printer tertentu     " << endl;
    cout << "9. Menghapus file pada printer tertentu   " << endl;
    cout << "10. Menghitung banyak lembar yang dicetak " << endl;
    cout << "11. Exit                                  " << endl;
    cout << "------------------------------------------" << endl;
}

void pilihInsertPr(){
    cout << "------------------------------------------" << endl;
    cout << "1. Masukkan dari depan                    " << endl;
    cout << "2. Masukkan dari belakang                 " << endl;
    cout << "------------------------------------------" << endl;
}

void createListPr(listPr &L) {
    //I.S. listPr L Belum diinisialisasi
    //F.S. listPr L Kosong
    first(L) = nullptr;
    last(L) = nullptr;
}

adrPr createElemenPr(infotypePr X) {
    //I.S. Input berupa data printer X yang akan dimasukkan.
    //F.S. Mengembalikan address P yang berisi data X
    adrPr P = new elmPr;
    info(P) = X;
    next(P) = nullptr;
    prev(P) = nullptr;
    return P;
}

void insertFirstP(listPr &L, adrPr P){
    if (first(L) == nullptr) {
        first(L) = P;
        last(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLastP(listPr &L, adrPr P) {
    //I.S. listPr L bisa kosong atau sudah terisi
    //F.S. Menambahkan elemen P diakhir list
    if (first(L) == nullptr && last(L) == nullptr) {
        first(L) = P;
        last(L) = P;
    } else {
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void showPr(listPr &L) {
    //I.S. listPr L bisa kosong atau sudah terisi
    //F.S. Semua data di elemen-elemen list ditampilkan ke layar, satu per satu, hingga akhir list.
    adrPr P = first(L);
    cout << "------------------------------------------" << endl;
    cout << "Daftar Printer :" << endl;
    while (P != nullptr) {
        cout << "Merek Printer: " << info(P).merek << endl;
        P = next(P);
    }
    cout << "------------------------------------------" << endl;
}

void deleteFirstParent(listPr &L) {
    if (first(L) != nullptr) {
        adrPr P = first(L);
        if (first(L) == last(L)) {
            first(L) = nullptr;
            last(L) = nullptr;
        } else {
            first(L) = next(P);
            prev(first(L)) = nullptr;
        }
        adrAnak C = child(P);
        while (C != nullptr) {
            adrAnak temp = C;
            C = next(C);
            delete temp;
        }
        delete P;
    }
}

void deleteLastParent(listPr &L) {
    if (first(L) != nullptr) {
        adrPr P = last(L);
        if (first(L) == last(L)) {
            first(L) = nullptr;
            last(L) = nullptr;
        } else {
            last(L) = prev(P);
            next(last(L)) = nullptr;
        }
        adrAnak C = child(P);
        while (C != nullptr) {
            adrAnak temp = C;
            C = next(C);
            delete temp;
        }
        delete P;
    }
}

void deleteAfterParent(listPr &L, adrPr prec) {
    if (prec != nullptr && next(prec) != nullptr) {
        adrPr P = next(prec);
        if (P == last(L)) {
            last(L) = prec;
            next(prec) = nullptr;
        } else {
            next(prec) = next(P);
            prev(next(P)) = prec;
        }
        adrAnak C = child(P);
        while (C != nullptr) {
            adrAnak temp = C;
            C = next(C);
            delete temp;
        }
        delete P;
    }
}

void deleteParent(listPr &L, string merek) {
    adrPr P = first(L);
    while (P != nullptr && info(P).merek != merek) {
        P = next(P);
    }
    if (P != nullptr) {
        if (P == first(L)) {
            deleteFirstParent(L);
        } else if (P == last(L)) {
            deleteLastParent(L);
        } else {
            deleteAfterParent(L, prev(P));
        }
    }
}

adrPr findParent(listPr L, string merek) {
    adrPr P = first(L);
    while (P != nullptr && info(P).merek != merek) {
        P = next(P);
    }
    return P;
}

adrAnak createElemenAnak(infotypeAnak data) {
    adrAnak C = new elmAnak;
    info(C) = data;
    next(C) = nullptr;
    return C;
}

void insertChild(adrPr &P, infotypeAnak data) {
    if (P == nullptr) return;
    adrAnak C = createElemenAnak(data);
    if (child(P) == nullptr) {
        child(P) = C;
    } else {
        adrAnak Q = child(P);
        while (next(Q) != nullptr) {
            Q = next(Q);
        }
        next(Q) = C;
    }
}

void deleteFirstChild(adrPr &P) {
    if (P != nullptr && child(P) != nullptr) {
        adrAnak C = child(P);
        child(P) = next(C);
        delete C;
    }
}

void deleteLastChild(adrPr &P) {
    if (P != nullptr && child(P) != nullptr) {
        adrAnak C = child(P);
        if (next(C) == nullptr) {
            child(P) = nullptr;
            delete C;
        } else {
            adrAnak prevC = nullptr;
            while (next(C) != nullptr) {
                prevC = C;
                C = next(C);
            }
            next(prevC) = nullptr;
            delete C;
        }
    }
}

void deleteAfterChild(adrAnak &prec) {
    if (prec != nullptr && next(prec) != nullptr) {
        adrAnak C = next(prec);
        next(prec) = next(C);
        delete C;
    }
}

void deleteChild(adrPr &P, string nama_file) {
    if (P == nullptr) return;
    adrAnak C = child(P);
    if (C != nullptr && info(C).nama_file == nama_file) {
        deleteFirstChild(P);
    } else {
        adrAnak prevC = nullptr;
        while (C != nullptr && info(C).nama_file != nama_file) {
            prevC = C;
            C = next(C);
        }
        if (C != nullptr) {
            if (next(C) == nullptr) {
                deleteLastChild(P);
            } else {
                deleteAfterChild(prevC);
            }
        }
    }
}

void showAll(listPr L) {
    adrPr P = first(L);
    while (P != nullptr) {
        cout << "------------------------------------------" << endl;
        cout << "Printer: " << info(P).merek << endl;
        adrAnak C = child(P);
        while (C != nullptr) {
            cout << "  File: " << info(C).nama_file << " | Type: " << info(C).tipe_file << " | Pages: " << info(C).jumlah_halaman << endl;
            C = next(C);
        }
        cout << "------------------------------------------" << endl;
        P = next(P);
    }
}

int countPages(listPr L) {
    int totalPages = 0;
    adrPr P = first(L);
    while (P != nullptr) {
        adrAnak C = child(P);
        while (C != nullptr) {
            totalPages += info(C).jumlah_halaman;
            C = next(C);
        }
        P = next(P);
    }
    return totalPages;
}

int countPagesPr(listPr L, adrPr P){
    int totalPages = 0;
    adrAnak C = child(P);
    while (C != nullptr) {
        totalPages += info(C).jumlah_halaman;
        C = next(C);
    }
    return totalPages;
}

void updateParent(adrPr &P, string newMerek) {
    if (P != nullptr) {
        info(P).merek = newMerek;
    }
}

void updateChild(adrAnak &C, string newNamaFile, string newTipeFile, int newJumlahHalaman) {
    if (C != nullptr) {
        info(C).nama_file = newNamaFile;
        info(C).tipe_file = newTipeFile;
        info(C).jumlah_halaman = newJumlahHalaman;
    }
}

adrAnak findChild(adrPr P, string nama_file) {
    if (P == nullptr) return nullptr;
    adrAnak C = child(P);
    while (C != nullptr && info(C).nama_file != nama_file) {
        C = next(C);
    }
    return C;
}
