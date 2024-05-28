#include <iostream>

using namespace std;

class Studentas{
    private:
        int pazymejimo_nr;
        double egzaminu_vidurkis;
        bool VF;
    public:
        Studentas(){
            pazymejimo_nr = 0;
            egzaminu_vidurkis = 0;
            VF = 0;
        }
        Studentas(int _pazymejimo_nr, double _egzaminu_vidurkis, bool _VF){
            pazymejimo_nr = _pazymejimo_nr;
            egzaminu_vidurkis = _egzaminu_vidurkis;
            VF = _VF;
        }
        void rasyti_pazymejimo_nr(int _pazymejimo_nr){
            pazymejimo_nr = _pazymejimo_nr;
        }
        int gauti_pazymejimo_nr(){
            return pazymejimo_nr;
        }
        void rasyti_egzaminu_vidurki(double _egzaminu_vidurkis){
            egzaminu_vidurkis = _egzaminu_vidurkis;
        }
        double gauti_egzaminu_vidurki(){
            return egzaminu_vidurkis;
        }
        void rasyti_VF(bool _VF){
            VF = _VF;
        }
        bool gauti_VF(){
            return VF;
        }
};

void suvesti_studentus(Studentas studentai[], int &sz, const int &MAX_STUDENTU, double &ribinis_vid){
    bool b;
    int pazymejimo_nr;
    double egzaminu_vidurkis;
    bool VF;

    cout << "Ivesti ribini vidurki: ";
    cin >> ribinis_vid;

    while(true){
        cout << "Ivesti studento pazymejimo numeri: ";
        cin >> pazymejimo_nr;
        cout << "Ivesti studento egzaminu vidurki: ";
        cin >> egzaminu_vidurkis;
        cout << "Ar studentas moka uz studijas (1 - Taip, 0 - Ne)\n";
        cin >> VF;
        studentai[sz].rasyti_pazymejimo_nr(pazymejimo_nr);
        studentai[sz].rasyti_egzaminu_vidurki(egzaminu_vidurkis);
        studentai[sz].rasyti_VF(!VF);
        sz++;
        if(sz >= MAX_STUDENTU){
            cout << "Studentu uztenka\n";
            break;
        }
        cout << "Ivesti dar viena studenta (1/0)?: ";
        cin >> b;
        if(b != 1){
            break;
        }
    }
    sz = 4;
    ribinis_vid = 5;

    studentai[0].rasyti_egzaminu_vidurki(4.5);
    studentai[0].rasyti_pazymejimo_nr(0);
    studentai[0].rasyti_VF(0);

    studentai[1].rasyti_egzaminu_vidurki(5.5);
    studentai[1].rasyti_pazymejimo_nr(1);
    studentai[1].rasyti_VF(0);

    studentai[2].rasyti_egzaminu_vidurki(4.5);
    studentai[2].rasyti_pazymejimo_nr(2);
    studentai[2].rasyti_VF(1);

    studentai[3].rasyti_egzaminu_vidurki(5.5);
    studentai[3].rasyti_pazymejimo_nr(3);
    studentai[3].rasyti_VF(1);
}

void atrinkti_studentus(Studentas studentai[], const int &sz, const double &ribinis_vid){
    for (int i = 0; i < sz; i++)
    {
        if(studentai[i].gauti_VF() == 1 && studentai[i].gauti_egzaminu_vidurki() < ribinis_vid){
            cout << "Studentas su pazymejimo numeriu " << studentai[i].gauti_pazymejimo_nr() << " turi mazesni vidurki negu ribinis (" << studentai[i].gauti_egzaminu_vidurki() << "<" << ribinis_vid << ")\n";
        }
    }
    
}

int main(){
    const int MAX_STUDENTU = 4;
    double ribinis_vid;
    Studentas studentai[MAX_STUDENTU] = {Studentas()};
    int sz = 0;
    suvesti_studentus(studentai, sz, MAX_STUDENTU, ribinis_vid);
    atrinkti_studentus(studentai, sz, ribinis_vid);

}