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

	Kembalian%=100000;
	Seratus++;
	cout<<"- Rp 100.000 : "<<Seratus<<" Lembar"<<endl;
	Kembalian%=50000;
	Limapuluh++;
	cout<<"- Rp 50.000 : "<<Limapuluh<<" Lembar"<<endl;
	Kembalian%=20000;
	DuaPuluh++;
	cout<<"- Rp 20.000 : "<<DuaPuluh<<" Lembar"<<endl;
	Kembalian%=10000;
	Sepuluh++;
	cout<<"- Rp 10.000 : "<<Sepuluh<<" Lembar"<<endl;
	Kembalian%=5000;
	Lima++;
	cout<<"- Rp 5.000 : "<<Lima<<" Lembar"<<endl;
	Kembalian%=1000;
	Seribu++;
	cout<<"- Rp 1.000 : "<<Seribu<<" Lembar"<<endl;
	Kembalian%=1000;
	SeribuKoin++;
	cout<<"- Rp 1.000 : "<<SeribuKoin<<" Koin"<<endl;
	Kembalian%=500;
	LimaRatus++;
	cout<<"- Rp 500 : "<<LimaRatus<<" Koin"<<endl;
	Kembalian%=200;
	DuaRatus++;
	cout<<"- Rp 200 : "<<DuaRatus<<" Koin"<<endl;
	Kembalian%=100;
	SeratusKoin++;
	cout<<"- Rp 100 : "<<SeratusKoin<<" Koin"<<endl;
	cout<<"-----------------------------------------"<<endl;
	Donasi=Kembalian;
	cout<<"[Fathan] : Aman! Sisa receh tak terpecahnya: RP "<<Donasi<<endl;
	cout<<"Ini mau di Donasikan ga Ren?"<<endl;
	cout<<"[Rendy] GAS"<<endl;
	cout<<"========================================="<<endl;

	return 0;
}