#include <iostream>


using namespace std;


int main(){

    double a,b,c,d,e,f;

    cout << "Valores para a, b , c , d ,e ,f (nesta ordem especifica)" << endl;
    cin >> a >> b >> c >> d >> e >> f;

    cout << "x = " << (c*e-b*f)/(a*e-b*d) << endl;
    cout << "y = " << (a*f-c*d)/(a*e-b*d) << endl;



    return 0;
}