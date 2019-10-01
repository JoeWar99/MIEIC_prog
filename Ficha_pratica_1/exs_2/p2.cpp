#include <iostream>

using namespace std;
int main()
{

    double op1;
    double op2;
    double op3;
    double media;

    cout << "A ?";
    cin >> op1;
    cout << endl;
    cout << "B ?";
    cin >> op2;
    cout << endl;
    cout << "c?";
    cin >> op3;
    cout << endl;

    media = (op1+op2+op3)/3.0;

    cout << "media =" << media << endl;
    cout << "A-media = " << op1-media << endl;
    cout << "B-media = " << op2-media << endl;
    cout << "C-media = " << op3-media << endl;

        return 0;
}