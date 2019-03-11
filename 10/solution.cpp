/*

You’ll be given a grid as below:


    0 1 0 2 0

    0 2 2 2 1

    0 2 1 1 1

    1 0 1 0 0

    0 0 1 2 2

    1 1 0 0 1

    x x S x x


   In the grid above,

  1: This cell has a coin.

  2: This cell has an enemy.

  0: It contains nothing.

  The highlighted(yellow) zone is the control zone. S is a spaceship that we need to control so that we can get maximum coins.
  Now, S’s initial position will be at the center and we can only move it right or left by one cell or do not move.
  At each time, the non-highlighted part of the grid will move down by one unit.
  We can also use a bomb but only once. If we use that, all the enemies in the 5×5 region above the control zone will be killed.
  If we use a bomb at the very beginning, the grid will look like this:


    0 1 0 2 0

    0 0 0 0 1

    0 0 1 1 1

    1 0 1 0 0

    0 0 1 0 0

    1 1 0 0 1

    x x S x x


  As soon as, the spaceship encounters an enemy or the entire grid has come down, the game ends.
  For example,
  At the very first instance, if we want to collect a coin we should move left( coins=1). This is because when the grid comes down by 1 unit we have a coin on the second position and by moving left we can collect that coin. Next, we should move right to collect another coin( coins=2).
  After this, remain at the same position( coins=4).
  This is the current situation after collecting 4 coins.

    0 1 0 2 0 0 1 0 0 0

    0 2 2 2 1 -->after using 0 0 0 0 1

    x x S x x -->bomb x x S x x


   Now, we can use the bomb to get out of this situation. After this, we can collect at most 1 coin. So maximum coins=5.

*/





#include <iostream>

using namespace std;
#define lim 100

int grid[lim][5];
int num_rows;
int maxCoins=0;
bool bombUsed=false;

void go_to(int i, int j, int coins){
    if(j<0 || j>=5){
        //Went out of board
        return;
    }
    if(i==num_rows){
        //Reached the end of grid
        if(coins>maxCoins)
            maxCoins=coins;
        return;
    }
    int flag=0, ctr=0;
    int enemy_coord[25][2];
    if(grid[i][j]==2){
        if(bombUsed==true){
            //Game over here
            if(coins>maxCoins)
                maxCoins=coins;
            return;
        }else{
            //Use the bomb now
            bombUsed=true;
            flag=1;
            for(int x=i; x<min(i+5,num_rows); x++){
                for(int y=0; y<5; y++){
                    if(grid[x][y]==2){
                        enemy_coord[ctr][0]=x;
                        enemy_coord[ctr++][1]=y;
                        grid[x][y]=0;
                    }
                }
            }
        }
    }else if(grid[i][j]==1)
        coins=coins+1;

    go_to(i+1, j+1, coins);
    go_to(i+1, j, coins);
    go_to(i+1, j-1, coins);

    if(flag==1){
        for(int k=0; k<ctr; k++){
            int x=enemy_coord[k][0];
            int y=enemy_coord[k][1];
            grid[x][y]=2;
        }
    }
    return;
}


int main(){
    cin>>num_rows;
    for(int i=0; i<num_rows; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        grid[num_rows-1-i][0]=a;
        grid[num_rows-1-i][1]=b;
        grid[num_rows-1-i][2]=c;
        grid[num_rows-1-i][3]=d;
        grid[num_rows-1-i][4]=e;
    }
    maxCoins=0;
    go_to(0,1,0);
    go_to(0,2,0);
    go_to(0,3,0);
    cout<<"Max_Coins : "<<maxCoins<<endl;
    return 1;
}
