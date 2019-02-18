/*
    Approach-1
    1. Run BFS from every point on road.
    2. Find distance of all the rare-elements from that point and store its maximum.
    3. Return the minimum of all the Maximums calculated.
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
        this.START=0;
        this.END=0;
        this.SIZE=0;
        for(int i=0; i<2000; i++){
            this.q[i][0]=0;
            this.q[i][1]=0;
            this.q[i][2]=0;
        }
    }

    int isEmpty(){
        if(this.SIZE==0){
            return 1;
        }else{
            return 0;
        }
    }

    void enqueue(int x, int y, int cost){
        this.q[this.END][0]=x;
        this.q[this.END][1]=y;
        this.q[this.END][2]=cost;
        this.END+=1;
        this.SIZE+=1;
    }

    co_ord dequeue(){
        int x = this.q[this.START][0];
        int y = this.q[this.START][1];
        int cost = this.q[this.START][2];
        this.START+=1;
        this.SIZE-=1;
        co_ord val = {x, y, cost};
        return val;
    }
};


class Solution{
    int num_rows
};
