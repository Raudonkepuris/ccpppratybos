#include <iostream>

int main(){
    std::cout << "Kaimynui is desnes linkiu laimes\n";


    int alga;
    std::cin >> alga;
    std::cout << "Baiges studijas tikiuosi gauti " << alga << " euru atlyginima\n";


    int p_int, a_int, vid_int, vid_float_int;
    float p_float, a_float, vid_float;

    std::cout << "Ivesti du sveikuosius skaicius: \n";
    std::cin >> p_int >> a_int;

    std::cout << "Ivesti du realiuosius skaicius: \n";
    std::cin >> p_float >> a_float;

    vid_int = (p_int + a_int) / 2;
    std::cout << "Sveikuju skaiciu vidurkis saugamas sveikojo tipo kintamajame " << vid_int << "\n";

    vid_float_int = (p_float + a_float) / 2;
    std::cout << "Realiuju skaiciu vidurkis saugamas sveikojo tipo kintamajame " << vid_float_int << "\n";

    vid_float = (p_float + a_float) / 2;
    std::cout << "Realiuju skaiciu vidurkis saugamas realiojo tipo kintamajame " << vid_float << "\n";

    return 0;
}