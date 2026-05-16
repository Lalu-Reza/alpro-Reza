#include <iostream>
using namespace std;
int x=0,urutan=x+1,lihat;
string item[1000];
long long stok[1000];
long long harga[1000];

void bannerInput(){
	cout<<"____________________________________"<<endl;
	cout<<"            INPUT BARANG            "<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"____________________________________"<<endl;
}
void banner(){
	cout<<"#===================================#"<<endl;
	cout<<"|           TIVAIZ STORE            |"<<endl;
	cout<<"#===================================#"<<endl;
}
void hapusBarang(){
    int j;
	while(true){
    system("cls");
    banner();
	cout<<"____________________________________"<<endl;
	cout<<"            HAPUS BARANG            "<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"____________________________________"<<endl;
    if (x==0) {
        cout<<"Belum ada barang yang ditambahkan."<<endl;
        system("pause");
		return;
    }
    
    for(int i=0;i<x;i++){
		cout<<"No		: "<<i+1<<endl;
		cout<<"Nama Barang	: "<<item[i]<<endl;
		cout<<"Stok Barang	: "<<stok[i]<<endl;
		cout<<"Harga/Stok	: Rp. "<<harga[i]<<endl;
		cout<<"_______________________________________________________"<<endl;
	};
	cout<<"pilih 0 jika tidak ingin hapus apapun!"<<endl;
    cout<<"Pilih nomor barang yang dihapus (1-"<<x<<"): ";
    cin>>j;
	cin.ignore(1000, '\n');
    if (j>0&&j<=x){
        int pos=j-1;
		string sampah=item[pos];
        for (int i=pos;i<x-1;i++) {
            item[i]=item[i+1];
            stok[i]=stok[i+1];
            harga[i]=harga[i+1];
        }x--;
        cout << "[Berhasil] "<<sampah<<" dihapus! (Total barang: "<<x<<")" << endl;
		system("pause");
		return;
    }else if(j<0||j>x){
		cout<<"[Gagal] Nomor "<<j<<" tidak valid! Pilih antara 1 sampai "<<x<<"."<<endl;
  		system("pause");
	}else if(j==0){
		return;
	}
	}
}
void itemEdit(int a){
	int itemEdit;
	double afterHarga;
	int stoktambah;
	int stokkurang;
	while (true){
	system("cls");
	banner();
	cout<<"____________________________________"<<endl;
	cout<<"             EDIT BARANG            "<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"Barang: "<<item[a-1]<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"1. Edit Harga"<<endl;
	cout<<"2. Tambah Stok"<<endl;
	cout<<"3. Kurangi Stok"<<endl;
	cout<<"0. Kembali"<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"Pilih opsi: ";
	cin>>itemEdit;
	cin.ignore(1000, '\n');
	if(itemEdit<0||itemEdit>3){
		cout<<"[Gagal] Pilih opsi dari 0 sampai 3!";
		system("pause");
	}else if(itemEdit==1){
		cout<<"____________________________________"<<endl;
		while (true){
		cout<<"Harga baru (Rp): ";
		cin>>afterHarga;
		cin.ignore(1000,'\n');
		if(afterHarga<1){
			cout<<"[Gagal] Harga minimal Rp.1"<<endl;
			system("pause");
		}else {
			cout<<"[Berhasil] Harga "<<item[a-1]<<": Rp "<<harga[a-1]<<" -> Rp "<<afterHarga<<endl;
			harga[a-1]=afterHarga;
			system("pause");
			break;
		}
		};
	}else if(itemEdit==2){
		cout<<"____________________________________"<<endl;
		while (true){
		cout<<"Jumlah tambah: ";
		cin>>stoktambah;
		cin.ignore(1000,'\n');
		if(stoktambah<1){
			cout<<"[Gagal] Nambah Stok minimal 1"<<endl;
			system("pause");
		}else {
			cout<<"[Berhasil] Stok "<<item[a-1]<<": Rp "<<stok[a-1]<<" -> Rp "<<stok[a-1]+stoktambah<<endl;
			stok[a-1]+=stoktambah;
			system("pause");
			break;
		}
		};
	}else if(itemEdit==3){
		cout<<"____________________________________"<<endl;
		while (true){
		cout<<"Kurangi Stok: ";
		cin>>stokkurang;
		cin.ignore(1000,'\n');
		if(stokkurang<1){
			cout<<"[Gagal] Kurangi Stok minimal 1"<<endl;
			system("pause");
		}else {
			cout<<"[Berhasil] Stok "<<item[a-1]<<": Rp "<<stok[a-1]<<" -> Rp "<<stok[a-1]-stokkurang<<endl;
			stok[a-1]-=stokkurang;
			system("pause");
			break;
		}
		};
	}else {
		system("cls");
		break;
	}
	};
}
void edit(){
	int editItem;
	system("cls");
	banner();
	cout<<"____________________________________"<<endl;
	cout<<"             EDIT BARANG            "<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"____________________________________"<<endl;
	if (x==0){
		cout<<"Belum ada barang yang ditambahkan."<<endl;
		system("pause");
		return;
	}
	for(int i=0;i<x;i++){
		cout<<"No		: "<<i+1<<endl;
		cout<<"Nama Barang	: "<<item[i]<<endl;
		cout<<"Stok Barang	: "<<stok[i]<<endl;
		cout<<"Harga/Stok	: Rp. "<<harga[i]<<endl;
		cout<<"_______________________________________________________"<<endl;
	};
	while (true)
	{
	cout<<"pilih 0 jika tidak ingin hapus apapun!"<<endl;
	cout<<"Pilih nomor barang yang diedit (1-"<<x<<" ): ";
	cin>>editItem;
	cin.ignore(1000,'\n');
	if(editItem<1||editItem>x){
			cout<<"[Gagal] Menu tidak valid! Pilih antara 1 sampai "<<x<<"."<<endl;
			cin.clear();
			cin.ignore();
			system("pause");
	}else if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus berupa angka"<<endl;
			system("pause");
	}else if (editItem==0){
		return;
	}else {
		itemEdit(editItem);
		break;
	}
	};

}
void lihatBarang(){
	system("cls");
	banner();
	cout<<"____________________________________"<<endl;
	cout<<"            LIHAT BARANG            "<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"____________________________________"<<endl;
	if (x==0){
		cout<<"Belum ada barang yang ditambahkan."<<endl;
		system("pause");
		return;
	}
	for(int i=0;i<x;i++){
		cout<<"No		: "<<i+1<<endl;
		cout<<"Nama Barang	: "<<item[i]<<endl;
		cout<<"Stok Barang	: "<<stok[i]<<endl;
		cout<<"Harga/Stok	: Rp. "<<harga[i]<<endl;
		cout<<"Total Harga	: Rp. "<<stok[i]*harga[i]<<endl;
		cout<<"_______________________________________________________"<<endl;
		} cout<<"Total barang : "<<x<<" Jenis"<<endl;
		cout<<"___________________________________"<<endl;
	system("pause");
	system("cls");
	return;
}
void inputItem(){
    system("cls");
	banner();
	bannerInput();
	while (true) {
        cout << "Nama Barang	: ";
        getline(cin, item[x]);
        if (!item[x].empty()){
		break;
		} else{
        cout << "[Gagal] Nama barang tidak boleh kosong!" << endl;
		}
    }
	while (true) {
        cout << "Stok (unit)	: ";
        cin>>stok[x];
        if (stok[x]>=0) {
		break;
		} else{
        cout << "[Gagal] Stok tidak boleh negatif!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
		}
    }
    while (true) {
        cout << "Harga (Rp)	: ";
        cin>>harga[x];
        if (harga[x]>=1) {
		break;
		}else{
        cout << "[Gagal] Harga barang minimal Rp.1!" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
		}
    }
	x++; 
    cout<<"[Berhasil] "<<item[x-1]<<" ditambahkan! (Total barang: "<<x<<")"<<endl;
    system("pause");
	system("cls");
    return;
}
void faktorial(){
	int fakto,n=1;
	cout<<"+===================================-"<<endl;
	cout<<"|            K4LKUL4T0R             |"<<endl;
	cout<<"x===================================/"<<endl;
	cout<<"____________________________________"<<endl;
	cout<<"N : ";
	cin>>fakto;
	cout<<"------------------------------------"<<endl;
	if(fakto<0){
		cout<<"[Gagal] Faktorial tidak bisa untuk angka negatif!"<<endl;
		system("pause");
		system("cls");
		return;
	}else if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus berupa angka positif"<<endl;
			system("pause");
			system("cls");
			return;
	}else if(fakto==0||fakto==1){
		cout<<fakto<<"!"<<" = 1"<<endl;
		system("pause");
		system("cls");
		return;
	}else {
	for(int i=fakto;i>1;i--){
		n=i*n;
	}
	cout<<fakto<<"!"<<" = "<<n<<endl;
		system("pause");
		system("cls");
		return;
	}
}
void kal(){
	bool berhasil=true;
	string kalku;
	do{
		cout<<"+===================================-"<<endl;
		cout<<"|            K4LKUL4T0R             |"<<endl;
		cout<<"x===================================/"<<endl;
		cout<<"Operator (+, -, *, /) : ";
		cin>>kalku[0];
		if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus (+, -, *, /)"<<endl;
			system("pause");
			system("cls");
			berhasil=true;
		}else if(kalku=="+"){
			float pertama, kedua;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka pertama : ";
			cin>>pertama;
			cout<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka kedua : ";
			cin>>kedua;
			cout<<endl;
			cout<<pertama<<" + "<<kedua<<"= "<<pertama+kedua<<endl;
			system("pause");
			system("cls");
			return;
		}else if(kalku=="-"){
			double pertama, kedua;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka pertama : ";
			cin>>pertama;
			cout<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka kedua : ";
			cin>>kedua;
			cout<<endl;
			cout<<pertama<<" - "<<kedua<<"= "<<pertama-kedua<<endl;
			system("pause");
			system("cls");
			return;
		}else if(kalku=="*"){
			double pertama, kedua;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka pertama : ";
			cin>>pertama;
			cout<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka kedua : ";
			cin>>kedua;
			cout<<endl;
			cout<<pertama<<" * "<<kedua<<"= "<<pertama*kedua<<endl;
			system("pause");
			system("cls");
			return;
		}else if(kalku=="/"){
			double pertama, kedua;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka pertama : ";
			cin>>pertama;
			cout<<endl;
			cout<<"-------------------------------------"<<endl;
			cout<<"Angka kedua : ";
			cin>>kedua;
			if (kedua==0){
				cout<<"Tidak terdefinisi"<<endl;
				system("pause");
				system("cls");
				return;	
			}else{
			cout<<endl;
			cout<<pertama<<" / "<<kedua<<"= "<<pertama/kedua<<endl;
			system("pause");
			system("cls");
			return;
			}
		}else if (kalku==""){
			cout<<"[Gagal] Input harus (+, -, *, /)"<<endl;
			system("pause");
			system("cls");
			berhasil=true;
		}
	}while(berhasil);
}

int pil0(){
	system("cls");
	cout<<"Sampai jumpa! Terima kasih telah menggunakan Toko TIVAIZ!"<<endl;
	cout<<"================================";
	return 0;
}
void pil1(){
	bool berhasil=true;
	int store;
	do{
	system("cls");
		banner();
		cout<<"1. Input Barang"<<endl;
		cout<<"2. Hapus Barang"<<endl;
		cout<<"3. Edit Barang"<<endl;
		cout<<"4. Lihat Barang"<<endl;
		cout<<"0. Kembali"<<endl;
		cout<<"Pilih menu: ";
		cin>>store;
		cin.ignore(1000, '\n');
		if(store<0||store>4){
			cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 4."<<endl;
			cin.clear();
			cin.ignore();
			system("pause");
			system("cls");
			berhasil=true;
		}else if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus berupa angka"<<endl;
			system("pause");
			system("cls");
			berhasil=true;
		}else if (store==0){
			return;
		}else if(store==1){
			inputItem();
		}else if(store==2){
			hapusBarang();
		}else if(store==3){
			edit();
		}else if(store==4){
			lihatBarang();
		}else {
		}
	}while(berhasil);
}
void pil2(){
	int pilihkal;
	bool berhasil=true;
		system("cls");
		do{
		cout<<"+===================================-"<<endl;
		cout<<"|            K4LKUL4T0R             |"<<endl;
		cout<<"x===================================/"<<endl;
		cout<<"1. Operasi Dasar (+, -, *, /)"<<endl;
		cout<<"2. Faktorial"<<endl;
		cout<<"0. Kembali"<<endl;		
		cout<<"Pilih menu: ";
		cin>>pilihkal;
		if(pilihkal<0||pilihkal>2){
			cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 2."<<endl;
			cin.clear();
			cin.ignore();
			system("pause");
			system("cls");
			berhasil=true;
		}else if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus berupa angka"<<endl;
			system("pause");
			system("cls");
			berhasil=true;
		}else if (pilihkal==1){
			system("cls");
			kal();
		}else if (pilihkal==2){
			system("cls");
			faktorial();
		}else if(pilihkal==0) {
			system("cls");
			return;
		}
	}while(berhasil);
}

void utama(){
	int pilihUtama;
	bool berhasil=true;
	do{
	system("cls");
	cout<<"|==================================================|"<<endl;
	cout<<"|                                                  |"<<endl;
	cout<<"[               MODULE 4 - FUNCTION                ]"<<endl;
	cout<<"|                                                  |"<<endl;
	cout<<"|==================================================|"<<endl;
	cout<<"1. TIVAIZ Store"<<endl;
	cout<<"2. Kalkulator TIVAIZ"<<endl;
	cout<<"0. Keluar"<<endl;
	cout<<"======================================"<<endl;
		cout<<"Pilih menu: ";
		cin>>pilihUtama;
		if(pilihUtama<0||pilihUtama>2){
			cout<<"[Gagal] Menu tidak valid! Pilih antara 0 sampai 2."<<endl;
			cin.clear();
			cin.ignore();
			system("pause");
			system("cls");
			berhasil=true;
		}else if (cin.fail()){
			cin.clear();
			cin.ignore(1000,'\n');
			cout<<"[Gagal] Input harus berupa angka"<<endl;
			system("pause");
			system("cls");
			berhasil=true;
		}else if (pilihUtama==0){
			pil0();
			break;
		}else if(pilihUtama==1){
			pil1();
		}else {
			pil2();
		}
	}while(berhasil);
}

int main(){
	utama();
	
	return 0;
}