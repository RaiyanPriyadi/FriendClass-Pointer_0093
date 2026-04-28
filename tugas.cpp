#include <iostream>
using namespace std;

class LayangLayang; // Deklarasi maju (Forward declaration)

class BelahKetupat {
private:
    double d1, d2, sisi;
    
public:
    void input();
    void output();
    double luas();
    
    // Method keliling normal milik Belah Ketupat
    double keliling(); 
    
    // Method keliling (overloading) yang akan dijadikan friend oleh Layang-Layang
    void keliling(LayangLayang &l);
};

class LayangLayang {
private:
    double d1, d2, sisi_pendek, sisi_panjang;

    // Mendeklarasikan method keliling dari BelahKetupat sebagai friend
    // Agar method ini bisa mengakses variabel private di atas.
    friend void BelahKetupat::keliling(LayangLayang &l);

public:
    void input();
    void output();
    double luas();
    double keliling();
};

// ==========================================
// Implementasi Method Class BelahKetupat
// ==========================================
void BelahKetupat::input() {
    cout << "\n--- Input Belah Ketupat ---\n";
    cout << "Masukkan diagonal 1  : "; cin >> d1;
    cout << "Masukkan diagonal 2  : "; cin >> d2;
    cout << "Masukkan panjang sisi: "; cin >> sisi;
}

double BelahKetupat::luas() {
    return 0.5 * d1 * d2;
}

double BelahKetupat::keliling() {
    return 4 * sisi;
}

void BelahKetupat::output() {
    cout << "\n[Hasil Belah Ketupat]\n";
    cout << "Luas     : " << luas() << "\n";
    cout << "Keliling : " << keliling() << "\n";
}

// Implementasi Friend Method
// Meskipun berada di class BelahKetupat, ia dapat memanggil sisi_pendek & sisi_panjang 
// yang sifatnya private di dalam objek LayangLayang.
void BelahKetupat::keliling(LayangLayang &l) {
    double kel_layang = 2 * (l.sisi_pendek + l.sisi_panjang);
    cout << "Keliling Layang-Layang (dihitung via Friend Method Belah Ketupat): " << kel_layang << "\n";
}

// ==========================================
// Implementasi Method Class LayangLayang
// ==========================================
void LayangLayang::input() {
    cout << "\n--- Input Layang-Layang ---\n";
    cout << "Masukkan diagonal 1  : "; cin >> d1;
    cout << "Masukkan diagonal 2  : "; cin >> d2;
    cout << "Masukkan sisi pendek : "; cin >> sisi_pendek;
    cout << "Masukkan sisi panjang: "; cin >> sisi_panjang;
}

double LayangLayang::luas() {
    return 0.5 * d1 * d2;
}

double LayangLayang::keliling() {
    return 2 * (sisi_pendek + sisi_panjang);
}

void LayangLayang::output() {
    cout << "\n[Hasil Layang-Layang]\n";
    cout << "Luas     : " << luas() << "\n";
    cout << "Keliling : " << keliling() << "\n";
}

// ==========================================
// Fungsi Utama (Main)
// ==========================================
int main() {
    // Memenuhi syarat: semua class hanya dapat diakses menggunakan object
    BelahKetupat objekBelahKetupat;
    LayangLayang objekLayangLayang;

    // Proses Input
    objekBelahKetupat.input();
    objekLayangLayang.input();

    // Proses Output Masing-masing
    objekBelahKetupat.output();
    objekLayangLayang.output();

    cout << "\n[Demonstrasi Friend Method]\n";
    // Memanggil method yang sudah di-friend-kan
    objekBelahKetupat.keliling(objekLayangLayang);

    return 0;
}