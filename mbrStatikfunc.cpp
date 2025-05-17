#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    static int nim;  // Static member variable
public:
    int id;
    string nama;

    void setID();
    void printAll();

    static void setNim(int pNim) { nim = pNim; }  // Static member function
    static int getNim() { return nim; }           // Static member function

    mahasiswa(string pnama) : nama(pnama) { setID(); }
};

int mahasiswa::nim = 0;  // Static variable initialization

void mahasiswa::setID() {
    id = ++nim;
}

void mahasiswa::printAll() {
    cout << "ID = " << id << endl;
    cout << "Nama = " << nama << endl;
    cout << endl;
}

int main() {
    mahasiswa mhs1("Sri Dadi");
    mahasiswa mhs2("Budi Jatmiko");
    mahasiswa::setNim(9); // Corrected from setMin to setNim
    mahasiswa mhs3("Andi Janu");
    mahasiswa mhs4("Joko Mahono");

    mhs1.printAll();
    mhs2.printAll();
    mhs3.printAll();
    mhs4.printAll();

    cout << "akses dari luar object = " << mahasiswa::getNim() << endl;

    return 0;
}