#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, ncopy;

    cin >> n;

    ncopy = n;

    vector<vector<int>> notasQuantidade(7, vector<int> (2, 0));

    notasQuantidade[0][0] = 100;
    notasQuantidade[1][0] = 50;
    notasQuantidade[2][0] = 20;
    notasQuantidade[3][0] = 10;
    notasQuantidade[4][0] = 5;
    notasQuantidade[5][0] = 2;
    notasQuantidade[6][0] = 1;

    while(n > 0){
        for(int i = 0; i <= 6; i++){
            if(n / notasQuantidade[i][0] > 0){
                n -= notasQuantidade[i][0];
                notasQuantidade[i][1]++;
                break;
            }
        }
    }

    cout << ncopy << endl;
    for(int i = 0; i <= 6; i++){
        cout << notasQuantidade[i][1] << " nota(s) de R$ " << notasQuantidade[i][0] << ",00" << endl;
    }

    return 0;
}