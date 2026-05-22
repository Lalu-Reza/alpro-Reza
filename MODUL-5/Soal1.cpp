#include <iostream>
using namespace std;

int x = 0;
int jumlah[100];
char jumlahAlergi;
struct kalender {
	const int tanggal = 21;
	const int bulan = 5;
	const int tahun = 2026;
};
struct MasukPasien {
	int tanggal, bulan, tahun;
};
struct DetailPasien{
	char nik[100];
	char telp[100];
	string nama;
	string gol;
	char kelamin[10];
	char bpjs[10];
	string alergen[100];
	string reaksi[100];
};
struct LahirPasien{
	int tanggal;
	int bulan;
	int tahun;
};
struct AlamatPasien{
	string jalan;
	string kelurahan;
	string kota;
	string provinsi;
	char kodePos[100];
};

	DetailPasien pasien[100];
	LahirPasien lahir[100];
	AlamatPasien alamat[100];
	MasukPasien masuk[100];
	kalender acuan;
void alergi(int b){
	bool gagal = false;
	for (int i = 0; i < b; i++){
	cout << "[Alergi "<<i+1<<"]" << endl;
	cout << " Alergen : ";
	getline (cin, pasien[x].alergen[i]);
	while(pasien[x].alergen[i].empty()){
		bool kosong = pasien[x].alergen[i].empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<< endl;
		}
	cout << " Alergen : ";
	getline (cin, pasien[x].alergen[i]);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << " Alergen : " << pasien[x].alergen[i] << endl;
    }
	gagal = false;
	cout << " Reaksi  : ";
	getline (cin, pasien[x].reaksi[i]);
	while(pasien[x].reaksi[i].empty()){
		bool kosong = pasien[x].reaksi[i].empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<< endl;
		}
	cout << " Reaksi  : ";
	getline (cin, pasien[x].reaksi[i]);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << " Reaksi  : " << pasien[x].reaksi[i] << endl;
    }}
}
void garis(){
	cout << "==================================================================="<<endl;
}
void pil1(){
	bool gagal = false;
	int panjang=0;
	system("cls");
	garis();
	cout << "		PENDAFTARAN PASIEN BARU"<<endl;
	garis();
	cout << "NIK (16 digit)		: ";
	cin.getline(pasien[x].nik, 100);
	while (pasien[x].nik[panjang] != '\0'){
		panjang++;
	}
	bool huruf = false;
	for (int i = 0; i < panjang; i++) {
		if (pasien[x].nik[i] < '0' || pasien[x].nik[i] > '9') {
			huruf = true;
			break; 
		}
	}
	while(huruf || (pasien[x].nik[0]=='\0' || pasien[x].nik[0]=='\n') || panjang != 16){
		bool kosong = (pasien[x].nik[0]=='\0' || pasien[x].nik[0]=='\n');
		bool kurang = !huruf && (panjang != 16);
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
		cout<<"[Gagal] NIK Tidak boleh huruf!"<<endl;
		}else if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<<endl;
		}else if (kurang){
		cout<<"[Gagal] NIK Tidak boleh Lebih atau kurang dari 16 angka!"<<endl;
		}
		cout << "NIK (16 digit)	: ";
		cin.getline(pasien[x].nik, 100);
		panjang=0;
		while (pasien[x].nik[panjang] != '\0'){
		panjang++;
		}
		huruf = false;
		for (int i = 0; i < panjang; i++) {
			if (pasien[x].nik[i] < '0' || pasien[x].nik[i] > '9') {
				huruf = true;
				break; 
			}
		}
	} if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "NIK (16 digit)		: "<< pasien[x].nik << endl;
    }
	gagal = false;
	cout << "Nama			: ";
	getline (cin, pasien[x].nama);
	while(pasien[x].nama.empty()){
		bool kosong = pasien[x].nama.empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Nama Tidak boleh kosong!"<< endl;
		}
	cout << "Nama			: ";
	getline (cin, pasien[x].nama);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "Nama			: "<< pasien[x].nama << endl;
    }
	cout << "Tgl Lahir" << endl;
	gagal = false;
	cout << "	Tanggal		: ";
	cin >> lahir[x].tanggal;
		cin.ignore(1000, '\n');
	while (cin.fail() || (lahir[x].tanggal < 1 || lahir[x].tanggal > 30)){
		bool huruf = cin.fail();
		bool lebih = (lahir[x].tanggal < 1 || lahir[x].tanggal > 30);
		cin.clear();
		cin.ignore(1000, '\n');
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cout<<"[Gagal] Tanggal tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Tanggal tidak boleh lebih dari 30 ataupun negatif!"<<endl;
		}
	cout << "	Tanggal		: ";
	cin >> lahir[x].tanggal;
		cin.ignore(1000, '\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Tanggal		: "<< lahir[x].tanggal << endl;
    }
	gagal = false;
	cout << "	Bulan		: ";
	cin >> lahir[x].bulan;
		cin.ignore(1000, '\n');
	while (cin.fail() || (lahir[x].bulan < 1 || lahir[x].bulan > 12)){
		bool huruf = cin.fail();
		bool lebih = (lahir[x].bulan < 1 || lahir[x].bulan > 12);
		cin.clear();
		cin.ignore(1000, '\n');
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cout<<"[Gagal] Bulan tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Bulan tidak boleh lebih dari 12 ataupun negatif!"<<endl;
		}
	cout << "	Bulan		: ";
	cin >> lahir[x].bulan;
		cin.ignore(1000, '\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Bulan		: "<< lahir[x].bulan << endl;
    }
	gagal = false;
	cout << "	Tahun		: ";
	cin >> lahir[x].tahun;
	cin.clear();
	cin.ignore(1000, '\n');
	while (cin.fail() || lahir[x].tahun < 1){
		bool huruf = cin.fail();
		bool lebih = lahir[x].tahun < 1;
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cout<<"[Gagal] Tahun tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Tahun tidak boleh negatif!"<<endl;
		}
	cout << "	Tahun		: ";
	cin >> lahir[x].tahun;
	cin.clear();
	cin.ignore(1000, '\n');
	}if (gagal) {
        cout << "\033[A\033[2K";
        cout << "\033[A\033[2K";
        cout << "	Tahun		: " << lahir[x].tahun <<endl;
    }
	gagal = false;
	cout << "Jenis kelamin (L/P)	: ";
	cin.getline(pasien[x].kelamin, 100);
	if (pasien[x].kelamin[0] == 'l' || pasien[x].kelamin[0] == 'L'){
		pasien[x].kelamin[0] = 'L';
	}else if (pasien[x].kelamin[0] == 'p' || pasien[x].kelamin[0] == 'P'){
		pasien[x].kelamin[0] = 'P';
	}
	while((pasien[x].kelamin[0] != 'l' && pasien[x].kelamin[0] != 'L' && pasien[x].kelamin[0] != 'P' && pasien[x].kelamin[0] != 'p') || (pasien[x].kelamin[0] == '\n' || pasien[x].kelamin[0] == '\0')){
		bool kosong = (pasien[x].kelamin[0] == '\n' || pasien[x].kelamin[0] == '\0');
		bool bukan = (pasien[x].kelamin[0] != 'l' && pasien[x].kelamin[0] != 'L' && pasien[x].kelamin[0] != 'P' && pasien[x].kelamin[0] != 'p');
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
			cout<<"[Gagal] Tidak boleh kosong!" << endl;
		} else if (bukan){
			cout<<"[Gagal] Harus memilih jenis kelamin (L) Laki-Laki atau (P) Perempuan!" << endl;
		}
	cout << "Jenis kelamin (L/P)	: ";
	cin.getline(pasien[x].kelamin, 100);
	if (pasien[x].kelamin[0] == 'l' || pasien[x].kelamin[0] == 'L'){
		pasien[x].kelamin[0] = 'L';
	}else if (pasien[x].kelamin[0] == 'p' || pasien[x].kelamin[0] == 'P'){
		pasien[x].kelamin[0] = 'P';
	}
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "Jenis kelamin (L/P)	: "<< pasien[x].kelamin << endl;
    }
	gagal = false;
	cout << "Gol. Darah		: ";
	getline(cin, pasien[x].gol);
	while (pasien[x].gol != "A+" && pasien[x].gol != "A" && pasien[x].gol != "A-" && pasien[x].gol != "B" && pasien[x].gol != "B+" && pasien[x].gol != "B-" && pasien[x].gol != "AB" && pasien[x].gol != "AB+" && pasien[x].gol != "AB-" && pasien[x].gol != "O" && pasien[x].gol != "O+" && pasien[x].gol != "O-" && pasien[x].gol != "-"){
		bool bukan = pasien[x].gol != "A+" && pasien[x].gol != "A" && pasien[x].gol != "A-" && pasien[x].gol != "B" && pasien[x].gol != "B+" && pasien[x].gol != "B-" && pasien[x].gol != "AB" && pasien[x].gol != "AB+" && pasien[x].gol != "AB-" && pasien[x].gol != "O" && pasien[x].gol != "O+" && pasien[x].gol != "O-" && pasien[x].gol != "-";
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (bukan){
			cout<<"[Gagal] Pilihan harus (A, B, O, AB) pilih (-) jika tidak tahu golongan darah!"<<endl;
		}
	cout << "Gol. Darah		: ";
	getline(cin, pasien[x].gol);
	}if (gagal) {
        cout << "\033[A\033[2K";
        cout << "\033[A\033[2K";
        cout << "Gol. Darah		: " << pasien[x].gol <<endl;
    }
	gagal = false;
	panjang = 0;
	cout << "No. Telp (Jgn ada spasi): ";
	cin.getline(pasien[x].telp, 100);
	while (pasien[x].telp[panjang] != '\0'){
		panjang++;
	}
	huruf = false;
	for (int i = 0; i < panjang; i++) {
		if (pasien[x].telp[i] < '0' || pasien[x].telp[i] > '9') {
			huruf = true;
			break; 
		}
	}
	while(huruf || (pasien[x].telp[0] == '\0' || pasien[x].telp[0] == '\n') || panjang != 12){
		bool kosong = (pasien[x].telp[0] == '\0' || pasien[x].telp[0] == '\n');
		bool kurang = !huruf && (panjang != 12);
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
		cout<<"[Gagal] No. Telp Tidak boleh huruf!"<<endl;
		}else if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<<endl;
		}else if (kurang){
		cout<<"[Gagal] No. Telp Tidak boleh Lebih atau kurang dari 12 angka!"<<endl;
		}
		cout << "No. Telp (Jgn ada spasi): ";
		cin.getline(pasien[x].telp, 100);
		panjang=0;
		while (pasien[x].telp[panjang] != '\0'){
		panjang++;
		}
		huruf = false;
		for (int i = 0; i < panjang; i++) {
			if (pasien[x].telp[i] < '0' || pasien[x].telp[i] > '9') {
				huruf = true;
				break; 
			}
		}
	} if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "No. Telp (Jgn ada spasi): "<< pasien[x].telp << endl;
    }
	gagal = false;
	cout << "Alamat"<<endl;
	cout << "	Jalan		: ";
	getline (cin, alamat[x].jalan);
	while(alamat[x].jalan.empty()){
		bool kosong = alamat[x].jalan.empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout << "[Gagal] Tidak boleh kosong!" << endl;
		}
	cout << "	Jalan		: ";
	getline (cin, alamat[x].jalan);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Jalan		: " << alamat[x].jalan << endl;
    }
	gagal = false;
	cout << "	Kelurahan	: ";
	getline (cin, alamat[x].kelurahan);
	while(alamat[x].kelurahan.empty()){
		bool kosong = alamat[x].kelurahan.empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<< endl;
		}
	cout << "	Kelurahan	: ";
	getline (cin, alamat[x].kelurahan);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Kelurahan	: "<< alamat[x].kelurahan << endl;
    }
	gagal = false;
	cout << "	Kota		: ";
	getline (cin, alamat[x].kota);
	while(alamat[x].kota.empty()){
		bool kosong = alamat[x].kota.empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<< endl;
		}
	cout << "	Kota		: ";
	getline (cin, alamat[x].kota);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Kota		: "<< alamat[x].kota << endl;
    }
	gagal = false;
	cout << "	Provinsi	: ";
	getline (cin, alamat[x].provinsi);
	while(alamat[x].provinsi.empty()){
		bool kosong = alamat[x].provinsi.empty();
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<< endl;
		}
	cout << "	Provinsi	: ";
	getline (cin, alamat[x].provinsi);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Provinsi	: "<< alamat[x].provinsi << endl;
    }
	gagal = false;
	panjang = 0;
	cout << "	Kode Pos	: ";
	cin.getline(alamat[x].kodePos, 100);
	while (alamat[x].kodePos[panjang] != '\0'){
		panjang++;
	}
	huruf = false;
	for (int i = 0; i < panjang; i++) {
		if (alamat[x].kodePos[i] < '0' || alamat[x].kodePos[i] > '9') {
			huruf = true;
			break; 
		}
	}
	while(huruf || (alamat[x].kodePos[0] == '\0' || alamat[x].kodePos[0] == '\n') || panjang != 5){
		bool kosong = (alamat[x].kodePos[0] == '\0' || alamat[x].kodePos[0] == '\n');
		bool kurang = !huruf && (panjang != 5);
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
		cout<<"[Gagal] Kode Pos Tidak boleh huruf!"<<endl;
		}else if (kosong){
		cout<<"[Gagal] Tidak boleh kosong!"<<endl;
		}else if (kurang){
		cout<<"[Gagal] Kode Pos Tidak boleh Lebih atau kurang dari 5 angka!"<<endl;
		}
		cout << "	Kode Pos	: ";
		cin.getline(alamat[x].kodePos, 100);
		panjang=0;
		while (alamat[x].kodePos[panjang] != '\0'){
		panjang++;
		}
		huruf = false;
		for (int i = 0; i < panjang; i++) {
			if (alamat[x].kodePos[i] < '0' || alamat[x].kodePos[i] > '9') {
				huruf = true;
				break; 
			}
		}
	} if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Kode Pos	: "<< alamat[x].kodePos << endl;
    }
	gagal = false;
	cout << "pasien BPJS (y/t)	: ";
	cin.getline(pasien[x].bpjs, 100);
	if (pasien[x].bpjs[0] == 'y'){
		pasien[x].bpjs[0] = 'Y';
	}
	if (pasien[x].bpjs[0] == 't'){
		pasien[x].bpjs[0] = 'T';
	}
	while((pasien[x].bpjs[0] != 'y' && pasien[x].bpjs[0] != 'Y' && pasien[x].bpjs[0] != 't' && pasien[x].bpjs[0] != 'T') || (pasien[x].bpjs[0] == '\n' || pasien[x].bpjs[0] == '\0')){
		bool kosong = (pasien[x].bpjs[0] == '\n' || pasien[x].bpjs[0] == '\0');
		bool bukan = (pasien[x].bpjs[0] != 'y' && pasien[x].bpjs[0] != 'Y' && pasien[x].bpjs[0] != 't' && pasien[x].bpjs[0] != 'T');
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
			cout<<"[Gagal] Tidak boleh kosong!" << endl;
		} else if (bukan){
			cout<<"[Gagal] Pilih antara Ya(y) atau Tidak(t)!" << endl;
		}
	cout << "pasien BPJS (y/n)	: ";
	cin.getline(pasien[x].bpjs, 100);
	if (pasien[x].bpjs[0] == 'y'){
		pasien[x].bpjs[0] = 'Y';
	}
	if (pasien[x].bpjs[0] == 't'){
		pasien[x].bpjs[0] = 'T';
	}
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "pasien BPJS (y/n)	: "<< pasien[x].bpjs << endl;
    }
	gagal = false;
	cout << "Jumlah alergi (0-5)	: ";
	cin >> jumlahAlergi;
	cin.clear();
	cin.ignore(1000, '\n');
	while (jumlahAlergi == '\n' || jumlahAlergi == '\0' || jumlahAlergi < '0' || jumlahAlergi > '5'){
		bool kosong = (jumlahAlergi == '\n' || jumlahAlergi == '\0');
		bool lebih = (jumlahAlergi < '0' || jumlahAlergi > '5');
	if(gagal){
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
	} else {
		cout << "\033[A\033[2K";
		gagal = true;
	}if (kosong){
		cout << "[Gagal] Tidak boleh kosong!" << endl;
	} if (lebih){
		cout << "[Gagal] Jumlah Alergi harus 1 sampai 5! 0 jika tidak memiliki alergi!" << endl; 
	}
	cout << "Jumlah alergi (0-5)	: ";
	cin >> jumlahAlergi;
	cin.clear();
	cin.ignore(1000, '\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
	}
	jumlah[x] = (jumlahAlergi - '0');
	if (jumlah[x] == 0){
		cout << "Tidak ada alergi" << endl;
	} else {
	alergi(jumlah[x]);
	}

	gagal = false;
	cout << "Kapan pasien masuk RS GazaCare Plus" << endl;
	cout << "	Tahun		: ";
	cin >> masuk[x].tahun;
		cin.ignore(1000, '\n');
	while (cin.fail() || masuk[x].tahun < 1 || masuk[x].tahun > acuan.tahun){
		bool huruf = cin.fail();
		bool lebih = masuk[x].tahun < 1;
		bool lebihDari = masuk[x].tahun > acuan.tahun;
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"[Gagal] Tahun tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Tahun tidak boleh negatif!"<<endl;
		} else if (lebihDari){
			cout<<"[Gagal] Tahun tidak boleh lebih dari tahun sekarang!"<<endl;
		}
	cout << "	Tahun		: ";
	cin >> masuk[x].tahun;
	cin.clear();
	cin.ignore(1000, '\n');
	}if (gagal) {
        cout << "\033[A\033[2K";
        cout << "\033[A\033[2K";
        cout << "	Tahun		: " << masuk[x].tahun <<endl;
    }
	gagal = false;
	cout << "	Bulan		: ";
	cin >> masuk[x].bulan;
		cin.ignore(1000, '\n');
	while (cin.fail() || masuk[x].bulan < 1 || masuk[x].bulan > 12 || (masuk[x].tahun == acuan.tahun && masuk[x].bulan > acuan.bulan)){
		bool huruf = cin.fail();
		bool lebih = (masuk[x].bulan < 1 || masuk[x].bulan > 12);
		bool lebihDari = (masuk[x].tahun == acuan.tahun && masuk[x].bulan > acuan.bulan);
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"[Gagal] Bulan tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Bulan tidak boleh lebih dari 12 ataupun negatif!"<<endl;
		}else if (lebihDari){
			cout<<"[Gagal] Bulan masuk tidak bisa lebih dari bulan sekarang!"<<endl;
		}
	cout << "	Bulan		: ";
	cin >> masuk[x].bulan;
		cin.ignore(1000, '\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Bulan		: "<< masuk[x].bulan << endl;
    }
	bool skip = (masuk[x].tahun == acuan.tahun && masuk[x].bulan == acuan.bulan);
	gagal = false;
	cout << "	Tanggal		: ";
	cin >> masuk[x].tanggal;
		cin.ignore(1000, '\n');
	while ((skip && masuk[x].tanggal > acuan.tanggal) || cin.fail() || (masuk[x].tanggal < 1 || masuk[x].tanggal > 30)){
		bool huruf = cin.fail();
		bool lebih = (masuk[x].tanggal < 1 || masuk[x].tanggal > 30);
		bool tgl = (skip && masuk[x].tanggal > acuan.tanggal);
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (huruf){
			cin.clear();
			cin.ignore(1000, '\n');
			cout<<"[Gagal] Tanggal tidak boleh kosong atau huruf!"<<endl;
		} else if (lebih){
			cout<<"[Gagal] Tanggal tidak boleh lebih dari 30 ataupun negatif!"<<endl;
		}else if (tgl){
			cout<<"[Gagal] Tanggal tidak boleh lebih dari tanggal sekarang!"<<endl;
		}
	cout << "	Tanggal		: ";
	cin >> masuk[x].tanggal;
	cin.ignore(1000,'\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << "	Tanggal		: "<< masuk[x].tanggal << endl;
    }
	x++;
	cout << endl << "[OK] Pasien ID-" << x << " berhasil didaftarkan!" << endl;
	system("pause");
}
void pil2(){
	system("cls");
	cout << "		DAFTAR PASIEN" << endl;
	garis();
	if (x == 0){
		cout << "Tidak ada data pasien yang aktif"<<endl;
		system("pause");
		system("cls");
		return;
	}
	for(int i = 0; i < x ; i++){
		cout << "ID			: " << i + 1 << "			Tgl Masuk " << masuk[i].tanggal << "/" << masuk[i].bulan << "/" <<masuk[i].tahun << endl;
		cout << "NIK (16 digit)		: ";
		for(int j = 0; j < 16; j++ ){
		cout << pasien[i].nik[j];
		}
		cout << endl << "Nama			: " << pasien[i].nama << endl;
		cout << "Jenis kelamin (L/P)	: ";
		if (pasien[i].kelamin[0] == 'L'){
			cout << "Laki - laki" << endl;	
		} else if (pasien[i].kelamin[0] == 'P'){
			cout << "Perempuan" << endl;
		}
		cout << "Tgl Lahir" << endl;
		cout << "	Tanggal		: ";
		if (lahir[i].tanggal < 10){
			cout << "0" << lahir[i].tanggal << endl;
		} else {
			cout << lahir[i].tanggal << endl;
		}
		cout << "	Bulan		: ";
		if (lahir[i].bulan < 10){
			cout << "0" << lahir[i].bulan << endl;
		}else {
			cout << lahir[i].bulan << endl;
		}
		cout << "	Tahun		: " << lahir[i].tahun << endl;
		cout << "Gol. Darah		: " << pasien[i].gol << endl;
		cout << "No. Telp		: " << pasien[i].telp << endl;
		cout << "pasien BPJS 		: ";
		if (pasien[i].bpjs[0] == 'Y'){
			cout << "Ya" << endl;	
		} else if (pasien[i].bpjs[0] == 'T'){
			cout << "Tidak" << endl;
		}
		cout << "Alamat"<<endl;
		cout << "	Jalan		: " << alamat[i].jalan << endl;
		cout << "	Kelurahan	: " << alamat[i].kelurahan << endl;
		cout << "	Kota		: " << alamat[i].kota << endl;
		cout << "	Provinsi	: " << alamat[i].provinsi << endl;
		cout << "	Kode Pos	: " << alamat[i].kodePos << endl;
		cout << " Alergi	: ";
		if (jumlah[i] == 0){
			cout << "Tidak ada" << endl;
		} else {
			cout << endl;
		for (int q = 0; q < jumlah[i]; q++){
			cout << " " << pasien[i].alergen[q] << " -> " << pasien[i].reaksi[q] << endl;
		}}
		garis ();
		} system ("pause");
}
void pil3(){
	string cari;
	int ketemu = -1;
	system ("cls");
	garis();
	cout << "		CARI PASIEN" << endl;
	garis();
	if (x == 0){
		cout << "Tidak ada data pasien yang aktif"<<endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "Masukkan nama : ";
	getline(cin, cari);
	for (int i = 0; i < x; i++){
		if (cari == pasien[i].nama){
			ketemu = i;
			break;
		}
	}
	if (ketemu == -1){
		cout << "Pasien tidak ditemukan." << endl;
		system ("pause");
		return;
	}
	garis();
	cout << endl << "		DAFTAR PASIEN" << endl;
	garis();
	cout << "ID			: " << ketemu + 1 << "			Tgl Masuk " << masuk[ketemu].tanggal << "/" << masuk[ketemu].bulan << "/" <<masuk[ketemu].tahun << endl;
		cout << "NIK (16 digit)		: ";
		for(int j = 0; j < 16; j++ ){
		cout << pasien[ketemu].nik[j];
		}
		cout << endl << "Nama			: " << pasien[ketemu].nama << endl;
		cout << "Jenis kelamin (L/P)	: ";
		if (pasien[ketemu].kelamin[0] == 'L'){
			cout << "Laki - laki" << endl;	
		} else if (pasien[ketemu].kelamin[0] == 'P'){
			cout << "Perempuan" << endl;
		}
		cout << "Tgl Lahir" << endl;
		cout << "	Tanggal		: ";
		if (lahir[ketemu].tanggal < 10){
			cout << "0" << lahir[ketemu].tanggal << endl;
		} else {
			cout << lahir[ketemu].tanggal << endl;
		}
		cout << "	Bulan		: ";
		if (lahir[ketemu].bulan < 10){
			cout << "0" << lahir[ketemu].bulan << endl;
		}else {
			cout << lahir[ketemu].bulan << endl;
		}
		cout << "	Tahun		: " << lahir[ketemu].tahun << endl;
		cout << "Gol. Darah		: " << pasien[ketemu].gol << endl;
		cout << "No. Telp		: " << pasien[ketemu].telp << endl;
		cout << "pasien BPJS 		: ";
		if (pasien[ketemu].bpjs[0] == 'Y'){
			cout << "Ya" << endl;	
		} else if (pasien[ketemu].bpjs[0] == 'T'){
			cout << "Tidak" << endl;
		}
		cout << "Alamat"<<endl;
		cout << "	Jalan		: " << alamat[ketemu].jalan << endl;
		cout << "	Kelurahan	: " << alamat[ketemu].kelurahan << endl;
		cout << "	Kota		: " << alamat[ketemu].kota << endl;
		cout << "	Provinsi	: " << alamat[ketemu].provinsi << endl;
		cout << "	Kode Pos	: " << alamat[ketemu].kodePos << endl;
		cout << " Alergi	: ";
		if (jumlah[ketemu] == 0){
			cout << "Tidak ada" << endl;
		} else {
			cout << endl;
		for (int q = 0; q < jumlah[ketemu]; q++){
			cout << " " << pasien[ketemu].alergen[q] << " -> " << pasien[ketemu].reaksi[q] << endl;
		}}
		garis (); 
		system ("pause");
}
void pil4(){
	system ("cls");
	bool gagal = false;
	int hapus;
	garis();
	cout << "		HAPUS / PULANGKAN PASIEN" << endl;
	garis();
	cout << " Daftar Pasien:" << endl;
	garis();
	if (x == 0){
		cout << "Tidak ada data pasien yang aktif"<<endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < x; i++){
		cout << " ID-" << i + 1 << "	| " << pasien[i].nama << endl;
	}
	garis();
	cout << endl << endl;
	cout << " Pilih 0 jika ingin kembali" << endl;
	cout << " Masukkan ID pasien yang ingin dipulangkan: ";
	cin >> hapus;
	cin.clear();
	cin.ignore(1000, '\n');
	while (hapus < 0 || hapus > x){
		bool fail = hapus < 0 || hapus > x;
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (fail){
			cout << "Pilih antara 0 sampai " << x << endl;
		}
	cout << " Masukkan ID pasien yang ingin dipulangkan: ";
	cin >> hapus;
	cin.clear();
	cin.ignore(1000, '\n');
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << " Masukkan ID pasien yang ingin dipulangkan: " << hapus << endl;
	}
	if (hapus == 0){
		return;
	}
	cout << endl;
	garis();
	cout << "			RINCIAN TAGIHAN" << endl;
	garis();
	int setHapus = hapus - 1;
	bool bpjs = false;
	cout << endl << "Nama			: " << pasien[setHapus].nama << endl;
	cout << "NIK (16 digit)		: ";
	for(int j = 0; j < 16; j++ ){
		cout << pasien[setHapus].nik[j];
	}
	cout << endl << "pasien BPJS 		: " << endl;
	if (pasien[setHapus].bpjs[0] == 'Y'){
		bpjs = true;
		cout << "Ya" << endl;	
	} else if (pasien[setHapus].bpjs[0] == 'T'){
		cout << "Tidak" << endl;
	}
	int lama = (acuan.tanggal - masuk[setHapus].tanggal) + ((acuan.bulan - masuk[setHapus].bulan) * 30) + ((acuan.tahun - masuk[setHapus].tahun) * 365);
	if (lama < 0) {
		lama = 0;
	}
	int tarif = lama * 75000;
	garis();
	cout << " Tgl Masuk	: " << masuk[setHapus].tanggal << "/" << masuk[setHapus].bulan << "/" <<masuk[setHapus].tahun << endl;
	cout << " Tgl Keluar	: " << acuan.tanggal << "/" << acuan.bulan << "/" << acuan.tahun << endl;
	cout << " Lama Rawat	: " << lama << " hari" << endl;
	cout << " Tarif/Hari	: Rp 75000" << endl;
	garis();
	cout << "Total Tagihan	: Rp ";
	if (bpjs){
		cout << "0 (Ditanggung BPJS)" << endl;
	} else {
		cout << tarif << endl;
	}
	garis();
	char pilih[10];
	gagal = false;
	cout << endl << " Pasien wajib melunasi tagihan sebelum dipulangkan." << endl << endl;
	cout << " Yakin ingin memulangkan pasien ini? (y/n): ";
	cin.getline(pilih, 10);
	while((pilih[0] != 'y' && pilih[0] != 'Y' && pilih[0] != 't' && pilih[0] != 'T') || (pilih[0] == '\n' || pilih[0] == '\0')){
		bool kosong = (pilih[0] == '\n' || pilih[0] == '\0');
		bool bukan = (pilih[0] != 'y' && pilih[0] != 'Y' && pilih[0] != 't' && pilih[0] != 'T');
		if(gagal){
			cout << "\033[A\033[2K";
			cout << "\033[A\033[2K";
		} else {
			cout << "\033[A\033[2K";
			gagal = true;
		}if (kosong){
			cout<<"[Gagal] Tidak boleh kosong!" << endl;
		} else if (bukan){
			cout<<"[Gagal] Harus memilih (y) Ya atau (t) Tidak!" << endl;
		}
	cout << " Yakin ingin memulangkan pasien ini? (y/n): ";
	cin.getline(pilih, 10);
	}if (gagal) {
		cout << "\033[A\033[2K";
		cout << "\033[A\033[2K";
		cout << " Yakin ingin memulangkan pasien ini? (y/t): " << pilih << endl;
	}
	if (pilih[0] == 'y'){
		pilih[0] = 'Y';
	}
	if (pilih[0] == 't'){
		pilih[0] = 'T';
	}
	
	if (pilih[0] == 'Y'){
	if (hapus > 0 && hapus <= x){
        for (int i = setHapus; i < x - 1; i++) {
			pasien[i] = pasien[i + 1];
			lahir[i] = lahir[i + 1];
			alamat[i] = alamat[i + 1];
			masuk[i] = masuk[i + 1];
			jumlah[i] = jumlah[i + 1];
		}
	cout << "[OK] Pasien ID-" << hapus << " berhasil dipulangkan" << endl;
	x--;
	cout << "	Sisa pasien terdaftar: " << x << endl;
	system ("pause");
	return;
	}}
	else if (pilih[0] == 'T'){
		return;
	}
}
void pil0(){
	system("cls");
	cout << endl << "	Terima Kasih! Sistem ditutup." << endl << endl;
	garis();
	return;
}
void utama(){
	bool loop = true;
	int pilihan;
	while(loop){
		system("cls");
		garis();
		cout << "	SISTEM MANAJEMEN RS GAZACARE PLUS"<< endl;
		garis();
		cout << "						Tanggal 21/5/2026"<< endl;
		cout << " [1] Daftarkan Pasien Baru"<< endl;
		cout << " [2] Lihat Semua Pasien"<< endl;
		cout << " [3] Cari Pasien"<< endl;
		cout << " [4] Pulangkan Pasien"<< endl;
		cout << " [0] Keluar"<< endl;
		garis();
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore(1000, '\n');
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
		}else if(pilihan == 1){
			pil1();
		}else if(pilihan == 2){
			pil2();
		}else if(pilihan == 3){
			pil3();
		}else if(pilihan == 4){
			pil4();
		} else {
			pil0();
			return;
		}
	}
}
int main() {
	utama();
	
	return 0;
}