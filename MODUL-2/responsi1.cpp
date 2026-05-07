#include <iostream>
using namespace std;

int main(){
    int angka;
    bool berhasil=false;
    
    do {
        cout<<"Masukkan angka agar dicetak sampai berapa (minimal 10) = ";
        cin>>angka;
        if(angka<10){
            cout<<"Masukkan angka minimal 10!!!"<<endl;
            system("pause");
            berhasil=true;
        }
        else {
        for(int i=0; i<=angka;i++){
            if(i==5) continue;
            cout<<i<<endl;
        }
        berhasil=false;
        }
        
    } while(berhasil);
    string strategi;
    int peringkat=10;
    cout<<"============================="<<endl;
    do {
         if (peringkat==11){
            cout<<"Sudah season, peringkat anda kembali ke 10"<<endl;
            peringkat=10;
            berhasil=true;
        }
        if (peringkat==1){
            cout<<"Selamat anda top 1 global!!";
            return 0;
        }
        cout<<"Peringkat anda sekarang "<<peringkat<<endl;
        cout<<"Pilih strategi untuk menjadi top global (r: ngerank; t: tidak) = ";
        cin>>strategi;
        if (strategi=="r"||strategi=="R"){
            peringkat--;
            cout<<"Push terusss!!"<<endl;
            berhasil=true;
        }
        if (strategi=="t"||strategi=="T"){
            peringkat++;
            cout<<"Push terus lahh!!"<<endl;
            continue;
            berhasil=true;
            
        }
        else {
            cout<<"Strategi mu tidak valid ulangi pilihan"<<endl;
            continue;
            berhasil=true;
            
        }
    } while (berhasil);
    return 0;
}