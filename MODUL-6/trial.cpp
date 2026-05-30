#include <iostream>
#include <string>
#include <ctime>
#define Reset "\033[0m"
#define Green "\033[1;32m"
#define Yellow "\033[1;33m"
#define Red "\033[1;31m"
#define Cyan "\033[1;36m"
#define Grey "\033[0;90m"
#define White "\033[1;37m"
#define Magenta "\033[1;35m"
using namespace std;

struct Commit {
    string hash;
    string message;
    string timestamp;
};

struct detailBranch {
    string branchName;
    Commit commitList[100];
    int jumlahCommit = 0;
};

struct Repository {
    string repoName;
    detailBranch Branch[100];
    int jumlahBranch = 0;
    int lastActiveBranch = 0;
};

Repository repo[100];
string namaAuthor;
int repoAktif = 0, totalRepo = 0, totalBranch = 0, branchAktif = 0;

string getCurrentTimestamp() {
    time_t now = time(nullptr);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", localtime(&now));
    return string(buffer);
}

string generateShortHash(int commitId) {
    const char hexChars[] = "0123456789abcdef";
    string hash = "";
    int value = commitId * 2654435761u;
    if (value < 0) value = -value;
    for (int i = 0; i < 7; i++) {
        hash = hexChars[value & 0xF] + hash;
        value >>= 4;
    }
    return hash;
}

bool cekSpasi(string teks) {
    int i = 0;
    while (teks[i] != '\0') {
        if (teks[i] == ' ') {
            return true;
        }
        i++;
    }
    return false;
}

void garis() {
    cout << Reset << "--------------------------------------------------------" << endl;
}

void Clear() {
    cout << "\033[2J\033[H";
}

void Enter() {
    cout << Reset << "Press Enter...";
    cin.get();
}

void utama(int menu, int menuB) {
    while (true) {
        repo[menu].lastActiveBranch = menuB;
        Clear();
        char pilihan;
        cout << Cyan << " GITSIM" << White << " - Lightweight Git Simulator" << endl;
        cout << Grey << " Author : " << White << namaAuthor << Grey << " | Repo: " << White << repo[menu].repoName << Grey << " | HEAD: " << Green << repo[menu].Branch[menuB].branchName << Reset << " | [" << White << menu + 1 << "/" << totalRepo << Reset << "]" << endl;
        garis();
        cout << " [1] git commit" << endl;
        cout << " [2] git log" << endl;
        cout << " [3] git branch" << endl;
        cout << " [4] git checkout" << endl;
        cout << " [5] new repository" << endl;
        cout << " [6] switch repository" << endl;
        cout << " [0] exit" << endl;
        garis();
        cout << Cyan << "> ";
        cin >> pilihan; 
        cin.ignore(10000, '\n');
        
        if (pilihan < '0' || pilihan > '6') {
            cout << Red << "[ERROR] " << Reset << "Invalid input!" << endl;
            Enter();
            Clear();
        } else if (pilihan == '1') {
            Clear();
            cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
            cout << Grey << " Author: " << White << namaAuthor << endl;
            garis();
            cout << White << " git commit  " << Reset << "[" << Green << repo[menu].Branch[menuB].branchName << Reset << "]" << endl;
            garis();
            
            int idxCommit = repo[menu].Branch[menuB].jumlahCommit;
            if (idxCommit >= 100) {
                cout << Red << " [ERROR] " << Reset << "Maximum commit limit (100) for this branch has been reached!" << endl;
                Enter();
                continue;
            }
            
            string msg;
            cout << Cyan << " Message : " << Reset;
            getline(cin, msg);
            
            if (msg.empty()) {
                cout << Red << " [ERROR]" << Reset << " Pesan commit tidak boleh kosong!" << endl;
                Enter();
            } else {
                char pushPilihan;
                cout << Cyan << " Push commit? (y/n): " << Reset;
                cin >> pushPilihan;
                cin.ignore(10000, '\n');

                string shortHash = generateShortHash(idxCommit + 1);
                string timeStamp = getCurrentTimestamp();
                repo[menu].Branch[menuB].commitList[idxCommit].hash = shortHash;
                repo[menu].Branch[menuB].commitList[idxCommit].message = msg;
                repo[menu].Branch[menuB].commitList[idxCommit].timestamp = timeStamp;
                repo[menu].Branch[menuB].jumlahCommit++;
                
                cout << endl;
                cout << " [" << Green << repo[menu].Branch[menuB].branchName << " " << shortHash << Reset << "] " << msg << endl;
                
                if (pushPilihan == 'y' || pushPilihan == 'Y') {
                    garis();
                    cout << Grey << " " << repo[menu].Branch[menuB].branchName << " -> origin/" << repo[menu].Branch[menuB].branchName << Reset << endl;
                    cout << " $ " << White << "git push origin " << Green << repo[menu].Branch[menuB].branchName << Reset << endl;
                }
                
                garis();
                cout << endl;
                Enter();
            }
        } else if (pilihan == '2') {
            Clear();
            cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
            cout << Grey << " Author: " << White << namaAuthor << endl;
            garis();
            cout << White << " git log  " << Reset << "[" << Green << repo[menu].Branch[menuB].branchName << Reset << "]" << endl;
            garis();
            
            int totalCommitSekarang = repo[menu].Branch[menuB].jumlahCommit;
            
            if (totalCommitSekarang == 0) {
                cout << Grey << " (No commits on this branch)" << Reset << endl;
            } else {
                for (int i = totalCommitSekarang - 1; i >= 0; i--) {
                    cout << Yellow << " commit " << repo[menu].Branch[menuB].commitList[i].hash << Reset << endl;
                    cout << " Author : " << namaAuthor << endl;
                    cout << " Date   : " << repo[menu].Branch[menuB].commitList[i].timestamp << endl;
                    cout << "          " << White << repo[menu].Branch[menuB].commitList[i].message << Reset << endl;
                    cout << endl;
                }
                garis();
            }
            Enter();
        } else if (pilihan == '3') {
            Clear();
            cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
            cout << Grey << " Author: " << White << namaAuthor << endl;
            garis();
            cout << White << " git branch" << endl;
            garis();
            
            int totalBranchRepo = repo[menu].jumlahBranch;
            for (int i = 0; i < totalBranchRepo; i++) {
                int jlhCmt = repo[menu].Branch[i].jumlahCommit;
                if (i == menuB) {
                    cout << Green << " * " << repo[menu].Branch[i].branchName << " (" << jlhCmt << " commits)" << Reset << endl;
                } else {
                    cout << Grey << "   " << repo[menu].Branch[i].branchName << " (" << jlhCmt << " commits)" << Reset << endl;
                }
            }
            garis();
            
            string branchBaru;
            cout << Cyan << " New branch name: " << Reset;
            getline(cin, branchBaru);
            
            if (branchBaru.empty()) {
                cout << endl << Red << " [ERROR]" << Reset << " Branch name cannot be empty!" << endl;
                Enter();
            } else if (cekSpasi(branchBaru)) {
                cout << endl << Red << " [ERROR]" << Reset << " Branch name cannot contain spaces!" << endl;
                Enter();
            } else {
                bool ada = false;
                for (int i = 0; i < totalBranchRepo; i++) {
                    if (repo[menu].Branch[i].branchName == branchBaru) {
                        ada = true;
                        break;
                    }
                }
                
                if (ada) {
                    cout << endl << Red << " [ERROR]" << Reset << " Branch '" << branchBaru << "' already exists!" << endl;
                    Enter();
                } else {
                    repo[menu].Branch[totalBranchRepo].branchName = branchBaru;
                    
                    int jlhCommitDiwarisi = repo[menu].Branch[menuB].jumlahCommit;
                    repo[menu].Branch[totalBranchRepo].jumlahCommit = jlhCommitDiwarisi;
                    
                    for (int c = 0; c < jlhCommitDiwarisi; c++) {
                        repo[menu].Branch[totalBranchRepo].commitList[c] = repo[menu].Branch[menuB].commitList[c];
                    }
                    
                    repo[menu].jumlahBranch++;
                    
                    cout << endl << Green << " [OK]" << Reset << " Branch '" << branchBaru << "' created from '" << repo[menu].Branch[menuB].branchName << "'" << endl;
                    cout << " " << jlhCommitDiwarisi << " commit(s) inherited" << endl;
                    cout << endl;
                    Enter();
                }
            }
        } else if (pilihan == '4') {
            Clear();
            cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
            cout << Grey << " Author: " << White << namaAuthor << endl;
            garis();
            cout << White << " git checkout" << endl;
            garis();
            
            int totalBranchRepo = repo[menu].jumlahBranch;
            for (int i = 0; i < totalBranchRepo; i++) {
                if (i == menuB) {
                    cout << Green << " * " << repo[menu].Branch[i].branchName << Reset << endl;
                } else {
                    cout << Grey << "   " << repo[menu].Branch[i].branchName << Reset << endl;
                }
            }
            garis();
            
            string targetBranch;
            cout << Cyan << " Switch to branch: " << Reset;
            getline(cin, targetBranch);
            
            if (targetBranch.empty()) {
                cout << endl << Red << " [ERROR]" << Reset << " Invalid branch!" << endl;
                Enter();
            } else {
                bool ditemukan = false;
                for (int i = 0; i < totalBranchRepo; i++) {
                    if (repo[menu].Branch[i].branchName == targetBranch) {
                        if (i == menuB) {
                            break; 
                        }
                        menuB = i;
                        ditemukan = true;
                        cout << endl << Green << " [OK]" << Reset << " Switched to branch '" << targetBranch << "'" << endl;
                        Enter();
                        break;
                    }
                }
                
                if (!ditemukan) {
                    cout << endl << Red << " [ERROR]" << Reset << " Invalid branch!" << endl;
                    Enter();
                }
            }
        } else if (pilihan == '5') {
            string namaRepoBaru;
            while (true) {
                repo[totalRepo].lastActiveBranch = 0;
                Clear();
                cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
                cout << Grey << " Author: " << White << namaAuthor << endl;
                garis();
                cout << White << " git init (new repository)" << endl;
                garis();
                cout << Cyan << " New repository name: " << Reset;
                getline(cin, namaRepoBaru);

                if (namaRepoBaru.empty()) {
                    namaRepoBaru = "repo-" + to_string(totalRepo);
                    repo[totalRepo].repoName = namaRepoBaru;
                    cout << endl << Green << " [OK]" << Reset << " Repository '" << repo[totalRepo].repoName << "' created and set as active." << endl;
                    cout << " On branch: " << Green << "main" << Reset << endl << endl;
                    repo[totalRepo].Branch[0].branchName = "main";
                    repo[totalRepo].jumlahBranch = 1;
                    repo[totalRepo].Branch[0].jumlahCommit = 0;
                    Enter();
                    menu = totalRepo; 
                    menuB = 0; 
                    totalRepo++;
                    break;
                } else if (cekSpasi(namaRepoBaru) == true) {
                    cout << endl << Red << " [ERROR]" << Reset << " Repository name cannot contain spaces. Please try again." << endl;
                    Enter();
                } else {
                    bool ada = false;
                    for (int i = 0; i < totalRepo; i++) {
                        if (repo[i].repoName == namaRepoBaru) {
                            ada = true;
                            break;
                        }
                    }
                    
                    if (ada) {
                        cout << endl << Red << " [ERROR]" << Reset << " Repository '" << namaRepoBaru << "' already exists!" << endl;
                        Enter();
                    } else {
                        repo[totalRepo].repoName = namaRepoBaru;
                        cout << endl << Green << " [OK]" << Reset << " Repository '" << repo[totalRepo].repoName << "' created and set as active." << endl;
                        cout << " On branch: " << Green << "main" << Reset << endl << endl;
                        repo[totalRepo].Branch[0].branchName = "main"; 
                        repo[totalRepo].jumlahBranch = 1;
                        repo[totalRepo].Branch[0].jumlahCommit = 0;
                        Enter();
                        menu = totalRepo; 
                        menuB = 0; 
                        totalRepo++;
                        break;
                    }
                }
            }
        } else if (pilihan == '6') {
            Clear();
            cout << Cyan << " GITSIM" << White << " - Git Simulator" << endl;
            cout << Grey << " Author: " << White << namaAuthor << endl;
            garis();
            cout << White << " switch repository" << endl;
            garis();
            
            for (int i = 0; i < totalRepo; i++) {
                int activeB = repo[i].lastActiveBranch;
                int jlhBranch = repo[i].jumlahBranch;
                int jlhCommitHead = repo[i].Branch[activeB].jumlahCommit;
                
                string branchWord = " branch, ";
                string commitWord = " commits at HEAD)";
                
                if (i == menu) {
                    cout << Green << " * [" << (i + 1) << "] " << repo[i].repoName 
                         << "  (" << jlhBranch << branchWord << jlhCommitHead << commitWord << Reset << endl;
                } else {
                    cout << "   [" << (i + 1) << "] " << repo[i].repoName 
                         << "  (" << jlhBranch << branchWord << jlhCommitHead << commitWord << endl;
                }
            }
            garis();
            
            int nomorPilihan;
            cout << Cyan << " Select repository number: " << Reset;
            cin >> nomorPilihan;
            cin.ignore(10000, '\n');
            
            if (nomorPilihan >= 1 && nomorPilihan <= totalRepo) {
                menu = nomorPilihan - 1;
                menuB = repo[menu].lastActiveBranch;
                
                cout << endl << Green << " [OK]" << Reset << " Switched to repository '" << repo[menu].repoName << "'" << endl;
                cout << " HEAD: " << Green << repo[menu].Branch[menuB].branchName << Reset << endl;
                Enter();
            } else {
                cout << endl << Red << " [ERROR]" << Reset << " Invalid repository number!" << endl;
                Enter();
            }
        } else if (pilihan == '0') {
            Clear();
            cout << Cyan << " Session Ended" << endl;
            cout << Grey << " Author : " << White << namaAuthor << endl;
            cout << Green << " Goodbye!" << Reset << endl;
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << ".\\trial.exe <Username>";
        return 1;
    }
    namaAuthor = argv[1];
    bool loop = true;
    repo[totalRepo].lastActiveBranch = 0;
    
    while (loop) {
        cout << Cyan << " GITSIM" << White << " - Lightweight Git Simulator" << endl;
        cout << Reset << " Author : " << White << namaAuthor << endl;
        garis();
        cout << White << " git init" << endl;
        garis();
        cout << Cyan << " Repository name: " << Reset;
        getline(cin, repo[totalRepo].repoName);
        if (repo[totalRepo].repoName.empty()) {
            repo[totalRepo].repoName = "my-repo";
            cout << endl << Green << "[OK]" << Reset << " Initialized empty repository: " << repo[totalRepo].repoName << endl << "On branch: " << Green << "main " << endl << endl;
            repo[totalRepo].Branch[totalBranch].branchName = "main";
            repo[totalRepo].jumlahBranch = 1;
            Enter();
            branchAktif = totalBranch;
            totalBranch++;
            repoAktif = totalRepo;
            totalRepo++;
            break;
        } else if (cekSpasi(repo[totalRepo].repoName) == true) {
            cout << Red << "[ERROR]" << Reset <<" repository name cannot contain spaces. Please try again." << endl;
            Enter();
            Clear();
        } else {
            cout << endl << Green << "[OK]" << Reset << " Initialized empty repository: " << repo[totalRepo].repoName << endl << "On branch: " << Green << "main " << endl << endl;
            repo[totalRepo].Branch[totalBranch].branchName = "main";
            repo[totalRepo].jumlahBranch = 1;
            Enter();
            branchAktif = totalBranch;
            totalBranch++;
            repoAktif = totalRepo;
            totalRepo++;
            break;
        }
    }
    utama(repoAktif, branchAktif);
    
    return 0;
}