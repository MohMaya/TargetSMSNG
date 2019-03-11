/*

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] –> [3,5,8] –> [3,8] –> [8] –> [] coins = 3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167

*/



#include <iostream>
using namespace std;

#define lim 500
int bal[lim];
int dp[lim][lim];
int n;


int solution(){
    for(int len=1; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j=i+len-1;
            for(int k=i; k<=j; k++){
                int leftVal=1;
                int rightVal=1;

                if(i!=0){
                    leftVal=bal[i-1];
                }
                if(j!=n-1){
                    rightVal=bal[j+1];
                }

                int before=0;
                int after=0;
                if(i!=k){
                    before=dp[i][k-1];
                }
                if(j!=k){
                    after=dp[k+1][j];
                }
                dp[i][j]=max(dp[i][j], before+after+(leftVal*rightVal*bal[k]));
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        bal[i]=x;
    }
    cout<<solution()<<endl;
}
