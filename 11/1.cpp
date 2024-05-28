#include <fstream>
#include <iostream>
using namespace std;

int suskaiciuoti_vardus(string vardai){
    int i = 0, n = 0;
    while(vardai.find(" ", i) != -1){
        i = vardai.find(" ", i) + 1;
        if(isalpha(vardai[i])) n++;
    }

    return n;
}

int main(){
    ifstream vardaiF("vardai.txt");
    if(!vardaiF.is_open()) return 1;

    string vardai;
    getline(vardaiF, vardai);
    cout << vardai << endl;
    int vardu_sk = suskaiciuoti_vardus(vardai);
    cout << vardu_sk << endl;
}