#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Kaimynas{
    private:
        string vardas;
        long int AK;
        int amzius;
    public:
        Kaimynas(){
            vardas = "Kaimyno vardas";
            AK = 100000000;
            amzius = 99;
        }
        Kaimynas(string ivardas, long int iAK, int iamzius){
            vardas = ivardas;
            AK = iAK;
            amzius = iamzius;
        }
        void irasyti_varda(string ivestis){
            vardas = ivestis;
        }
        string nuskaityti_varda(){
            return vardas;
        }
        void irasyti_AK(long int ivestis){
            AK = ivestis;
        }
        long int nuskaityti_AK(){
            return AK;
        }
        void irasyti_amziu(int ivestis){
            amzius = ivestis;
        }
        int nuskaityti_amziu(){
            return amzius;
        }
};

bool lyginti_vardus(Kaimynas & a, Kaimynas & b){
    return a.nuskaityti_varda() < b.nuskaityti_varda();
}
bool lyginti_amzius(Kaimynas & a, Kaimynas & b){
    return a.nuskaityti_amziu() < b.nuskaityti_amziu();
}


void spausdinti_kaimyno_informacija(Kaimynas kaimynai[], int n){
    cout << "*   Vardas     *     ID numeris     *  amžius  *\n";
    for (int i = 0; i < n; i++)
    {
        cout << "*" << setw(14) << kaimynai[i].nuskaityti_varda() <<
            "*" << setw(20) << kaimynai[i].nuskaityti_AK() <<
            "*" << setw(10) << kaimynai[i].nuskaityti_amziu() << "*\n";
    }
}

void rikiuoti(Kaimynas kaimynai[], int n){
    int i;
    cout << "Pagal ka rikiuoti objektu masyva:\n\t1 - varda\n\t2 - amziu\n";
    cin >> i;
    switch (i)
    {
    case 1:
        sort(kaimynai, kaimynai + n, lyginti_vardus);
        break;
    case 2:
        sort(kaimynai, kaimynai + n, lyginti_amzius);
        break;
    default:
        break;
    }   
}

int main(){
    string vardas;
    long int AK;
    int amzius;
    cout << "Ivesti kaimyno duomenis: vardas, AK, amzius\n";
    cin >> vardas;
    cin >> AK;
    cin >> amzius;
    Kaimynas k;
    k.irasyti_varda(vardas);
    k.irasyti_AK(AK);
    k.irasyti_amziu(amzius);
    Kaimynas k2;
    Kaimynas k3("Jonas", 414321345, 44);
    Kaimynas kaimynai[] = {k, k2, k3};
    spausdinti_kaimyno_informacija(kaimynai, 3);
    rikiuoti(kaimynai, 3);
    spausdinti_kaimyno_informacija(kaimynai, 3);
}