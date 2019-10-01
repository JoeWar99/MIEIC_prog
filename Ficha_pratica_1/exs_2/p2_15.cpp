#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main()
{

    srand(time(NULL));

    int op1, op2, reposta1, reposta2;
    time_t time1;
    time_t time2;

    while (1)
    {
        op1 = rand() % 7 + 2;
        op2 = rand() % 7 + 2;

        cout << op1 << " x " << op2 << endl;
        cout << "Resposta ?? ";
        reposta2 = op1 * op2;
        time(&time1);
        cin >> reposta1;
        time(&time2);
        if (reposta1 == reposta2)
        {
            if ((time2 - time1) < 5)
            {
                cout << "bom" << endl;
            }

            if ((time2 - time1) > 5 && (time2 - time1) < 10)
            {
                cout << "satisfaz" << endl;
            }

            if ((time2 - time1) > 10)
            {
                cout << "insuficiente" << endl;
            }
        }
        else
        {
            cout << "reposta errada" << endl;
        }
    }

    return 0;
}