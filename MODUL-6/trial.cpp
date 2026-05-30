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
void garis(){
	cout << "--------------------------------------------------------" << endl;
}
void Clear(){
	cout << "\033[2J\033[H";
}
void utama(){
	cout << Cyan << " GITSIM" << White << " - Lightweight Git Simulator" << endl;
}

int main(int argc, char* argv[]) {
	if (argc != 2){
		cout << ".\\trial.exe <Name_Author>";
		return 1;
	}
	string namaAuthor = argv[1];
	bool loop = true;
	int x = 0;
	string inputan[100];
	char pilih;
	string waktuInputan[100];
	
	cout << Cyan << " GITSIM" << White << " - Lightweight Git Simulator" << endl;
	cout << Grey << " Author : " << namaAuthor << endl;
	garis();
	cout << White << "git init" << endl;
	garis();
	cout << Cyan << "Repository name: ";
	utama();
	
    return 0;
}