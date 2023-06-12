#include <iostream>
using namespace std;

class bidangdatar {  
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun bujursangkar

public:
    bidangdatar() { // constructor
        x = 0;
    }

    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x
    
    virtual float Luas(int a) = 0; // fungsi untuk menghitung luas
    
    virtual float Keliling(int a) = 0; // fungsi untuk menghitung keliling
    
    void setX(int a) { // enkapsulasi (mutator method) fungsi untuk memberi/mengirim nilai  ke dalam variabel x di kelas bidangdatar.
        this->x = a;
    }
    int getX() { // enkapsulasi. fungsi untuk membaca/mengambil nilai dalam x (assesor method)
        return x;
    }
}; 



class Lingkaran : public bidangdatar {  // inheritance/pewarisan
public:
    void input() {
        cout << "Masukkan jari-jari: ";
        int r;
        cin >> r;
        setX(r);   // enkapsulasi (mutator method) yg digunakan untuk memberi atau mengubah nilai variable dalam kelas  
    }

    float Luas(int r) {
        return 3.14 * r * r;   // rumus Luas Lingkarang
    }

    float Keliling(int r) {
        return 2 * 3.14 * r;    // // rumus Keliling Lingkarang
    }
};


class Bujursangkar : public bidangdatar {  // inheritance/pewarisan 
public:
    void input() {
        cout << "Masukkan sisi: ";
        int s;
        cin >> s;
        setX(s);
    }

    float Luas(int s) {
        return s * s;
    }

    float Keliling(int s) {
        return 4 * s;
    }
};

int main() {
    bidangdatar* bd;

    cout << "Lingkaran dibuat" << endl;
    bd = new Lingkaran();  // Operator new digunakan untuk mengalokasikan memori dan membuat objek dari kelas turunan,  kemudian ditunjuk oleh pointer bd.
    bd->input();
    int r = bd->getX();
    cout << "Luas Lingkaran = " << bd->Luas(r) << endl;
    cout << "Keliling Lingkaran = " << bd->Keliling(r) << endl;

    cout << "Bujursangkar dibuat" << endl;
    bd = new Bujursangkar();
    bd->input();
    int s = bd->getX();
    cout << "Luas Bujursangkar = " << bd->Luas(s) << endl;
    cout << "Keliling Bujursangkar = " << bd->Keliling(s) << endl;

    delete bd;
    return 0;

};

