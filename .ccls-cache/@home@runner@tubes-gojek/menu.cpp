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
}

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

void menuCustomerInsert(listCustomer &LC){
    clearScreen();
    cout << "====================================" << endl;
    cout << "|  Customer Menu - Input Customer  |" << endl;
    cout << "====================================" << endl;
  
  adrCustomer C;
  infoCust X;
  cout << "Masuk data customer baru" << endl;
  cout << "Nama: "; cin >> X.nama;
  cout << "Alamat: "; cin >> X.alamat;
  cout << "Nomor telp: "; cin >> X.no_telp;
  cout << "====================================" << endl;
  C = createElmCust(X);
  insertLastCustomer(LC, C);
  
  cout << "Customer berhasil ditambahkan!" << endl;
  pressEnter();
  clearScreen();

  
};

void menuCustomerEdit(listCustomer &LC){
    clearScreen();
  
    cout << "====================================" << endl;
    cout << "|   Customer Menu - Edit Customer  |" << endl;
    cout << "====================================" << endl;
    string nama;
    cout << "Edit customer: ";cin >> nama;
    editC(LC, nama);
    pressEnter();
    clearScreen();
};

void menuCustomerDelete(listCustomer &LC, adrCustomer &C){
    clearScreen();
    cout << "====================================" << endl;
    cout << "|  Customer Menu - Delete Customer  |" << endl;
    cout << "====================================" << endl;
    cout << "Find customer by phone number: ";
    string no; cin >> no;
    deleteC(LC, C, no);
    pressEnter();
    clearScreen();
};

void menuCustomerShow(listCustomer LC){
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

void menuOrderInsert(listOrder &LD){

};

void menuOrderEdit(listOrder &LD){

};

void menuOrderDelete(listOrder &LD){

};

void menuOrderShow(listOrder LD){

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
  cout << "| [5] Show All Customer With Driver    |" << endl;
  cout << "----------------------------------------" << endl;
  cout << "| [6] Count Driver By Customer         |" << endl;
  cout << "| [7] Count Driver Not Have Customer   |" << endl;
  cout << "| [8] Count Customer By Driver         |" << endl;
  cout << "| [9] Count Customer Not Have Driver   |" << endl;
  cout << "| [`~] Back                            |" << endl;
  cout << "========================================" << endl;
  char option;
  cout << "Input Option : ";
  cin >> option;
  return option;
};

void menuShowDriverByCustomer(listCustomer LC, listOrder LO){
  infoCust IC;
  clearScreen();
  cout << "========[ DAFTAR DRIVER BY CUSTOMER ]========" << endl;
  cout << "Find driver by namaCustomer: ";
  cin >> IC.nama;
  showDriverByCustomer(LC, LO, IC.nama);
  pressEnter();
  clearScreen();
};

void menuShowAllDriverWithCustomer(listDriver LD, listOrder LO){
  clearScreen();
  showAllDriverWithCustomer(LD, LO);
  pressEnter();
  clearScreen();
};