#include <stdio.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b,a%b);
}

int eulerFunction(int n) {
    int count = 0;
    if(n<=0)
    {
        printf("not defined");
        return -1;
    }
   
    if(n>0)
    {
    for (int i = 1; i <= n; i++) {
        if (gcd(i, n) == 1) {
            count++;
        }
    }
    } 
    return count;
    
}

int main() {
    int n,answer;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    answer= eulerFunction(n);
    if(answer!=-1) 
    printf(" value of q(%d)  is %d",n,answer);
   //printf("euler function:",result);
    return 0;
}
