#include<iostream>
#include<stack>

using namespace std;

struct Sepeda {
    string merk, nama, warna, speed, tahun, harga;
};
	
Sepeda katalog[50];
int jumlahSepeda = 0;

stack<string> laporanStack;

void bubbleSort() {
    for (int i = 0; i < jumlahSepeda - 1; i++) {
        for (int j = 0; j < jumlahSepeda - i - 1; j++) {
            if (katalog[j].tahun > katalog[j + 1].tahun) {
                Sepeda temp = katalog[j];
                katalog[j] = katalog[j + 1];
                katalog[j + 1] = temp;
            }
        }
    }
}

void tampilkanKatalog(string merk) {
	bubbleSort();
    cout << "\n=============== Katalog Sepeda ===============" << endl;
    for (int i = 0; i < jumlahSepeda; i++) {
        if (katalog[i].merk == merk || merk == "Semua") {
            cout << "\nMerk: " << katalog[i].merk << endl;
            cout << "Nama: " << katalog[i].nama << endl;
            cout << "Spesifikasi" << endl;
            cout << "Speed: " << katalog[i].speed << endl;
            cout << "Warna: " << katalog[i].warna << endl;
            cout << "Tahun: " << katalog[i].tahun << endl;
            cout << "\n----------------------------------------------" << endl;
        }
    }
}

void tambahKatalog() {
    bubbleSort();
    Sepeda katalogBaru;
    cout << "\nMerk: ";
    cin >> katalogBaru.merk;
    cout << "Nama: ";
    cin >> katalogBaru.nama;
    cin.ignore();
    getline(cin, katalogBaru.nama);
    cout << "Spesifikasi" << endl;
    cout << "Speed: ";
    cin >> katalogBaru.speed;
    cout << "Warna: ";
    cin >> katalogBaru.warna;
    cout << "Tahun: ";
    cin >> katalogBaru.tahun;
    cout << "Harga: Rp.";
    cin >> katalogBaru.harga;

    katalog[jumlahSepeda] = katalogBaru;
    jumlahSepeda++;

    cout << "\nKatalog berhasil ditambahkan!" << endl;
}

void prediksiHarga() {
    string merk;
    cout << "\n=============== Prediksi Harga ===============" << endl;
    cout << "\nMasukkan merk sepeda : ";
    cin >> merk;

    bool ditemukan = false;
    for (int i = 0; i < jumlahSepeda; i++) {
        if (katalog[i].merk == merk) {
            cout << "\nNama: " << katalog[i].nama << endl;
            cout << "Harga: Rp." << katalog[i].harga << endl;
            cout << "\n----------------------------------------------" << endl;
            ditemukan = true;
        }
    }
    if (!ditemukan) {
        cout << "Tidak ada sepeda dengan merk tersebut." << endl;
    }
}

void laporan() {
    cout << "\n=================== Laporan ==================" << endl;
    stack<string> tempStack = laporanStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << endl;
        tempStack.pop();
    }
    
    cout << "\nJumlah katalog yang sudah diinput :" << endl;

    int jumlahPolygon = 0;
    int jumlahWimcycle = 0;
    for (int i = 0; i < jumlahSepeda; i++) {
        if (katalog[i].merk == "Polygon") {
            jumlahPolygon++;
        } else if (katalog[i].merk == "Wimcycle") {
            jumlahWimcycle++;
        }
    }

    cout << "\nPolygon: " << jumlahPolygon << " katalog" << endl;
    cout << "Wimcycle: " << jumlahWimcycle << " katalog" << endl;
    cout << "\n----------------------------------------------" << endl;
}

int main() {
    cout << "    SELAMAT DATANG DI WARUNG PIT    " << endl;
    cout << "------------------------------------" << endl;
    int pilihan;
    int merkPilihan;

    do {
        cout << "1. Tampilkan Katalog" << endl;
        cout << "2. Tambah Katalog" << endl;
        cout << "3. Prediksi Harga" << endl;
        cout << "4. Laporan" << endl;
        cout << "0. Keluar" << endl;
        cout << "\nPilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\nPilih merk sepeda:" << endl;
                cout << "1. Polygon" << endl;
                cout << "2. Wimcycle" << endl;
                cout << "\nPilihan: ";
                cin >> merkPilihan;

                if (merkPilihan == 1) {
                    tampilkanKatalog("Polygon");
                } else if (merkPilihan == 2) {
                    tampilkanKatalog("Wimcycle");
                } else {
                    cout << "Pilihan tidak valid!" << endl;
                }
                break;
            case 2:
                tambahKatalog();
                break;
            case 3:
                prediksiHarga();
                break;
            case 4:
                laporan();
                break;
            case 0:
                cout << "\nTerima Kasih!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid!" << endl;
                break;
        }
        
        cout << endl;
    } while (pilihan != 0);

    return 0;
}
