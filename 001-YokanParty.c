#include<stdio.h>

int main(void){
    int n, l, k;
    scanf("%d %d", &n, &l);
    scanf("%d", &k);

    int A[n+1];
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    A[n] = l;

    int left = 1;
    int right = l;
    int rightn = 0;
    int c = 0;
    int score = 0;
    int remmid = 0;
    while(1){
        c = 0;
        int middle = (left+right)/2;
        if(remmid == middle){
            break;
        }
        for(int i = 0; i < n+1; i++){
            if((A[i] - rightn) >= middle){
                c++;
                rightn = A[i];
            }
        }
        rightn = 0;
        remmid = middle;
        if(k < c){
            left = middle;
            if(middle > score){
                score = middle;
            }
        }else{
            right = middle;
        }
    }
    printf("%d\n", score);

    return 0;
}