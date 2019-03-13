// Fishery Problem

#include <iostream>
using namespace std;

int visited[3];
int gateLoc[3];
int numFishermen[3];
int N;
int minCost, flagOut;
int numPermutations=0;
int permutations[50];
bool allVisited(){
    if(visited[0]==1 && visited[1]==1 && visited[2]==1)
        return true;
    return false;
}

int abs(int x){
    if(x>=0){
        return x;
    }else{
        return -x;
    }
}

int cost_calc(int spots[]){
    int cost=0;
    for(int i=0; i<N; i++){
        if(spots[i]==1){
            cost+=abs(i-gateLoc[0])+1;
        }
        if(spots[i]==2){
            cost+=abs(i-gateLoc[1])+1;
        }
        if(spots[i]==3){
            cost+=abs(i-gateLoc[2])+1;
        }
    }
    //cout<<"\n SPOTS : \t";
    //for(int i=0; i<N; i++)
    //    cout<<spots[i]<<"\t";
    //cout<<"\n COST : \t"<<cost<<endl;
    return cost;
}




void genPermute(int rec_dep, int x){
    if(rec_dep==3){
        //cout<<x<<endl;
        permutations[numPermutations++]=x;
        return;
    }
    for(int i=1; i<4; i++){
        if(!visited[i-1]){
            visited[i-1]=1;
            if(numFishermen[i-1]%2==0){
                genPermute(rec_dep+1, x*100+i*10+7);
                genPermute(rec_dep+1, x*100+i*10+9);
            }else{
                genPermute(rec_dep+1, x*100+i*10+8);
            }
            visited[i-1]=0;
        }
    }
}


int* fillGate(int spots[], int gateNum, int bVal){
    int n = numFishermen[gateNum-1];
    int loc = gateLoc[gateNum-1];
    char bias='N';
    if(bVal==7)
        bias='L';
    else if(bVal==8)
        bias='N';
    else
        bias='R';

    while(n>0){
        int l_index=-1;
        int r_index=-1;


        for(int l=loc; l>=0; l--){
            if(spots[l]==-1){
                l_index=l;
                break;
            }
        }

        for(int r=loc; r<N; r++){
            if(spots[r]==-1){
                r_index=r;
                break;
            }
        }

        //cout<<"\nFOR n = "<<n<<"\tl_index = "<<l_index<<"\tr_index = "<<r_index;
        int l_distance = abs(l_index-loc);
        int r_distance = abs(r_index-loc);


        if((l_index==-1) || (r_distance<l_distance)){
            //cout<<"\nCASE 1";
            spots[r_index]=gateNum;
            n-=1;
            continue;
        }


        if((r_index==-1) || (l_distance<r_distance)){
            //cout<<"\nCASE 2";
            spots[l_index]=gateNum;
            n-=1;
            continue;
        }

        if(l_distance==r_distance){
            if(l_distance==0){
                //cout<<"\nCASE 3";
                spots[l_index]=gateNum;
                n-=1;
                continue;
            }
            if(n>=2){
                //cout<<"\nCASE 4";
                n-=2;
                spots[r_index]=gateNum;
                spots[l_index]=gateNum;
            }else if(n==1){
                if(bias=='L'){
                    //cout<<"\nCASE 5";
                    n-=1;
                    spots[l_index]=gateNum;
                }else{
                    //cout<<"\nCASE 6";
                    n-=1;
                    spots[r_index]=gateNum;
                }
            }
        }

    }
    return spots;
}


int evaluatePermutation(int p){
    int spots[N];
    for(int i=0; i<N; i++)
        spots[i]=-1;

    int X[6];
    //cout<<"\n"<<p;
    for(int i=5; i>=0; i--){
        X[i]=p%10;
        p=p/10;
    }

    for(int i=0; i<6; i+=2){
        fillGate(spots, X[i], X[i+1]);
    }
    int cost = cost_calc(spots);
    return cost;

}


int main(){
    int test_cases;
    cin>>test_cases;
    int ctr=1;
    while(test_cases>0){
        test_cases--;
        cin>>N;
        int l1, l2, l3, n1, n2, n3;
        cin>>l1>>n1;
        cin>>l2>>n2;
        cin>>l3>>n3;
        int spot[N];
        for(int i=0; i<N; i++)
        {
            spot[i]=-1;
        }
        numFishermen[0]=n1;
        gateLoc[0]=l1-1;
        numFishermen[1]=n2;
        gateLoc[1]=l2-1;
        numFishermen[2]=n3;
        gateLoc[2]=l3-1;
        for(int i=0; i<3; i++)
            visited[i]=0;
        //cout<<"#"<<ctr<<" "<<minCost<<endl;
        genPermute(0, 0);
        minCost=999999;
        for(int i=0; i<numPermutations; i++){
            //cout<<"\n FOR : "<<permutations[i];
            int cost = evaluatePermutation(permutations[i]);
            minCost = min(minCost, cost);
        }
        cout<<"#"<<ctr<<" "<<minCost<<endl;
        ctr++;
    }
}
