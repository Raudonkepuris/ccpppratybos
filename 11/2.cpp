#include<fstream>
#include<random>
#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;

class Studentas{
    private:
        string vardas;
        int studiju_kursas;
        double egzaminu_vidurkis;
    public:
        Studentas(){
            random_device rd;
            uniform_int_distribution<int> disti(1, 4);
            uniform_real_distribution<double> distf(6, 10);           
            vardas = "";
            studiju_kursas = disti(rd);
            egzaminu_vidurkis = distf(rd);
        }
        void rasyti_varda(string _vardas){
            vardas = _vardas;
        }

        stringstream studento_informacija(){
            stringstream info;
            info << "Vardas: " << vardas << "\nStudiju kursas: " << studiju_kursas << setprecision(2) << "\nEgzaminu vidurkis: " << egzaminu_vidurkis << "\n";
            return info;
        }

        int gauti_kursa(){
            return studiju_kursas;
        }
        double gauti_egzaminu_vidurki(){
            return egzaminu_vidurkis;
        }
};

void surasyti_vardus(string vardai, Studentas studentai[], int m){
    int i = 0, l = 0, n = 0;
    string vardas;
    while(vardai.find(" ", i) != -1 && n < m){
        i = vardai.find(" ", i) + 1;
        if(isalpha(vardai[i])){
            l = vardai.find(" ", i);
            vardas = vardai.substr(i, l - i);
            studentai[n].rasyti_varda(vardas);
            n++;
        }
    }
}

template <size_t N>
void atrinkti_pazangius(Studentas (&studentai)[N]){
    ofstream of("rezultatai.txt");
    if(of.is_open()){
        for(Studentas s : studentai){
            if(s.gauti_kursa() > 1 && s.gauti_egzaminu_vidurki() >= 8){
                of << s.studento_informacija().str();
            }
        }
    }
    of.close();
}

int main(){
    ifstream vardaiF("vardai.txt");
    if(!vardaiF.is_open()) return 1;

    string vardai;
    getline(vardaiF, vardai);
    cout << vardai << endl;

    Studentas studentai[10];

    surasyti_vardus(vardai, studentai, 10);

    for(auto s : studentai){
        cout << s.studento_informacija().str() << endl;
    }

    atrinkti_pazangius(studentai);
}