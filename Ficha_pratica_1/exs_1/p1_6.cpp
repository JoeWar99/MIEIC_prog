#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double v1_x, v1_y;
    double v2_x, v2_y;
    double v3_x, v3_y;
    double area;
    double s, a, b, c;

    cout << "Coordenadas do primeiro vertice (x,y) ?" << endl;
    cin >> v1_x >> v1_y;
    cout << "Coordenadas do segundo vertice (x,y) ?" << endl;
    cin >> v2_x >> v2_y;
    cout << "Coordenadas do tercedouble s = distance(x1,y1,x2,y2);iro vertice (x,y) ?" << endl;
    cin >> v3_x >> v3_y;

    a = sqrt(pow(v2_x-v1_x, 2)+ pow(v2_y-v1_y,2));
    b = sqrt(pow(v2_x-v3_x, 2)+ pow(v2_y-v3_y,2));
    c = sqrt(pow(v1_x-v3_x, 2)+ pow(v1_y-v3_y,2));
    s = a + b+c;
    s = s/2;
    area  = sqrt(s*(s-a)*(s-b)*(s-c));

    cout << "area é " << area << endl;




    return 0;   
}