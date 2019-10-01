

/*
C++ STRINGS
getline()
string member funcions call: length(), find_last_of(), substr()

#include <iostream>
#include <string>
#include <cstddef>
using namespace std;
int main()
{
string name, lastName;
size_t posLastSpace;
cout << "Your full name ? "; //try with "Rui" and "Rui Sousa"
getline(cin,name);
cout << "Hello " << name << "!\n";
posLastSpace = name.find_last_of(' ');
if (posLastSpace == string::npos) // no space character was found
cout << "Your name has only one word ?!\n";
else
{
lastName = name.substr(posLastSpace+1,name.length()-posLastSpace-1);
cout << "Your last name is: " << lastName << endl;
}
return 0;
}
TO DO, BY THE STUDENTS:
search for other methods (similar to find_last_of(), substr() and length())
of the string class, for string manipulation.
The class and method concepts will be introduced later.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void erase_right(string &s)
{
    s.erase(s.find_last_not_of(" ") + 1, s.size());
}
void erase_left(string &s)
{
    s.erase(0, s.find_first_not_of(" "));
}
void erase_middle(string &s)
{
    int pos = 0;
    string name;
    int cnt = 0;

    while (1)
    {
        erase_left(s);
        erase_right(s);
        pos = s.find_first_of(" ");
        if (pos == string::npos)
        {
            break;
        }
        else
        {
            name.append(s.substr(0, pos + 1));
            s.erase(0, pos);
        }
    }
    name.append(s);
    s = name;
}
void erase(string &s)
{
    erase_left(s);
    erase_right(s);
    erase_middle(s);
}

string normalizeName(string name)
{

    string name1 = name;
    int pos;
    vector<string> vec = {" DE ",
                          " DO ",
                          " DA ",
                          " E "};
    erase(name);

    for (int i = 0; i < name1.size(); i++)
    {
        name1.at(i) = toupper(name1.at(i));
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i)<< endl;
        while ((pos = name1.find(vec.at(i))) != string::npos)
        {
            if(vec.at(i) == "DO" && name1.at(pos+2) == 'S'){
                name1.erase(pos, (vec.at(i).size()));
                erase(name1);
            }
            else if(vec.at(i) == "DA" && name1.at(pos+2)== 'S'){
                name1.erase(pos, (vec.at(i).size()));
                erase(name1);
            }
            else{
                name1.erase(pos, (vec.at(i).size()-1));
                erase(name1);

            }
            
        }
    }

    return name1;
}

int main()
{
    string name, name_normalized;
    size_t posLastSpace;
    cout << "Your full name ? "; //try with "Rui" and "Rui Sousa"
    getline(cin, name);

    name_normalized = normalizeName(name);
    cout << "comparação : " << endl;
    cout << name << endl;
    cout << name_normalized << endl;
}