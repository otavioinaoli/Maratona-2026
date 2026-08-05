#include<iostream>
#include<vector>

using namespace std;

int main(){
    int T;
    
    cin >> T;

    while (T--){
        int N;
        
        cin >> N;

        int V, A;
        
        cin >> V >> A;
        
        vector<vector<int>> Grafo(V, vector<int>(V, 0));
        int arestasUnicas = 0;
        for(int i = 0; i < A; i++){
            int x, y;
            
            cin >> x >> y;
            
            if(!Grafo[x][y]){
                Grafo[x][y] = 1;
                Grafo[y][x] = 1;
                arestasUnicas++;
            }
        }

        cout << 2 * arestasUnicas << '\n';
    }

    return 0;
}