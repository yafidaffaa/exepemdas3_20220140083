#include <iostream>
#include <vector>
#include <string>	

using namespace std;

class Penerbit {
	string namaPenerbit;
	vector <string> bukuDikarang;
	Penerbit(string nama) {
		namaPenerbit = nama;
	}
};

class Pengarang {
	string namaPengarang;
	vector <string> bukuDikarang;
	Penerbit* penerbit;

	Pengarang(string nama, Penerbit* pnr) {
		namaPengarang = nama;
		penerbit = pnr;
	}

	void tambahkanBuku(string judul) {
		bukuDikarang.push_back(judul);
	}
};

class Buku {
	string judulBuku;
	Pengarang* pengarang;

	Buku(string judul, Pengarang* png) {
		judulBuku = judul;
		pengarang = png;
		pengarang->tambahkanBuku(judul);
	}
};

int main() {



}