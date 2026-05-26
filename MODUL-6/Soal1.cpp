#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
   if (argc > 2){
    cout << "Error: Too many parameters. Connection unstable." << endl;
    return 1;
   }
   int panjang;
   while (*argv[panjang] !='\0'){
    panjang++;
   }
   if (panjang != 11){
    cout << "Error: Operator ID must be exactly 11 characters long." << endl;
   }
    if (*argv[0] != 'F'){
        if (*argv[1] != '1'){
            if(*argv[2] != 'D'){
                if(*argv[3] != '0'){
                    if(*argv[4] != '2'){
                    cout << "Error: Too many parameters. Connection unstable." << endl;
                    return 1;
                    }
                }
            }
        }
    }
    
	cout << "Berhasil" << endl;
    return 0;
}