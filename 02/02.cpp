#include <stdio.h>
#include <stdlib.h>

int pow(int b, int e){
    int result=1;
    for(int i=1; i<=e; i++){
        result*=b;
    }
    return result;
}

int main(){
    //Input
    int n, m, k;
    scanf("%d %d %d",&n, &m, &k);
    int A[20][20] = {0};

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &A[i][j]);
        }
    }

    int size = 1;
    for(int i=1; i<=20; i++){
        size*=2;
    }

    int *hash = (int *)calloc(size, sizeof(int));

    for(int i=0; i<n; i++){
        int keyvalue = 0;
        int numZeros = 0;
        for(int j=0; j<m; j++){
            keyvalue += (A[i][j]*pow(2, j));
            if(A[i][j]==0){
                numZeros+=1;
            }
        }
        if((numZeros-k)%2==0 && (numZeros-k)>=0)
            hash[keyvalue]+=1;
    }

    int keyWithMaxVal=0, MaxVal=0;
    for(int i=0; i<size; i++){
        if(hash[i] > MaxVal){
            MaxVal = hash[i];
            keyWithMaxVal = i;
            //printf("%d\n",MaxVal);
        }
    }

    printf("%d", MaxVal);

    return 0;

}
