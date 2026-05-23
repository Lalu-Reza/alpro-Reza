#include <iostream>
#include <cstdlib>

using namespace std;

struct Karakter {
    char nama[50];
    int level;
    int exp;
    int maxExp;
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    int atk;
    int def;
    int agi;
};

struct Musuh {
    char nama[50];
    int level;
    int hp;
    int maxHp;
    int atk;
    int def;
    int agi;
    int expHadiah;
};

bool bossKalah[7] = {false, false, false, false, false, false, false};

const char* namaStage[7] = {
    "Pride", "Greed", "Wrath", "Sloth", "Gluttony", "Envy", "Lust"
};

const char* namaMusuh[7][4] = {
    {"Arrogant Soldier", "Noble Knight", "Fallen Champion", "King of Pride (Boss)"},
    {"Gold Hoarder", "Corrupt Merchant", "Living Treasure", "Dragon of Greed (Boss)"},
    {"Furious Beast", "Berserker", "Flame Demon", "Avatar of Wrath (Boss)"},
    {"Lazy Undead", "Sleeping Giant", "Dream Spirit", "Lord of Sloth (Boss)"},
    {"Hungry Slime", "Devourer Beast", "Endless Maw", "Lord of Gluttony (Boss)"},
    {"Shadow Copy", "Mirror Spirit", "Shapeshifter", "Embodiment of Envy (Boss)"},
    {"Charming Spirit", "Siren", "Succubus", "Queen of Lust (Boss)"}
};

void bersihkanLayar() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void jeda() {
    cout << "Press ENTER to continue...";
    cin.get();
}

int hitungPanjang(const char* str) {
    int p = 0;
    while (str[p] != '\0') p++;
    return p;
}

bool bandingkanString(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];
        if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 += 32;
        if (c1 != c2) return false;
        i++;
    }
    return true;
}

void banner(){
    cout << "+=======================================================================+" << endl;
    cout << "|                                                                       |" << endl;
    cout << "|      _    _                         _   ____            _             |" << endl;
    cout << "|     / \\  | |__  _   _ ___ ___  __ _| | |  _ \\ ___  __ _| |_ __ ___    |" << endl;
    cout << "|    / _ \\ | '_ \\| | | / __/ __|/ _` | | | |_) / _ \\/ _` | | '_ ` _ \\   |" << endl;
    cout << "|   / ___ \\| |_) | |_| \\__ \\__ \\ (_| | | |  _ <  __/ (_| | | | | | | |  |" << endl;
    cout << "|  /_/   \\_\\_.__/ \\__, |___/___/\\__,_|_| |_| \\_\\___|\\__,_|_|_| |_| |_|  |" << endl;
    cout << "|                 |___/                                                 |" << endl;
    cout << "|                                                                       |" << endl;
    cout << "+=======================================================================+" << endl;
}

void buatMusuh(Musuh &m, int stageIdx, int pathIdx) {
    int pengali = stageIdx + 1;
    int tingkatJalur = pathIdx + 1;
    
    int i = 0;
    const char* srcNama = namaMusuh[stageIdx][pathIdx];
    while (srcNama[i] != '\0' && i < 49) {
        m.nama[i] = srcNama[i];
        i++;
    }
    m.nama[i] = '\0';
    
    m.level = (pengali * 2) + pathIdx;
    
    if (pathIdx == 3) {
        m.maxHp = 300 * pengali;
        m.atk = 40 * pengali;
        m.def = 25 * pengali;
        m.agi = 10 + (pengali * 3);
        m.expHadiah = 100 * pengali;
    } else {
        m.maxHp = (50 * pengali) + (tingkatJalur * 20);
        m.atk = (12 * pengali) + (tingkatJalur * 4);
        m.def = (5 * pengali) + (tingkatJalur * 3);
        m.agi = 5 + pengali + tingkatJalur;
        m.expHadiah = (15 * pengali) + (tingkatJalur * 10);
    }
    m.hp = m.maxHp;
}

void cekNaikLevel(Karakter &p) {
    while (p.exp >= p.maxExp) {
        p.exp -= p.maxExp;
        p.level++;
        
        int tambahAtk = 15;
        int tambahDef = 9;
        int tambahAgi = 5;
        int tambahHp = 750;
        int tambahMp = 50;
        
        p.atk += tambahAtk;
        p.def += tambahDef;
        p.agi += tambahAgi;
        p.maxHp += tambahHp;
        p.maxMp += tambahMp;
        
        p.hp = p.maxHp;
        p.mp = p.maxMp;
        p.maxExp = p.maxExp + 100;
        
        cout << "\n*** LEVEL UP! ***\n";
        cout << "You reached Level " << p.level << "\n";
        cout << "ATK +" << tambahAtk << " DEF +" << tambahDef << " AGI +" << tambahAgi 
             << " MaxHP +" << tambahHp << " MaxMP +" << tambahMp << " (HP/MP restored)\n";
        jeda();
    }
}

bool cekKemenanganSistem() {
    for (int i = 0; i < 7; i++) {
        if (!bossKalah[i]) return false;
    }
    return true;
}

void mulaiPertarungan(Karakter &p, int stageIdx, int pathIdx) {
    Musuh m;
    buatMusuh(m, stageIdx, pathIdx);
    
    bersihkanLayar();
    cout << "=========================================\n";
    cout << "[" << m.nama << "]: Welcome, adventurer. Show me what you are made of!\n";
    cout << "=========================================\n";
    cin.ignore();
    jeda();
    
    int turn = 1;
    while (p.hp > 0 && m.hp > 0) {
        bersihkanLayar();
        cout << "=========================================\n";
        cout << "ABYSSAL REALM\n";
        cout << "=========================================\n";
        cout << "TURN " << turn << "\n";
        cout << "-----------------------------------------\n";
        cout << "[" << p.nama << "] (Player)\n";
        cout << "Level : " << p.level << "\n";
        cout << "HP    : " << p.hp << "/" << p.maxHp << "\n";
        cout << "MP    : " << p.mp << "/" << p.maxMp << "\n";
        cout << "AGI   : " << p.agi << "\n";
        cout << "EXP   : " << p.exp << "/" << p.maxExp << "\n";
        cout << "-----------------------------------------\n";
        cout << "[" << m.nama << "] (Enemy)\n";
        cout << "Level : " << m.level << "\n";
        cout << "HP    : " << m.hp << "/" << m.maxHp << "\n";
        cout << "AGI   : " << m.agi << "\n";
        cout << "=========================================\n";
        cout << "1. Basic Attack   (No MP, 100% ATK)\n";
        cout << "2. Heavy Attack   (30 MP, 160% ATK)\n";
        cout << "3. Heal           (20 MP, Restore 200 HP)\n";
        cout << "14. Run Away      (Exit Battle Path)\n";
        cout << "=========================================\n";
        cout << "[Choose action]: ";
        
        int aksi;
        cin >> aksi;
        
        if (aksi == 14) {
            cout << "You ran away from the battle safely.\n";
            cin.ignore();
            jeda();
            return;
        }
        
        int damageDiberikan = 0;
        
        if (aksi == 1) {
            int acakDodge = rand() % 100;
            if (acakDodge < m.agi) {
                cout << "\n[Basic Attack] " << p.nama << " attacks, but " << m.nama << " dodges!\n";
            } else {
                damageDiberikan = p.atk - (m.def / 2);
                if (damageDiberikan <= 0) damageDiberikan = 5;
                m.hp -= damageDiberikan;
                cout << "\n[Basic Attack] " << p.nama << " hits " << m.nama << " for " << damageDiberikan << " damage.\n";
            }
        } 
        else if (aksi == 2) {
            if (p.mp < 30) {
                cout << "\nNot enough MP for Heavy Attack. Turn wasted.\n";
            } else {
                p.mp -= 30;
                int acakDodge = rand() % 100;
                if (acakDodge < (m.agi + 20)) { 
                    cout << "\n[Heavy Attack] " << p.nama << " swung widely, but " << m.nama << " easily dodges!\n";
                } else {
                    damageDiberikan = (p.atk * 1.6) - (m.def / 2);
                    if (damageDiberikan <= 0) damageDiberikan = 10;
                    m.hp -= damageDiberikan;
                    cout << "\n[Heavy Attack] " << p.nama << " lands a crushing blow on " << m.nama << " for " << damageDiberikan << " damage!\n";
                }
            }
        } 
        else if (aksi == 3) {
            if (p.mp < 20) {
                cout << "\nNot enough MP for Heal. Turn wasted.\n";
            } else {
                p.mp -= 20;
                p.hp += 200;
                if (p.hp > p.maxHp) p.hp = p.maxHp;
                cout << "\n[Heal] " << p.nama << " restores 200 HP.\n";
            }
        } 
        else {
            cout << "\nInvalid Action! You stumbled and wasted your turn.\n";
        }
        
        cin.ignore();
        jeda();
        
        if (m.hp <= 0) {
            cout << "\n-----------------------------------------\n";
            cout << m.nama << " has been defeated!\n";
            cout << "EXP gained: " << m.expHadiah << "\n";
            p.exp += m.expHadiah;
            
            if (pathIdx == 3) {
                bossKalah[stageIdx] = true;
                cout << "SUCCESS! You have conquered the Boss of " << namaStage[stageIdx] << "!\n";
            }
            cout << "-----------------------------------------\n";
            jeda();
            cekNaikLevel(p);
            return;
        }
        
        bersihkanLayar();
        cout << "\n=== ENEMY TURN ===\n";
        int acakDodgePemain = rand() % 100;
        if (acakDodgePemain < p.agi) {
            cout << "[" << m.nama << "] attacked, but " << p.nama << " dodges perfectly!\n";
        } else {
            int damageDiterima = m.atk - (p.def / 2);
            if (damageDiterima <= 0) damageDiterima = 3;
            p.hp -= damageDiterima;
            cout << "[" << m.nama << "] attacks " << p.nama << " for " << damageDiterima << " damage.\n";
        }
        jeda();
        
        if (p.hp <= 0) {
            cout << "\n=========================================\n";
            cout << "       YOU DIED IN THE ABYSS...          \n";
            cout << "=========================================\n";
            jeda();
            return;
        }
        
        turn++;
    }
}

void masukStage(Karakter &p, int stageIdx) {
    bool diDalamStage = true;
    while (diDalamStage && p.hp > 0) {
        bersihkanLayar();
        cout << "=========================================\n";
        cout << "ABYSSAL REALM - " << namaStage[stageIdx] << "\n";
        cout << "=========================================\n";
        if (bossKalah[stageIdx]) {
            cout << " STATUS: [BOSS DEFEATED]\n";
            cout << "You have cleared this realm completely.\n";
            cout << "-----------------------------------------\n";
        } else {
            cout << "Challenge the sins and reach the King.\n";
            cout << "-----------------------------------------\n";
        }
        
        cout << "1. " << namaMusuh[stageIdx][0] << "\n";
        cout << "2. " << namaMusuh[stageIdx][1] << "\n";
        cout << "3. " << namaMusuh[stageIdx][2] << "\n";
        cout << "4. " << namaMusuh[stageIdx][3] << " (Boss)\n";
        cout << "5. Retreat (Kembali ke Gerbang Utama)\n";
        cout << "=========================================\n";
        cout << "[Which path will you take?]: ";
        
        int pilJalur;
        cin >> pilJalur;
        
        if (pilJalur >= 1 && pilJalur <= 4) {
            if (pilJalur == 4 && bossKalah[stageIdx]) {
                cout << "\nThe Boss of this stage is already dead. No need to fight again!\n";
                cin.ignore();
                jeda();
            } else {
                mulaiPertarungan(p, stageIdx, pilJalur - 1);
            }
        } else if (pilJalur == 5) {
            diDalamStage = false;
        } else {
            cout << "Path unknown! Stay focused.\n";
            cin.ignore();
            jeda();
        }
    }
}

void menuUtamaGame(Karakter &p) {
    bool bermain = true;
    while (bermain && p.hp > 0) {
        if (cekKemenanganSistem()) {
            bersihkanLayar();
            cout << "========================================================\n";
            cout << "*** CONGRATULATIONS, CHAMPION OF THE ABYSS! ***\n";
            cout << "You have defeated all Seven Deadly Sins!\n";
            cout << "========================================================\n";
            for (int i = 0; i < 7; i++) {
                cout << namaStage[i] << "\t\t: DEFEATED\n";
            }
            cout << "--------------------------------------------------------\n";
            cout << "The Abyssal Realm trembles before your name, " << p.nama << "!\n";
            cout << "You are the true master of the Abyss!\n";
            cout << "========================================================\n";
            cin.ignore();
            jeda();
            break;
        }
        
        bersihkanLayar();
        cout << "=========================================\n";
        cout << "ABYSSAL REALM" << endl;
        cout << "THE 7 DEADLY SINS ARE WAITING FOR YOU\n";
        cout << "=========================================\n";
        
        for (int i = 0; i < 7; i++) {
            cout << " " << i + 1 << ". " << namaStage[i];
            if (bossKalah[i]) {
                cout << "\t\t[BOSS DEFEATED]";
            }
            cout << "\n";
        }
        cout << " 8. EXIT GAME\n";
        cout << "=========================================\n";
        cout << "The deeper you go, the stronger they are\n";
        cout << "=========================================\n";
        cout << "[Choose your desired stage]: ";
        
        int pilihanStage;
        cin >> pilihanStage;
        
        if (pilihanStage >= 1 && pilihanStage <= 7) {
            masukStage(p, pilihanStage - 1);
        } else if (pilihanStage == 8) {
            cout << "\nThank you for playing! Exiting Abyssal Realm.\n";
            bermain = false;
        } else {
            cout << "\nInvalid stage number!\n";
            cin.ignore();
            jeda();
        }
    }
}

int main() {
    srand(13122002); 

    bersihkanLayar();
    banner();
    cout << "Welcome to Abyssal Realm, adventurer.\n";
    cout << "The seven deadly sins await your challenge.\n";
    cout << "-----------------------------------------\n";
    
    Karakter pemain;
    cout << "[Enter your name]: ";
    cin.getline(pemain.nama, 50);
    
    pemain.level = 1;
    pemain.exp = 0;
    pemain.maxExp = 150;
    pemain.hp = 1500;
    pemain.maxHp = 1500;
    pemain.mp = 100;
    pemain.maxMp = 100;
    pemain.atk = 50;
    pemain.def = 30;
    pemain.agi = 15;
    
    cout << "-----------------------------------------\n";
    cout << "Prolog: Menuju Abyssal Realm...\n";
    jeda();
    
    menuUtamaGame(pemain);
    
    return 0;
}