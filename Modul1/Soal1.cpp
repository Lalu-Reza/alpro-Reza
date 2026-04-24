#include <iostream>
using namespace std;

int main(){
	int hargaBeras, hargaTelur, HargaMinyakGoreng, NominalUang, Kembalian ;
	int Seratus=0, Limapuluh=0, DuaPuluh=0, Sepuluh=0, Lima=0, Seribu=0, SeribuKoin=0, LimaRatus=0, DuaRatus=0, SeratusKoin=0, Donasi; 
	float ppn=0.25,TotalBelanja;
	
	cout<<"========================================="<<endl;
	cout<<"|\tTOKO SEMBAKO JAYA ABADI\t\t|"<<endl;
	cout<<"========================================="<<endl;
	cout<<"[Bina] : Than, masukkin harga barangnya rendy ke program ini!"<<endl;
	cout<<"Harga Beras (Rp)\t: ";
	cin>>hargaBeras;
	cout<<"Harga Telur (Rp)\t: ";
	cin>>hargaTelur;
	cout<<"Harga Beras (Rp)\t: ";
	cin>>HargaMinyakGoreng;
	cout<<"-----------------------------------------"<<endl;

	ppn=(hargaBeras+hargaTelur+HargaMinyakGoreng)*ppn;
	TotalBelanja=hargaBeras+hargaTelur+HargaMinyakGoreng;
	TotalBelanja+=ppn;
	cout<<"Total Belanja (+ PPN 25%)\t: Rp "<<(double)TotalBelanja<<endl;
	cout<<"[Fathan]: Ren, totalnya segitu. Uang lu ada berapa?"<<endl;
	cout<<"[Rendy]: hmmmmmmm, pajaknya gede juga ya."<<endl<<"Nih Than, my uang gweh segini"<<endl;
	cout<<"Nominal uang Rendy (Rp)\t: ";
	cin>>NominalUang;
	Kembalian=NominalUang-TotalBelanja;

	cout<<"========================================="<<endl;
	cout<<"|\tSTRUK KEMBALIAN\t\t|"<<endl;
	cout<<"========================================="<<endl;
	cout<<"[Bina] : Nih, Than. Rincian Kembaliannya:"<<endl;
	cout<<"Total Kembalian : Rp "<<Kembalian<<endl;
	cout<<"-----------------------------------------"<<endl;

	Seratus=Kembalian/100000;
	Kembalian%=100000;
	cout<<"- Rp 100.000 : "<<Seratus<<" Lembar"<<endl;
	Limapuluh=Kembalian/50000;
	Kembalian%=50000;
	cout<<"- Rp 50.000 : "<<Limapuluh<<" Lembar"<<endl;
	DuaPuluh=Kembalian/20000;
	Kembalian%=20000;
	cout<<"- Rp 20.000 : "<<DuaPuluh<<" Lembar"<<endl;
	Sepuluh=Kembalian/10000;
	Kembalian%=10000;
	cout<<"- Rp 10.000 : "<<Sepuluh<<" Lembar"<<endl;
	Lima=Kembalian/5000;
	Kembalian%=5000;
	cout<<"- Rp 5.000 : "<<Lima<<" Lembar"<<endl;
	Seribu=Kembalian/1000;
	Kembalian%=1000;
	cout<<"- Rp 1.000 : "<<Seribu<<" Lembar"<<endl;
	SeribuKoin=Kembalian/1000;
	Kembalian%=1000;
	cout<<"- Rp 1.000 : "<<SeribuKoin<<" Koin"<<endl;
	LimaRatus=Kembalian/500;
	Kembalian%=500;
	cout<<"- Rp 500 : "<<LimaRatus<<" Koin"<<endl;
	DuaRatus=Kembalian/200;
	Kembalian%=200;
	cout<<"- Rp 200 : "<<DuaRatus<<" Koin"<<endl;
	SeratusKoin=Kembalian/100;
	Kembalian%=100;
	cout<<"- Rp 100 : "<<SeratusKoin<<" Koin"<<endl;
	cout<<"-----------------------------------------"<<endl;
	Donasi=Kembalian;
	cout<<"[Fathan] : Aman! Sisa receh tak terpecahnya: RP "<<Donasi<<endl;
	cout<<"Ini mau di Donasikan ga Ren?"<<endl;
	cout<<"[Rendy] GAS"<<endl;
	cout<<"========================================="<<endl;

	return 0;
}