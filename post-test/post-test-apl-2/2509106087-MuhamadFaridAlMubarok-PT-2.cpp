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

const int MAX_USER = 100;

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
|      Nouveau compte      |
|                          |
============================)";
    string judulLogin = R"(
=======================
|                     |
|      Connexion      |
|                     |
=======================)";

    do {
        system("cls");
        cout << judulAwal << endl;
        cout << "Masukkan Opsi: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == '1') {

            system("cls");
            string usernameBenar, passwordBenar;

            cout << judulLogin << endl;
            cout << "\nMasukkan Username: ";
            getline(cin, usernameBenar);
            cout << "\nMasukkan Password: ";
            getline(cin, passwordBenar);

        } else if (pilihan == '2') {

            if (jumlahAkun >= MAX_USER) {
                cout << "Maaf, Kapasitas Pengguna Penuh" << endl;
                cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
                cin.ignore(10000, '\n');
                cin.get();
                continue;

            } else {

            int percobaan = 0;
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
                continue;
            }

            cout << "Masukkan Password Baru: " << endl;
            getline(cin, usernameBaru);
            cout << "Masukkan Role Baru: " << endl;
            getline(cin, roleBaru);

            daftarAkun[jumlahAkun].username = usernameBaru;
            daftarAkun[jumlahAkun].password = passwordBaru;
            daftarAkun[jumlahAkun].role = roleBaru;
            jumlahAkun++;
    
            cout << hijau << "Akun berhasil dibuat! Silakan login." << putih << endl;

            cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
            cin.get();

            }
        } else if (pilihan == '3') {
            
        }
        } while (pilihan != '3');

    return 0;
}