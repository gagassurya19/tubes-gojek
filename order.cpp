#include "gojek.h"
#include <iostream>

using namespace std;

adrOrder createElmOrder(adrDriver D, adrCustomer C) {
  adrOrder O = new elmOrder;
  orderDriver(O) = D;
  orderCustomer(O) = C;
  next(O) = NULL;
  prev(O) = NULL;
  return O;
};

void createListOrder(listOrder &L) {
  firstOrder(L) = NULL;
  lastOrder(L) = NULL;
};

void insertOrderDummy(listDriver LD, listCustomer LC, listOrder &LO,
                      string namaDriver, string namaCustomer) {

  adrDriver D = searchDriver(LD, namaDriver);
  adrCustomer C = searchCustomer(LC, namaCustomer);
  if (D != NULL && C != NULL) {
    adrOrder O = createElmOrder(D, C);
    if (O != NULL) {
      if (firstOrder(LO) == NULL) {
        firstOrder(LO) = O;
        lastOrder(LO) = O;
      } else {
        next(lastOrder(LO)) = O;
        prev(O) = lastOrder(LO);
        lastOrder(LO) = O;
      };
    };
  };
};

void insertOrder(listDriver LD, listCustomer LC, listOrder &LO,
                 string namaDriver, string namaCustomer) {

  adrDriver D = searchDriver(LD, namaDriver);
  adrCustomer C = searchCustomer(LC, namaCustomer);

  if (D != NULL && C != NULL) {
    adrOrder O = createElmOrder(D, C);

    if (O != NULL) {
      if (firstOrder(LO) == NULL) {
        firstOrder(LO) = O;
        lastOrder(LO) = O;
      } else {
        next(lastOrder(LO)) = O;
        prev(O) = lastOrder(LO);
        lastOrder(LO) = O;
      };
      cout << "Order successfully inserted." << endl << endl;
    } else {
      cout << "Failed to create order element." << endl;
    };
  } else {
    cout << "Driver or customer not found." << endl;
  };
};

void editOrder(listOrder &LO, listDriver LD, listCustomer LC, string namaDriver,
               string namaCustomer) {
  infoDriver ID;
  infoCust IC;
  adrDriver D = searchDriver(LD, namaDriver);
  adrCustomer C = searchCustomer(LC, namaCustomer);
  adrOrder O = firstOrder(LO);

  while (O != NULL) {
    if (orderDriver(O) == D && orderCustomer(O) == C) {
      cout << endl;
      cout << "Order Found!" << endl;
      cout << "==============[ Order Detail ]==============" << endl;
      cout << "[Driver]" << endl;
      cout << "Name: " << orderDriver(O)->info.nama << endl;
      cout << "Plat Nomor: " << orderDriver(O)->info.no_pol << endl;
      cout << "Rating: " << orderDriver(O)->info.rating << endl;
      cout << "[Customer]" << endl;
      cout << "Name: " << orderCustomer(O)->info.nama << endl;
      cout << "Alamat: " << orderCustomer(O)->info.alamat << endl;
      cout << "No Telp: " << orderCustomer(O)->info.no_telp << endl;
      cout << endl;
      cout << "===================[ EDIT ]=================" << endl;
      cout << "[Driver]" << endl;
      cout << "Find driver byName: ";
      cin >> ID.nama;
      D = searchDriver(LD, ID.nama);
      if (D == NULL) {
        cout << "Driver tidak ditemukan." << endl;
        break;
      };

      cout << "[Customer]" << endl;
      cout << "Find customer byName: ";
      cin >> IC.nama;
      C = searchCustomer(LC, IC.nama);
      if (C == NULL) {
        cout << "Customer tidak ditemukan." << endl;
        break;
      };

      orderDriver(O) = D;
      orderCustomer(O) = C;

      cout << "Order Successfully Edited." << endl;
      cout << "==============[ Order Edited ]==============" << endl;
      cout << "[Driver]" << endl;
      cout << "Name: " << orderDriver(O)->info.nama << endl;
      cout << "Plat Nomor: " << orderDriver(O)->info.no_pol << endl;
      cout << "Rating: " << orderDriver(O)->info.rating << endl;
      cout << "[Customer]" << endl;
      cout << "Name: " << orderCustomer(O)->info.nama << endl;
      cout << "Alamat: " << orderCustomer(O)->info.alamat << endl;
      cout << "No Telp: " << orderCustomer(O)->info.no_telp << endl;
      cout << endl;
      cout << "===========================================" << endl;
      return;
    };
    O = next(O);
  };
  cout << "Order Unsucsessfully Edited." << endl;
};

// delete order
void deleteO(listDriver LD, listCustomer LC, listOrder &LO, adrOrder &O,
             string namaDriver, string namaCustomer) {
  adrDriver D = searchDriver(LD, namaDriver);
  adrCustomer C = searchCustomer(LC, namaCustomer);
  O = firstOrder(LO);

  while (O != NULL) {
    if (orderDriver(O) == D && orderCustomer(O) == C) {

      if (O == firstOrder(LO)) {
        deleteFirstO(LO, O);
      } else if (O == lastOrder(LO)) {
        deleteLastO(LO, O);
      } else {
        deleteAfterO(LO, O, prev(O));
      };

      cout << "Order Successfully Deleted." << endl;
      return;
    };

    O = next(O);
  };
  cout << "Order Unsucsessfully Deleted." << endl;
};

void deleteFirstO(listOrder &LO, adrOrder &O) {
  if (firstOrder(LO) == NULL) {
    cout << "Data order kosong." << endl;
  } else if (next(firstOrder(LO)) == NULL) {
    O = firstOrder(LO);
    firstOrder(LO) = NULL;
    lastOrder(LO) = NULL;
  } else {
    O = firstOrder(LO);
    firstOrder(LO) = next(O);
    next(O) = NULL;
    prev(firstOrder(LO)) = NULL;
  };
};

void deleteAfterO(listOrder &LO, adrOrder &O, adrOrder prec) {
  O = next(prec);
  next(prec) = next(O);
  prev(next(O)) = prec;
  next(O) = NULL;
  prev(O) = NULL;
};

void deleteLastO(listOrder &LO, adrOrder &O) {
  if (firstOrder(LO) == NULL) {
    cout << "Data order kosong." << endl;
  } else if (next(firstOrder(LO)) == NULL) {
    O = firstOrder(LO);
    firstOrder(LO) = NULL;
    lastOrder(LO) = NULL;
  } else {
    O = lastOrder(LO);
    lastOrder(LO) = prev(O);
    next(lastOrder(LO)) = NULL;
    prev(O) = NULL;
  };
};

bool isHaveRelation(listDriver LD, listCustomer LC, listOrder LO,
                    string namaDriver, string namaCustomer) {
  adrDriver D = searchDriver(LD, namaDriver);
  
  adrCustomer C = searchCustomer(LC, namaCustomer);
  adrOrder O = firstOrder(LO);

  while (O != NULL) {
    if (orderDriver(O) == D && orderCustomer(O) == C) {
      cout << endl;
      cout << "------- Driver -------" << endl;
      cout << "Nama: " << D->info.nama << endl;
      cout << "Plat Nomor: " << D->info.no_pol << endl;
      cout << "Rating: " << D->info.rating << endl;
      cout << "------ Customer ------" << endl;
      cout << "Nama: " << info(C).nama << endl;
      cout << "Alamat: " << C->info.alamat << endl;
      cout << "No Telp: " << C->info.no_telp << endl;
      cout << endl;
      return true;
    };
    O = next(O);
  };
  return false;
};

void showOrder(listOrder LO) {
  int i = 0;
  adrOrder O = firstOrder(LO);
  if (O == NULL) {
    cout << "Data order kosong." << endl;
    return;
  };

  do {
    i++;
    cout << endl;
    cout << "[" << i << "] "
         << "[Driver]" << endl;
    cout << "Name: " << orderDriver(O)->info.nama << endl;
    cout << "Plat Nomor: " << orderDriver(O)->info.no_pol << endl;
    cout << "Rating: " << orderDriver(O)->info.rating << endl;
    cout << "\t[Customer]" << endl;
    cout << "\t| Name: " << orderCustomer(O)->info.nama << endl;
    cout << "\t| Alamat: " << orderCustomer(O)->info.alamat << endl;
    cout << "\t| No Telp: " << orderCustomer(O)->info.no_telp << endl;
    cout << "--------------------------------------------" << endl;
    O = next(O);
  } while (O != NULL);
  cout << endl;
  cout << "==================================" << endl;
};