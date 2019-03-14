// Next greater number given set of digits

#include <iostream>
using namespace std;

int nextNum(int actualNum[], int len){
    int result=0;

    int flag=0, d=0;
    for(int i=len-1; i>0; i--){
        if(actualNum[i-1]<actualNum[i]){
            flag=1;
            d=i-1;
            break;
        }
    }
    if(flag==0){
            //Num in descending order
        return -1;
    }

    int c=actualNum[d], smallest=d+1;
    for(int i=d+1; i<len; i++){
        if(actualNum[i]>c && actualNum[i]<actualNum[smallest])
            smallest=i;
    }


    int temp=c;
    actualNum[d]=actualNum[smallest];
    actualNum[smallest]=temp;

    for(int i=d+1; i<len; i++){
        for(int j=i; j<len; j++){
            if(actualNum[i]>actualNum[j]){
                int temp=actualNum[i];
                actualNum[i]=actualNum[j];
                actualNum[j]=temp;
            }
        }
    }

    for(int i=0; i<len; i++){
        result = (result*10 + actualNum[i]);
    }

    return result;
}


int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        int n;
        cin>>n;
        int X[10],rev[10];
        int ctr=0;
        while(n>0){
            X[ctr++]=n%10;
            n=n/10;
        }
        for(int i=0; i<ctr; i++){
            rev[i]=X[ctr-i-1];
        }
        cout<<nextNum(rev, ctr)<<endl;
    }
}
