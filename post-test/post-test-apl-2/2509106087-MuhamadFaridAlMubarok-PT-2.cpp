#include <iostream>
#include <iomanip>

using namespace std;

#define putih   "\033[0m"
#define merah   "\033[31m"
#define biru    "\033[34m"
#define hijau   "\033[32m"
#define cyan    "\033[36m"
#define magenta "\033[35m"
#define abu     "\033[90m"
#define emas    "\033[38;5;220m" 

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

    daftarAkun[0] = {"farid", "087", "admin"};
    daftarAkun[1] = {"parid", "087", "user"};

    lukisan[0] = {"Mona Lisa", "Leonardo Da Vinci", "1503", "Dipamerkan"};
    lukisan[1] = {"The Weeding Feast at Cana", "Paolo Veronese", "1563", "Dipamerkan"};
    lukisan[2] = {"Liberty Leading the People", "Eugene Delacroix", "1830", "Restorasi"};
    lukisan[3] = {"The Raft of the Medusa", "Theodore Gericault", "1819", "Dipamerkan"};
    lukisan[4] = {"The Coronation of Napoleon", "Jacques-Louis David", "1807", "Disimpan"};
    lukisan[5] = {"Virgin of the Rocks", "Leonardo da Vinci", "1486", "Dipamerkan"};
    lukisan[6] = {"The Lacemaker", "Johannes Vermeer", "1670", "Restorasi"};
    lukisan[7] = {"Spring", "Giuseppe Arcimboldo", "1573", "Restorasi"};
    lukisan[8] = {"The Fortune Teller", "Caravaggio", "1594", "Dipamerkan"};
    lukisan[9] = {"Woman with a Mirror", "Titian", "1515", "Dipamerkan"};

    int jumlahAkun = 2;
    int jumlahData = 10;
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
                cout << " |    " << hijau << "Login Akun" << putih "    |" << endl;
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

                        cout << hijau << "\n[+] Login Berhasil!, Selamat Datang " << usernameLogin << '!' << putih << endl;

                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        break;
                    }
                }

                if (loginBerhasil) {

                    
                    if (cekRole == "admin") {
                        
                        char pilihanAdmin;
                        
                        do
                        {
                            system("cls");
                            cout << "======================================" << endl;
                            cout << "|                                    |" << endl;
                            cout << " |            " << biru << "MENU ADMIN" << putih << "            |" << endl;
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
                                if (jumlahData == MAKS_DATA) {
                                    cout << merah << "\n[!] Kapasitas Data Sudah Penuh!" << putih << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();

                                } else {
                                    cout << "\nJudul Lukisan: ";
                                    cin.ignore();
                                    getline(cin, lukisan[jumlahData].judul);
                                    cout << "Nama Pelukis : ";
                                    getline(cin, lukisan[jumlahData].namaPelukis);
                                    cout << "Tahun Dibuat : ";
                                    getline(cin, lukisan[jumlahData].tahun);
                                    cout << "Status : ";
                                    getline(cin, lukisan[jumlahData].status);
                                    
                                    jumlahData++;

                                    cout << hijau << "\n[+] Data Berhasil Ditambahkan." << putih << endl ;
                                    
                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();
                                }
                            } else if (pilihanAdmin == '2') {
                                if (jumlahData == 0) {
                                    cout << merah << "[!] Belum Ada Data." << putih << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();

                                } else {
                                    system("cls");
                                    cout << "======================================================================================" << endl;
                                    cout << "| " << cyan << setw(3) << left << "NO" << putih 
                                            "| " << biru << setw(30) << left << "JUDUL" << putih 
                                        << "| " << biru << setw(25) << left << "NAMA PELUKIS" << putih
                                        << "| " << biru << setw(6) << left << "TAHUN" << putih
                                        << "| " << emas << setw(10) << left << "STATUS" << putih << " |" << endl;
                                    cout << "======================================================================================" << endl;

                                    for (int i = 0; i < jumlahData; i++) {
                                    cout << "| " << setw(3) << left << i + 1
                                        << "| " << setw(30) << left << lukisan[i].judul
                                        << "| " << setw(25) << left << lukisan[i].namaPelukis 
                                        << "| " << setw(6) << left << lukisan[i].tahun 
                                        << "| " << setw(10) << lukisan[i].status << " |" << endl;
                                    }
                                    cout << "======================================================================================" << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.ignore(10000, '\n');
                                    cin.get();

                                    system("cls");
                                } 

                            } else if (pilihanAdmin == '3') {

                                int indeks;

                                if (jumlahData == 0) {
                                    cout << merah << "\n[!] Belum Ada Data." << putih << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();
                                } else {
                                    system("cls");
                                    
                                    cout << "======================================================================================" << endl;
                                    cout << "| " << cyan << setw(3) << left << "NO" << putih 
                                            "| " << biru << setw(30) << left << "JUDUL" << putih 
                                        << "| " << biru << setw(25) << left << "NAMA PELUKIS" << putih
                                        << "| " << biru << setw(6) << left << "TAHUN" << putih
                                        << "| " << emas << setw(10) << left << "STATUS" << putih << " |" << endl;
                                    cout << "======================================================================================" << endl;
                                    for (int i = 0; i < jumlahData; i++) {
                                    cout << "| " << setw(3) << left << i + 1
                                        << "| " << setw(30) << left << lukisan[i].judul
                                        << "| " << setw(25) << left << lukisan[i].namaPelukis 
                                        << "| " << setw(6) << left << lukisan[i].tahun 
                                        << "| " << setw(10) << lukisan[i].status << " |" << endl;
                                    }
                                    cout << "======================================================================================" << endl;

                                    cout << "\nMasukkan Nomor Data Yang Ingin DiUpdate: ";
                                    cin >> indeks;

                                    cin.ignore(10000, '\n');

                                    if (indeks > 0 && indeks <= jumlahData) {
                                        cout << "Judul Lukisan (Baru): ";
                                        getline(cin, lukisan[indeks - 1].judul);

                                        cout << "Nama Pelukis (Baru): ";
                                        getline(cin, lukisan[indeks - 1].namaPelukis);

                                        cout << "Tahun Dibuat (Baru): ";
                                        getline(cin, lukisan[indeks - 1].tahun);

                                        cout << "Status (Baru): ";
                                        getline(cin, lukisan[indeks - 1].status);

                                        cout << hijau << "\n[+]Data Lukisan Berhasil Di-Update!" << putih << endl;

                                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                        cin.get();

                                    } else {
                                        cout << merah << "\n[!] Error: Pilihan Data Tidak Valid!" << putih << endl;

                                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                        cin.get();
                                        continue;
                                    }
                                }
                            }

                        } while (pilihanAdmin != '5');
                        
                    } else if (cekRole == "user") {

                        char pilihanUser;

                            do {
                                system("cls");
                                cout << "======================================" << endl;
                                cout << "|                                    |" << endl;
                                cout << " |            " << biru << "MENU USER " << putih << "            |" << endl;
                                cout << "|                                    |" << endl;
                                cout << "==-=-=-=-=-=-=--=--=--=-=-=-=-=-=-=-==" << endl;
                                cout << "| [1]. Lihat Data Lukisan            |" << endl;
                                cout << "| [2]. Keluar                        |" << endl;
                                cout << "======================================" << endl;
                                cout << "Masukkan Pilihan: ";
                                cin >> pilihanUser;

                                if (pilihanUser == '1') {
                                    if (jumlahData == 0) {
                                    cout << merah << "\n[!] Data Belum Ada." << putih << endl;

                                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                    cin.get();

                                    } else {
                                        system("cls");
                                        cout << "--------------------------------------------------------------------------------------" << endl;
                                        cout << "| " << cyan << setw(3) << left << "NO" << putih 
                                                "| " << biru << setw(30) << left << "JUDUL" << putih 
                                            << "| " << biru << setw(25) << left << "NAMA PELUKIS" << putih
                                            << "| " << biru << setw(6) << left << "TAHUN" << putih
                                            << "| " << emas << setw(10) << left << "STATUS" << putih << " |" << endl;
                                        cout << "--------------------------------------------------------------------------------------" << endl;

                                        for (int i = 0; i < jumlahData; i++) {
                                        cout << "| " << setw(3) << left << i + 1
                                            << "| " << setw(30) << left << lukisan[i].judul
                                            << "| " << setw(25) << left << lukisan[i].namaPelukis 
                                            << "| " << setw(6) << left << lukisan[i].tahun 
                                            << "| " << setw(10) << lukisan[i].status << " |" << endl;
                                        }
                                        cout << "--------------------------------------------------------------------------------------" << endl;

                                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                        cin.ignore(10000, '\n');
                                        cin.get();

                                        system("cls");

                                    }

                            } else if (pilihanUser == '2') {
                                cout << merah << "\n[-] Anda Akan Keluar Dari Menu Ini." << putih << endl;

                                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                                cin.ignore(10000, '\n');
                                cin.get();

                                break;
                            }

                        } while (pilihanUser != 2);
                        
                    }

                } else {
                    if (percobaan == 3) {
                        cout << merah << "\n[-] Login Gagal! Akses Ditolak!" << putih << endl;
                        cout << endl;

                        break;
                    } else {
                        cout << merah << "\n[-] Username Atau Password! Silahkan Coba Lagi!" << putih << endl;
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
                if (jumlahAkun == MAKS_USER) {
                    cout << "============================" << endl;
                    cout << "|                          |" << endl;
                    cout << "|     " << hijau << "Registrasi Akun" << putih << "      |" << endl;
                    cout << "|                          |" << endl;
                    cout << "============================" << endl;
                    cout << merah << "\n[!] Error: Kapasitas Akun Pengguna Penuh" << putih << endl;

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
                        cout << merah << "\n[!] Error: Username Telah Dipakai!" << putih << endl;
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

                        cout << hijau << "\n[+] Akun Berhasil Dibuat! Silahkan Login!" << endl;
                        cout << "[+] Role: " << pilihRole << putih << endl;
                        
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        break;

                    } else if (pilihRole == "user" || pilihRole == "User" || pilihRole == "USER") {

                        daftarAkun[jumlahAkun].role = "user";
                        jumlahAkun++;

                        cout << hijau << "\n[+] Akun Berhasil Dibuat! Silahkan Login!" << endl;
                        cout << "[+] Role: " << pilihRole << putih << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();

                        break;

                    } else {

                        cout << merah << "\n[!] Error: Role Tidak Valid!" << putih << endl;

                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.get();
                    }
                }
            }

        } else if (pilihan == '3') {

            cout << merah << "\n[-] Anda Keluar Dari Program." << putih << endl;
            cout << endl;

        } else {

            cout << merah << "\n[!] Error: Pilihan Tidak Valid!" << putih << endl;

            cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
            cin.get();
        }

    } while (pilihan != '3');

    return 0;

}