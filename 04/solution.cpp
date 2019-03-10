/*

Find a cycle, if exists, in a directed graph.
If there is none, print 0.
If there is one, print the path starting from the first node of the cycle to the last.
If there are more than one, print any path.


1<=N<=100



Sample Input:
5
6 12    //Single loop
0 1
0 2
0 5
1 3
1 5
2 1
2 4
3 0
4 3
5 0
5 3
5 4
6 12    //Single loop
0 1
0 2
0 5
1 3
1 5
2 0
2 4
3 0
4 3
5 0
5 3
5 4
6 13       //Self Loop
0 1
0 2
0 5
1 1
1 3
1 5
2 1
2 4
3 0
4 3
5 0
5 3
5 4
6 15        // No loop
0 1
0 2
0 3
0 4
0 5
1 2
1 3
1 4
1 5
2 3
2 4
2 5
3 4
3 5
4 5
6 6             //Single Loop not from origin
0 1
1 2
2 5
5 1
2 3
3 4
6 5             //Disconnected Components
1 2
2 5
5 1
2 3
3 4

Output:
0->1->3->0
0->1->3->0
1->1
-1
*/


#include <iostream>

using namespace std;

int N, E;//Number of Nodes, Number of edges
bool V[100][100];
bool visited[100];
int k,l;  //The node from where the cycle starts
int path[100];

void input(){
    cin>>N>>E;
    for(int i=0; i<E; i++){
        int x,y;
        cin>>x>>y;
        V[x][y]=true;
    }
}

void reset(){
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++)
            V[i][j]=false;
        visited[i]=false;
        path[i]=-1;
    }
    k=-2;
    l=-2;
}


int recur(int node, int counter){

    /*cout<<"\n";
    for(int i=0; i<counter; i++)
        cout<<"     ";
    cout<<node;
    */
    path[counter]=node;

    for(int y=0; y<N; y++){
        if(V[node][y]){
            if(visited[y]){
                k=y;
                l=node;
                //cout<<"\nFound a cycle\t"<<y<<endl;
                return -1;
            }
            visited[y]=true;
            int i = recur(y, counter+1);
            if(i==-1){
                return -1;
            }
            visited[y]=false;
        }
    }
}


void driver(){
    for(int x=0; x<N; x++){

        visited[x]=true;
        path[0]=x;
        //cout<<"\n\n***********************************\n"<<x;
        for(int y=0; y<N; y++){
            if(V[x][y]){
                if(visited[y]){
                    if(x==y){
                        //Self loop found
                        k=-1;
                        return;
                    }
                }
                visited[y]=true;
                int ret = recur(y, 1);
                if(ret==-1){
                    return;
                }
                visited[y]=false;
            }
        }


    }
}


void output(){
    cout<<endl;
    if(k==-2){
        cout<<-1<<endl; //=> No cycle
        return;
    }
    if(k==-1){
        cout<<path[0]<<endl;
        return;
    }
    int start_idx=0;
    for(int i=0; i<100; i++){
        if(path[i]==k)
            start_idx=i;
    }
    for(int i=start_idx; i<100; i++){
        if(path[i]==l){
            cout<<path[i]<<"->";
            break;
        }
        cout<<path[i]<<"->";
    }
    cout<<path[start_idx];
    cout<<endl;
}

int main(){
    int test_cases;
    cin>>test_cases;
    while(test_cases>0){
        test_cases--;
        reset();
        input();
        driver();
        output();
    }
}
