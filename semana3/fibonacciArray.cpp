#include <iostream>
#include <vector>

using namespace std;
 
int main() {
    vector<long long> fib(61, 0);
    
    fib[1] = 1;
    
    for(int i = 2; i <= 60; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    int n;

    cin >> n;

    while(n--){
        int n2;

        cin >> n2;

        cout << "Fib(" << n2 << ") = " << fib[n2] << endl;
    }
 
    return 0;
}