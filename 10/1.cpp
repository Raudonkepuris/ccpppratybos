#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void keisti_tarpus(string &ivestis){
    while(ivestis.find(" ") != -1){
        ivestis.replace(ivestis.find(" "), 1, ";");
    }
}

void skaldyti(string ivestis, int &z, int mas[], int &ns, string mass[]){
    int n = -1;
    int i;
    int sk;
    string zodis;

    do{
        i = ivestis.find(";", n+1);
        zodis = ivestis.substr(n+1, i-n-1);

        try{
            sk = stoi(zodis);
            mas[z] = sk;
            z++;
        }
        catch(std::invalid_argument){
            mass[ns] = zodis;
            ns++;
        }

        n = i;
    }while(n != -1);
}

int main(){
    string ivestis = "999999 afs 55 d 12312 safrwe adsffs 20 fsfa 4";
    // string ivestis;
    // getline(cin, ivestis);

    keisti_tarpus(ivestis);
    cout << ivestis << endl;

    int n = 0;
    int mas[100];
    
    int ns = 0;
    string mass[100];

    skaldyti(ivestis, n, mas, ns, mass);

    sort(mas, mas + n);
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < ns; i++)
    {
        cout << mass[i] << endl;
    }
    
}