#include <iostream>
#include <string>
using namespace std;

class Petugas;
class Admin;

class Buku {
private:
    string judul;
    string penulis;
    bool dipinjam;

public:
    Buku(string j, string p) : judul(j), penulis(p), dipinjam(false) {}

    void tampilkanInfo() {
        cout << "Judul: " << judul << ", Penulis: " << penulis << ", Status: " 
             << (dipinjam ? "Dipinjam" : "Tersedia") << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(Admin a, Buku b);
};

class Peminjam {
private:
    string nama;
    int ID;
    int totalPinjaman;

public:
    Peminjam(string n, int id) : nama(n), ID(id), totalPinjaman(0) {}

    void tampilkanInfo() {
        cout << "Nama: " << nama << ", ID: " << ID << ", Total Pinjaman: " << totalPinjaman << endl;
    }

    friend class Petugas;
    friend void lihatStatistik(Admin a, Peminjam p);
};

