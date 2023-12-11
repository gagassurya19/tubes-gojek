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

  ID.nama = "Budi_Purnomo";
  ID.rating = 4;
  ID.no_pol = "D_5555_DE";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Dhika_Rahmat";
  ID.rating = 3;
  ID.no_pol = "D_6666_EF";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Fita_Anggara";
  ID.rating = 4;
  ID.no_pol = "D_7777_FG";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Joko_Susilo";
  ID.rating = 4;
  ID.no_pol = "D_9999_JK";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Lukman_Hakim";
  ID.rating = 5;
  ID.no_pol = "D_1010_LH";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Citra_Ayu";
  ID.rating = 4;
  ID.no_pol = "D_1111_CA";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Eva_Lestari";
  ID.rating = 5;
  ID.no_pol = "D_1212_EL";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Galih_Wibowo";
  ID.rating = 4;
  ID.no_pol = "D_1313_GW";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Irfan_Putro";
  ID.rating = 5;
  ID.no_pol = "D_1414_IP";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Krisna_Budi";
  ID.rating = 4;
  ID.no_pol = "D_1515_KB";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Mira_Antika";
  ID.rating = 5;
  ID.no_pol = "D_1616_MA";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Oscar_Rizki";
  ID.rating = 4;
  ID.no_pol = "D_1717_OR";
  D = createElmD(ID);
  insertLastD(LD, D);

  ID.nama = "Qori_Lubis";
  ID.rating = 5;
  ID.no_pol = "D_1818_QL";
  D = createElmD(ID);
  insertLastD(LD, D);

  // insert customer
  IC.nama = "Kevin_Izzan";
  IC.alamat = "Universitas_Telkom";
  IC.no_telp = 856591262;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Azrian_Rifqi";
  IC.alamat = "23_Paskal_Shopping_Centre";
  IC.no_telp = 816704572;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Budi_Setiawan";
  IC.alamat = "Jln_Jati_Padang_Baru_19";
  IC.no_telp = 236351380;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Irwan_Saputra";
  IC.alamat = "Jln_Panatayuda_2";
  IC.no_telp = 236203801;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Ahmad_Susilo";
  IC.alamat = "Jalan_Merdeka_5";
  IC.no_telp = 555555555;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Citra_Ayu";
  IC.alamat = "Jalan_Indah_6";
  IC.no_telp = 666666666;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Eka_Wijaya";
  IC.alamat = "Jalan_Bahagia_7";
  IC.no_telp = 777777777;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Galih_Pratama";
  IC.alamat = "Jalan_Suka_8";
  IC.no_telp = 888888888;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  ID.nama = "Hesti_Widodo";
  ID.rating = 5;
  ID.no_pol = "D_8888_GH";
  D = createElmD(ID);
  insertLastD(LD, D);

  IC.nama = "Indah_Sari";
  IC.alamat = "Jalan_Cantik_9";
  IC.no_telp = 999999999;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Kartika_Dewi";
  IC.alamat = "Jalan_Indah_10";
  IC.no_telp = 1010101010;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Andi_Saputra";
  IC.alamat = "Jalan_Maju_11";
  IC.no_telp = 1111111111;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Dhika_Adi";
  IC.alamat = "Jalan_Damai_12";
  IC.no_telp = 1212121212;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Farhan_Maulana";
  IC.alamat = "Jalan_Santai_13";
  IC.no_telp = 1313131313;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Hani_Rahayu";
  IC.alamat = "Jalan_Harapan_14";
  IC.no_telp = 1414141414;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Jihan_Fitri";
  IC.alamat = "Jalan_Jujur_15";
  IC.no_telp = 1515151515;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Lia_Wijaya";
  IC.alamat = "Jalan_Lancar_16";
  IC.no_telp = 1616161616;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Nanda_Putri";
  IC.alamat = "Jalan_Nyaman_17";
  IC.no_telp = 1717171717;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Putri_Amelia";
  IC.alamat = "Jalan_Pesan_18";
  IC.no_telp = 1818181818;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Rama_Kurnia";
  IC.alamat = "Jalan_Riang_19";
  IC.no_telp = 1919191919;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  IC.nama = "Taufan_Arif";
  IC.alamat = "Jalan_Terang_20";
  IC.no_telp = 2020202020;
  C = createElmCust(IC);
  insertLastCustomer(LC, C);

  // insert order
  insertOrderDummy(LD, LC, LO, "Fauzan_Majid", "Budi_Setiawan");
  insertOrderDummy(LD, LC, LO, "Fauzan_Majid", "Azrian_Rifqi");
  insertOrderDummy(LD, LC, LO, "Budi_Purnomo", "Ahmad_Susilo");
  insertOrderDummy(LD, LC, LO, "Dhika_Rahmat", "Citra_Ayu");
  insertOrderDummy(LD, LC, LO, "Fita_Anggara", "Eka_Wijaya");
  insertOrderDummy(LD, LC, LO, "Hesti_Widodo", "Galih_Pratama");
  insertOrderDummy(LD, LC, LO, "Joko_Susilo", "Indah_Sari");
  insertOrderDummy(LD, LC, LO, "Lukman_Hakim", "Kartika_Dewi");
  insertOrderDummy(LD, LC, LO, "Citra_Ayu", "Andi_Saputra");
  insertOrderDummy(LD, LC, LO, "Eva_Lestari", "Dhika_Adi");
  insertOrderDummy(LD, LC, LO, "Galih_Wibowo", "Farhan_Maulana");
  insertOrderDummy(LD, LC, LO, "Irfan_Putro", "Hani_Rahayu");
  insertOrderDummy(LD, LC, LO, "Krisna_Budi", "Jihan_Fitri");
  insertOrderDummy(LD, LC, LO, "Mira_Antika", "Lia_Wijaya");
  insertOrderDummy(LD, LC, LO, "Oscar_Rizki", "Nanda_Putri");
  insertOrderDummy(LD, LC, LO, "Qori_Lubis", "Putri_Amelia");
  insertOrderDummy(LD, LC, LO, "Sari_Widya", "Rama_Kurnia");
  insertOrderDummy(LD, LC, LO, "Uci_Aulia", "Taufan_Arif");
};