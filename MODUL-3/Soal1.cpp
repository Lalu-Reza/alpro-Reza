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
	berhasil=true;
	continue;
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
	cout<<p<<"Hasil Dekripsi final		: ";
	for (int i=0;i<baris;i++){
		for(int j=0;j<4;j++){
			if (matrik2[i][j]=='_'){
				cout<<"";
			}else {
			cout<<matrik2[i][j];
			}
		}
	}
	cout<<p<<">> [TASK 1/3] COMPLETE - Signal channel restored."<<endl;
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
	bool ulang=false, inv=false;
	char pernyataan[1000];
	do{
	bool berhasil1=false;
	int simpan=0;
	panjang=0;
	int panjang2=0;

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
	if (urutan>3){
		cout<<"==============================================="<<endl;
		do{
			cout<<"Verifikasi Teks Lain? (y/n) : ";
			cin.getline(pernyataan, 1000);
 			if(pernyataan[0]=='y' || pernyataan[0]=='Y'){
			ulang=true;
			inv=false;
			urutan=1;
			cin.ignore();
			break;
			}
			else if (pernyataan[0]=='\0'){
			cout<<"[!] Input tidak boleh kosong. Coba lagi."<<endl;
			inv=true;}
			else if (pernyataan[0]=='n' || pernyataan[0]=='N'){
			inv=false;
			ulang=false;
			}
			else {
			cout<<"[!] Input tidak valid. Masukkan y atau n"<<endl;
			inv=true;}
			} while (inv);
	} else ulang=true;
	}while(ulang);
	cout<<">> [TASK 2/3] COMPLETE - Text console back online."<<endl;
	cout << "Tekan ENTER untuk melanjutkan ke [ TASK 3 ]!";
    cin.get();
	system ("cls");

	berhasil=false;
	int bk, ganjil=1 , genap=2;
	cout<<"[TASK 3/3] ALIGN NAVIGATION MATRIX - Engine Core"<<p;
	cout<<">> Sistem navigasi mati total akibat sabotase."<<p;
	cout<<" Rekontruksi matriks koordinat sekarang!"<<p;
	cout<<p<<"[ MATRIX NAVIGATION ]"<<p<<p;
	
	do {
		cout<<"Masukkan ukuran Navigation Matrix (max 5): ";
		cin>>bk;
		if( bk < 3 || bk > 5 ){
			cout<<"[!] Input tidak valid. Masukkan ukuran antara 3 sampai 5."<<endl;
			berhasil=true;
		} else berhasil=false;
	}while(berhasil);
	int matrikganjil[bk][bk]; 
	int matrikgenap[bk][bk];
	cout<<"-----------------------------------------------"<<endl;
	cout<<"Prime Coordinate Matrix (Ganjil): "<<endl;
	for(int i=0 ; i<bk ; i++){
		for (int j=0 ; j<bk ; j++){
			matrikganjil[i][j]=ganjil;
			if (matrikganjil[i][j]<10){
				cout<<"0"<<matrikganjil[i][j]<<" ";
			} else cout<<matrikganjil[i][j]<<" ";
			ganjil+=2;
		}
		cout<<endl;
	}cout<<endl;
	
	cout<<"Even Coordinate Matrix (Genap): "<<endl;
	for(int i=0 ; i<bk ; i++){
		for (int j=0 ; j<bk ; j++){
			matrikgenap[i][j]=genap;
			if (matrikgenap[i][j]<10){
				cout<<"0"<<matrikgenap[i][j]<<" ";
			} else cout<<matrikgenap[i][j]<<" ";
			genap+=2;
		}
		cout<<endl;
	} cout<<endl;
	cout<<endl<<endl;
	cout<<"--------------------------------------------------"<<endl<<endl;
	cout<<"Matriks koordinat telah dipulihkan"<<endl;
	cout<<"Lakukanlah proses-proses berikut ini untuk membuat matriks koordinat lebih akurat!"<<endl;
	cout<<"1. Coordinate Matrix Integration"<<endl;
	cout<<"2. Matrix Transpose"<<endl;
	cout<<"3. Snake Traverse"<<endl<<endl;
	cout<<"Tekan ENTER untuk melanjutkan...";
	cin.get();
	system ("cls");
	
	cout<<"COORDINATE MATRIX INTEGRATION:"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(int i=0 ; i<bk ; i++){
		for (int j=0 ; j<bk ; j++){
			matrikgenap[i][j]=matrikgenap[i][j]+matrikganjil[i][j];
			if (matrikgenap[i][j]<10){
				cout<<"0"<<matrikgenap[i][j]<<" ";
			} else cout<<matrikgenap[i][j]<<" ";
		}
		cout<<endl;
	} cout<<endl<<endl;
	cout<<"MATRIX TRANSPOSE:"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(int i=0 ; i<bk ; i++){
		for (int j=0 ; j<bk ; j++){
			if (matrikgenap[j][i]<10){
				cout<<"0"<<matrikgenap[j][i]<<" ";
			} else cout<<matrikgenap[j][i]<<" ";
		}
		cout<<endl;
	} cout<<endl;
	cout<<"SNAKE TRAVERSE:"<<endl;
	cout<<"--------------------------------------------------"<<endl;
	for(int i = 0; i < bk; i++){
		if (i%2 ==0) {
			for (int j=0; j<bk; j++) {
				if (matrikgenap[j][i] < 10) cout << "0";
				cout << matrikgenap[j][i] << " ";
			}
		} else {
			for (int j = bk-1; j>=0; j--) {
				if (matrikgenap[j][i] < 10) cout << "0";
				cout << matrikgenap[j][i] << " ";
			}
		}
		cout << endl;
	} cout<<endl;
	cout<<endl<<endl<<"--------------------------------------------------"<<endl<<endl;
	cout<<">> [TASK 3/3] COMPLETE - Navigation matrix aligned."<<endl;
	cout<<"======================================================================"<<endl;
	cout<<"	ALL TASKS COMPLETE - SHIP SYSTEMS RESTORED"<<endl;
	cout<<"======================================================================"<<endl;
	return 0;
}