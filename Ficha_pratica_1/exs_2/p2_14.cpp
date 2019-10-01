#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

    double rq = 1, rqn;
    double n;
    double precision;
    double dif;

    cout << "precision ? " <<endl;
    cin >> precision;
    cout << "Qual o n?" << endl;
    cin >> n;

    

    cout << "rq" << setw(10) << "rqn" << setw(10) << "rqn^2" << setw(15) << "dif =n-rqn^2"<< endl;

    while(1){
        rqn = (rq+n/rq)/2.0;
        dif = n - pow(rqn,2);
        cout << rq << setw(12) << rqn << setw(10) << pow(rqn, 2) << setw(15) << dif << endl;
       
       if(abs(rqn -rq) < precision){
           break;
       }
        rq = rqn;
        

    }















    return 0;
}