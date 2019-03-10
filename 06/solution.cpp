/*

Find if given graph is bipartite or not, if it is bipartite then print either white color nodes or black color nodes.


Constraint :  No. of nodes<=1000
*/


#include <iostream>

using namespace std;

int color[1000];
bool edge[1000][1000];
int E, V;


class Queue{
public:
    int num_elems,front,end;
    int arr[10000];
    Queue(){
        num_elems=0;
        front=0;
        end=0;
        for(int i=0; i<10000; i++)
            arr[i]=-1;
    }
    bool isEmpty(){
        if(num_elems==0)
            return true;
        else
            return false;
    }

    void enqueue(int x){
        arr[end++]=x;
        num_elems++;
    }
    int dequeue(){
        num_elems--;
        return arr[front++];
    }
};

void reset(){
    for(int i=0; i<1000; i++){
        for(int j=0; j<1000; j++)
            edge[i][j]=false;
        color[i]=-1;
    }
}

bool isBipart(int src){
    color[src]=1;
    Queue q;
    q.enqueue(src);

    while(!q.isEmpty()){
        int node=q.dequeue();
        if(edge[node][node]){
            return false;
        }
        for(int i=0; i<V; i++){
            if(edge[node][i]){
                if(color[i]==-1){
                    color[i]=1-color[node];
                    q.enqueue(i);
                }else if(color[i]==color[node]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main(){
    reset();
    cin>>V>>E;
    for(int i=0; i<E; i++){
        int x,y;
        cin>>x>>y;
        edge[x-1][y-1]=true;
    }
    int flag=0;
    for(int i=0; i<V; i++){
        if(color[i]==-1){
            if(!isBipart(i)){
                    flag=1;
                cout<<"No"<<endl;
            }
        }
    }
    if(flag==0){
        for(int i=0; i<V; i++){
            if(color[i]==0)
                cout<<color[i]<<"\t";
        }
    }
    cout<<endl;
}
