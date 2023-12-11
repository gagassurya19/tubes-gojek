#include "gojek.h"
#include <iostream>
#include <limits>
#include <string>

using namespace std;

adrCustomer createElmCust(infoCust X) {
  adrCustomer C = new elmCustomer;
  info(C) = X;
  next(C) = NULL;
  return C;
};

void createListCust(listCustomer &LC) { first(LC) = NULL; };

void insertLastCustomer(listCustomer &LC, adrCustomer C) {
  if (first(LC) == NULL) {
    first(LC) = C;

  } else {
    adrCustomer Q = first(LC);
    while (next(Q) != NULL) {
      Q = next(Q);
    }
    next(Q) = C;
  }
};

void deleteC(listCustomer &LC, adrCustomer &C, int NoTelp) {
  C = first(LC);
  while (C != NULL) {
    if (info(C).no_telp == NoTelp) {
      break;
    } else {
      C = next(C);
    }
  }
  if (C == NULL) {
    cout << "Data tidak ditemukan" << endl;
  } else {
    if (C == first(LC)) {
      deleteFirstC(LC, C);

    } else if (next(C) != NULL) {
      adrCustomer prec = first(LC);
      while (next(prec) != C) {
        prec = next(prec);
      }
      deleteAfterC(LC, C, prec);

    } else {
      deleteLastC(LC, C);
    }
    cout << "Data berhasil dihapus" << endl;
  }
};

// delete
void deleteFirstC(listCustomer &LC, adrCustomer &C) {
  if (first(LC) == NULL) {
    cout << "Data kosong." << endl;

  } else if (next(first(LC)) == NULL) {
    C = first(LC);
    first(LC) = NULL;

  } else {
    C = first(LC);
    first(LC) = next(C);
    next(C) = NULL;
  }
};

void deleteAfterC(listCustomer &LC, adrCustomer &C, adrCustomer prec) {
  C = next(prec);
  next(prec) = next(C);
  next(C) = NULL;
};

void deleteLastC(listCustomer &LC, adrCustomer &C) {
  if (first(LC) == NULL) {
    cout << "Data kosong." << endl;

  } else if (next(first(LC)) == NULL) {
    C = first(LC);
    first(LC) = NULL;

  } else {
    adrCustomer Q = first(LC);
    while (next(next(Q)) != NULL) {
      Q = next(Q);
    }
    C = next(Q);
    next(Q) = NULL;
  }
};

// cari customer
adrCustomer searchCustomer(listCustomer LC, string nama) {
  adrCustomer C = first(LC);
  bool found = false;
  while (C != NULL && !found) {
    if (info(C).nama == nama) {
      found = true;
      return C;
    } else {
      C = next(C);
    }
  }
  return NULL;
};

// show customer
void showCustomer(listCustomer LC) {
  adrCustomer C = first(LC);
  int i = 1;
  cout << "==========[ DAFTAR CUSTOMER ]==========" << endl;
  cout << endl;
  while (C != NULL) {
    cout << "[" << i << "]" << endl;
    cout << "Nama: " << info(C).nama << endl;
    cout << "No. Telp: +62" << info(C).no_telp << endl;
    cout << "Alamat: " << info(C).alamat << endl;
    cout << "-------------------------------------" << endl;
    C = next(C);
    i++;
  }
  cout << endl;
  cout << "=======================================" << endl;
};

void showElmCustomer(listCustomer LC, adrCustomer C) {
  cout << "Nama : " << info(C).nama << endl;
  cout << "Alamat : " << info(C).alamat << endl;
  cout << "No. Telp : +62" << info(C).no_telp << endl;
  cout << "------------------------------------" << endl;
}

void editC(listCustomer &LC, string nama) {
  adrCustomer C = searchCustomer(LC, nama);

  if (C == NULL) {
    cout << "Data customer tidak ditemukan." << endl;
  } else {
    cout << "Data ditemukan" << endl;
    showElmCustomer(LC, C);
    cout << "Masukkan nama baru: ";
    cin >> info(C).nama;
    cout << "Masukkan alamat baru: ";
    cin >> info(C).alamat;
    // Validasi input untuk memastikan input adalah integer
    while (true) {
      cout << "Masukkan nomor baru: ";
      cin >> info(C).no_telp;
      if (cin.fail()) {
        // Handle kesalahan input yang bukan integer
        cin.clear(); // Membersihkan status error pada cin
        cin.ignore(numeric_limits<streamsize>::max(),
                   '\n'); // Membersihkan buffer hingga newline
        cout << "nomor telp harus berupa angka. Silakan masukkan kembali."
             << endl;
      } else {
        // Input valid, keluar dari loop
        break;
      }
    }
    cout << endl;
    cout << "Data berhasil diubah." << endl;
  }
};

void showCustomerByDriver(listDriver LD, listOrder LO, string namaDriver) {
  bool found = false;
  adrDriver D = searchDriver(LD, namaDriver);
  if (D == NULL) {
    cout << "Data Driver tidak ditemukan." << endl;
    return;
  };
  cout << endl;
  cout << "=============[ Data Driver ]===============" << endl;
  cout << "Nama : " << info(D).nama << endl;
  cout << "Plat Nomor : " << info(D).no_pol << endl;
  cout << "Rating : +62" << info(D).rating << endl;
  cout << endl;
  cout << "==========[ Related Data Customer ]============" << endl;
  adrOrder O = firstOrder(LO);
  if (O == NULL) {
    cout << "Tidak ada data order." << endl;
    cout << endl;
    cout << "=============================================" << endl;
    return;
  };
  while (O != NULL) {
    if (orderDriver(O) == D) {
      cout << "\t| Nama : " << orderCustomer(O)->info.nama << endl;
      cout << "\t| No Telp : +62" << orderCustomer(O)->info.no_telp << endl;
      cout << "\t| Alamat : " << orderCustomer(O)->info.alamat << endl;
      cout << "\t-------------------------------------" << endl;
      found = true;
    };
    O = next(O);
  };
  if (!found) {
    cout << "Driver ini belum pernah narik." << endl;
  };
  cout << endl;
  cout << "============================================" << endl;
};

void showAllCustomerWithDriver(listCustomer LC, listOrder LO) {
  bool found = false;
  adrCustomer C = first(LC);
  cout << "======[ DAFTAR CUSTOMER DENGAN DRIVER ]=======" << endl;
  if (C == NULL) {
    cout << "Data customer kosong." << endl;
    return;
  };
  while (C != NULL) {
    cout << endl;
    cout << "==============[ Data Customer ]===============" << endl;
    cout << "Nama: " << info(C).nama << endl;
    cout << "No. Telp: +62" << info(C).no_telp << endl;
    cout << "Alamat: " << info(C).alamat << endl;
    cout << "============[ Related Data Driver ]===========" << endl;
    adrOrder O = firstOrder(LO);
    if (O == NULL) {
      cout << "Tidak ada data order." << endl;
      cout << endl;
      cout << "============================================" << endl;
      return;
    };
    do {
      if (orderCustomer(O) == C) {
        cout << "\t| No pol : " << orderDriver(O)->info.no_pol << endl;
        cout << "\t| Nama : " << orderDriver(O)->info.nama << endl;
        cout << "\t| Rating : " << orderDriver(O)->info.rating << endl;
        cout << "\t-------------------------------------" << endl;
        found = true;
      };
      O = next(O);
    } while (O != NULL);
    if (!found) {
      cout << "Customer ini belum pernah order." << endl;
    }
    found = false;
    C = next(C);
  };
  cout << endl;
  cout << "==============================================" << endl;
};

void countDriverByCustomer(listDriver LD, listOrder LO, listCustomer LC,
                           string namaCustomer) {
  adrCustomer C = searchCustomer(LC, namaCustomer);
  adrOrder O = firstOrder(LO);

  int count = 0;
  if (C == NULL) {
    cout << "Data customer tidak ditemukan." << endl;
    return;
  } else {
    while (O != NULL) {
      if (orderCustomer(O) == C) {
        count++;
      }
      O = next(O);
    }
    cout << "Customer " << info(C).nama << " memiliki driver: " << count
         << endl;
  }
};

void countCustomerByDriver(listDriver LD, listOrder LO, listCustomer LC,
                           string namaDriver) {
  adrDriver D = searchDriver(LD, namaDriver);
  adrOrder O = firstOrder(LO);

  int count = 0;
  if (D == NULL) {
    cout << "Data driver tidak ditemukan." << endl;
    return;
  } else {
    while (O != NULL) {
      if (orderDriver(O) == D) {
        count++;
      }
      O = next(O);
    }
    cout << "Driver " << info(D).nama << " memiliki customer: " << count
         << endl;
  }
};

void countDriverNoOrder(listDriver LD, listOrder LO, listCustomer LC) {
  adrDriver D = first(LD);
  int count = 0;

  do {
    adrOrder O = firstOrder(LO); // Reset O to the first order for each driver
    bool hasOrder = false;

    while (O != NULL) {
      if (orderDriver(O) == D) {
        hasOrder = true;
        break; // Break the loop if the driver has an order
      }
      O = next(O);
    }

    if (!hasOrder) {
      count++;
    }

    D = next(D);
  } while (D != first(LD));

  cout << "Jumlah driver yang tidak memiliki order: " << count << endl;
}

void countCustomerNoOrder(listDriver LD, listOrder LO, listCustomer LC) {
  adrCustomer C = first(LC);
  int count = 0;

  while (C != NULL) {
    adrOrder O = firstOrder(LO); // Reset O to the first order for each customer
    bool hasOrder = false;

    while (O != NULL) {
      if (orderCustomer(O) == C) {
        hasOrder = true;
        break; // Break the loop if the customer has an order
      }
      O = next(O);
    }

    if (!hasOrder) {
      count++;
    }

    C = next(C);
  }

  cout << "Jumlah customer yang tidak memiliki order: " << count << endl;
}

/*
Kevin_izzan
Universitas_Telkom
0856591262

Azrian_Rifqi
23_Paskal_Shopping_Centre
0816704572

Budi_Setiawan
Jln_Jati_Padang_Baru_19
0823620380

Siti_Nurul
GOR_Saparua
0834394034

Fahran_Darmawan
Jln_Arcamanik_Endah
0829498374

Aditya_Ramadhan
Jln_Panatayuda_No_14
0882137123
*/
