#include<stdio.h>
 
int main(){
    int t;
    long long base, soma;
 
    scanf("%d", &t);
 
    for(int i = 0; i < t; i++){
        soma = 0;
 
        scanf("%lld", &base);
 
        while(base){
            soma += base;
            base /= 2;
        }
 
        printf("%lld\n", soma);
    }
 
 
    return 0;
}