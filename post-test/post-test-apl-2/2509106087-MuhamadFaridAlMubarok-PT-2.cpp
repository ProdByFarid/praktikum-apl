#include <iostream>
using namespace std;

// Agar Lebih Mudah Nge-Run
// g++ 2509106087-MuhamadFaridAlMubarok-PT-2.cpp -o 2509106087-MuhamadFaridAlMubarok-PT-2.exe ; .\2509106087-MuhamadFaridAlMubarok-PT-2

#define putih   "\033[0m"
#define merah   "\033[31m"
#define biru    "\033[34m"
#define hijau   "\033[32m"
#define cyan    "\033[36m"
#define magenta "\033[35m"
#define abu     "\033[90m"

#define MAX_USER 100

struct User {
    string username;
    string password;
    string role;
};

User daftarAkun[MAX_USER];
int jumlahAkun = 0;


int main() {

    char pilihan;
    string judulAwal = R"(
====================================================
|                                                  |
|           Bienvenue au Musee du Louvre           |
|  Silahkan Login atau Registrasi terlebih dahulu  |
|                                                  |
|=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=|
|                                                  |
|  [1]. Login                                      |
|  [2]. Registrasi                                 |
|  [3]. Keluar                                     |
|                                                  |
====================================================
)";
    string judulRegistrasi = R"(
============================
|                          |
|     Registrasi Akun      |
|                          |
============================)";
    string judulLogin = R"(
======================
|                    |
|     Login Akun     |
|                    |
======================)";

    do {
        system("cls");
        cout << judulAwal << endl;
        cout << "Masukkan Opsi: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == '1') {

            int percobaan = 0;
            string usernameBenar, passwordBenar;
            
            while (percobaan < 3) {
                
                system("cls"); // perbaikin login
                cout << judulLogin << endl;
                cout << "\nMasukkan Username: ";
                getline(cin, usernameBenar);
                cout << "Masukkan Password: ";
                cin >> passwordBenar;
                
                if (percobaan == 3) {
                    cout << "[!] Percobaan Telah Habis. Akses Ditolak." << endl;
                    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                    cin.ignore(10000, '\n');
                    cin.get();
                    break;

                } else {
                    if (usernameBenar != daftarAkun[jumlahAkun].username || passwordBenar != daftarAkun[jumlahAkun].password) {
                        cout << "\nUsername Atau Password Salah" << endl;
                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.ignore(10000, '\n');
                        cin.get();
                        continue;

                    } else {
                        cout << "\nBerhasil Login" << endl;
                        cout << "Selamat Datang, " << usernameBenar;

                        cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                        cin.ignore(10000, '\n');
                        cin.get();
                        break;
                    }
                }
            }

        } else if (pilihan == '2') {

            if (jumlahAkun >= MAX_USER) {
                cout << "Maaf, Kapasitas Akun Pengguna Penuh" << endl;
                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                cin.ignore(10000, '\n');
                cin.get();
                continue;

            } else {
                string usernameBaru, passwordBaru, roleBaru;
                bool usernameAda = false;

                system("cls");
                cout << judulRegistrasi << endl;
                cout << "\nMasukkan Username Baru: ";
                getline(cin, usernameBaru);

                for (int i = 0; i < jumlahAkun; i++) {
                    if (daftarAkun[i].username == usernameBaru) {
                        usernameAda = true;
                        break;
                }
            }

            if (usernameAda) {
                cout << "Username Sudah Dipakai. Silahkan Pake Username Lain" << endl;
                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                cin.ignore(10000, '\n');
                cin.get();

            } else {
                cout << "Masukkan Password Baru: ";
                cin >> passwordBaru;
                cout << "Masukkan Role Baru: ";
                cin >> roleBaru;
    
                daftarAkun[jumlahAkun].username = usernameBaru;
                daftarAkun[jumlahAkun].password = passwordBaru;
                daftarAkun[jumlahAkun].role = roleBaru;
                jumlahAkun++;
        
                cout << hijau << "Akun berhasil dibuat! Silakan login." << putih << endl;
    
                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                cin.ignore(10000, '\n');
                cin.get();

                }
            }
        } else if (pilihan == '3') {
            
            }
        } while (pilihan != '3');
    
    
    return 0;
}