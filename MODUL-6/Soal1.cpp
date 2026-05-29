#include <iostream>
#include <climits>
using namespace std;

constexpr int buffer_limit = 128;
int buffer_resize = buffer_limit;
char* memori = nullptr;
int* catatan_panjang = nullptr;
int* tipeInput = nullptr;
int kursor = 0;
int jumlah_inputan = 0;

void clear() {
    cout << "\033[2J\033[H";
}
void enter() {
    cout << ">> Tekan ENTER untuk pulse berikutnya...";
    cin.get();
}
void garis() {
    cout << "------------------------------------------------------------" << endl;
}
void pil1() {
    int stabilitas = 100 - (100 * kursor / buffer_resize);
    if (stabilitas < 0) stabilitas = 0;
    clear();
    cout << "============================================================" << endl;
    cout << "NEURAL MAP: HISTORIA KOURA [STABILITAS: " << stabilitas << "%]" << endl;
    cout << "============================================================" << endl;
    if (jumlah_inputan == 0) {
        cout << "(Buffer kosong. Xelisa sedang mengumpulkan kekuatan...)" << endl;
    } else {
        int indeks_baca = 0;
        bool ada_data_aktif = false;
        for (int i = 0; i < jumlah_inputan; i++) {
            if (tipeInput[i] != 0) {
                ada_data_aktif = true;
                void* alamat_memori = static_cast<void*>(&memori[indeks_baca]);
                
                cout << " [" << i << "]";

                if (tipeInput[i] == 1) {
                    cout << " TIPE: Willpower Pulse | " << "OFFSET: " << indeks_baca << " | Alamat: " << alamat_memori << " Data \"";
                } else if (tipeInput[i] == 2) {
                    cout << " TIPE Thunder Discharge | " << "OFFSET: " << indeks_baca << " | Alamat: " << alamat_memori << " Data ";
                }
                for (int j = 0; j < catatan_panjang[i]; j++) {
                    cout << memori[indeks_baca + j];
                }
                if (tipeInput[i] == 2) {
                    cout << "MW" << endl;
                } else {
                    cout << "\"" << endl;
                }
            }
            indeks_baca += catatan_panjang[i];
        }

        if (!ada_data_aktif) {
            cout << "(Semua data telah dihapus, memori berisi residu teks)" << endl;
        }
    }
    
    garis();
    cout << "Kursor: " << kursor << " / " << buffer_resize << " Byte terpakai." << endl;
    garis();
    enter();
}
void pil2() {
    clear();
    char input_user[500];
    char tipe_pilihan;
    int sisaMemori = buffer_resize - kursor;
    cout << "Pilih Tipe Injeksi: 0 = Willpower (Teks), 1 = Thunder (Energi): ";
    cin >> tipe_pilihan;
    cin.ignore(INT_MAX, '\n');
    if (tipe_pilihan != '0' && tipe_pilihan != '1') {
        cout << "!! ERROR !! Opsi tipe injeksi tidak valid." << endl;
        enter();
        return;
    }
    if (tipe_pilihan == '0') {
        cout << "Masukkan Input Willpower: ";
        cin.getline(input_user, 500);

        int panjangInputBaru = 0;
        while (input_user[panjangInputBaru] != '\0') {
            panjangInputBaru++;
        }
        if (panjangInputBaru >= sisaMemori) {
            cout << "!! ERROR OPTIMALISASI !! Ego vessel menolak thread! Memori penuh." << endl;
        } else {
            catatan_panjang[jumlah_inputan] = panjangInputBaru;
            tipeInput[jumlah_inputan] = 1;
            jumlah_inputan++;

            int i = 0;
            while (input_user[i] != '\0') {
                memori[kursor + i] = input_user[i];
                i++;
            }
            kursor += panjangInputBaru; 
            memori[kursor] = '\0';  
            
            cout << "Perintah CyroN: \"Resistansi subjek terdeteksi. Mengesampingkan umpan balik.\"" << endl;
        }
    } else {
        cout << "Masukkan Tingkat Energi Thunder (int): ";
        cin.getline(input_user, 500);
        int panjangInputBaru = 0;
        while (input_user[panjangInputBaru] != '\0') {
            panjangInputBaru++;
        }
        if (panjangInputBaru == 0) {
            cout << "!! ERROR !! Input tidak boleh kosong" << endl;
            enter();
            return;
        }
        bool valid = true;
        int start_idx = (input_user[0] == '-' && panjangInputBaru > 1) ? 1 : 0;
        for (int v = start_idx; v < panjangInputBaru; v++) {
            if (input_user[v] < '0' || input_user[v] > '9') {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << "!! ERROR !! Input ditolak! Tingkat Energi Thunder (int) tidak boleh mengandung huruf." << endl;
            enter();
            return;
        }
        if (panjangInputBaru >= sisaMemori) {
            cout << "!! ERROR OPTIMALISASI !! Burnout neural terdeteksi!" << endl;
        } else {
            catatan_panjang[jumlah_inputan] = panjangInputBaru;
            tipeInput[jumlah_inputan] = 2;
            jumlah_inputan++;

            int i = 0;
            while (input_user[i] != '\0') {
                memori[kursor + i] = input_user[i];
                i++;
            }
            kursor += panjangInputBaru;
            memori[kursor] = '\0';  
            
            cout << "Daiki: \"(Keheningan. Angin telah dijinakkan.)\"" << endl;
        }
    }
    enter();
}
void pil3() {
    clear();
    if (jumlah_inputan == 0) {
        cout << "Memori kosong!" << endl;
        enter();
        return;
    }
    int indeks_target = 0;
    cout << "Masukkan indeks link untuk dihapus (0 - " << jumlah_inputan - 1 << "): ";
    cin >> indeks_target;
    if (cin.fail() || indeks_target < 0 || indeks_target >= jumlah_inputan) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Indeks link tidak valid." << endl;
        enter();
        return;
    }
    cin.ignore(INT_MAX, '\n');
    if (tipeInput[indeks_target] == 0) {
        cout << "Indeks link sudah dihapus sebelumnya." << endl;
    } else {
        tipeInput[indeks_target] = 0;
        cout << "Link " << indeks_target << " berhasil dihapus." << endl;
        cout << "Neural Core berhasil mengembalikan ruang memori. Ujung (Tail) saat ini tetap di: " << kursor << endl;
    }
    enter();
}

void pil4() {
    clear();
    long long tambahan = 0;
    cout << "Masukkan batas buffer baru: ";
    cin >> tambahan;
    if (cin.fail() || tambahan <= 0 || tambahan > INT_MAX || tambahan < buffer_resize) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Ekspansi harus lebih besar dari batas saat ini dan valid!" << endl;
        enter();
        return;
    }
    cin.ignore(INT_MAX, '\n');

    int kapasitas_baru = static_cast<int>(tambahan);
    char* memori_baru = new char[kapasitas_baru];
    int* buffer_baru = new int[kapasitas_baru];
    int* tipe_baru = new int[kapasitas_baru];
    for (int j = 0; j < kursor; j++) {
        memori_baru[j] = memori[j];
    }
    memori_baru[kursor] = '\0';
    for (int i = 0; i < kapasitas_baru; i++) {
        if (i < buffer_resize) {
            buffer_baru[i] = catatan_panjang[i];
            tipe_baru[i] = tipeInput[i];
        } else {
            buffer_baru[i] = 0;
            tipe_baru[i] = 0;
        }
    }

    delete[] memori;
    delete[] catatan_panjang;
    delete[] tipeInput;
    memori = memori_baru;
    catatan_panjang = buffer_baru;
    tipeInput = tipe_baru;
    buffer_resize = kapasitas_baru;

    cout << "Perintah CyroN: \"Stabilitas meningkat. Vessel sekarang 100% patuh.\"" << endl;
    cout << "Alamat Frekuensi Teralokasi: " << static_cast<void*>(memori) << endl;
    enter();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: Neural Link membutuhkan ID Operator (NIM)." << endl;
        cout << "Penggunaan: ./test.exe <NIM>" << endl;
        return 1;
    } else if (argc > 2) {
        cout << "Error: Terlalu banyak parameter. Koneksi tidak stabil." << endl;
        return 1;
    }
    int panjang = 0;
    while (argv[1][panjang] != '\0') {
        panjang++;
    }
    if (panjang != 11) {
        cout << "Error: NIM harus tepat 11 karakter." << endl;
        return 1;
    }
    if (argv[1][0] != 'F' || argv[1][1] != '1' || argv[1][2] != 'D' || argv[1][3] != '0' || argv[1][4] != '2') {
        cout << "Error: NIM harus diawali dengan 'F1D02'." << endl;
        return 1;
    }
    memori = new char[buffer_resize];
    catatan_panjang = new int[buffer_resize];
    tipeInput = new int[buffer_resize];
    memori[0] = '\0';
    for (int i = 0; i < buffer_resize; i++) {
        catatan_panjang[i] = 0;
        tipeInput[i] = 0;
    }

    while (true) {
        clear();
        char pilihan[10];
        cout << endl << "       CYRON TERMINAL: DIVINE SUPPRESSION" << endl;
        cout << endl << " [1;35mXelisa: \"Luar biasa... sinkronisasi terjalin sempurna.\"[0m" << endl;
        garis();
        cout << "1. Tampilkan Neural Map (Status)" << endl;
        cout << "2. Suntik Neural Thread (Tambah)" << endl;
        cout << "3. Bersihkan Link Terkorupsi (Hapus)" << endl;
        cout << "4. Perluas Willpower (Resize)" << endl;
        cout << "0. Menyerah (Keluar)" << endl;
        garis();
        cout << "Pilih Operasi : ";
        cin.getline(pilihan, 10);

        if (pilihan[0] == '\0' || pilihan[0] < '0' || pilihan[0] > '4' || pilihan[1] != '\0') {
            cout << "(Menu digambar ulang; input tidak valid dilewati secara diam-diam oleh error recovery cin)" << endl;
            cout << ">> Tekan ENTER untuk pulse berikutnya...";
            cin.get();
            continue;
        }
        if (pilihan[0] == '0') {
            clear();
            cout << "Realitas mulai tidak stabil..." << endl;
            cout << ">> Tekan ENTER untuk pulse berikutnya...";
            cin.get();
            cout << "Koneksi terputus. Selamat tinggal, Operator ";
            for (int i = 8; i < 11; i++) {
                cout << argv[1][i];
            }
            cout << "." << endl;
            break;
        } else if (pilihan[0] == '1') {
            pil1();
        } else if (pilihan[0] == '2') {
            pil2();
        } else if (pilihan[0] == '3') {
            pil3();
        } else if (pilihan[0] == '4') {
            pil4();
        }
    }
    delete[] memori;
    delete[] catatan_panjang;
    delete[] tipeInput;

    return 0;
}