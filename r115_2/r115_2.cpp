#include <iostream>

using namespace std;


class Solution{
    public:

    int L[1000], R[1000], leaf[1000];
    int num_stalls, num_men;
    char stalls[50];
    
    Solution(){
        for(int i=0; i<1000; i++){
            this->L[i]=-1;
            this->R[i]=-1;
            this->leaf[i]=-1;
        }
        for(int i=0; i<50; i++){
            stalls[i]='_';
        }
        this->num_stalls=0;
        this->num_men=0;
        this->leaf[0]=0;
    }

    int candidate_node(){
        int idx=0, maxDiff=-1;
        for(int i=0; i<50; i++){
            if(this->leaf[i]!=-1){
                int diff = R[this->leaf[i]]-L[this->leaf[i]];
                if(diff>maxDiff){
                    idx=i;
                    maxDiff=diff;
                }
            }
        }
        int result = this->leaf[idx];
        this->leaf[idx]=-1;
        return result;
    }

    void split(int idx_to_split){
        int left_idx = (2*idx_to_split)+1;//Since 0 indexed
        int right_idx = (2*idx_to_split)+2;
        int mid = (this->L[idx_to_split]+this->R[idx_to_split])/2;
        // mid+=1;
        //cout<<"\nLeft : "<<left_idx<<"\tRight : "<<right_idx<<"\tMid : "<<mid<<"\n";
        this->L[left_idx]=this->L[idx_to_split];
        this->R[left_idx]=mid-1;

        this->L[right_idx]=mid+1;
        this->R[right_idx]=this->R[idx_to_split];

        update_leaf(left_idx, right_idx);

        this->stalls[mid]='X';
    }

    void update_leaf(int x, int y){
        for(int i=0; i<50; i++){
            if(this->leaf[i]==-1){
                this->leaf[i]=x;
                break;
            }
        }
        for(int i=0; i<50; i++){
            if(this->leaf[i]==-1){
                this->leaf[i]=y;
                break;
            }
        }
    }

    void print_stalls(){
        for(int i=0; i<this->num_stalls; i++){
            cout<<this->stalls[i]<<" ";
        }
        cout<<"\n";
    }

    int driver(){
        this->L[0]=0;
        this->R[0]=this->num_stalls-1;
        for(int i=0; (i<this->num_men) && (i<this->num_stalls); i++){
            int idx = candidate_node();
            //cout<<"Index_to_split : "<<idx<<"\n";
            split(idx);
            print_stalls();
        }
        return 1;
    }

};


int main(){
    int T;
    cin>>T;
    while(T>0){
        T--;
        int x, y;
        Solution obj;
        cin>>x>>y;
        obj.num_stalls = x;
        obj.num_men = y;
        cout<<"\n***********************************************************************\n";
        obj.driver();
        cout<<"\n***********************************************************************\n";
    }
    return 0;
}