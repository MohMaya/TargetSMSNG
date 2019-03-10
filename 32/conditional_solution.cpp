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


/*
SAMPLE
1
6 12 30
0 1 0.3
0 2 0.2
0 5 0.5
1 3 0.6
1 5 0.4
2 0 0.3
2 4 0.7
3 0 1
4 3 1
5 0 0.4
5 3 0.2
5 4 0.4
0


*/

// ASSUMING CONDITIONAL PROBABILITY i.e P(D3,D2,D1) = P(D3|D2,D1)*P(D2|D1)*P(D1)

//SIMPLY DO DFS

#include <iostream>

using namespace std;


int N,E,T,start;
float adj_mat[1000][1000];
float finale[1000];

void go(int curr_node, float probab, int num_traversals){
    if(num_traversals==0){
        finale[curr_node]+=probab;
        return;
    }
    for(int i=0; i<N; i++){
        if(adj_mat[curr_node][i]>0){
            go(i, probab*adj_mat[curr_node][i], num_traversals-1);
        }
    }
}


void solution(){
    cin>>N>>E>>T;
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++){
            adj_mat[i][j]=0;
        }
        finale[i]=0;
    }

    for(int i=0; i<E; i++){
        int U,V;
        float probab;
        cin>>U>>V>>probab;
        adj_mat[U][V]=probab;
    }
    cin>>start;

    int num_traversals = T/10;
    if(num_traversals==0){
        cout<<start<<endl;
        return;
    }
    for(int i=0; i<N; i++){
        if(adj_mat[start][i]>0)
            go(i, adj_mat[start][i], num_traversals-1);
    }
    float max_probab=0;
    int idx=start;
    for(int i=0; i<N; i++){
        cout<<finale[i]<<" ";
        if(finale[i]>max_probab){
            idx=i;
            max_probab=finale[i];
        }
    }
    if(max_probab==0)
        cout<<"\nFinal Destination : Exit Lab"<<endl;
    else
        cout<<"\nFinal Destination : "<<idx<<endl;
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
