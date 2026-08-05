#include <iostream>
#include <sstream>
#include <set>
#include <string>

using namespace std;
 
int main() {
    int n;
    
    cin >> n;
    cin.ignore();
    
    while(n--){
        set<string> s;
        
        string linha;
        getline(cin, linha);
    
        stringstream ss(linha);
        string palavra;

        while (ss >> palavra) {
            s.insert(palavra);
        }
        
        bool prim = true;
        for(string palavra : s){
            if(!prim)
                cout << ' ';
            cout << palavra;
            prim = false;
        }
        
        cout << endl;
        
    }
 
    return 0;
}