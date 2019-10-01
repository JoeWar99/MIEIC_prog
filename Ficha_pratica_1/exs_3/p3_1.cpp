#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1,double x2, double y2){

    double distancia_int;

    distancia_int = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

    return distancia_int;
}

double area(double x1, double y1,double x2, double y2,double x3, double y3){

    double area_int;
    double a = distance(x1,y1,x2,y2);
   // cout << a <<endl;
    double b = distance(x1,y1,x3,y3);
   // cout << b << endl;
    double c = distance(x2,y2,x3,y3);
 //   cout << c << endl;
    double s = (a+b+c)/2.0;
    
    area_int = sqrt(s*(s-a)*(s-b)*(s-c)); 
 //   cout << area_int <<endl;
    return area_int;
}

int main(){

    double x1,y1,x2,y2,x3,y3;
    double area_int;
    
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    area_int  =  area(x1,y1,x2,y2,x3,y3);
    
    cout << area_int << endl;


    return 0;
}