#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
 
int main(){
    string s;
 
    cin >> s;
 
    vector<int> v(s.size(), 0);
 
    for(int i = 1; i < s.size(); i++){
        if(s[i] == s[i - 1]){
            v[i] = v[i - 1] + 1;
        }else{
            v[i] = v[i - 1];
        }
        
    }
    
    int n;
 
    cin >> n;
 
    while(n--){
        int l, r;
 
        cin >> l >> r;
 
        l--;
        r--;
 
        cout << v[r] - v[l] << endl;
    }
 
 
 
    return 0;
 
}