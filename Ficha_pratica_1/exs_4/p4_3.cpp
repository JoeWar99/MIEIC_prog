#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void decompse(string compound)
{
    cout << compound << "  ";
    int length = compound.length();
    string d1;
    ostringstream d11;

    d11.str(d1);

    for (int i = 0; i < length; i++)
    {

        if (compound.at(i) >= '0' && compound.at(i) <= '9')
        {
            cout << "  ";
        }
        else
        {
            cout << compound.at(i);
            if (i + 1 < length)
            {
                if (compound.at(i + 1) >= 'a' && compound.at(i + 1) <= 'z')
                {
                    cout << compound.at(i + 1);
                    i += 1;
                }
            }
            cout << "  ";
        }
    }

    cout << "\n";
}

int main()
{

    string compound6("KOH");
    string compound7("H2O2");
    string compound8("NaCl");
    string compound9("NaOH");
    string compound10("C9H8O4");
    string compound11("MgOH");

    decompse(compound6);
    decompse(compound7);
    decompse(compound8);
    decompse(compound9);
    decompse(compound10);
    decompse(compound11);

    return 0;
}