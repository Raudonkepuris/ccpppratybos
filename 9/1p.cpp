#include <iostream>

using namespace std;

class Preke{
    private:
        int prekes_kodas;
        int gauta_vnt;
        int parduota_vnt;
        double vieneto_kaina;
    public:
        Preke(){
            prekes_kodas = 0;
            gauta_vnt = 0;
            parduota_vnt = 0;
            vieneto_kaina = 0;
        }
        Preke(int pk, int gv, int pv, double vk){
            prekes_kodas = pk;
            gauta_vnt = gv;
            parduota_vnt = pv;
            vieneto_kaina = vk;
        }

        void rasyti_pk(int pk){
            prekes_kodas = pk;
        }
        int gauti_pk(){
            return prekes_kodas;
        }

        void rasyti_gv(int gv){
            gauta_vnt = gv;
        }
        int gauti_gv(){
            return gauta_vnt;
        }

        void rasyti_pv(int pv){
            parduota_vnt = pv;
        }
        int gauti_pv(){
            return parduota_vnt;
        }

        void rasyti_vk(double vk){
            vieneto_kaina = vk;
        }
        double gauti_vk(){
            return vieneto_kaina;
        }
};

void ivesti_prekes(Preke prekes[], int &sz, const int &MAX_PREKIU){
    int pk, gv, pv;
    bool b;
    double vk;
    cout << "Ivesti prekes info:\n";
    while(true){
        cout << "Prekes kodas: ";
        cin >> pk;
        cout << "Gauta vnt: ";
        cin >> gv;
        cout << "Parduota vnt: ";
        cin >> pv;
        cout << "Vnt kaina: ";
        cin >> vk;
        prekes[sz].rasyti_pk(pk);
        prekes[sz].rasyti_gv(gv);
        prekes[sz].rasyti_pv(pv);
        prekes[sz].rasyti_vk(vk);
        sz++;
        if(sz >= MAX_PREKIU){
            cout << "Prekiu uztenka\n";
            break;
        }
        cout << "Ivesti dar viena preke (1/0)?: ";
        cin >> b;
        if(b != 1){
            break;
        }
    }
    // prekes[0].rasyti_gv(2);
    // prekes[0].rasyti_pv(1);
    // prekes[0].rasyti_vk(100);

    // prekes[1].rasyti_gv(10);
    // prekes[1].rasyti_pv(5);
    // prekes[1].rasyti_vk(2);

    // prekes[2].rasyti_gv(100);
    // prekes[2].rasyti_pv(70);
    // prekes[2].rasyti_vk(1);
    // sz = 3;
}

void sumuoti_uzdarbi(Preke prekes[], const int &sz){
    double realus_uzd = 0, galimas_uzd = 0;
    for (int i = 0; i < sz; i++)
    {
        realus_uzd += prekes[i].gauti_pv() * prekes[i].gauti_vk();
        galimas_uzd += prekes[i].gauti_gv() * prekes[i].gauti_vk();
    }
    cout << "Dabar parduotuve uz parduodas prekes uzdirbo " << realus_uzd << " pinigu\n";
    cout << "Jeigu parduotuve parduotu visas turimas prekes, uzdirbtu " << galimas_uzd << " pinigu\n";
}

int main(){
    const int MAX_PREKIU = 3;
    Preke prekes[MAX_PREKIU] = {Preke()};
    int sz = 0;

    ivesti_prekes(prekes, sz, MAX_PREKIU);

    sumuoti_uzdarbi(prekes, sz);

    return 0;
}