#include <iostream>
using namespace std;

int x = 0, y = 1, z = 0;
string regis[1000];
string pass[1000];
string setregis[1000];
bool loop=true;

void berhasil() {
    system("cls");
    int j;
    cout << "==== HALAMAN USER ====" << endl;
    for (int i = 0; i < z; i++) {
        cout << "Nomor Registrasi : " << i + 1 << endl;
        cout << "Username         : " << setregis[i] << endl << endl;
    }
    
    cout << "0. kembali\n";
    cout << "Pilih nomor registrasi yang ingin di log out: ";
    cin >> j;
    
    if (j > 0 && j <= z) {
        int pos = j - 1;
        string sampah = setregis[pos];
        for (int i = pos; i < z - 1; i++) {
            setregis[i] = setregis[i + 1];
        }
        z--;
        
        cout << "[Berhasil] " << sampah << " telah logout!" << endl;
        system("pause");
        return;
    } else if (j == 0) {
        system("cls");
        return;
    }
}
void pil2() {
    system("cls");
    string loginregis;
    string loginpass;
    int pw = -1;
    
    cout << "==== LOGIN ====" << endl;
    cout << "Masukkan Username : ";
    cin >> loginregis;
    for (int i = 0; i < x; i++) {
        if (loginregis == regis[i]) {
            pw = i;
            break;
        }
    }
    if (pw == -1) {
        cout << "Username tidak terdaftar!" << endl;
        system("pause");
        system("cls");
        return;
    }
    
    cout << "Masukkan Password : ";
    cin >> loginpass;
    if (loginpass == pass[pw]) {
        bool sudahLogin = false;
        for (int i = 0; i < z; i++) {
            if (setregis[i] == regis[pw]) {
                sudahLogin = true;
                break;
            }
        }
        if (!sudahLogin) {
            setregis[z] = regis[pw];
            z++;
        }
        berhasil();
    } else {
        cout << "Password salah!" << endl;
        system("pause");
    }
}
void pil1() {
    system("cls");
    string usernameBaru;
    cout << "==== REGISTER ====" << endl;
    cout << "Masukkan Username : ";
    cin >> usernameBaru;
    for (int i = 0; i < x; i++) {
        if (regis[i] == usernameBaru) {
            cout << "Username sudah digunakan!" << endl;
            system("pause");
            return;
        }
    }
    regis[x] = usernameBaru;
    cout << "Masukkan Password : ";
    cin >> pass[x];
    x++;
    
    cout << "Registrasi Berhasil!" << endl;
    system("pause");
    system("cls");
}
void utama() {
    int pilih;
    while (loop) {
        system("cls");
        cout << "=== MENU ===" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;
        
        if (pilih == 1) {
            pil1();
        } else if (pilih == 2) {
            pil2();
        } else if (pilih == 3) {
            loop=false;
        }
    }
}

int main() {
    utama();
    return 0;
}