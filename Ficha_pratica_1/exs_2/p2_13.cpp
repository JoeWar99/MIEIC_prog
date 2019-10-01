#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int c;
    cout << "um numero inteiro qualquer ?" << endl;
    cin >> c;

    while (c != 1)
    {
        for (int i = 2; i <= c; i++)
        {
            if (c % i == 0 && i > 1)
            {
                c = c / i;
                cout << i << "x";
                break;
            }
        }
    }

    return 0;
}