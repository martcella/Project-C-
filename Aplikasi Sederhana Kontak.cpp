#include <iostream>
#include <string>
using namespace std;

struct Kontak {
string nama, telepon, email;
};

const int MAKS_KONTAK = 10;
Kontak kontak[MAKS_KONTAK];
int jumlahKontak = 0;

void TambahKontak() {
    string loop = "ya";
    while (loop == "ya") {
        if (jumlahKontak >= MAKS_KONTAK) {
        	cout << "\n==========================================";
            cout << "\nAnda telah mencapai batas maksimum kontak.";
            cout << "\n==========================================";
            return;
        } 

        Kontak kontakBaru;
        cout << "\nNama Kontak  : ";
        cin >> kontakBaru.nama;
        cout << "Nomor Telepon: ";
        cin >> kontakBaru.telepon;
        cout << "Email\t     : ";
        cin >> kontakBaru.email;

        kontak[jumlahKontak] = kontakBaru;
        jumlahKontak++;

        cout << "\n============================";
        cout << "\nKontak berhasil ditambahkan.";
        cout << "\n============================";

        cout << "\nTambahkan kontak lagi? (ya/tidak): ";
        cin >> loop;
    }
}


void HapusKontak() {
    if (jumlahKontak <= 0) {
    	cout << "\n================================";
        cout << "\nTidak ada kontak yang tersimpan.";
        cout << "\n================================";
        return;
    }

    string namaPencarian;
    cout << "\nMasukkan nama kontak yang ingin dihapus: ";
    cin >> namaPencarian;
    cout << "-------------------------------------------";

    int indeksDitemukan = -1;
    for (int i = 0; i < jumlahKontak; i++) {
        if (kontak[i].nama == namaPencarian) {
            indeksDitemukan = i;
            break;
        }
    }

    if (indeksDitemukan == -1) {
    	cout << "\n============================================";
        cout << "\nKontak dengan nama tersebut tidak ditemukan.";
        cout << "\n============================================";
        return;
    }

    for (int i = indeksDitemukan; i < jumlahKontak - 1; i++) {
        kontak[i] = kontak[i + 1];
    }
    jumlahKontak--;

    cout << "\n========================";
    cout << "\nKontak berhasil dihapus.";
    cout << "\n========================";
}

void CariKontak() {
    if (jumlahKontak <= 0) {
    	cout << "\n================================";
        cout << "\nTidak ada kontak yang tersimpan.";
        cout << "\n================================";
        return;
    }

    string namaPencarian;
    cout << "\nMasukkan nama kontak yang ingin dicari: ";
    cin >> namaPencarian;
    cout << "------------------------------------------";

    int indeksDitemukan = -1;
    for (int i = 0; i < jumlahKontak; i++) {
        if (kontak[i].nama == namaPencarian) {
            indeksDitemukan = i;
            break;
        }
    }

    if (indeksDitemukan == -1) {
    	cout << "\n============================================";
        cout << "\nKontak dengan nama tersebut tidak ditemukan.";
        cout << "\n============================================";
        return;
    }

    cout << "\nNama Kontak  : " << kontak[indeksDitemukan].nama << endl;
    cout << "Nomor Telepon: " << kontak[indeksDitemukan].telepon << endl;
    cout << "Email\t     : " << kontak[indeksDitemukan].email << endl;
}

void TampilkanKontak() {
    if (jumlahKontak <= 0) {
    	cout << "\n================================";
        cout << "\nTidak ada kontak yang tersimpan.";
        cout << "\n================================";
        return;
    }

    cout << "\nDaftar Kontak:";
    cout << "\n--------------";
    for (int i = 0; i < jumlahKontak; i++) {
        cout << "\nNama Kontak  : " << kontak[i].nama << endl;
        cout << "Nomor Telepon: " << kontak[i].telepon << endl;
        cout << "Email\t     : " << kontak[i].email << endl;
        cout << endl;
    }
}

int main() {
    int pilihan;

    do {
        cout << "Menu Kontak:" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Hapus Kontak" << endl;
        cout << "3. Cari Kontak" << endl;
        cout << "4. Tampilkan Semua Kontak" << endl;
        cout << "0. Keluar" << endl;
        cout << "\nPilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                TambahKontak();
                break;
            case 2:
                HapusKontak();
                break;
            case 3:
                CariKontak();
                break;
            case 4:
                TampilkanKontak();
                break;
            case 0:
            	cout << "\n===============================================";
                cout << "\nTerima kasih telah menggunakan aplikasi Kontak.";
                cout << "\n===============================================";
                break;
            default:
            	cout << "\n====================";
                cout << "\nPilihan tidak valid.";
                cout << "\n====================";
        }

        cout << endl;
    } while (pilihan != 0);

    return 0;
}
