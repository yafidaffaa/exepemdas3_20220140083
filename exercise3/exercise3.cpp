#include <iostream>
#include <vector>
#include <string>	

using namespace std;

class Penerbit {
public:
	string namaPenerbit;
	vector <string> bukuDikarang;
	Penerbit(string nama) {
		namaPenerbit = nama;
	}
};

class Pengarang {
public:
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
public:
	string judulBuku;
	Pengarang* pengarang;

	Buku(string judul, Pengarang* png) {
		judulBuku = judul;
		pengarang = png;
		pengarang->tambahkanBuku(judul);
	}
};

int main() {

	Penerbit gamaPress ("Gama Press");
	Penerbit intanPariwara ("Intan Pariwara");

	Pengarang joko ("Joko", &gamaPress);
	Pengarang lia ("Lia", &gamaPress);
	Pengarang asroni ("Asroni", &intanPariwara);
	Pengarang giga ("Giga", &gamaPress);
	Pengarang giga2 ("Giga", &intanPariwara);

	Buku fisika("Fisika", &joko);
	Buku algoritma("Algoritma", &joko);
	Buku basisData("Basisdata", &lia);
	Buku dasarPemrograman("Dasar Pemrograman", &asroni);
	Buku matematika("Matematika", &giga);
	Buku multimedia1("Multimedia 1", &giga);

	//output 1
	cout << "Daftar pengarang pada penerbit \"Gama Press\" :" << endl;
	for (Pengarang* pengarang : { &joko, &lia, &giga }) {
		if (pengarang->penerbit->namaPenerbit == "Gama Press") {
			cout << pengarang->namaPengarang << endl;
		}
	}

	cout << endl;

	//output 2
	cout << "Daftar pengarang pada penerbit \"Intan Pariwara\" :" << endl;
	for (Pengarang* pengarang : { &asroni, &giga2 }) {
		if (pengarang->penerbit->namaPenerbit == "Intan Pariwara") {
			cout << pengarang->namaPengarang << endl;
		}
	}

	cout << endl;

	//output 3
	cout << "Daftar penerbit yang diikuti \"Giga\" :" << endl;
	for (Penerbit* penerbit : { &gamaPress, &intanPariwara }) {
		if (penerbit->namaPenerbit == "Gama Press" || penerbit->namaPenerbit == "Intan Pariwara") {
			cout << penerbit->namaPenerbit << endl;
		}
	}

	cout << endl;

	//output 4
	cout << "Daftar buku yang dikarang \"Joko\" :" << endl;
	for (string buku : joko.bukuDikarang) {
		cout << buku << endl;
	}

	cout << endl;

	//output 5
	cout << "Daftar buku yang dikarang \"Lia\" :" << endl;
	for (string buku : lia.bukuDikarang) {
		cout << buku << endl;
	}

	cout << endl;

	//output 6
	cout << "Daftar buku yang dikarang \"Asroni\" :" << endl;
	for (string buku : asroni.bukuDikarang) {
		cout << buku << endl;
	}

	cout << endl;

	//output 7
	cout << "Daftar buku yang dikarang \"Giga\" :" << endl;
	for (string buku : giga.bukuDikarang) {
		cout << buku << endl;
	}

	return 0;

}