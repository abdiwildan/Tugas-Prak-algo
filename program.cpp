#include <iostream>
#include <stdlib.h>

using namespace std;
//Program Juragan Angkot
//tambah mobil
//Edit Info Mobil
//detail
//setoran 
//Jual

struct Angkot{
    string sopir,nopol;
    int setoran;
    bool servis;

    Angkot *next;

};

Angkot *head, *tail, *cur, *newNode, *del, *before;

int isijual[100];
const int maksimal = 100;
int jumlah = 0;
void Enqueue(){
  auto input_nilai = 0;
  cout << "Masukan harga jual: ";
  cin >> input_nilai;

  jumlah += 1;
  isijual[jumlah] = input_nilai;
  cout << "Data sudah diinputkan " << input_nilai << endl;
}

//create linked list

void createAngkotData(string sopir, string nopol, int setoran, bool servis){
  head = new Angkot();
  head->sopir = sopir;
  head->nopol = nopol;
  head->setoran = setoran;
  head->servis = servis;
  head->next = NULL;
  tail = head;
}

int countAngkotData(){
  cur = head;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}

void addLast(string sopir, string nopol){
  newNode = new Angkot();
  newNode->sopir = sopir;
  newNode->nopol = nopol;

  newNode->next = NULL;
  tail->next = newNode;
  tail = newNode;
}

void removeFirst(){
  del = head;
  head = head->next;
  delete del;
}

void removeLast(){
  del = tail;
  cur = head;
  while( cur->next != tail ){
    cur = cur->next;
  }
  tail = cur;
  tail->next = NULL;
  delete del;
}

void removeMiddle(int posisi){
  if( posisi < 1 || posisi > countAngkotData() ){
    cout << "Pilihan di Luar Data" << endl;
  }else{
    int nomor = 1;
    cur = head;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        before = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    before->next = cur;
    delete del;
  }
}




// ubahAwal Single linked list
void changeFirst(){
    string sopir, nopol;

    cout << "Masukan data terbaru\n"
         << "Nama Supir : ";
    cin >> sopir;
    cout << "Masukan NO POLISI : ";
    cin >> nopol;

    
    head->sopir = sopir;
    head->nopol = nopol;

}

// ubahAkhir Single linked list
void changeLast(){
    string sopir, nopol;

    cout << "Masukan data terbaru\n"
         << "Nama Supir : ";
    cin >> sopir;
    cout << "Masukan NO POLISI : ";
    cin >> nopol;
    tail->sopir = sopir;
    tail->nopol = nopol;
}

// ubah Tengah Single linked list
void changeMiddle(int posisi){

    cur = head;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
    string sopir, nopol;


    cout << "Masukan data terbaru\n"
         << "Nama Supir : ";
    cin >> sopir;
    cout << "Masukan NO POLISI : ";
    cin >> nopol;
    cur->sopir = sopir;
    cur->nopol = nopol;

}
// setoran
void changeFirstSetoran(){
    int setoran;

    cout << "Masukan data terbaru\n"
         << "Masukan setoran : ";
    cin >> setoran;
    
    head->setoran = setoran;

}

// ubahAkhir Setoran
void changeLastSetoran(){
    int setoran;

    cout << "Masukan data terbaru\n"
         << "Masukan setoran : ";
    cin >> setoran;
    
    tail->setoran = setoran;

}

// ubah Tengah Setoran
void changeMiddleSetoran(int posisi){

    cur = head;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
        int setoran;

    cout << "Masukan data terbaru\n"
         << "Masukan setoran : ";
    cin >> setoran;
    
    cur->setoran = setoran;

}

// ubahAwal Servis
void changeFirstServis(){
    int servis;

    cout << "Masukan data terbaru\n"
         << "0 = Tidak / 1 = Servis : ";
    cin >> servis;
    
    head->servis = servis;

}

// ubahAkhir Servis
void changeLastServis(){
    int servis;

    cout << "Masukan data terbaru\n"
         << "0 = Tidak / 1 = Service : ";
    cin >> servis;
    
    tail->servis = servis;
}

// ubah Tengah Servis
void changeMiddleServis(int posisi){

    cur = head;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
    int servis;

    cout << "Masukan data terbaru\n"
         << "0 = Tidak / 1 = Servis : ";
    cin >> servis;
    cur->servis = servis;

}
//Ubah data
void changeData();
void dataSetoran();
void dataServis();

//keuangan
void keuangan();

//Jual Kendaraan
void Jual();

// print single linked list
void printSingleLinkedList(){
    cout << "============================\n"
         << "Jumlah data ada : " << countAngkotData() << "\n"
         << "No\tSopir\tNo Polisi\tSetoran(Rp)\tServis" << endl;

    cur = head;
    int i = 1;
    while( cur != NULL ){
        cout << i <<  "\t " 
             << cur->sopir << "\t"
             << cur->nopol << "\t\t"
             << cur->setoran << "\t\t";
             if (cur->servis == 1)
             {
                 cout << "Mobil Harus di Servis" << endl;
             } else {
                 cout << "Mobil baik baik saja" << endl;
             }
             
        i++;
        cur = cur->next;
        
    }
}


int main()
{
    createAngkotData("Tayo", "F123", 0, false);

    auto pilihan_user = 0;
    auto isLoop = true;
    string sopir, nopol;
    int setoran;
    int pilihan;
    bool servis; 

    while (isLoop)
    {
        cout << "Selamat Datang Juragan Angkot, Silahkan Pilih Menu"
            << "\n1. Tambah Kendaraan"
            << "\n2. Ubah Data"
            << "\n3. Setoran"
            << "\n4. Servis"
            << "\n5. laporan Pemasukan"
            << "\n6. Detail"
            << "\n7. Jual Kendaraan"
            << "\n8. Quit" << endl;
        cout << "Masukan pilihan: ";
        cin >> pilihan_user;

        system ("cls");
        switch (pilihan_user)
        {
        case 1:
            cout << "Masukan Data Tambahan"
                << "\n1. Nama Sopir :" ;
            cin >> sopir;
            cout << "\n2. No Polisi : " ;
            cin >> nopol;

           addLast(sopir, nopol);
             system("CLS");
           cout << " Data Sudah ditambahkan " << endl;
          
       
        break;

        case 2:
          changeData();
          cout << endl;
        break;

        case 3:
          dataSetoran();
        cout << endl;
        break;

        case 4:
        dataServis();
        cout << endl;
        break;

        case 5:
        keuangan();
        cout << endl;
        break;

        case 6:
        printSingleLinkedList();
        cout << endl;
        break;

        case 7:
        Jual();
        cout << endl;
      
        break;

        case 8:
        cout << "Terima kasih Juragan!!";
        isLoop = false;
        break;


        default:
        cout << "Salah input!" << endl;
        cout << endl;
        break;
        }
    }
    return 0;
}


void changeData(){
  int pilihan;
  printSingleLinkedList();
  cout << "Masukan Pilihan yang mau diubah :";
  cin >> pilihan;
    if( pilihan < 1 || pilihan > countAngkotData() ){
      cout << "pilihan diluar jangkauan" << endl;
    }else if( pilihan == 1 ){
      changeFirst();

    }else if( pilihan == countAngkotData()){
      changeLast();
    }else{
      changeMiddle(pilihan);
    }
}

void dataSetoran(){
  int pilihan;
   printSingleLinkedList();
            cout << "Masukan Pilihan yang mau diubah :";
            cin >> pilihan;
  if( pilihan < 1 || pilihan > countAngkotData() ){
    cout << "pilihan diluar jangkauan" << endl;
  }else if( pilihan == 1 ){
    changeFirstSetoran();

  }else if( pilihan == countAngkotData()){
    changeLastSetoran();
  }else{
    changeMiddleSetoran(pilihan);
  }
}

void dataServis(){
   int pilihan;
   printSingleLinkedList();
   cout << "Masukan Pilihan yang mau diubah :";
   cin >> pilihan;
    if( pilihan < 1 || pilihan > countAngkotData() ){
      cout << "pilihan diluar jangkauan" << endl;
    }else if( pilihan == 1 ){
      changeFirstServis();

    }else if( pilihan == countAngkotData()){
      changeLastServis();
    }else{
      changeMiddleServis(pilihan);
    }
}

void keuangan(){
    int hasil;
    int jual=0;
    printSingleLinkedList();
    cur =head;
    while( cur != NULL ){

        hasil = hasil + cur->setoran ;
        cur = cur->next;
        
    }

    for (size_t i = 1; i <= jumlah; i++){
      jual = jual + isijual[i];
    }

    cout << " Setoran Hari Ini :" << hasil << endl;
    cout << " Penjualan :" << jual << endl;
    cout << " Jumlah Pemasukan (Rp) : " << hasil + jual;
    

}

void Jual(){
    int pilihan;
    printSingleLinkedList();
    cout << "Masukan Kendaraan yang mau dijual :";
    cin >> pilihan;
      if( pilihan < 1 || pilihan > countAngkotData() ){
        cout << "pilihan diluar jangkauan" << endl;
      }else if( pilihan == 1 ){
        removeFirst();

      }else if( pilihan == countAngkotData()){
        removeLast();
      }else{
        removeMiddle(pilihan);
      }
    Enqueue();

}