#include<iostream>
#include<vector>

using namespace std;

int main(){

    while(true){
        int n, p;
        
        cin >> n;
        
        if(n == 0)
            return 0;
            
        cin >> p;
        
        vector<vector<int>> tempoQuantidade(n, vector<int>(2));
        for(int i = 0; i < n; i++){
            cin >> tempoQuantidade[i][0] >> tempoQuantidade[i][1];
        }
        
        vector<vector<int>> dp(n + 1, vector<int> (p + 1, 0));
        
        for(int i = 1; i <= n; i++){
            int valor = tempoQuantidade[i-1][0];
            int peso = tempoQuantidade[i-1][1];
            for(int j = 0; j <= p; j++){
                dp[i][j] = dp[i-1][j];
                if(peso <= j){
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i-1][j-peso] + valor
                    );
                }
            }
        }
        
        cout << dp[n][p] << " min.\n";
    }
    
    
    return 0;
}