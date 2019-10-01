#include <iostream>

using namespace std;



int main(){

    int h1,h2,m1,m2,s1,s2;  
    int h=0,m=0,s=0;
    int dias;

    cout << "Tempo 1 (horas minutos segundos) ?";
    cin >> h1 >> m1 >> s1;
    cout << endl;
    cout << "Tempo 2 (horas minutos segundos) ?";
    cin >> h2 >> m2 >> s2;
    cout << endl;

    s  = s1+s2;
    if(s >= 60){
        m++;
        s = s - 60;
    }
    
    m = m + m1+m2;
    
    if(m >= 60){
        h++;
        m = m - 60;
    }
    h = h + h1 + h2;

    if(h >=24){
        dias = 1;
        h = h - 24;
    }
    cout << "Soma dos tempos :" << dias << " dia";
    cout << ", " << h << " horas";
    cout << ", " << m << " minutos";
    cout << ", " << s << " segundos" << endl;



    return 0;
}