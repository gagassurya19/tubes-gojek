#ifndef GOJEK_H
#define GOJEK_H

#include <iostream>
using namespace std;

#define first(L) (L).first
#define last(L) (L).last
#define firstOrder(L) (L).firstOrder
#define lastOrder(L) (L).lastOrder

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define orderDriver(P) (P)->orderDriver
#define orderCustomer(P) (P)->orderCustomer

// deklarasi linked list driver
struct driver {
  string no_pol, nama;
  int rating;
};

typedef driver infoDriver;
typedef struct elmDriver *adrDriver;

struct elmDriver {
  infoDriver info;
  adrDriver next, prev;
};

struct listDriver {
  adrDriver first, last;
};

// deklarasi linked list customer
struct customer {
  string nama, alamat;
  int no_telp;
};

typedef struct elmCustomer *adrCustomer;
typedef customer infoCust;

struct elmCustomer {
  infoCust info;
  adrCustomer next;
};

struct listCustomer {
  adrCustomer first;
};

// deklarasi linked list order [relasi]
typedef struct elmOrder *adrOrder;

struct elmOrder {
  adrDriver orderDriver;
  adrCustomer orderCustomer;
  adrOrder next, prev;
};

struct listOrder {
  adrOrder firstOrder, lastOrder;
};

//--------------------------------------------------------------------------------------------------------
// DRIVER
adrDriver createElmD(infoDriver D);
void createListD(listDriver &LD);
void insertLastD(listDriver &LD, adrDriver D);
void editD(listDriver &LD, string no_pol);
void deleteD(listDriver &LD, adrDriver &D, string no_pol);
// delete driver
void deleteFirstD(listDriver &LD, adrDriver &D);
void deleteAfterD(listDriver &LD, adrDriver &D, adrDriver prec);
void deleteLastD(listDriver &LD, adrDriver &D);
// cari driver
adrDriver searchDriver(listDriver LD, string namaDriver);
// show driver
void showDriver(listDriver LD);
void showDriverByCustomer(listCustomer LC, listOrder LO, string namaCustomer);
void showAllDriverWithCustomer(listDriver LD, listOrder LO);

//--------------------------------------------------------------------------------------------------------
// CUSTOMER
adrCustomer createElmCust(infoCust X);
void createListCust(listCustomer &LC);
void insertLastCustomer(listCustomer &LC, adrCustomer C);
void editC(listCustomer &LC, string no_pol);

// delete customer
void deleteC(listCustomer &LC, adrCustomer &C, int NoTelp);
void deleteFirstC(listCustomer &LC, adrCustomer &C);
void deleteAfterC(listCustomer &LC, adrCustomer &C, adrCustomer prec);
void deleteLastC(listCustomer &LC, adrCustomer &C);
//  cari customer
adrCustomer searchCustomer(listCustomer LC, string nama);

// show customer
void showCustomer(listCustomer LC);
void showElmCustomer(listCustomer LC, adrCustomer C);
void showCustomerByDriver(listDriver LD, listOrder LO, string namaDriver);
void showAllCustomerWithDriver(listCustomer LC, listOrder LO);
void countDriverByCustomer(listDriver LD, listOrder LO, listCustomer LC,
                           string namaCustomer);
void countCustomerByDriver(listDriver LD, listOrder LO, listCustomer LC,
                           string namaDriver);
void countDriverNoOrder(listDriver LD, listOrder LO, listCustomer LC);
void countCustomerNoOrder(listDriver LD, listOrder LO, listCustomer LC);

//--------------------------------------------------------------------------------------------------------
// ORDER
adrOrder createElmOrder(adrDriver D, adrCustomer C);
void createListOrder(listOrder &LO);
void insertOrder(listDriver LD, listCustomer LC, listOrder &LO,
                 string namaDriver, string namaCustomer);
void editOrder(listOrder &LO, listDriver LD, listCustomer LC, string namaDriver,
               string namaCustomer);
void deleteO(listDriver LD, listCustomer LC, listOrder &LO, adrOrder &O,
             string namaDriver, string namaCustomer);

// delete order
void deleteFirstO(listOrder &LO, adrOrder &O);
void deleteAfterO(listOrder &LO, adrOrder &O, adrOrder prec);
void deleteLastO(listOrder &LO, adrOrder &O);

bool isHaveRelation(listDriver LD, listCustomer LC, listOrder LO,
                    string namaDriver, string namaCustomer);
void showOrder(listOrder LO);
void insertOrderDummy(listDriver LD, listCustomer LC, listOrder &LO,
                      string namaDriver, string namaCustomer);

//--------------------------------------------------------------------------------------------------------
// MENU
void pressEnter();
void clearScreen();
char mainMenu();
char menuDriver();
void menuDriverInsert(listDriver &LD);
void menuDriverEdit(listDriver &LD);
void menuDriverDelete(listDriver &LD, adrDriver &D);
void menuDriverShow(listDriver LD);
char menuCustomer();
void menuCustomerInsert(listCustomer &LD);
void menuCustomerEdit(listCustomer &LD);
void menuCustomerDelete(listCustomer &LD, adrCustomer &D);
void menuCustomerShow(listCustomer LD);
char menuOrder();
void menuOrderInsert(listOrder &LO, listCustomer LC, listDriver LD);
void menuOrderEdit(listOrder &LO, listDriver LD, listCustomer LC);
void menuOrderDelete(listOrder &LO, listCustomer LC, listDriver LD,
                     adrOrder &O);
void menuOrderShow(listOrder LO);
char menuShowCount();
void menuShowDriverByCustomer(listCustomer LC, listOrder LO);
void menuShowAllDriverWithCustomer(listDriver LD, listOrder LO);
void menuShowCustomerByDriver(listDriver LD, listOrder LO);
void menuShowAllCustomerWithDriver(listCustomer LC, listOrder LO);
void menuCountDriverByCustomer(listDriver LD, listOrder LO, listCustomer LC);
void menuCountCustomerByDriver(listDriver LD, listOrder LO, listCustomer LC);
void menuCountDriverNoOrder(listDriver LD, listOrder LO, listCustomer LC);
void menuCountCustomerNoOrder(listDriver LD, listOrder LO, listCustomer LC);
void menuIsHaveRelation(listDriver LD, listCustomer LC, listOrder LO);

// deklarasi data dummy
void data_dummy(listDriver &LD, listOrder &LO, listCustomer &LC, adrDriver &D,
                adrCustomer &C);
#endif