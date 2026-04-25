#include <iostream>
using namespace std;

int main(){
    int nilaiuts, nilaiuas, nilaitugas,nim;
    char a,b;
    float nilaiAkhir;
    int sks, sisasks, semester=18;

    cout<<"|============= SISTEM NILAI AKADEMIK =============|"<<endl;
    cout<<"Masukkan NIM Anda \t= ";
    cin>>nim;
    cout<<"Masukkan nilai UTS \t= ";
    cin>>nilaiuts;
    cout<<"Masukkan nilai UAS \t= ";
    cin>>nilaiuas;
    cout<<"Masukkan nilai TUGAS \t= ";
    cin>>nilaitugas;

    nilaiAkhir=(nilaiuts*30)+(nilaiuas*40)+(nilaitugas*40);
    cout.precision(2);
    cout<<fixed;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Nilai Akhir Anda adalah = "<<nilaiAkhir/100.00<<endl;
    cout<<"Nilai Akhir Bulat Atas \t= "<<(int)(nilaiAkhir/100)+(int)((nilaiAkhir/100)/100)<<endl;
    cout<<"Nilai Akhir Bulat Bawah = "<<(int)nilaiAkhir/100<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"SKS DiTempuh \t= ";
    cin>>sks;
    sisasks=144-sks;
    cout<<"Sisa SKS \t= "<<sisasks<<" sks"<<endl;
    sisasks=sks/semester;
    sks=sisasks%semester;
    cout<<" Semester Penuh = "<<sks<<endl;
    cout<<" SKS Sisa \t= "<<sisasks<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"Kode Grade (lowercase)\t= ";
    cin>>a;
    b=a-32;
    cout<<"Uppercase (manual)\t= "<<b<<endl;
    cout<<"Nilai ASCII = "<<b+0<<endl;
    nim%=10;
    cout<<"Shift (digit terakhir NIM= "<<nim<<")"<<endl;
    cout<<"Hasil Enkripsi ="<<endl;
    cout<<"|================================================|";
    return 0;
}