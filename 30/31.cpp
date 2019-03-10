/*
    Approach-1
    1-> Run BFS from every point on road->
    2-> Find distance of all the rare-elements from that point and store its maximum->
    3-> Return the minimum of all the Maximums calculated->
*/
#include<stdio.h>

struct co_ord{
    int x;
    int y;
    int cost;
};


class Queue{
public:
    int START, END, SIZE;
    int q[2000][3];
    Queue(){
        this->START=0;
        this->END=0;
        this->SIZE=0;
        for(int i=0; i<2000; i++){
            this->q[i][0]=0;
            this->q[i][1]=0;
            this->q[i][2]=0;
        }
    }

    int isEmpty(){
        if(this->SIZE==0){
            return 1;
        }else{
            return 0;
        }
    }

    void enqueue(int x, int y, int cost){
        this->q[this->END][0]=x;
        this->q[this->END][1]=y;
        this->q[this->END][2]=cost;
        this->END+=1;
        this->SIZE+=1;
    }

    co_ord dequeue(){
        int x = this->q[this->START][0];
        int y = this->q[this->START][1];
        int cost = this->q[this->START][2];
        this->START+=1;
        this->SIZE-=1;
        co_ord val = {x, y, cost};
        return val;
    }
};


class Solution{
public:
    int num_rows, num_cols, num_rare;
    int matrix[20][20], rare_loc[5][2], visited[20][20], dist[5], costs[400];
    Solution(){
        this->num_rows = 0;
        this->num_cols=0;
        this->num_rare=0;
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                this->matrix[i][j]=0;
                this->visited[i][j]=0;
            }
        }
        for(int i=0; i<5; i++){
            this->dist[i]=0;
            this->rare_loc[i][0]=0;
            this->rare_loc[i][1]=0;
        }
        for(int i=0; i<400; i++){
            this->costs[i]=-1;
        }
    }


    void reset(){
        for(int i=0; i<20; i++){
            for(int j=0; j<20; j++){
                this->visited[i][j]=0;
            }
        }
    }

    int driver(){
        for(int i=0; i<this->num_rare; i++){
            int x= this->rare_loc[i][0];
            int y= this->rare_loc[i][1];
            this->matrix[x][y]=2;
        }
        for(int x=0; x<this->num_rows; x++){
            for(int y=0; y<this->num_cols; y++){
                if(matrix[x][y]!=0){
                    reset();
                    this->costs[20*x+y] = DFS(x, y);
                }
            }
        }
        int min_cost = 5000;
        for(int i=0; i<400; i++){
            if(this->costs[i]!=-1 && this->costs[i]<min_cost){
                min_cost=this->costs[i];
            }
        }
        if(min_cost==5000){
            return 0;
        }else{
            return min_cost;
        }
    }


    int DFS(int x, int y){
        int max_cost=0;
        Queue q;
        q.enqueue(x, y, 0);
        this->visited[x][y]=1;
        while(!q.isEmpty()){
            co_ord c = q.dequeue();
            int x = c.x;
            int y = c.y;
            int cost = c.cost;

            if(matrix[x][y]==2){
                if(cost>max_cost){
                    max_cost=cost;
                }
            }

            if((x-1 >= 0) && (this->visited[x-1][y]==0) && (this->matrix[x-1][y]!=0)){
                q.enqueue(x-1, y, cost+1);
                this->visited[x-1][y]=1;
            }
            if((y-1 >= 0) && (this->visited[x][y-1]==0) && (this->matrix[x][y-1]!=0)){
                q.enqueue(x, y-1, cost+1);
                this->visited[x][y-1]=1;
            }
            if((x+1<this->num_rows) && (this->visited[x+1][y]==0) && (this->matrix[x+1][y]!=0)){
                q.enqueue(x+1, y, cost+1);
                this->visited[x+1][y]=1;
            }
            if((y+1<this->num_cols) && (this->visited[x][y+1]==0) && (this->matrix[x][y+1]!=0)){
                q.enqueue(x, y+1, cost+1);
                this->visited[x][y+1]=1;
            }

        }
        return max_cost;
    }
};


int main(){
    int T;
    scanf("%d", &T);
    while(T>0){
        T--;
        int n_r, n_c, n_rare;
        scanf("%d %d %d", &n_r, &n_c, &n_rare);
        Solution s;
        s.num_rows = n_r;
        s.num_cols = n_c;
        s.num_rare = n_rare;
        for(int i=0; i<n_r; i++){
            for(int j=0; j<n_c; j++){
                scanf("%d", &s.matrix[i][j]);
            }
        }
        for(int i=0; i<n_rare; i++){
            scanf("%d %d", &s.rare_loc[i][0], &s.rare_loc[i][1]);
        }
        int result = s.driver();
        for(int i=0; i<n_r; i++){
            for(int j=0; j<n_c; j++){
                printf("%d\t",s.costs[20*i+j]);
            }
            printf("\n");
        }
        printf("\n\n%d\n", result);
    }
    return 1;
}
