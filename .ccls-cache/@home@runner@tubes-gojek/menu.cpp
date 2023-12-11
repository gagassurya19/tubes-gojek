#include "gojek.h"
#include <iostream>
#include <limits>
#include <string>
using namespace std;

// fungsi untuk break dan melanjutkan operasi
void pressEnter() {
  string skip;
  cout << "Tekan [enter] untuk melanjutkan...";
  cin.ignore(numeric_limits<streamsize>::max(),
             '\n');   // Membersihkan buffer sampai newline
  getline(cin, skip); // Menggunakan getline untuk menunggu tombol Enter
  cout << endl;
};

// fungsi untuk menghapus layar
void clearScreen() {
#ifdef _WIN32 // Windows
  system("cls");
#else
  (void)system("clear"); // Mac/Linux
#endif
};

char mainMenu() {
  cout << "=========================================" << endl;
  cout << "|           Welcome to Gojek            |" << endl;
  cout << "=========================================" << endl;
  cout << "| 1. GAGAS SURYA LAKSANA - 1301223164   |" << endl;
  cout << "| 2. AZRIAN RIFQI RADHITYA - 1301223292 |" << endl;
  cout << "=========================================" << endl;
  cout << "| [1] Driver                            |" << endl;
  cout << "| [2] Customer                          |" << endl;
  cout << "| [3] Order                             |" << endl;
  cout << "| [4] Show & Count                      |" << endl;
  cout << "| [`~] Exit                             |" << endl;
  cout << "=========================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

// menu driver
char menuDriver() {
  cout << "====================================" << endl;
  cout << "|  Welcome to Gojek - Driver Menu  |" << endl;
  cout << "====================================" << endl;
  cout << "| [1] Input Data Driver            |" << endl;
  cout << "| [2] Edit Data Driver             |" << endl;
  cout << "| [3] Delete Data Driver           |" << endl;
  cout << "| [4] Show Data Driver             |" << endl;
  cout << "| [`~] Back                        |" << endl;
  cout << "====================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

void menuDriverInsert(listDriver &LD) {
  infoDriver ID;
  clearScreen();
  cout << "====================================" << endl;
  cout << "|  Driver Menu - Input Data Driver |" << endl;
  cout << "====================================" << endl;
  cout << "Nama: ";
  cin >> ID.nama;
  cout << "Plat Nomor: ";
  cin >> ID.no_pol;
  // Validasi input untuk memastikan input adalah integer
  while (true) {
    cout << "Rating: ";
    cin >> ID.rating;
    if (cin.fail()) {
      // Handle kesalahan input yang bukan integer
      cin.clear(); // Membersihkan status error pada cin
      cin.ignore(numeric_limits<streamsize>::max(),
                 '\n'); // Membersihkan buffer hingga newline
      cout << "Rating harus berupa angka. Silakan masukkan kembali." << endl;
    } else {
      // Input valid, keluar dari loop
      break;
    }
  }
  cout << "====================================" << endl;
  adrDriver D = createElmD(ID);
  insertLastD(LD, D);
  cout << "Driver berhasil ditambahkan!" << endl;
  pressEnter();
  clearScreen();
};

void menuDriverEdit(listDriver &LD) {
  infoDriver ID;
  clearScreen();
  cout << "====================================" << endl;
  cout << "|  Driver Menu - Input Data Driver |" << endl;
  cout << "====================================" << endl;
  cout << "Find driver by PlatNomor: ";
  cin >> ID.no_pol;
  editD(LD, ID.no_pol);
  pressEnter();
  clearScreen();
};

void menuDriverDelete(listDriver &LD, adrDriver &D) {
  infoDriver ID;
  clearScreen();
  cout << "====================================" << endl;
  cout << "| Driver Menu - Delete Data Driver |" << endl;
  cout << "====================================" << endl;
  cout << "Find driver by PlatNomor: ";
  cin >> ID.no_pol;
  deleteD(LD, D, ID.no_pol);
  pressEnter();
  clearScreen();
};

void menuDriverShow(listDriver LD) {
  clearScreen();
  cout << "====================================" << endl;
  cout << "|  Driver Menu - Show Data Driver  |" << endl;
  showDriver(LD);
  pressEnter();
  clearScreen();
};

// menu customer
char menuCustomer() {
  cout << "====================================" << endl;
  cout << "| Welcome to Gojek - Customer Menu |" << endl;
  cout << "====================================" << endl;
  cout << "| [1] Input Data Customer          |" << endl;
  cout << "| [2] Edit Data Customer           |" << endl;
  cout << "| [3] Delete Data Customer         |" << endl;
  cout << "| [4] Show Data Customer           |" << endl;
  cout << "| [`~] Back                        |" << endl;
  cout << "====================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

void menuCustomerInsert(listCustomer &LC) {
  clearScreen();
  cout << "====================================" << endl;
  cout << "|  Customer Menu - Input Customer  |" << endl;
  cout << "====================================" << endl;

  adrCustomer C;
  infoCust X;
  cout << "Masuk data customer baru" << endl;
  cout << "Nama: ";
  cin >> X.nama;
  cout << "Alamat: ";
  cin >> X.alamat;
  // Validasi input untuk memastikan input adalah integer
  while (true) {
    cout << "Nomor telp: ";
    cin >> X.no_telp;
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
  cout << "====================================" << endl;
  C = createElmCust(X);
  insertLastCustomer(LC, C);

  cout << "Customer berhasil ditambahkan!" << endl;
  pressEnter();
  clearScreen();
};

void menuCustomerEdit(listCustomer &LC) {
  clearScreen();

  cout << "====================================" << endl;
  cout << "|   Customer Menu - Edit Customer  |" << endl;
  cout << "====================================" << endl;
  string nama;
  cout << "Edit customer: ";
  cin >> nama;
  editC(LC, nama);
  pressEnter();
  clearScreen();
};

void menuCustomerDelete(listCustomer &LC, adrCustomer &C) {
  int no;
  clearScreen();
  cout << "====================================" << endl;
  cout << "|  Customer Menu - Delete Customer  |" << endl;
  cout << "====================================" << endl;
  // Validasi input untuk memastikan input adalah integer
  while (true) {
    cout << "Find customer by phone number: ";
    cin >> no;
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
  deleteC(LC, C, no);
  pressEnter();
  clearScreen();
};

void menuCustomerShow(listCustomer LC) {
  clearScreen();
  cout << "====================================" << endl;
  cout << "|   Customer Menu - Show Customer  |" << endl;
  showCustomer(LC);
  pressEnter();
  clearScreen();
};

// menu order
char menuOrder() {
  cout << "====================================" << endl;
  cout << "|   Welcome to Gojek - Order Menu  |" << endl;
  cout << "====================================" << endl;
  cout << "| [1] Input Data Order             |" << endl;
  cout << "| [2] Edit Data Order              |" << endl;
  cout << "| [3] Delete Data Order            |" << endl;
  cout << "| [4] Show Data Order              |" << endl;
  cout << "| [`~] Back                        |" << endl;
  cout << "====================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

void menuOrderInsert(listOrder &LO, listCustomer LC, listDriver LD) {
  string namaDriver, namaCustomer;
  clearScreen();
  cout << "========[ Insert Order ]========" << endl;
  cout << "namaCustomer: ";
  cin >> namaCustomer;
  cout << "namaDriver: ";
  cin >> namaDriver;
  insertOrder(LD, LC, LO, namaDriver, namaCustomer);
  pressEnter();
  clearScreen();
};

void menuOrderEdit(listOrder &LO, listDriver LD, listCustomer LC) {
  string namaDriver, namaCustomer;
  clearScreen();
  cout << "========[ Edit Order ]========" << endl;
  cout << "Find order related namaCustomer: ";
  cin >> namaCustomer;
  cout << "Find order related namaDriver: ";
  cin >> namaDriver;
  editOrder(LO, LD, LC, namaDriver, namaCustomer);
  pressEnter();
  clearScreen();
};

void menuOrderDelete(listOrder &LO, listCustomer LC, listDriver LD,
                     adrOrder &O) {
  string namaDriver, namaCustomer;
  clearScreen();
  cout << "========[ Delete Order ]========" << endl;
  cout << "Find order related namaCustomer: ";
  cin >> namaCustomer;
  cout << "Find order related namaDriver: ";
  cin >> namaDriver;
  deleteO(LD, LC, LO, O, namaDriver, namaCustomer);
  pressEnter();
  clearScreen();
};

void menuOrderShow(listOrder LO) {
  clearScreen();
  cout << "===============[ Show Order ]=================" << endl;
  showOrder(LO);
  pressEnter();
  clearScreen();
};

// show
char menuShowCount() {
  cout << "========================================" << endl;
  cout << "| Welcome to Gojek - Show & Count Menu |" << endl;
  cout << "========================================" << endl;
  cout << "| [1] Show All Driver                  |" << endl;
  cout << "| [2] Show Driver By Customer          |" << endl;
  cout << "| [3] Show All Driver With Customer    |" << endl;
  cout << "| [4] Show All Customer                |" << endl;
  cout << "| [5] Show Customer By Driver          |" << endl;
  cout << "| [6] Show All Customer With Driver    |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "| [Q] Count Driver By Customer         |" << endl;
  cout << "| [W] Count Driver Not Have Customer   |" << endl;
  cout << "| [E] Count Customer By Driver         |" << endl;
  cout << "| [R] Count Customer Not Have Driver   |" << endl;
  cout << "| [`~] Back                            |" << endl;
  cout << "========================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

void menuShowDriverByCustomer(listCustomer LC, listOrder LO) {
  infoCust IC;
  clearScreen();
  cout << "========[ DAFTAR DRIVER BY CUSTOMER ]========" << endl;
  cout << "Find driver by namaCustomer: ";
  cin >> IC.nama;
  showDriverByCustomer(LC, LO, IC.nama);
  pressEnter();
  clearScreen();
};

void menuShowAllDriverWithCustomer(listDriver LD, listOrder LO) {
  clearScreen();
  showAllDriverWithCustomer(LD, LO);
  pressEnter();
  clearScreen();
};

void menuShowCustomerByDriver(listDriver LD, listOrder LO) {
  infoDriver ID;
  clearScreen();
  cout << "========[ DAFTAR CUSTOMER BY DRIVER ]========" << endl;
  cout << "Find customer by namaDriver: ";
  cin >> ID.nama;
  showCustomerByDriver(LD, LO, ID.nama);
  pressEnter();
  clearScreen();
};

void menuShowAllCustomerWithDriver(listCustomer LC, listOrder LO) {
  clearScreen();
  showAllCustomerWithDriver(LC, LO);
  pressEnter();
  clearScreen();
};

void menuCountDriverByCustomer(listDriver LD, listOrder LO, listCustomer LC) {
  string namaCustomer;
  clearScreen();
  cout << "========[ COUNT DRIVER BY CUSTOMER ]========" << endl;
  cout << "Find customer by namaCustomer: ";
  cin >> namaCustomer;
  countDriverByCustomer(LD, LO, LC, namaCustomer);
  cout << endl;
  cout << "============================================" << endl;
  pressEnter();
  clearScreen();
};

void menuCountCustomerByDriver(listDriver LD, listOrder LO, listCustomer LC) {
  string namaDriver;
  clearScreen();
  cout << "========[ COUNT CUSTOMER BY DRIVER ]========" << endl;
  cout << "Find customer by namaDriver: ";
  cin >> namaDriver;
  countCustomerByDriver(LD, LO, LC, namaDriver);
  cout << endl;
  cout << "============================================" << endl;
  pressEnter();
  clearScreen();
};

void menuCountDriverNoOrder(listDriver LD, listOrder LO, listCustomer LC) {
  clearScreen();
  cout << "========[ COUNT DRIVER NO ORDER ]========" << endl;
  cout << endl;
  countDriverNoOrder(LD, LO, LC);
  cout << endl;
  cout << "=========================================" << endl;
  pressEnter();
  clearScreen();
};

void menuCountCustomerNoOrder(listDriver LD, listOrder LO, listCustomer LC) {
  clearScreen();
  cout << "========[ COUNT CUSTOMER NO ORDER ]========" << endl;
  cout << endl;
  countCustomerNoOrder(LD, LO, LC);
  cout << endl;
  cout << "===========================================" << endl;
  pressEnter();
  clearScreen();
};
