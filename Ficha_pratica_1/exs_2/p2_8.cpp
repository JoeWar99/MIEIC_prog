#include <iostream>
#include <cmath>

using namespace std;

int main(){


    double n, q, j;


    cout << " n , q , j ?" << endl;
    cin >> n >> q >> j;

    for(int i = 0; i <= n; i++){
        q = q + (j * q)/100.0;
    }

    cout << " A quantia vai ser " << q << endl;









    return 0;
}