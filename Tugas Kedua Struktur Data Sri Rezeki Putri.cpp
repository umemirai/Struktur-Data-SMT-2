#include <iostream>
#include <iomanip>

using namespace std;

// Deklarasi struct untuk data KTP
struct KTP {
    string nama;
    string alamat;
    string nomorKTP;
    int umur;
};

// Fungsi untuk menampilkan data KTP
void tampilkanData(const KTP& data) {
    cout << "Nama      : " << data.nama << endl;
    cout << "Alamat    : " << data.alamat << endl;
    cout << "Nomor KTP : " << data.nomorKTP << endl;
    cout << "Umur      : " << data.umur << " tahun" << endl;
    cout << endl;
}

// Fungsi untuk menginput data KTP
void inputData(KTP& data) {
    cout << "Masukkan Nama      : ";
    getline(cin, data.nama);

    cout << "Masukkan Alamat    : ";
    getline(cin, data.alamat);

    cout << "Masukkan Nomor KTP : ";
    getline(cin, data.nomorKTP);

    cout << "Masukkan Umur      : ";
    cin >> data.umur;

    // Membersihkan buffer input setelah penggunaan cin
    cin.ignore();
}

// Fungsi untuk mengedit data KTP
void editData(KTP& data) {
    cout << "Edit Data KTP" << endl;
    cout << "---------------" << endl;

    cout << "Nama Baru      : ";
    getline(cin, data.nama);

    cout << "Alamat Baru    : ";
    getline(cin, data.alamat);

    cout << "Nomor KTP Baru : ";
    getline(cin, data.nomorKTP);

    cout << "Umur Baru      : ";
    cin >> data.umur;

    // Membersihkan buffer input setelah penggunaan cin
    cin.ignore();
}

int main() {
    int jumlahData;
    cout << "Masukkan jumlah data KTP: ";
    cin >> jumlahData;
    cin.ignore(); 

    
    KTP *dataKTP = new KTP[jumlahData];

    
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Data KTP ke-" << i + 1 << endl;
        inputData(dataKTP[i]);
    }


    cout << "\nData KTP yang Dimasukkan\n";
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Data KTP ke-" << i + 1 << endl;
        tampilkanData(dataKTP[i]);
    }

    
    int nomorEdit;
    cout << "Masukkan nomor data KTP yang ingin diedit (1-" << jumlahData << "): ";
    cin >> nomorEdit;
    cin.ignore(); 

    if (nomorEdit >= 1 && nomorEdit <= jumlahData) {
        editData(dataKTP[nomorEdit - 1]);

        
        cout << "\nData KTP setelah Diedit\n";
        tampilkanData(dataKTP[nomorEdit - 1]);
    } else {
        cout << "Nomor data KTP tidak valid." << endl;
    }


    delete[] dataKTP;

    return 0;
}
