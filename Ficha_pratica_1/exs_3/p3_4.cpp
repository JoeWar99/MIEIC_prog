#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double round(double x, unsigned n)
{
    double y;

    double factor = 1;

    for(int i = 0; i < n ; i++){
        factor = factor * 10;
    }
    y = floor(x * factor+(1/n))/factor;


    return y;
}

int main()
{

    double n;
    int casa;
    double rounded;

    cout << "Qual o numero que quer arrendodar ?" << endl;
    cin >> n;
    cout << " A que casa decimal ?(1,2,3,4....) ? " << endl;
    cin >> casa;
    rounded = round(n,casa);
    cout << "valor arredondado =  " << rounded<< endl;

    return 0;
}