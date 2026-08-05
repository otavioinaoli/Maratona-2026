#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void dfsAux(int v, vector<vector<int>> &grafo, vector<int> &visitados, vector<char> &componentes, int a){
    char saida = 'a' + a;
    componentes.push_back(saida);
    visitados[a] = 1;
    
    for(int j = 0; j < v; j++){
        if(grafo[a][j] && !visitados[j])
            dfsAux(v, grafo, visitados, componentes, j);
    }
}

void dfs(int v, vector<vector<int>> &grafo){
    vector<int> visitados(v, 0);
    
    
    int conexoes = 0;
    for(int i = 0; i < v; i++){
        vector<char> componentes;
        if(!visitados[i]){
            conexoes++;
            dfsAux(v, grafo, visitados, componentes, i);
            sort(componentes.begin(), componentes.end());
            for(char c : componentes){
                cout << c << ",";
            }
            cout << endl;
        }
        
    }
    
    cout << conexoes << " connected components\n" << endl;
    
}
 
int main() {
 
    int t;
    
    cin >> t;
    
    for(int i = 1; i <= t; i++){
        int v, e;
        
        cin >> v >> e;
        
        vector<vector<int>> grafo(v, vector<int>(v, 0));
        
        while(e--){
            char o, d;
            
            cin >> o >> d;
            
            grafo[o - 'a'][d - 'a'] = 1;
            grafo[d - 'a'][o - 'a'] = 1;
        }
        cout << "Case #" << i << ":" << endl;
        dfs(v, grafo);
    }
 
    return 0;
}