#include <iostream>
#include <cmath>
#include <iomanip>
#include <climits>
using namespace std;

long factorial_ite(int n){
    long factorial_result = 1;

    for(int i = 1; i<=n; i++){
        factorial_result = factorial_result * i;
    }

    return factorial_result;
}
long factorial_rec(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    else{
        return n * factorial_rec(n-1);
    }
}
int main(){
    int i=0;
    long factorial_result;
    cout << LONG_MAX << endl;

    while(true){
        i++;
        cout << i << "  ";
        cout << factorial_rec(i) << endl;
        if(factorial_rec(i)==0){
            break;
        }
    }

    return 0;
}


















