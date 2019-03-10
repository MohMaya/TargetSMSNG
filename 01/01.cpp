/*
You are given an unsorted array with both positive and negative elements. You have to find the smallest positive number missing from the array in O(n) time using constant extra space.

**Input:** First line consists of T test cases. First line of every test case consists of N, denoting the number of elements in array. Second line of every test case consists of elements in array.

**Output:** Single line output, print the smallest positive number missing.

**Constraints:**

1<=T<=100 and 1<=N<=100

**Example:**
```
Input:
2
5
1 2 3 4 5
5
0 -10 1 3 -20
Output:
6
2
```
*/

#include <iostream>
using namespace std;

int abs(int x){
    if(x>=0)
        return x;
    else
        return -x;
}

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        test_cases--;

        //Input Stage
        int size;
        cin>>size;
        int arr[size];
        int f=0;
        for(int i=0; i<size; i++){
            cin>>arr[i];
            if(arr[i]>0)
                f=1;
        }


        //Handling all non-positives
        if(f==0){
            cout<<1<<endl;
            continue;
        }

        //First move all negative nos. to the left side
        int neg_final_idx=0;
        int start=0;
        while(start<size){
            if(arr[start]<=0){
                int temp=arr[start];
                arr[start]=arr[neg_final_idx];
                arr[neg_final_idx]=temp;
                neg_final_idx++;
            }
            start++;
        }


        /*cout<<"NEG_FINAL_IDX ="<<neg_final_idx<<"\n";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;*/

        //Now the positive array lies from neg_final_idx to end
        for(int i=neg_final_idx; i<size; i++){
            int actual_idx = i;
            int item = (abs(arr[actual_idx])-1)+neg_final_idx;
            if(item<size && arr[item]>0)
                arr[item] *= -1;
        }
        int flag=0;


        /*for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        */

        for(int i=0; i<size; i++){
            if(arr[i]>0 && flag==0){
                cout<<i-neg_final_idx+1<<endl;
                flag=1;
            }
        }
        if(flag==0){
            if(neg_final_idx==0)
                cout<<size+1<<endl;
        }
    }
}
