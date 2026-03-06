#include <iostream>
using namespace std;

#define putih   "\033[0m"
#define merah   "\033[31m"
#define biru    "\033[34m"
#define hijau   "\033[32m"
#define cyan    "\033[36m"
#define magenta "\033[35m"
#define abu     "\033[90m"

#define MAKS_USER 5
#define MAKS_DATA 100

struct User {
    string username;
    string password;
    string role;
};

struct Data {
    string judul;
    string namaPelukis;
    string tahun;
    string status;
};

User daftarAkun[MAKS_USER];
Data lukisan[MAKS_DATA];

int main() {

    int jumlahAkun = 0;
    int jumlahData = 0;
    char pilihan;

    do {
        system("cls");

        cout << "====================================================" << endl;
        cout << "|                                                  |" << endl;
        cout << "|           " << cyan << "Bienvenue au Musee du Louvre" << putih << "           |" << endl; // mau warnai tapi malas, nanti aja gin
        cout << "|      " << biru << "Login atau Registrasi terlebih dahulu" << putih << "       |" << endl;
        cout << "|                                                  |" << endl;
        cout << "|=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=|" << endl;
        cout << "|                                                  |" << endl;
        cout << "|  [1]. Login                                      |" << endl;
        cout << "|  [2]. Registrasi                                 |" << endl;
        cout << "|  [3]. Keluar                                     |" << endl;
        cout << "|                                                  |" << endl;
        cout << "====================================================" << endl;
        cout << "Masukkan Opsi: ";
        cin >> pilihan;
        cin.ignore(10000, '\n');

        if (pilihan == '1') {

            if (jumlahAkun == 0) {
                cout << merah << "[!] Error: Belum Ada Akun Yang Terdaftar!" << putih << endl;

                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                cin.get();
                continue;
            }

            int percobaan = 1;
            bool loginBerhasil = false;
            string usernameLogin, passwordLogin;
            string cekRole = "";

            while (percobaan <= 3) {

                system("cls");

                cout << "======================" << endl;
                cout << "|                    |" << endl;
                cout << "|     " << hijau << "Login Akun" << putih "     |" << endl;
                cout << "|                    |" << endl;
                cout << "======================" << endl;
                cout << "\nMasukkan Username: ";
                getline(cin, usernameLogin);
    
                cout << "Masukkan Password: ";
                cin >> passwordLogin;
                cin.ignore(10000, '\n');

                for (int i = 0; i < jumlahAkun; i++) {
                    if (usernameLogin == daftarAkun[i].username && passwordLogin == daftarAkun[i].password) {

                        loginBerhasil = true;
                        cekRole = daftarAkun[i].role;

                        cout << hijau << "[+] Login Berhasil!, Selamat Datang " << usernameLogin << '!' << putih << endl;

                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        break;
                    }
                }

                if (loginBerhasil) {

                    system("cls");

                    if (cekRole == "admin") {
                        
                        char pilihanAdmin;
                        
                        do
                        {
                            cout << "======================================" << endl;
                            cout << "|                                    |" << endl;
                            cout << "|             " << biru << "MENU ADMIN" << putih << "            |" << endl;
                            cout << "|                                    |" << endl;
                            cout << "==-=-=-=-=-=-=--=--=--=-=-=-=-=-=-=-==" << endl;
                            cout << "| [1]. Tambahkan Data Lukisan        |" << endl;
                            cout << "| [2]. Lihat Data Lukisan            |" << endl;
                            cout << "| [3]. Update Data Lukisan           |" << endl;
                            cout << "| [4]. Hapus Data Lukisan            |" << endl;
                            cout << "| [5]. Keluar                        |" << endl;
                            cout << "======================================" << endl;
                            cout << "Masukkan Pilihan: ";
                            cin >> pilihanAdmin;
                            
                            if (pilihanAdmin == '1') {
                                if (jumlahData < MAKS_DATA) {
                                    cout << merah << "[!] Kapasitas Data Sudah Penuh!" << putih << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();
                                } else {
                                    cout << "Judul Lukisan: ";
                                    cin.ignore();
                                    getline(cin, lukisan[jumlahData].judul);

                                    cout << "Nama Pelukis : ";
                                    cin.ignore();
                                    getline(cin, lukisan[jumlahData].namaPelukis);

                                    cout << "Tahun Dibuat : ";
                                    cin.ignore();
                                    getline(cin, lukisan[jumlahData].tahun);

                                    cout << "Status : ";
                                    cin.ignore();
                                    getline(cin, lukisan[jumlahData].status);
                                    
                                }
                            } else if (pilihanAdmin == '2') {
                                
                            }
                        } while (pilihanAdmin != 5);
                        
                    
                    }

                    else if (cekRole == "user") {
                        cout << biru << "\n=== MENU USER ===" << putih << endl;
                        cout << "1. Lihat Koleksi" << endl;

                    }
                    cout << abu << "\n[Tekan Enter Untuk Kembali...]" << putih;
                    cin.get();
                    
                    break;
                } else {
                    if (percobaan == 3) {
                        cout << merah << "[-] Login Gagal! Akses Ditolak!" << putih << endl;
    
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih << endl;
                        cout << endl;
                        break;

                        cin.get();
                    } else {
                        cout << merah << "[-] Login Gagal! Silahkan Coba Lagi" << putih << endl;
                        percobaan++;
                        cout << "\nJumlah Percobaan: " << percobaan - 1 << endl;
                        
        
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                    }
                }
            }
            break;

        } else if (pilihan == '2') {

            string pilihRole;

            while (true) {

                bool cekUsername = false;

                system("cls");
                if (jumlahAkun >= MAKS_USER) {

                    cout << "Maaf, Kapasitas Akun Pengguna Penuh" << endl;

                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                    cin.get();
                    break;

                } else {
                    cout << "============================" << endl;
                    cout << "|                          |" << endl;
                    cout << "|     " << hijau << "Registrasi Akun" << putih << "      |" << endl;
                    cout << "|                          |" << endl;
                    cout << "============================" << endl;
                    cout << "\nMasukkan Username: ";
                    getline(cin, daftarAkun[jumlahAkun].username);

                    for (int i = 0; i < jumlahAkun; i++) {
                        if (daftarAkun[jumlahAkun].username == daftarAkun[i].username) {
                            cekUsername = true;
                            break; 
                        }
                    }

                    if (cekUsername) {
                        cout << merah << "[!] Error: Username Telah Dipakai!" << putih << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        continue;
                    }

                    cout << "Masukkan Password: ";
                    cin >> daftarAkun[jumlahAkun].password;

                    cout << "Pilih Role (admin/user): ";
                    cin >> pilihRole;
                    cin.ignore(10000, '\n');

                    if (pilihRole == "admin" || pilihRole == "Admin" || pilihRole == "ADMIN") {

                        daftarAkun[jumlahAkun].role = "admin";
                        jumlahAkun++;

                        cout << hijau << "\n[+] Akun Berhasil Dibuat!" << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih; // kasi status role nya, sama dibawahnya jua
                        cin.get();

                        break;

                    } else if (pilihRole == "user" || pilihRole == "User" || pilihRole == "USER") {

                        daftarAkun[jumlahAkun].role = "user";
                        jumlahAkun++;

                        cout << hijau << "\n[+] Akun Berhasil Dibuat! Silahkan Login!" << putih << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        break;

                    } else {

                        cout << merah << "[!] Error: Role Tidak Valid!" << putih << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();
                    }
                }
            }

        } else if (pilihan == '3') {

            cout << "Anda Keluar Dari Program. :)" << endl;

            cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
            cin.get();

        } else {

            cout << merah << "[!] Error: Pilihan Tidak Valid!" << putih << endl;

            cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
            cin.get();
        }

    } while (pilihan != '3');

    

    return 0;
}