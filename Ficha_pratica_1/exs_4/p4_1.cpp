#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

bool isHydroxide(char compound[])
{
    int n = strlen(compound);
    cout << compound << endl;
    
    if (compound[n - 2] == 'O' && compound[n - 1] == 'H')
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isHydroxide_string(string compound)
{
    int n = compound.length(); 
    cout << compound << endl;
    if (compound.at(n - 2) == 'O' && compound.at(n - 1) == 'H')
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{

    char compound[4] = {'K', 'O', 'H','\0'};
    char compound1[5] = {'H', '2', 'O', '2','\0'};
    char compound2[5] = {'N', 'a', 'C', 'l','\0'};
    char compound3[5] = {'N', 'a', 'O', 'H','\0'};
    char compound4[7] = {'C', '9', 'H', '8', 'O', '4', '\0'};
    char compound5[5] = "MgOH";

    cout << isHydroxide(compound) << endl;
    cout << isHydroxide(compound1) << endl;
    cout << isHydroxide(compound2) << endl;
    cout << isHydroxide(compound3) << endl;
    cout << isHydroxide(compound4) << endl;
    cout << isHydroxide(compound5) << endl;

    string compound6("KOH");
    string compound7("H2O2");
    string compound8("NaCl");
    string compound9("NaOH");
    string compound10("C9H8O4");
    string compound11("MgOH");


    cout << isHydroxide_string(compound6) << endl;
    cout << isHydroxide_string(compound7) << endl;
    cout << isHydroxide_string(compound8) << endl;
    cout << isHydroxide_string(compound9) << endl;
    cout << isHydroxide_string(compound10) << endl;
    cout << isHydroxide_string(compound11) << endl;




    return 0;
}