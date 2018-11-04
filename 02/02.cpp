#include <iostream>
using namespace std;

int count_normal(int **mat, int n, int m){
    int count=0;
    for (int i = 0; i < n; i++){
        int tempCount=0;
        for (int j = 0; j < m; j++)
            tempCount+=mat[i][j];
        if(tempCount==m)
            count+=1;
    }
    return count;
}

int* rowWiseSum(int **mat, int n, int m){
    int* rowwisesum = new int[n];
    for(int i=0; i<n; i++){
        int tempSum=0;
        for(int j=0; j<m; j++)
            tempSum+=mat[i][j];
        rowwisesum[i] = tempSum;
    }  
    return rowwisesum;
}


int count_toggled(int **mat, int n, int m, int toggle, int *rowwisesum){
    int count=0;
    int **tempMat = new int *[n];
    for (int i = 0; i < n; i++){
        tempMat[i] = new int[m];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(j!= toggle)
                tempMat[i][j] = mat[i][j];
            else
                tempMat[i][j] = 1-mat[i][j];
        }
    }

    count = count_normal(tempMat, n, m);

    return count;
}

int main(){
    int n,m,k;
    cout<<"Enter the value of N : ";
    cin>>n;
    cout<<"Enter the value of M : ";
    cin>>m;
    cout<<"Enter the value of k : ";
    cin>>k;

    int **mat = new int*[n];
    for(int i=0; i<n; i++){
        mat[i] = new int[m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            cin>>mat[i][j];
    }

    // for (int i = 0; i < n; i++){
    //     for (int j = 0; j < m; j++)
    //         cout << mat[i][j]<<" ";
    //     cout<<endl;
    // }
    int normalCount = count_normal(mat, n, m);
    if(k%2==0){
        cout<<normalCount<<endl;
    }else{
        int* rowwisesum = rowWiseSum(mat, n, m);
        int maxCount = normalCount, toggled = -1;
        for(int i=0; i<m; i++){
            int count = count_toggled(mat, n, m, i, rowwisesum);
            if(count>maxCount){
                maxCount = count;
                toggled = i;
            }
        }
        cout<<"MaxRowsWithAll1 = "<<maxCount<<" Upon toggling column "<<toggled+1<<", "<<k<<" times"<<endl;
    }


    return 0;
}
