#include "gojek.h"
#include <iostream>

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

void deleteC(listCustomer &LC, adrCustomer &C, string NoTelp ) {
  C = first(LC);
  while (C != NULL){
    if (info(C).no_telp == NoTelp){
        break;
    }else{
      C = next(C);
    }
  }
  if (C == NULL){
    cout << "Data tidak ditemukan" << endl;
  }else{
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
    cout << "No. Telp: " << info(C).no_telp << endl;
    cout << "Alamat: " << info(C).alamat << endl;
    cout << "-------------------------------------" << endl;
    C = next(C);
    i++;
  }
  cout << endl;
  cout << "=======================================" << endl;
};

void showElmCustomer(listCustomer LC, adrCustomer C){
    cout << "Nama : " << info(C).nama << endl;
    cout << "Alamat : " << info(C).alamat << endl;
    cout << "No. Telp : " << info(C).no_telp << endl;
    cout << "------------------------------------" << endl;
}

void editC(listCustomer &LC, string nama){
  adrCustomer C = searchCustomer(LC, nama);
  
  if (C == NULL){
    cout << "Data customer tidak ditemukan." << endl;
  }else{
    cout << "Data ditemukan" << endl;
    showElmCustomer(LC, C);
    cout << "Masukkan nama baru: "; cin >> info(C).nama;
    cout << "Masukkan alamat baru: "; cin >> info(C).alamat;
    cout << "Masukkan nomor baru: "; cin >> info(C).no_telp; cout << endl;
    cout << "Data berhasil diubah." << endl;
  }
  
};

void showAllCustomerWithDriver(listCustomer LC, listOrder LO) {
  adrCustomer C = first(LC);
  adrOrder O = firstOrder(LO);
  cout << "====[ DAFTAR CUSTOMER DENGAN DRIVER ]====" << endl;
  cout << endl;
  if(C == NULL) {
    cout << "Data customer kosong." << endl;
    return;
  };

  do {
    cout << "Nama: " << info(C).nama << endl;
    cout << "No. Telp: " << info(C).no_telp << endl;
    cout << "Alamat: " << info(C).alamat << endl;
    cout << "====================================" << endl;
    cout << "======[ Related Data Driver ]=====" << endl;
    do {
      if (orderCustomer(O)->info.nama == info(C).nama) {
        cout << "\t| No pol : " << orderDriver(O)->info.no_pol << endl;
        cout << "\t| Nama : " << orderDriver(O)->info.nama << endl;
        cout << "\t| Rating : " << orderDriver(O)->info.rating << endl;
        cout << "\t-------------------------------------" << endl;
      };
      O = next(O);
    } while(O != NULL);

    C = next(C);
  } while (C != first(LC));
};

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
