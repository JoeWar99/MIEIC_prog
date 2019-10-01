#include <iostream>
#include <cmath>
using namespace std;
# define M_PI           3.14159265358979323846  /* pi */
int main(){

    double raio;
    double p;


    cout << "qual é o p (Kg/m^3) ? " << endl;
    cin >> p;
    cout << endl;
    cout << "qual é o raio (m) ?" << endl;
    cin >> raio;
    cout << endl;

    cout<< "Massa da esfera é " << (4/3.0)*   M_PI* pow(raio,3) << "(Kg)" << endl;



    return 0;
}