/*

Byteland has N cities (numbered from 1 to N) and N−1 bidirectional roads. It is guaranteed that there is a route from any city to any other city.
Jeanie is a postal worker who must deliver K letters to various cities in Byteland. She can start and end her delivery route in any city.
Given the destination cities for K letters and the definition of each road in Byteland,
find and print the minimum distance Jeanie must travel to deliver all K letters.
Note: The letters can be delivered in any order.



Input Format
The first line contains two space-separated integers, N (the number of cities) and K (the number of letters), respectively.
The second line contains K space-separated integers describing the delivery city for each letter.
Each line i of the N−1 subsequent lines contains 3 space-separated integers describing a road
as ui vi di, where di is the distance (length) of the bidirectional road between cities ui and vi.


Constraints
2≤K≤N≤10^5
1≤di≤10^3
Byteland is a weighted undirected acyclic graph.


Output Format
Print the minimum distance Jeanie must travel to deliver all K letters.


Sample Input
5 3
1 3 4
1 2 1
2 3 2
2 4 2
3 5 3


Sample Output
6


Explanation
Jeanie has 3 letters she must deliver to cities 1, 3, and 4 in the following map of Byteland:
One of Jeanie's optimal routes is 3→2→1→2→4,
for a total distanced traveled of 2+1+1+2=6.
Thus, we print 6 on a new line.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
#define pb push_back
#define mp make_pair
#define MA(x,y) ((x)>(y)?(x):(y))
using namespace std;
const int N=500002;
const int inf=1000000000;
int n,K,s[N],SUM,M;
bool f[N];
vector <int> v[N],d[N];

int input(){
    scanf("%d%d",&n, &K);
    for (int i=0,x;i<K;i++){
        scanf("%d",&x);
        s[x]=1;
        f[x]=1;
    }
    for (int i=1,x,y,z;i<n;i++){
        scanf("%d%d%d",&x,&y,&z);
        v[x].pb(y);
        v[y].pb(x);
        d[x].pb(z);
        d[y].pb(z);
    }
    return 0;
}

int go(int x,int from, int count){
    
    cout<<"\n\n";
    for(int i=0; i<count; i++){
        cout<<"   ";
    }
    cout<<"go("<<x<<","<<from<<")"<<endl;


    int D1=-inf;
    int D2=-inf;


    for (int i=0;i<v[x].size();i++)
    {
        if (v[x][i]!=from){
            
            
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout<<"inside if block for vertex = "<<v[x][i]<<endl;
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout << "D1 before = " << D1;
            
            
            D1=max(D1,go(v[x][i],x,count+1)+d[x][i]);
            
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout<<"D1 after = "<<D1<<endl;
            
            
            if (D1>D2) 
                swap(D1,D2);
            
            
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout << "s[x] before = " << s[x];
            
            
            s[x]+=s[v[x][i]];
                
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout << "s[x] after = " << s[x]<<endl;
            
            if (0<s[v[x][i]] && s[v[x][i]]<K) {
                SUM+=d[x][i];
                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout<<"SUM = "<<SUM<<endl<<endl;
            }
        }
    }
    if (D1>0) 
        M=max(M,D1+D2);

    if (D2>0 && f[x])
        M=max(M,D2);

    if (f[x]) 
        D2=max(D2,0);


                for (int i = 0; i < count; i++){
                    cout << "   ";
                }
                cout << "returning D2 = " << D2<<"\n"<<endl;


    return D2;
}

int sol(){
    go(5,5,0);
    printf("\n\n%d\n",SUM*2-M);
    return 0;
}

int main() {
    input();
    sol();
    return 0;
}
