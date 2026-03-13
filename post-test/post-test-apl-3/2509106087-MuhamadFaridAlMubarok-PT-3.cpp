#include <iostream>
#include <iomanip>
#include <conio.h>

// g++ 2509106087-MuhamadFaridAlMubarok-PT-3.cpp -o 2509106087-MuhamadFaridAlMubarok-PT-3.exe ; .\2509106087-MuhamadFaridAlMubarok-PT-3

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

void jeda() {
    cout << abu << "\n[Tekan Enter Untuk Melanjutkan...]" << putih;
    getche();
}

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
int jumlahAkun = 2;
int jumlahData = 10;

void menuUtama() {
    cout << "====================================================" << endl;
    cout << "|                                                  |" << endl;
    cout << "|           " << cyan << "Bienvenue au Musee du Louvre" << putih << "           |" << endl;
    cout << "|      " << biru << "Login atau Registrasi terlebih dahulu" << putih << "       |" << endl;
    cout << "|                                                  |" << endl;
    cout << "|=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=|" << endl;
    cout << "|                                                  |" << endl;
    cout << "|  [1]. Login                                      |" << endl;
    cout << "|  [2]. Registrasi                                 |" << endl;
    cout << "|  [3]. Keluar Program                             |" << endl;
    cout << "|                                                  |" << endl;
    cout << "====================================================" << endl;
}

void menuLogin() {
    cout << "======================" << endl;
    cout << "|                    |" << endl;
    cout << "|    " << hijau << "Login Akun" << putih << "   |" << endl;
    cout << "|                    |" << endl;
    cout << "======================" << endl;
}

void menuRegister() {
    cout << "============================" << endl;
    cout << "|                          |" << endl;
    cout << "|     " << hijau << "Registrasi Akun" << putih << "      |" << endl;
    cout << "|                          |" << endl;
    cout << "============================" << endl;
}

void menuAdmin() {
    cout << "======================================" << endl;
    cout << "|                                    |" << endl;
    cout << "|            " << biru << "MENU ADMIN" << putih << "           |" << endl;
    cout << "|                                    |" << endl;
    cout << "==-=-=-=-=-=-=--=--=--=-=-=-=-=-=-=-==" << endl;
    cout << "| [1]. Tambahkan Data Lukisan        |" << endl;
    cout << "| [2]. Lihat Data Lukisan            |" << endl;
    cout << "| [3]. Update Data Lukisan           |" << endl;
    cout << "| [4]. Hapus Data Lukisan            |" << endl;
    cout << "| [5]. Logout                        |" << endl;
    cout << "======================================" << endl;
}

void menuUser() {
    cout << "======================================" << endl;
    cout << "|                                    |" << endl;
    cout << "|            " << biru << "MENU USER " << putih << "           |" << endl;
    cout << "|                                    |" << endl;
    cout << "==-=-=-=-=-=-=--=--=--=-=-=-=-=-=-=-==" << endl;
    cout << "| [1]. Lihat Data Lukisan            |" << endl;
    cout << "| [2]. Logout                        |" << endl;
    cout << "======================================" << endl;
}

void tabelLukisan() {
    cout << "========================================================================================" << endl;
    cout << "| " << cyan << setw(3) << left << "NO" << putih 
        "| " << biru << setw(30) << left << "JUDUL" << putih 
    << "| " << biru << setw(25) << left << "NAMA PELUKIS" << putih
    << "| " << biru << setw(6) << left << "TAHUN" << putih
    << "| " << emas << setw(12) << left << "STATUS" << putih << " |" << endl;
    cout << "========================================================================================" << endl;

    for (int i = 0; i < jumlahData; i++) {
    cout << "| " << setw(3) << left << i + 1
    << "| " << setw(30) << left << lukisan[i].judul
    << "| " << setw(25) << left << lukisan[i].namaPelukis 
    << "| " << setw(6) << left << lukisan[i].tahun 
    << "| " << setw(10) << lukisan[i].status << " |" << endl;
}
cout << "========================================================================================" << endl;
}

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

    tabelLukisan();

    return 0;

}


