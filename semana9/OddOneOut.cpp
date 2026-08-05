#include<iostream>
 
using namespace std;
 
int main(){
    int t;
 
    cin >> t;
 
    while(t--){
        int a,b,c;
 
        cin >> a >> b >> c;
 
        int res = a ^ b ^ c;
 
        cout << res << endl;
    }
 
    return 0;
}