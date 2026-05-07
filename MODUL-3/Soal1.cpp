#include <iostream>
using namespace std;

int main(){
	int key;
	bool berhasil=false;
	string teks;

	cout<<"[TASK 1/3] DECODE SIGNAL - Communication Room"<<endl;
	cout<<">> Kirim Sinyal terenkripsi dan deskripsi balasan dari Bumi!"<<endl;
	cout<<endl<<"[ ENKRIPSI ]"<<endl<<endl;
	do{
	cout<<"Masukkan key: ";
	cin>>key;
	
	if (key<1){
		cout<<"[!] Key harus bilangan bulat positif. Coba lagi."<<endl;
		berhasil=true;
	}else berhasil=false;
	}while (berhasil);

	do{
	cout<<"Masukkan teks : ";
 	getline(cin, teks);
	if (cin.fail()){
	cin.ignore();
	cin.clear();
	}	
	if (teks==""){
	cout<<"[!] Input tidak boleh kosong. Coba lagi."<<endl;
	
	berhasil=true;
	}
	else berhasil=false;
		
	} while (berhasil&&teks.empty());

	
	return 0;
}