//
//  MLL.h
//  Tubes_STD
//
//  Created by Fadhilla on 01/12/24.
//

#ifndef MLL_h
#define MLL_h

#include <stdio.h>
#include <iostream>
#include <string>
#define first(L) L.first
#define last(L) L.last
#define next(P) P->next
#define prev(P) P->prev
#define info(P) P->info
#define child(P) P->child

using namespace std;

struct parent {
    string merek;
};

struct anak {
    string nama_file;
    string tipe_file;
    int jumlah_halaman;
};

typedef parent infotypePr;
typedef anak infotypeAnak;
typedef struct elmPr *adrPr;
typedef struct elmAnak *adrAnak;

struct elmPr {
    infotypePr info;
    adrPr next;
    adrPr prev;
    adrAnak child;
};

struct elmAnak {
    infotypeAnak info;
    adrAnak next;
};

struct listPr {
    adrPr first;
    adrPr last;
};

struct listAnak {
    adrAnak first;
};

void tampilanmenu();
void pilihInsertPr();

void createListPr(listPr &L);
adrPr createElemenPr(infotypePr X);
void insertFirstP(listPr &L, adrPr P);
void insertLastP(listPr &L, adrPr P);
void showPr(listPr &L);
void deleteFirstParent(listPr &L);
void deleteLastParent(listPr &L);
void deleteAfterParent(listPr &L, adrPr prec);
void deleteParent(listPr &L, string merek);
adrPr findParent(listPr L, string merek);
adrAnak createElemenAnak(infotypeAnak data);
void insertChild(adrPr &P, infotypeAnak data);
void deleteFirstChild(adrPr &P);
void deleteLastChild(adrPr &P);
void deleteAfterChild(adrAnak &prec);
void deleteChild(adrPr &P, string nama_file);
void showAll(listPr L);
int countPages(listPr L);
int countPagesPr(listPr L, adrPr P);
void updateParent(adrPr &P, string newMerek);
void updateChild(adrAnak &C, string newNamaFile, string newTipeFile, int newJumlahHalaman);
adrAnak findChild(adrPr P, string nama_file);

#endif /* MLL_h */
