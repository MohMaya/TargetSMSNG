//DJIKSTRA's Algo

#include <bits/stdc++.h>

using namespace std;
# define INF 0x3f3f3f3f
typedef pair<int, int> mypair;

class Graph
{
    int V;

    list <pair <int , int> > *adj;

    public:
        Graph(int V);

        void addEdge(int u, int v, int w);

        void shortestDis(int s);
};

Graph :: Graph(int V)
{
    this->V = V;
    adj = new list <mypair> [V];
}

void Graph :: addEdge(int u, int v, int w)
{
    adj[u].push_back(mypair(v,w));
    adj[v].push_back(mypair(u,w));
}

void Graph ::shortestDis(int src)
{
    priority_queue <mypair , vector<mypair>, greater<mypair> >pq;   //min heap pq

    vector<int> dist(V, INF);

    pq.push(make_pair(0,src));
    dist[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        list <mypair> ::iterator i;

        for(i = adj[u].begin();i!=adj[u].end();++i)
        {

            int v = (*i).first;
            int weight = (*i).second;

            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        cout<<i<<"\t"<<dist[i]<<"\n";
    }
}

int main()
{
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestDis(7);

    return 0;
}


