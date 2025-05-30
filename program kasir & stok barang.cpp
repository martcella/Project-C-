#include <iostream>
#include <iomanip>
#include <map>
#include <string>

using namespace std;
void showItems(map<string, int>& items, map<string, int>& prices) {
	cout << "-----------------------------------------------" << endl;
    cout << left << setw(20) << "Barang" << setw(21) << "Stok" << setw(26) << "Harga" << endl;
    cout << "-----------------------------------------------" << endl;
    for (auto item : items) {
        cout <<left<<setw(16)<<item.first<<setw(1)<<item.second/12<<" box "<<item.second%12
		<<" pcs	"<< setw(1)<<"	Rp."<<prices[item.first]<<endl;
    }
    cout << "-----------------------------------------------" << endl;
    cout << endl;
}

void stok(map<string, int>& items, map<string, int>& prices) {
	cout << "-----------------------------------------------" << endl;
    cout << left << setw(20) << "Barang" << setw(21) << "Stok" << setw(26) << "Harga" << endl;
    cout << "-----------------------------------------------" << endl;
    for (auto item : items) {
        cout <<left<<setw(16)<<item.first<<setw(1)<<item.second/12<<" box "<<item.second%12
		<<" pcs	"<< setw(1)<<"	Rp."<<prices[item.first]<<endl;
    }
    cout << "-----------------------------------------------" << endl;
    cout << endl;
}

int main() {
    map<string, int> items = {
        {"Pensil", 60},    
        {"Pulpen", 42},    
        {"Rautan", 49},   
        {"Kertas", 90}    
    };
    
    map<string, int> prices = {
        {"Pensil", 2500},
        {"Pulpen", 3000},
        {"Rautan", 7000},
        {"Kertas", 1000}
    };

    string item;
    int qty, bayar, total, nama_barang, points, harga_grosir;
    char member;

    showItems(items,prices);
	
	cout << "Member (y/n)	: ";
    cin >> member;
    cout << "Nama Barang	: ";
    cin >> item;
    cout << "Jumlah		: ";
    cin >> qty;
    cout << endl;

    if (items.count(item) == 0) {
        cout << "Barang tidak tersedia." << endl;
    } else {
        if (items[item] < qty) {
            cout << "Stok tidak mencukupi." << endl;
        } else {
            if (qty < 12) {
                harga_grosir = prices[item];
            } else if (qty >= 12 && qty <= 23) {
                harga_grosir = prices[item] * 0.9;
            } else if (qty >= 24 && qty <= 35) {
                harga_grosir = prices[item] * 0.85;
            } else {
                harga_grosir = prices[item] * 0.8;
            }
            
	total = qty * harga_grosir;
    items[item] -= qty;
            
	if (member == 'y') {
                points += total / 1000;    
            }
            
	cout << "------------------------------------------------------------" << endl;
	cout << "                        STRUK BELANJA                       " << endl;
	cout << "------------------------------------------------------------" << endl;
	cout << "Barang      Jumlah         Harga       Grosir      Sub Total" << endl;
	cout <<setw(10)<<item<<setw(1)<<qty/12<<" box "<<qty%12<<setw(11)<<" pcs"<<setw(13)
	<<prices[item]<<setw(14)<<harga_grosir<<setw(15)<<total<< endl; 
	cout << "------------------------------------------------------------" << endl;
    cout << "Poin	: " << points << endl;
	cout << "Total  	: Rp." << total << endl;
    cout << "Tunai	: Rp.";
    cin >> bayar;
    cout << "Kembali	: Rp." << bayar-total << endl;
    cout << endl;
    cout << "Update Stok" << endl;
	
    stok(items, prices);
       
        }
    }
}
