// Author      : Kunj Arora
// Codeforces  : kunnjjj
// github      : https://github.com/kunnjjj

// ALGORITHM:
// minimum computers during path, implies shortest path in an unweighted graph
// for shortest path we can can run bfs from src(1) to destination(n)
// for printing path we can set parent for every vertex and apply similar algo
// as in ( https://github.com/kunnjjj/CSES_GRAPH/blob/main/Labyrinth.cpp )
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>n>>m;
    unordered_map<int,vector<int>> graph;
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    // uncomment this to print the graph
    // for(auto ele:graph)
    // {
    //     cout<<ele.first<<" -> ";
    //     for(auto ele2:ele.second)
    //     cout<<ele2<<" ";
    //     cout<<'\n';
    // }
    int src=1;
    int dest=n;
    queue<int> q;
    vector<bool> visited(n+1,0);
    q.push(src);
    visited[src]=1;
    vector<int> parent(n+1);

    while(!q.empty())
    {
        int node_in_front=q.front();
        q.pop();
        vector<int> &adj_list=graph[node_in_front];
        for(int a:adj_list)
        {
            if(!visited[a])
            {
                visited[a]=1;
                parent[a]=node_in_front;
                q.push(a);
            }
        }
    }
    if(!visited[dest]) // if destination isnt visited
    {   
        cout<<"IMPOSSIBLE"<<'\n';
        return 0;
    }
    vector<int> path_in_reverse;
    int cur=n;
    while(cur!=src)
    {
        path_in_reverse.push_back(cur);
        cur=parent[cur];
        
    }
    path_in_reverse.push_back(src);
    cout<<path_in_reverse.size()<<'\n';
    for(auto it=path_in_reverse.rbegin();it!=path_in_reverse.rend();it++)
    cout<<*it<<" ";
    







    return 0;
}