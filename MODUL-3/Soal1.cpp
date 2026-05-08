#include <iostream>
using namespace std;
#define p '\n'

int main(){
	int key, panjang=0;
	bool berhasil=false;
	char teks[1000];

	cout<<"[TASK 1/3] DECODE SIGNAL - Communication Room"<<p;
	cout<<">> Kirim Sinyal terenkripsi dan deskripsi balasan dari Bumi!"<<p;
	cout<<p<<"[ ENKRIPSI ]"<<p<<p;
	do{
	cout<<"Masukkan key: ";
	if (cin.peek()=='\n'){
	cin.fail();
	cin.clear();
	cin.ignore(1000, '\n');
	cout<<"[!] Input tidak boleh kosong. Coba lagi."<<endl;
	berhasil=true;continue;
	}
	cin>>key;
	if (cin.fail()){
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "[!] Input harus berupa angka bulat positif!" << endl;
    berhasil = true;
	}
	if (key<1){
		cout<<"[!] Key harus bilangan bulat positif. Coba lagi."<<p;
		berhasil=true;
	}
	else berhasil=false;
	}while (berhasil);

	cin.ignore();

	do{
	cout<<"Masukkan teks : ";
 	cin.getline(teks, 1000);
	if (teks[0]=='\0'){
	cout<<"[!] Input tidak boleh kosong. Coba lagi."<<endl;
	berhasil=true;
	}else berhasil=false;	
	} while (berhasil);

	while (teks[panjang]!='\0'){
		panjang++;
	}

	cout<<endl<<endl;

	cout<<"Matriks Enkripsi:"<<endl<<endl;
	
	int baris=(panjang+3)/4;
	int x=0;
	char matrik[baris][4];

    for (int i=0;i<baris;i++) {
        for (int j=0;j<4;j++) {
            if (x<panjang){
                matrik[i][j]=teks[x++];
            } else {
                matrik[i][j] = '_'; 
            }
			cout << matrik[i][j] << "  "; 
        }
        cout << endl;
    }

	cout<<"Enkripsi sebelum ditambah key \t: ";
	for (int i=0;i<baris;i++){
		for(int j=0;j<4;j++){
			if (matrik[i][j]=='_'){
				cout<<"";
			}else {
			cout<<matrik[i][j];
			}
		}
	}
	cout<<"\nEnkripsi setelah ditambah key \t: ";
	for (int i=0;i<baris;i++){
		for(int j=0;j<4;j++){
			if (matrik[i][j]=='_'){
				cout<<"";
			}else {
			cout<<char(matrik[i][j]+key);
			}
		}
	}
	cout<<endl<<endl;

	char teks2[1000];
	panjang=0;
	cout<<"[ DEKRIPSI ]"<<endl;
	do{
	cout<<"Masukkan teks terenkripsi	: ";
	cin.getline(teks2, 1000);
	if (teks2[0]=='\0'){
	cout<<"[!] Input tidak boleh kosong. Coba lagi."<<endl;
	berhasil=true;
	}else berhasil=false;
	}while(berhasil);

	while (teks2[panjang]!='\0'){
		panjang++;
	}

	for (int i=0;i<panjang;i++){
		teks2[i]=char(teks2[i]-key);
	}
	baris=(panjang+3)/4;
	x=0;
	char matrik2[baris][4];
	cout<<"Dekripsi setelah dikurang key	: "<<teks2<<endl<<endl;
	cout<<"Matriks Dekripsi"<<endl<<endl;
	for (int i=0;i<4;i++) {
        for (int j=0;j<baris;j++) {
            if (x<panjang){
                matrik2[j][i]=teks2[x++];
            } else {
                matrik2[j][i] = '_'; 
            }
        }
    }
	for (int i=0;i<baris;i++){
		for (int j=0;j<4;j++){
			cout<<matrik2[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"Hasil Dekripsi final		: ";
	for (int i=0;i<baris;i++){
		for(int j=0;j<4;j++){
			if (matrik2[i][j]=='_'){
				cout<<"";
			}else {
			cout<<matrik2[i][j];
			}
		}
	}
	cout<<">> [TASK 1/3] COMPLETE - Signal channel restored."<<endl;
	cout << "Tekan ENTER untuk melanjutkan ke [ TASK 2 ]!";
    cin.get();
	system ("cls");
	
	cout<<"[TASK 2/3] REPAIR TEXT CONSOLE - Captain's Bridge"<<p;
	cout<<">> Konsol teks mengalami interferensi komsik."<<p;
	cout<<"Verifikasi integritas data teks sebelum terlambat!"<<p;
	cout<<p<<"[ ENKRIPSI ]"<<p<<p;
	
	char teks3[1000];
	int urutan=1;
	x=0;
	berhasil=true;
	bool ulang=false;
	string pernyataan;
	do{
	bool berhasil1=false;
	int simpan=0;
	panjang=0;
	int panjang2=0;

	if (urutan>3){
		cout<<"==============================================="<<endl;
		do{
			cout<<"Verifikasi Teks Lain? (y/n) : ";
			cin>>pernyataan;
 			if(pernyataan=="y" || pernyataan=="Y"){
			ulang=true;
			berhasil=false;
			urutan=1;
			break;
			}
			else if (pernyataan=="n" || pernyataan=="N"){
			ulang=false;
			berhasil=false;
			break;
			}
		else cout<<"[!] Input tidak valid. Masukkan y atau n"<<endl;
		berhasil=true;
		} while (berhasil);
	}

	cout<<"Masukkan Kalimat ke-"<<urutan<<"	: ";
	cin.getline(teks3, 1000);
	if (cin.fail()){
	cin.clear();
	cin.ignore(1000, '\n');
	}

	while (teks3[panjang]!='\0'){
		panjang++;
	}
	while (teks3[panjang2]!='\0'){
		if (teks3[panjang2]==' '){
			simpan++;
		}
		panjang2++;
	}
	panjang2-=simpan;
	cout<<"------------------------------------------------"<<endl;
	cout<<"Hasil untuk Kalimat ke-"<<urutan<<"	:"<<endl;
	cout<<"Jumlah Huruf			: "<<panjang2<<endl;
	cout<<"1. Asli				: ";
	for (int i=0;i<panjang;i++){
		if (teks3[i]!=' '){
			if (berhasil1) cout<<", ";
			cout<<teks3[i];
			berhasil1=true;
		}
	}
	berhasil1=false;
	cout<<p<<"2. Invers			: ";
	for (int i=panjang-1;i>=0;i--){
		if (teks3[i]!=' '){
			if (berhasil1) cout<<", ";
			cout<<teks3[i];
			berhasil1=true;
		}
	}
	cout<<p<<"3. Swap Awal-Akhir		: ";
	for(int i=panjang;i>=0;i--){
		if (teks3[i]!=' '){
		cout<<teks3[i];
		}
	}
	bool cek = true;
	cout<<p<<"4. Palindrom?			: ";
    for (int i = 0; i < panjang; i++) {
		if (teks3[i] != teks3[panjang - 1 - i]) {
           cek = false;
            break;
        }
   }
	if (cek) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	urutan++;
	ulang=true;
	}while(ulang);

	cout<<"mantap";

	return 0;
}