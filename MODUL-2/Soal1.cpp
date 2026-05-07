#include <iostream>
using namespace std;

int main(){
	int umur, perlindungan=3;
	bool berhasil=false;
	string strategi;
	cout<<"=== GOBLET OF FIRE: TURNAMEN TRIWIZARD ==="<<endl;
	do {
		cout<<"Masukkan umur Anda: ";
		cin>>umur;
		if(umur<17){
			cout<<"Piala Api menolak Anda! Umur anda terlalu Kecil"<<endl;
			berhasil=true;
		}
		else berhasil=false;
	}
	while(berhasil);
	cout<<"--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---"<<endl;
	cout<<"Sisa perlindungan sihir: "<<perlindungan<<" kali."<<endl;
	do { 
		if (perlindungan<=0){
			cout<<">> KESEMPATAN HABIS! Anda ditarik keluar arena oleh pawang naga."<<endl;
			cout<<"MENGULANG TUGAS 1 DARI AWAL..."<<endl;
			system ("pause");
			perlindungan=3;
			berhasil=true;
		}
		cout<<"Pilih strategi (a: Sembunyi, b: Panggil Sapu): ";
		cin>>strategi;
		if(strategi=="a" || strategi=="A"){
			perlindungan--;
			cout<<"Naga menyemburkan api! Anda terluka."<<endl;
			cout<<"Sisa perlindungan sihir: "<<perlindungan<<" kali."<<endl;
			berhasil=true;
		}
		else if (strategi=="b" || strategi=="B"){
			cout<<"Berhasil! Anda mengambil Telur Emas!"<<endl;
			system("pause");
			system("cls");
			break;
		}
		else cout<<"Pilihan tidak valid! Ulangi pilihan."<<endl;
		berhasil=true;
	}
		while(berhasil);

		//TUGAS 2

		cout<<"--- TUGAS 2: DANAU HITAM ---"<<endl;
		int menit=10;
		string strategi2;
	do { 
		if (menit>=60){
			cout<<"Tepat 60 menit! Anda menyelematkan sandera."<<endl;
			system("pause");
			system("cls");
			berhasil=false;
			break;
		}
		cout<<"Menit "<<menit<<"... Ada Grindylow!(l: Lawan, h: Hindari): ";
		cin>>strategi2;
		if(strategi2=="h" || strategi2=="H"){
			cout<<"Lolos dari Grinlow."<<endl;
			menit+=10;
			berhasil=true;
		} else if (strategi2=="l" || strategi2=="L"){
			cout<<"Oksigen Anda habis karena kelelahan bertarung!"<<endl;
			cout<<">> WAKTU/OKSIGEN HABIS! Putri duyung membawa Anda ke permukaan."<<endl;
			cout<<"MENGULANG TUGAS 2 DARI AWAL..."<<endl;
			system ("pause");
			menit=10;
			berhasil=true;
		} else {
		cout<<"Pilihan tidak valid! Ulangi pilihan."<<endl;
		system("pause");
		berhasil=true;
		}
	}
		while(berhasil);

		//TUGAS 3

		int langkah=0, kesalahan=2, strategi3;
		cout<<"--- TUGAS 3: LABIRIN ---"<<endl;
	do { 
		if (kesalahan<=0){
			cout<<">> KESEMPATAN HABIS! Labirin berubah bentuk dan menendang Anda ke pintu masuk."<<endl;
			cout<<"MENGULANG TUGAS 3 DARI AWAL..."<<endl;
			system ("pause");
			langkah=0;
			kesalahan=2;
			continue;
			berhasil=true;
		}
		if(langkah>=3){
			cout<<"Anda melihat cahaya... Oh tunggu, apa itu..."<<endl;
			system ("pause");
			system("cls");
			break;
		}
		cout<<"Sisa toleransi kesalahan: "<<kesalahan<<endl;
		cout<<"Langkah ditempuh: "<<langkah<<endl;
		cout<<"Pilih arah (1: Kiri, 2: Kanan, 3: Lurus): ";
		cin>>strategi3;
		if(strategi3==1){
			kesalahan--;
			cout<<"Terkena Akar Berbisa! Sisa toleransi kesalahan: "<<kesalahan<<endl;
			berhasil=true;
			system("pause");
		}
		else if (strategi3==2){
			cout<<"Jalan aman, Anda semakin dalam."<<endl;
			langkah++;
			berhasil=true;
			system("pause");
		}
		else if(strategi3==3){
			cout<<"Anda melihat cahaya... Oh tunggu, apa itu..."<<endl;
			system ("pause");
			system("cls");
			break;
		}
		else {
		cout<<"Anda tidak berada di jalur pilihan! Ulangi pilihan."<<endl;
		system("pause");
		berhasil=true;
		}
	}
		while(berhasil);

		//jalan keluar

		int angka;
		cout<<"--- JALAN KELUAR ---"<<endl;
		cout<<"Anda melihat sesuatu yang bersinar di tengah arena..."<<endl;
		cout<<"Terdapat sesuatu yang terkurung di dalamnya, dan terdapat mesin yang meminta Anda untuk memasukkan sebuah angka..."<<endl<<endl;
		do {
		cout<<"Masukkan angka (minimal 5): ";
		cin>>angka;
		if (angka<=4){
			berhasil=true;	
		}
		else {
			berhasil=false;
			break;
		}
		}
		while (berhasil);
		cout<<"Sebuah cahaya bersinar dan di tanganmu kini terdapat sebuah diamond besar!"<<endl;
		for (int i = 1; i <= angka; i++) {
        	for (int j = 1; j <= angka - i; j++) cout << " ";
        		for (int k = 1; k <= (2 * i - 1); k++) cout << "*";
        cout<<endl;
    	}

   		for (int i = angka - 1; i >= 1; i--) {
        	for (int j = 1; j <= angka - i; j++) cout <<" ";
        		for (int k = 1; k <= (2 * i - 1); k++) cout <<"*";
        cout<<endl;
    	}
		cout<<"SELAMAT! ANDA ADALAH PEMENANG TURNAMEN TRIWIZARD! ***"<<endl;
		cout<<"________________________________________";
	return 0;
}