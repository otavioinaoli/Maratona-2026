#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void dfsAux(vector<vector<int>> &grafo, int a, int b){
    grafo[a][b] = -1;
    
    if(a + 1 < 5 && grafo[a + 1][b] == 0){
        dfsAux(grafo, a + 1, b);
    }
    if(a - 1 >= 0 && grafo[a - 1][b] == 0){
        dfsAux(grafo, a - 1, b);
    }
    if(b + 1 < 5 && grafo[a][b + 1] == 0){
        dfsAux(grafo, a, b + 1);
    }
    if(b - 1 >= 0 && grafo[a][b - 1] == 0){
        dfsAux(grafo, a, b - 1);
    }
}

void dfs(vector<vector<int>> &grafo){
     if (!grafo[0][0]) {
        dfsAux(grafo, 0, 0);
    }
    
}
 
int main() {
 
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        vector<vector<int>> grafo(5, vector<int>(5, 0));
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 5; j++){
                cin >> grafo[i][j];
            }
        }
        dfs(grafo);
        
        if(grafo[4][4] == -1)
            cout << "COPS\n";
        else
            cout << "ROBBERS\n";
    }
 
    return 0;
}