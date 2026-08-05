#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;

    cin >> t;

    while(t--){
        int n;

        cin >> n;

        vector<int> fila(n);
        vector<int> filaCorreta(n);
        
        for(int i = 0; i < n; i++){
            cin >> fila[i];
            filaCorreta[i] = fila[i];
        }

        sort(filaCorreta.begin(), filaCorreta.end(), [](const int &a, const int &b){
            return a > b;
        } );

        int certos = 0;

        for(int i = 0; i < n; i++){
            if(fila[i] == filaCorreta[i])
                certos++;
        }

        cout << certos << endl;

    }

    return 0;
}