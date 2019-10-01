#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

bool sequenceSearch_mine(string s, int nc, char c){
    int length = s.length();

    for(int i = 0; i<length ; i++){
        if(s.at(i)== c){
            for(int j = i; j < i+nc; j++){
                if(s.at(j) != c){
                    break;
                }
                else if(j == i+nc-1){
                    return true;
                }
            }
        }
    }

    return false;

}

bool sequenceSearch(string s, string s2){
   if(s.find(s2) == -1){
       return false;
   }
   else{
       return true;
   }
}

int main(){

    string s;
    char c;
    int nc;
    getline(cin, s);
    
   /* istringstream s1;
    s1.str(s);
    s1 >> nc;
    cout << nc;*/

    cout << "char ? " << endl;
    cin >> c;
    cout << "n de characters na sequencia " << endl;
    cin >> nc;

    
    string s2;

    for(int i = 0; i<nc; i++){
        s2.push_back(c);
    }



   /* if(sequenceSearch_mine(s, nc, c)== true){
        cout << "existe" << endl;
    }*/
    if(sequenceSearch(s, s2)== true){
        cout << "existe" << endl;
    }
    else{
        cout << "nao existe" << endl;
    }




















    return 0;
}