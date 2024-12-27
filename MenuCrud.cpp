#include <iostream>
#include <string>
#include <limits> // untuk numeric_limits
using namespace std;

struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

mahasiswa sikc[30];
int pos = -1;

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Fungsi untuk memasukkan satu data mahasiswa
void masukanData() {
    if (pos >= 29) { // Membatasi jumlah maksimal data
        cout << "Data penuh! Tidak bisa menambahkan data baru.\n";
        return;
    }
    pos++;
    clearScreen();
    cout << "Masukan NIM: ";
    getline(cin, sikc[pos].nim);
    cout << "Masukan Nama: ";
    getline(cin, sikc[pos].nama);
    cout << "Masukan Alamat: ";
    getline(cin, sikc[pos].alamat);
    cout << "Masukan IPK: ";
    cin >> sikc[pos].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer
    cout << "Data berhasil ditambahkan!\n";
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilkanSemuaData() {
    clearScreen();
    if (pos == -1) { // Jika tidak ada data
        cout << "Belum ada data yang dimasukkan.\n";
        return;
    }

    cout << "Data Mahasiswa:\n";
    cout << "------------------------------------\n";
    for (int i = 0; i <= pos; i++) {
        cout << "Data ke-" << i + 1 << ":\n";
        cout << "NIM     : " << sikc[i].nim << endl;
        cout << "Nama    : " << sikc[i].nama << endl;
        cout << "Alamat  : " << sikc[i].alamat << endl;
        cout << "IPK     : " << sikc[i].ipk << endl;
        cout << "------------------------------------\n";
    }
}

// Fungsi untuk memperbarui data mahasiswa berdasarkan indeks
void perbaruiData() {
    clearScreen();
    if (pos == -1) { // Jika tidak ada data
        cout << "Belum ada data yang dimasukkan.\n";
        return;
    }

    int index;
    cout << "Masukkan indeks data yang ingin diperbarui (1-" << pos + 1 << "): ";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

    if (index < 1 || index > pos + 1) {
        cout << "Indeks tidak valid.\n";
        return;
    }

    // Kurangi indeks dengan 1 untuk mencocokkan array
    index--;

    cout << "Data lama:\n";
    cout << "NIM     : " << sikc[index].nim << endl;
    cout << "Nama    : " << sikc[index].nama << endl;
    cout << "Alamat  : " << sikc[index].alamat << endl;
    cout << "IPK     : " << sikc[index].ipk << endl;

    cout << "\nMasukkan data baru:\n";
    cout << "Masukan NIM: ";
    getline(cin, sikc[index].nim);
    cout << "Masukan Nama: ";
    getline(cin, sikc[index].nama);
    cout << "Masukan Alamat: ";
    getline(cin, sikc[index].alamat);
    cout << "Masukan IPK: ";
    cin >> sikc[index].ipk;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

    cout << "Data berhasil diperbarui!\n";
}

// Fungsi untuk menghapus data mahasiswa berdasarkan indeks
void hapusData() {
    clearScreen();
    if (pos == -1) { // Jika tidak ada data
        cout << "Belum ada data yang dimasukkan.\n";
        return;
    }

    int index;
    cout << "Masukkan indeks data yang ingin dihapus (1-" << pos + 1 << "): ";
    cin >> index;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

    if (index < 1 || index > pos + 1) {
        cout << "Indeks tidak valid.\n";
        return;
    }

    // Kurangi indeks dengan 1 untuk mencocokkan array
    index--;

    // Geser elemen setelah indeks yang dihapus ke kiri
    for (int i = index; i < pos; i++) {
        sikc[i] = sikc[i + 1];
    }

    pos--; // Kurangi jumlah data
    cout << "Data berhasil dihapus!\n";
}

int main() {
    int pilihan;
    do {
        clearScreen();
        cout << "Menu Crud:\n";
        cout << "1. Masukkan Data\n";
        cout << "2. Tampilkan Semua Data\n";
        cout << "3. Perbarui Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Membersihkan input buffer

        switch (pilihan) {
        case 1:
            masukanData();
            break;
        case 2:
            tampilkanSemuaData();
            break;
        case 3:
            perbaruiData();
            break;
        case 4:
            hapusData();
            break;
        case 5:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }

        if (pilihan != 5) {
            cout << "\nTekan Enter untuk kembali ke menu...";
            cin.get();
        }
    } while (pilihan != 5);

    return 0;
}
