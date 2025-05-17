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

