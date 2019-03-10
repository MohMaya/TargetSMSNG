/*

A Doctor travels from a division to other division where divisions are connected like a graph (directed graph)
and the edge weights are the probabilities of the doctor going from that division to other connected division
but the doctor stays 10 mins at each division. Given a time T, you have to determine the division at which doctor
will be found at time T. The doctor moves in the direction of highest probability.

Input is number of test cases followed by number of nodes, edges, time after which we need find the division in
which he will be there then the edges starting point, end point, probability.

Note: If he reach a point where there are no further nodes then he leaves the lab after 10 mins
    the travelling time is not considered and during that 10 min
    at 10th min he will be in next division

input:
N E T
U1 V1 P1
U2 V2 P2
.. .. ..
UE VE PE
START_DIVISION

0<= U,V <N


*/


// ASSUMING INDEPENDENT PROBABILITIES OF EACH STATE - EZPZ


#include <iostream>

using namespace std;


int N,E,T,start;
float adj_mat[1000][1000];
float copy_adj_mat[1000][1000];

void solution(){
    cin>>N>>E>>T;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            adj_mat[i][j]=0;
            copy_adj_mat[i][j]=0;
        }
    }

    for(int i=0; i<E; i++){
        int U,V;
        float probab;
        cin>>U>>V>>probab;
        adj_mat[U][V]=probab;
        copy_adj_mat[U][V]=probab;
    }
    cin>>start;

    int num_traversals = T/10;
    int curr_node=start;
    while(num_traversals>0){
        int next_node=-1;
        int max_probab=0;
        for(int i=0; i<N; i++){
            if(adj_mat[curr_node][i]>max_probab){
                max_probab=adj_mat[curr_node][i];
                next_node=i;
            }
        }
        if(next_node==-1){
            cout<<"Exited the last lab"<<endl;
            return;
        }
        curr_node=next_node;
        num_traversals--;
    }
    cout<<"After "<<T<<" minutes, at node : "<<curr_node<<endl;
}

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        test_cases--;
        solution();
    }
    return 0;
}
