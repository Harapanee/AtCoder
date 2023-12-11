#include<stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    char s[n+1];
    s[n] = '\0';

    if(n%2 == 0){
        for(int bit = 0; bit < (1 << n); bit++){
            for(int i = 0; i < n; i++){
                if(bit & (1 << i)){
                    s[n-i-1] = ')';
                }else{
                    s[n-i-1] = '(';
                }
            }
            int score = 0;
            for(int i = 0; i < n; i++){
                if(s[i] == '('){
                    score++;
                }else{
                    score--;
                }
                if(score < 0){
                    break;
                }
            }
            if(score == 0){
                printf("%s\n", s);
            }
        }
    }
}