#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

int mdc(int m, int n){

    if(m % n ==0){
        return n;
    }   
    else{
        return mdc(n, m % n);
    }
}

int main(){
    int m , n;

    cout << "m e n ?" << endl;
    cin >> m >> n;

    cout << mdc(m,n) << endl;

    return 0;
}












