#include<stdio.h>
int set[10],x[10],n,d;
void sumofsub(int, int);
int main(){
    int sum=0;
    printf("Enter the size of the set");
    scanf("%d", &n);
    printf("Enter the number of elements in increasing order");
    for(int i=0; i<n; i++){
    scanf("%d", &set[i]);
    }
    printf("Enter the maximum number of set");
    scanf("%d",&d);
    
    printf("The maximum number of sets are:");
    for(int i=0; i<n; i++)
        sum+=set[i];
    if(sum<d || set[d]>0){
        printf("No such subsets exists");
    }else{
        sumofsub(0,0);
    }
    return 0;
}

void sumofsub(int s, int k){
    if(s==d){
        printf("{");
        for(int i=0; i<n; i++)
            if(x[i])
                printf("%d", set[i]);
        printf(" }\n");
        return;
    }
    if(s>d ||k==n) return;
    x[k]=1;
    sumofsub(s+set[k], k+1);
    x[k]=0;
    sumofsub(s,k+1);
}