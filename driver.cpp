#include "gojek.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// CDLL - Circular Double Linked List

adrDriver createElmD(infoDriver D) {
  adrDriver p = new elmDriver;
  info(p) = D;
  next(p) = NULL;
  prev(p) = NULL;
  return p;
};

void createListD(listDriver &LD) {
  first(LD) = NULL;
  last(LD) = NULL;
};

void insertLastD(listDriver &LD, adrDriver D) {
  if (first(LD) == NULL) {
    first(LD) = D;
    last(LD) = D;
    next(last(LD)) = first(LD);
    prev(first(LD)) = last(LD);
  } else {
    next(last(LD)) = D;
    prev(D) = last(LD);
    last(LD) = D;
    next(last(LD)) = first(LD);
    prev(first(LD)) = last(LD);
  }
};

void editD(listDriver &LD, string no_pol) {
  adrDriver p = first(LD);
  if (first(LD) == NULL) {
    cout << "List Kosong" << endl;
    return;
  };
  do {
    if (info(p).no_pol == no_pol) {
      cout << "No pol : " << info(p).no_pol << endl;
      cout << "Nama : " << info(p).nama << endl;
      cout << "Rating : " << info(p).rating << endl;
      cout << "------------------------------------" << endl;
      cout << "Masukkan nama : ";
      cin >> info(p).nama;
      // Validasi input untuk memastikan input adalah integer
      while (true) {
        cout << "Masukkan rating: ";
        cin >> info(p).rating;
        if (cin.fail()) {
          // Handle kesalahan input yang bukan integer
          cin.clear(); // Membersihkan status error pada cin
          cin.ignore(numeric_limits<streamsize>::max(),
                     '\n'); // Membersihkan buffer hingga newline
          cout << "Rating harus berupa angka. Silakan masukkan kembali."
               << endl;
        } else {
          // Input valid, keluar dari loop
          break;
        }
      }
      cout << "Data berhasil diubah." << endl;
      return;
    };
    p = next(p);
  } while (p != first(LD));
  cout << "Data tidak ditemukan." << endl;
};

// delete
void deleteD(listDriver &LD, adrDriver &D, string no_pol) {
  adrDriver prec;
  adrDriver p = first(LD);
  if (first(LD) == NULL) {
    cout << "List Kosong" << endl;
    return;
  };

  do {
    if (info(p).no_pol == no_pol) {
      D = p;
      prec = prev(p);
      cout << "No pol : " << info(p).no_pol << endl;
      cout << "Nama : " << info(p).nama << endl;
      cout << "Rating : " << info(p).rating << endl;
      cout << "------------------------------------" << endl;
      if (p == first(LD)) {
        deleteFirstD(LD, D);
      } else if (p == last(LD)) {
        deleteLastD(LD, D);
      } else {
        deleteAfterD(LD, D, prec);
      };
      cout << "Data berhasil dihapus." << endl;
      return;
    };
    p = next(p);
  } while (p != first(LD));
  cout << "Data tidak ditemukan." << endl;
};

void deleteFirstD(listDriver &LD, adrDriver &D) {
  if (first(LD) == NULL) {
    cout << "Data kosong." << endl;
  } else if (next(first(LD)) == first(LD)) {
    D = first(LD);
    first(LD) = NULL;
  } else {
    D = first(LD);
    first(LD) = next(D);
    next(last(LD)) = first(LD);
    prev(first(LD)) = last(LD);
  };
};

void deleteAfterD(listDriver &LD, adrDriver &D, adrDriver prec) {
  if (first(LD) == NULL) {
    cout << "Data kosong." << endl;
  } else {
    D = next(prec);
    next(prec) = next(D);
    prev(next(D)) = prec;
  };
};

void deleteLastD(listDriver &LD, adrDriver &D) {
  if (first(LD) == NULL) {
    cout << "Data kosong." << endl;
  } else if (next(last(LD)) == last(LD)) {
    D = last(LD);
    last(LD) = NULL;
  } else {
    D = last(LD);
    last(LD) = prev(D);
    next(last(LD)) = first(LD);
    prev(first(LD)) = last(LD);
  };
};

// cari driver
adrDriver searchDriver(listDriver LD, string namaDriver) {
  adrDriver D = first(LD);
  do {
    if (info(D).nama == namaDriver) {
      return D;
    };
    D = next(D);
  } while (D != first(LD));

  return NULL;
};

// show driver
void showDriver(listDriver LD) {
  adrDriver p = first(LD);
  int i = 1;
  cout << "==========[ DAFTAR DRIVER ]=========" << endl;
  cout << endl;
  if (p == NULL) {
    cout << "Data kosong." << endl;
  } else {
    do {
      cout << "[" << i << "]" << endl;
      cout << "No pol : " << info(p).no_pol << endl;
      cout << "Nama : " << info(p).nama << endl;
      cout << "Rating : " << info(p).rating << endl;
      cout << "------------------------------------" << endl;
      p = next(p);
      i++;
    } while (p != first(LD));
  };
  cout << endl;
  cout << "====================================" << endl;
};

void showDriverByCustomer(listCustomer LC, listOrder LO, string namaCustomer) {
  bool found = false;
  adrCustomer C = searchCustomer(LC, namaCustomer);
  if (C == NULL) {
    cout << "Data customer tidak ditemukan." << endl;
    return;
  };
  cout << endl;
  cout << "=============[ Data Customer ]===============" << endl;
  cout << "Nama : " << info(C).nama << endl;
  cout << "Alamat : " << info(C).alamat << endl;
  cout << "No telp : " << info(C).no_telp << endl;
  cout << endl;
  cout << "==========[ Related Data Driver ]============" << endl;
  adrOrder O = firstOrder(LO);
  if (O == NULL) {
    cout << "Tidak ada data order." << endl;
    cout << endl;
    cout << "=============================================" << endl;
    return;
  };
  while (O != NULL) {
    if (orderCustomer(O) == C) {
      cout << "\t| No pol : " << orderDriver(O)->info.no_pol << endl;
      cout << "\t| Nama : " << orderDriver(O)->info.nama << endl;
      cout << "\t| Rating : " << orderDriver(O)->info.rating << endl;
      cout << "\t-------------------------------------" << endl;
      found = true;
    };
    O = next(O);
  };
  if (!found) {
    cout << "Driver ini belum pernah order." << endl;
  };
  cout << endl;
  cout << "============================================" << endl;
};

void showAllDriverWithCustomer(listDriver LD, listOrder LO) {
  adrDriver D = first(LD);
  bool found = false;
  cout << "======[ DAFTAR DRIVER DENGAN CUSTOMER ]=======" << endl;
  if (D == NULL) {
    cout << "Data driver kosong." << endl;
    return;
  };
  do {
    cout << endl;
    cout << "===============[ Data Driver ]================" << endl;
    cout << "No pol : " << info(D).no_pol << endl;
    cout << "Nama : " << info(D).nama << endl;
    cout << "Rating : " << info(D).rating << endl;
    cout << "===========[ Related Data Customer ]==========" << endl;
    adrOrder O = firstOrder(LO);
    if (O == NULL) {
      cout << "Tidak ada data order." << endl;
      cout << endl;
      cout << "====================================" << endl;
      return;
    };
    do {
      if (orderDriver(O)->info.nama == info(D).nama) {
        cout << "\t| Nama: " << info(orderCustomer(O)).nama << endl;
        cout << "\t| No. Telp: " << info(orderCustomer(O)).no_telp << endl;
        cout << "\t| Alamat: " << info(orderCustomer(O)).alamat << endl;
        cout << "\t-------------------------------------" << endl;
        found = true;
      };
      O = next(O);
    } while (O != firstOrder(LO) && O != NULL);
    if (!found) {
      cout << "Driver ini belum pernah order." << endl;
    }
    found = false;
    D = next(D);
  } while (D != first(LD));
  cout << endl;
  cout << "==============================================" << endl;
};

/*
Fauzan_Majid
5
D_3221_AB

Daffa_Rifalq
4
D_1341_AB

Kunto_Aji
5
D_2321_AB
*/