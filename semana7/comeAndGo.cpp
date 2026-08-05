#include<iostream>
#include<vector>

using namespace std;

void dfs(int i, vector<int>& vis, vector<vector<int>> &grafo){
    vis[i] = 1;
    
    for(int j = 0; j < grafo[0].size(); j++){
        if(!vis[j] && grafo[i][j])
            dfs(j, vis, grafo);
    }
}

int main(){
    
    while(true){
        int n, m;
        
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<int>> grafo(n + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++){
            
            int v, w, p;
            
            cin >> v >> w >> p;
            
            grafo[v][w] = 1;

            if(p == 2)
                grafo[w][v] = 1;
        }
        
        
        vector<int> visitados(n + 1, 0);
        
        int g = 1;
        for(int i = 1; i <= n; i++){
            vector<int> visitados(n + 1, 0);

            dfs(i, visitados, grafo);

            for(int j = 1; j <= n; j++){
                if(!visitados[j]){
                    g = 0;
                    break;
                }
            }
            if(!g)
                break;
        }
        
        cout << g << endl;
    }

    return 0;
}