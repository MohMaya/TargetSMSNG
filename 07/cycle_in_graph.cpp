// A very crude and hacky approach to solve the problem in hand where constraints are 20 node at max. 

#include <iostream>

using namespace std;

bool adjacency_mat[20][20];

bool visited[20];

int DFS(int node){
    bool neighbors[20];
    for(int i = 0; i < 20; i++)
    {
        neighbors[i] = false;
    }
    for(int i=0; i<20; i++){
        if(adjacency_mat[node][i]){
            neighbors[i] = true;
        }
    }
    for (int i = 0; i < 20; i++)
    {
        if(neighbors[i]){
            if (visited[i])
                return 1;
            visited[i] = true;
            int x = DFS(i);
            if(x==1){
                return 1;
            }
            visited[i] = false;
        }
    }
    return 0;
}


void addEdge(int source, int dest){
    adjacency_mat[source-1][dest-1]=true;
}


int main(){
    for(int i=0; i<20; i++)
        for(int j=0; j<20; j++)
            adjacency_mat[i][j] = false;

    for(int i=0; i<20; i++)
        visited[i]=false;
    int num_edges;
    cout<<"WELCOME!!!"<<endl;
    cout<<"ENTER No. of edges : ";
    cin>>num_edges;
    int i=1;

    while(i<=num_edges){
        cout<<"Enter Edge Number "<<i<<" : ";
        int source,dest;
        cin>>source;
        cin>>dest;
        cout<<"Adding Edge : "<<source<<"->"<<dest<<endl;
        addEdge(source, dest);
        i++;
    }

    for(int i=0; i<20; i++){
        int x = DFS(i);
        if(x==1){
            break;
        }
    }
    for(int i=0; i<20; i++){
        if(visited[i])
            cout<<i+1<<"   ";
    }
}

