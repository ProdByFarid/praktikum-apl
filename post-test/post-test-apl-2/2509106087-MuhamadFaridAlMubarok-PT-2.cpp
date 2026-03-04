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

#define MAX_USER = 10

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

    do {

        system("cls");
        cout << judulAwal << endl;
        cout << "Masukkan Opsi: ";
        cin >> pilihan;

        if (pilihan == '1') {
            cout << endl;
        } else if (pilihan == '2') {
            
            int percobaan = 0;
            string usernameBaru, passwordBaru;

            while (percobaan < 3) {

                cout << judulRegistrasi << endl;
                cout << "Masukkan Username Baru: ";
                getline(cin, usernameBaru);
                cout << "Masukkan Password Baru: ";
                getline(cin, passwordBaru);

            }
        } else if (pilihan == '3') {
            
        }
        } while (pilihan != '4');

    return 0;
}