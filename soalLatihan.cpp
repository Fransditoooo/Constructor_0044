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

class Petugas {
private:
    string nama;
    int IDPetugas;
    string levelAkses;

public:
    Petugas(string n, int id, string akses) : nama(n), IDPetugas(id), levelAkses(akses) {}

    void prosesPinjam(Buku &b, Peminjam &p) {
        if (!b.dipinjam) {
            b.dipinjam = true;
            p.totalPinjaman++;
            cout << "Buku dipinjam oleh: " << p.nama << endl;
        } else {
            cout << "Buku sedang dipinjam." << endl;
        }
    }

    void prosesKembali(Buku &b, Peminjam &p) {
        if (b.dipinjam) {
            b.dipinjam = false;
            p.totalPinjaman--;
            cout << "Buku dikembalikan oleh: " << p.nama << endl;
        } else {
            cout << "Buku tidak sedang dipinjam." << endl;
        }
    }

    friend class Admin;
};

class Admin {
public:
    void ubahLevelAkses(Petugas &p, string levelBaru) {
        p.levelAkses = levelBaru;
        cout << "Level akses petugas diubah menjadi: " << levelBaru << endl;
    }

    friend void lihatStatistik(Admin a, Buku b);
    friend void lihatStatistik(Admin a, Peminjam p);
};

