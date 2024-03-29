#include <iostream>
#include <iomanip>

using namespace std;


struct KTP {
    string nama;
    string alamat;
    string nomorKTP;
    int umur;
};

void tampilkanData(const KTP& data) {
    cout << "Nama      : " << data.nama << endl;
    cout << "Alamat    : " << data.alamat << endl;
    cout << "Nomor KTP : " << data.nomorKTP << endl;
    cout << "Umur      : " << data.umur << " tahun" << endl;
    cout << endl;
}

void inputData(KTP& data) {
    cout << "Masukkan Nama      : ";
    getline(cin, data.nama);

    cout << "Masukkan Alamat    : ";
    getline(cin, data.alamat);

    cout << "Masukkan Nomor KTP : ";
    getline(cin, data.nomorKTP);

    cout << "Masukkan Umur      : ";
    cin >> data.umur;


    cin.ignore();
}


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


    int nomorHapus;
    cout << "Masukkan nomor data KTP yang ingin dihapus (1-" << jumlahData << "): ";
    cin >> nomorHapus;
    cin.ignore(); 

    if (nomorHapus >= 1 && nomorHapus <= jumlahData) {
        for (int i = nomorHapus - 1; i < jumlahData - 1; ++i) {
            dataKTP[i] = dataKTP[i + 1];
        }

        --jumlahData;

        cout << "Data KTP berhasil dihapus." << endl;
    } else {
        cout << "Nomor data KTP tidak valid." << endl;
    }

    cout << "\nData KTP setelah Penghapusan\n";
    for (int i = 0; i < jumlahData; ++i) {
        cout << "Data KTP ke-" << i + 1 << endl;
        tampilkanData(dataKTP[i]);
    }

    delete[] dataKTP;

    return 0;
}
