/*

There are N pots. Every pot has some water in it.
They may be partially filled.
Every pot is associated with overflow number O which tell how many minimum no. of stones required for that pot to overflow.
The crow knows O1 to On(overflow no. for all the pots). Crow wants some K pots to be overflow.
So the task is the minimum number of stones he can make K pots overflow in the worst case.

An array of overflow no--. {1,...On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and the crow has to overflow one pot(k=1).
So crow will put 5 stones in the pot with overflow no.(58), it will not overflow, then he will put them in the pot with overflow no.(5),
hence the total no. of stones to make overflow one pot is=10.
What is the best algorithm to do it?

*/
#include <iostream>
using namespace std;

#define lim 100
int overflow_numbers[lim];
int k;
int num_pots;




void merger(int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++){
        L[i]=overflow_numbers[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=overflow_numbers[m+1+j];
    }


    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            overflow_numbers[k]=L[i];
            i++;
        }else{
            overflow_numbers[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        overflow_numbers[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        overflow_numbers[k]=R[j];
        k++;
        j++;
    }
}


void merge_sort(int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);
        merger(l, m, r);
    }
}



int main(){
    cin>>num_pots;
    for(int i=0; i<num_pots; i++){
        cin>>overflow_numbers[i];
    }
    cin>>k;
    merge_sort(0,num_pots-1);

    cout<<"\nTotal Stones Required : "<<overflow_numbers[k-1]*num_pots<<endl;

}


