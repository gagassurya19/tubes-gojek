#include "gojek.h"
#include <iostream>

using namespace std;

adrOrder createElmOrder(adrDriver D, adrCustomer C) {
  adrOrder O = new elmOrder;
  orderDriver(O) = D;
  orderCustomer(O) = C;
  next(O) = NULL;
  prev(O) = NULL;

  cout << "Order element created for " << endl;
  cout << "Driver: " << info(D).nama << endl;
  cout << "Customer: " << info(C).nama << endl;

  return O;
};

void createListOrder(listOrder &L) {
  firstOrder(L) = NULL;
  lastOrder(L) = NULL;
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
      }
      cout << "Order successfully inserted." << endl << endl;
    } else {
      cout << "Failed to create order element." << endl;
    }
  } else {
    cout << "Driver or customer not found." << endl;
  }
}
// delete order

void deleteO(listDriver LD, listCustomer LC, listOrder &LO, adrOrder &O, string namaDriver, string namaCustomer) {
  adrDriver D = searchDriver(LD, namaDriver);
  adrCustomer C = searchCustomer(LC, namaCustomer);
  O = firstOrder(LO);

  while (O != NULL){
      if (orderDriver(O) == D && orderCustomer(O) == C) {

          if (O == firstOrder(LO)){
            deleteFirstO(LO, O);
          }else if (O == lastOrder(LO)){
            deleteLastO(LO, O);
          }else{
            deleteAfterO(LO, O, prev(O));
          }
          return;
      }

    O = next(O);
  }
  
};
void deleteFirstO(listOrder &LO, adrOrder &O){
    if (firstOrder(LO) == NULL){
        cout << "Data order kosong." << endl;
    }else if (next(firstOrder(LO)) == NULL){
        O = firstOrder(LO);
        firstOrder(LO) = NULL;
        lastOrder(LO) = NULL;
    }else{
       O = firstOrder(LO);
       firstOrder(LO) = next(O);
       next(O) = NULL;
       prev(firstOrder(LO)) = NULL;
    }
}
void deleteAfterO(listOrder &LO, adrOrder &O, adrOrder prec){
    O = next(prec);
    next(prec) = next(O);
    prev(next(O)) = prec;
    next(O) = NULL;
    prev(O) = NULL;
}
void deleteLastO(listOrder &LO, adrOrder &O){
  if (firstOrder(LO) == NULL){
      cout << "Data order kosong." << endl;
  }else if (next(firstOrder(LO)) == NULL){
      O = firstOrder(LO);
      firstOrder(LO) = NULL;
      lastOrder(LO) = NULL;
  }else{
     O = lastOrder(LO);
     lastOrder(LO) = prev(O);
     next(lastOrder(LO)) = NULL;
     prev(O) = NULL;
  }
}

// show order
void showOrderbyDriver(listOrder LO, listDriver LD) {
  adrDriver D = first(LD);
  int i = 1;
  cout << "==========[ DATA ORDER berdasarkan DRIVER ]==========" << endl;

  if (firstOrder(LO) == NULL) {
    cout << "Tidak ada order." << endl;
  } else {
    do {
      cout << "[" << i << "]. ";
      cout << "Driver " << info(D).nama << " order: " << endl;
      adrOrder O = firstOrder(LO);

      while (O != NULL) {
        if (orderDriver(O) == D) {
          cout << "Customer: " << info(orderCustomer(O)).nama << endl;
        }
        O = next(O);
      }cout << "-------------------------------------" << endl;
      cout << endl;
      i++;
      D = next(D);
    } while (D != first(LD));
  }
  cout << "=======================================" << endl;
};

void showOrderbyCustomer(listOrder LO, listCustomer LC) {
  adrCustomer C = first(LC);
  int i = 1;
  cout << "==========[ DATA ORDER berdasarkan CUSTOMER]==========" << endl;

  if (firstOrder(LO) == NULL) {
    cout << "Tidak ada order." << endl;
  } else {
    while (C != NULL) {
      cout << "[" << i << "]. ";
      cout << "Customer " << info(C).nama << " order: " << endl;
      adrOrder O = firstOrder(LO);

      while (O != NULL) {
        if (orderCustomer(O) == C) {
          cout << "Driver: " << info(orderDriver(O)).nama << endl;
        }
        O = next(O);
      }
      cout << endl;
      i++;
      C = next(C);
    }
  }
  cout << "=======================================" << endl;
}