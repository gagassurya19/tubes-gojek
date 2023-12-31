#include "gojek.h"
#include <iostream>
using namespace std;

int main() {
  // deklarasi list
  listDriver LD;
  adrDriver D;
  createListD(LD);
  listCustomer LC;
  adrCustomer C;
  createListCust(LC);
  listOrder LO;
  adrOrder O;
  createListOrder(LO);

  // deklarasi variable
  char option, optionInCase;
  bool isExit = false;

  // insert data dummy
  data_dummy(LD, LO, LC, D, C);

  do {
    option = mainMenu();
    clearScreen();
    switch (option) {
    case '1':
      while (!isExit) {
        optionInCase = menuDriver();
        switch (optionInCase) {
        case '1':
          menuDriverInsert(LD);
          break;
        case '2':
          menuDriverEdit(LD);
          break;
        case '3':
          menuDriverDelete(LD, D);
          break;
        case '4':
          menuDriverShow(LD);
          break;
        case '`':
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Invalid Input" << endl;
          break;
        }
      };
      isExit = false; // kembaliin ke default value
      clearScreen();
      break;
    case '2':
      while (!isExit) {
        optionInCase = menuCustomer();
        switch (optionInCase) {
        case '1':
          menuCustomerInsert(LC);
          break;
        case '2':
          menuCustomerEdit(LC);
          break;
        case '3':
          menuCustomerDelete(LC, C);
          break;
        case '4':
          menuCustomerShow(LC);
          break;
        case '`':
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Invalid Input" << endl;
          break;
        }
      };
      isExit = false; // kembaliin ke default value
      clearScreen();
      break;
    case '3':
      while (!isExit) {
        optionInCase = menuOrder();
        switch (optionInCase) {
        case '1':
          menuOrderInsert(LO, LC, LD);
          break;
        case '2':
          menuOrderEdit(LO, LD, LC);
          break;
        case '3':
          menuOrderDelete(LO, LC, LD, O);
          break;
        case '4':
          menuOrderShow(LO);
          break;
        case '`':
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Invalid Input" << endl;
          break;
        }
      };
      isExit = false; // kembaliin ke default value
      clearScreen();
      break;
    case '4':
      while (!isExit) {
        optionInCase = menuShowCount();
        switch (optionInCase) {
        case '1':
          menuDriverShow(LD);
          break;
        case '2':
          menuShowDriverByCustomer(LC, LO);
          break;
        case '3':
          menuShowAllDriverWithCustomer(LD, LO);
          break;
        case '4':
          menuCustomerShow(LC);
          break;
        case '5':
          menuShowCustomerByDriver(LD, LO);
          break;
        case '6':
          menuShowAllCustomerWithDriver(LC, LO);
          break;
        case 'q':
          menuCountDriverByCustomer(LD, LO, LC);
          break;
        case 'w':
          menuCountDriverNoOrder(LD, LO, LC);
          break;
        case 'e':
          menuCountCustomerByDriver(LD, LO, LC);
          break;
        case 'r':
          menuCountCustomerNoOrder(LD, LO, LC);
          break;
        case 't':
          menuIsHaveRelation(LD, LC, LO);
          break;
        case '`':
          isExit = true;
          break;
        default:
          clearScreen();
          cout << "Invalid Input" << endl;
          break;
        }
      };
      isExit = false; // kembaliin ke default value
      clearScreen();
      break;
    case '`':
      clearScreen();
      cout << "Goodbye ^_^\nExiting program." << endl;
      break;
    default:
      cout << "Invalid option. " << endl;
      break;
    };
  } while (option != '`');

  return 0;
};