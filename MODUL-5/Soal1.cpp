#include <iostream>
using namespace std;

int x=0;
struct DetailPasien{
	char nik[100];
	string nama[100];
	string gol[100];
	char bpjs[100];
	int jumlahAlergi[100];
};
struct LahirPasien{
	int tanggal[100];
	int bulan[100];
	int tahun[100];
};
struct AlamatPasien{
	string jalan[100];
	string kelurahan[100];
	string kota[100];
	string provinsi[100];
	int kodePos[100];
};
struct alergiPertama{
	string alergen1[100];
	string reaksi1[100];	
	DetailPasien alergi1[100];
};
struct alergiKedua{
	string alergen2[100];
	string reaksi2[100];
	DetailPasien alergi2[100];
};
void garis(){
	cout << "================================================================="<<endl;
}
void pil1(){
	DetailPasien pasien;
	bool loop = true;
	do{
	int panjang=0;
	system("cls");
	garis();
	cout << "		PENDAFTARAN PASIEN BARU"<<endl;
	garis();
	cout << "NIK(16 digit)	: ";
	cin>>pasien.nik[x];
	while (!pasien.nik[x]=='\0'){
		panjang++;
	}
	if(cin.fail()){
		cin.clear();
		cin.ignore();
	} else if(pasien.nik[x]<0)
	cout << "Nama			:";
	cin >> pasien.nama[x]; 
	}while(loop);
};
void utama(){
	bool loop = true;
	int pilihan;
	while(loop){
		system("cls");
		garis();
		cout << "	SISTEM MANAJEMEN RS GAZACARE PLUS"<<endl;
		garis();
		cout<<"						Tanggal 21/5/2026"<<endl;
		cout<<"[1]	Daftarkan Pasien Baru"<<endl;
		cout<<"[2]	Lihat Semua Pasien"<<endl;
		cout<<"[3]	Cari Pasien"<<endl;
		cout<<"[4]	Pulangkan Pasien"<<endl;
		cout<<"[0]	Keluar"<<endl;
		garis();
		cout<<"Pilihan: ";
		cin>>pilihan;
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"Pilihan harus angka!"<<endl;
			system("pause");
			system("cls");
		}else if(pilihan<0||pilihan>4){
			cout<<"Pilihan Harus Antara 0 Sampai 4!"<<endl;
			system("pause");
			system("cls");
		}else if(pilihan=1){
			pil1();
		}
	}
}

int main() {
	utama();
	
	return 0;
}