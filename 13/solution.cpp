/*

There is one spaceship. X and Y coordinate of source of spaceship and destination spaceship is given.
There are N number of wormholes each wormhole has 5 values.
First 2 values are starting co-ordinate of wormhole and after that value no. 3 and 4 represents ending co-ordinate of wormhole
and last 5th value is represents cost to pass through this wormhole.
Now these wormholes are bi-direction.

Now the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2).

The main problem here is to find minimum distance to reach spaceship from source to destination co-ordinate using any number of warm-hole.
It is ok if you wont use any wormhole.


Hint:
You can make graph which contain edge between all points and put cost of that edge.
Now apply djikstra algorithm to find minimum distance between source to destination co-ordinate of spaceship.
Here the main catch is that the cost to pass through wormhole can be zero so you have to take care while making graph matrix.

*/


#include <iostream>
#define lim 10

using namespace std;

int visited[lim], wh[lim][5];
int ans,N;

int abs(int x){
    if(x>=0)
        return x;
    else
        return -x;
}

int distance(int sx, int sy, int dx, int dy){
    return (abs(sx-dx)+abs(sy-dy));
}

void fn(int sx, int sy, int dx, int dy, int dis){
    ans = min(ans, distance(sx, sy, dx, dy)+dis);

    for(int i=0; i<N; i++){
        if(visited[i]==0){
            visited[i]=1;
            int temp = distance(sx, sy, wh[i][0], wh[i][1])+wh[i][4]+dis;
            fn(wh[i][2], wh[i][3], dx, dy, temp);
            temp = distance(sx, sy, wh[i][2], wh[i][3])+wh[i][4]+dis;
            fn(wh[i][0], wh[i][1], dx, dy, temp);
            visited[i]=0;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        cin>>N;
        int sx, sy, dx, dy;
        cin>>sx>>sy>>dx>>dy;
        for(int i=0; i<N; i++){
            visited[i]=0;
            for(int j=0; j<5; j++){
                cin>>wh[i][j];
            }
        }
        ans=999999;
        cout<<ans<<endl;
    }
}
