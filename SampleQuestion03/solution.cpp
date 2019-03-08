/*

Chris Gayle has a legacy of hitting sixes in his innings. He loves to hit sixes. 
Now in a particular match, he already know that he will face total of (N + 1) balls which means that he will get out on (N + 1)th ball. 
So he has decided to hit sixes in each of the initial N balls. He will require some power Pi to hit a six on ith ball. 
He can only hit a six on any ball if he has power greater than the required power. He has M amount of power initially. 
He can play initial N balls in any order and by hitting six on ith ball, he will gain Gi power but he will loose that Pi power. 
Now you are required to output "YES" or "NO" to answer that if he can hit N sixes or not.


Input
First line will contain T(No.oftestcases).
First line of each test case will contain two space separated integers : N and M
Next each N lines will contain two space separated integers denoting Gi and Pi


Output
For every test case, print the required answer in a new line.


Constraints
1≤T≤10
1 ≤ N ≤ 10^4
1 ≤ M, Gi and Pi ≤ 10^9


Sample Input
1 
2 7
3 6 
2 4


Sample Output
YES
*/

#include <iostream>

using namespace std;


struct stat{
    int done;
    long long int G;
    long long int P;
};

void merge(stat arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    stat L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].P <= R[j].P)
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(stat arr[], int l, int r){
    if(l<r){
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}




int main(){
    int num_test_cases;
    cin>>num_test_cases;
    while(num_test_cases>0){
        num_test_cases--;
        int N;
        long long int M;
        cin>>N>>M;
        stat arr[N];
        for(int i=0; i<N; i++){
            long long int G, P;
            cin>>G>>P;
            arr[i].G = G;
            arr[i].P = P;
            arr[i].done = 0;
        }
        cout<<endl;
        mergeSort(arr, 0, N-1);       //Could have used quick sort in case of constraints
        long long int sum=0;
        arr[0].G+=M;
        for(int i=1; i<N; i++){
            arr[i].G+=arr[i-1].G;
        }


        long long int power = M;

        if(arr[0].P>M){
            cout<<"NO"<<endl;
            return 0;
        }

        // cout<<endl;
        // for(int i=0; i<N; i++){
        //     cout<<arr[i].G<<"\t"<<arr[i].P<<endl;
        // }

        int i=0;
        while(i<N){
            if(arr[i].P<=power){
                i++;
                continue;
            }else{
                if(arr[i-1].done==1){
                    break;
                }
                power=arr[i-1].G;
                arr[i-1].done=1;
            }
        }

        if(i<N){
            cout<<i<<" NO"<<endl;
        }else{
            cout<<i<<" YES"<<endl;
        }

        




        // This was approach 1
        // long long int diff[N];
        // for(int i=0; i<N; i++){
        //     long long int G, P;
        //     cin>>G>>P;
        //     diff[i] = G-P;
        // }
        // for(int i=0; i<N; i++){
        //     M+=diff[i];
        // }
        // if(M>=0){
        //     cout<<"YES"<<endl;
        // }else{
        //     cout<<"NO"<<endl;
        // }
    }
    return 0;
}