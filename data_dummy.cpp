#include "gojek.h"
#include <iostream>
using namespace std;

void data_dummy(listDriver &LD, listOrder &LO, listCustomer &LC, adrDriver &D,
                adrCustomer &C) {
  infoDriver ID;
  infoCust IC;

  // insert driver
  ID.nama = "Fauzan_Majid";
  ID.rating = 5;
  ID.no_pol = "D_3221_AB";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Daffa_Rifalq";
  ID.rating = 4;
  ID.no_pol = "D_1341_AB";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Kunto_Aji";
  ID.rating = 5;
  ID.no_pol = "D_2321_AB";
  D = createElmD(ID);
  insertLastD(LD, D);

  // insert customer
  IC.nama = "Kevin_Izzan";
  IC.alamat = "Universitas_Telkom";
  IC.no_telp = "0856591262";
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Azrian_Rifqi";
  IC.alamat = "23_Paskal_Shopping_Centre";
  IC.no_telp = "0816704572";
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Budi_Setiawan";
  IC.alamat = "Jln_Jati_Padang_Baru_19";
  IC.no_telp = "0236351380";
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Irwan_Saputra";
  IC.alamat = "Jln_Panatayuda_2";
  IC.no_telp = "0236203801";
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  // insert order
  // insertOrder(LD, LC, LO, "Fauzan_Majid", "Budi_Setiawan");
  // insertOrder(LD, LC, LO, "Fauzan_Majid", "Azrian_Rifqi");
}