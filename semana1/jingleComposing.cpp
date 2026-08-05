#include <iostream>
#include<vector>
#include <string>

using namespace std;
 
int main() {
    vector<double> v(26, 0);
    
    v['W' - 'A'] = 1;
    v['H' - 'A'] = 0.5;
    v['Q' - 'A'] = 0.25;
    v['E' - 'A'] = 0.125;
    v['S' - 'A'] = 0.0625;
    v['T' - 'A'] = 0.03125;
    v['X' - 'A'] = 0.015625;
    
    char c;
    double contadorS = 0;
    double contadorM = 0;
    while(cin.get(c)){
        if(c >= 'A' && c <= 'Z'){
            contadorM += v[c - 'A'];
        }else if(c == '/'){
            if(contadorM == 1)
                contadorS++;
            contadorM = 0;
        }else if(c == '\n'){
            cout << contadorS << endl;
            contadorS = 0;
            contadorM = 0;
        }else if(c == '*'){
            break;
        }
    }
    
    return 0;
}