#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    infotype x;
    address P;
    CreateList(L);

    
    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.thnBuat;

        if (findElm(L, x) != NULL) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            P = alokasi(x);
            insertFirst(L, P);
        }
        cout << endl;
    }

    printInfo(L);

    
    cout << endl << "Masukkan Nomor Polisi yang dicari : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P != NULL) {
        cout << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    
    cout << endl << "Masukkan Nomor Polisi yang akan dihapus : ";
    cin >> x.nopol;
    P = findElm(L, x);
    if (P == NULL) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        address hapus;
        if (P == L.First) {
            deleteFirst(L, hapus);
        } else if (P == L.Last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(P->prev, hapus);
        }
        cout << "Data dengan nomor polisi " << hapus->info.nopol
             << " berhasil dihapus." << endl;
        dealokasi(hapus);
    }

    printInfo(L);
    return 0;
}