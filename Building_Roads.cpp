// Author      : Kunj Arora
// Codeforces  : kunnjjj
// github      : https://github.com/kunnjjj

// ALGORITHM:
// It is obvious the in a connected component of a graph, we can find a path from any
// vertex to any other vertex.
// if we have say 3 connected components, it is obvious to connect any 2 of them
// similarly , for k connected components we need k-1 edges
// for the implementation, i will use disjoint set union as it is very easy to implement and fast
#include<bits/stdc++.h>
using namespace std;
int n,m;
int max_n=1e5;
vector<int> parent(max_n+1);

int find_parent(int i)
{
    if(parent[i]==i) return i;
    return parent[i]=find_parent(parent[i]); 
}
void unite(int i,int j)
{
    i=find_parent(i);
    j=find_parent(j);
    parent[j]=i;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a,b; cin>>a>>b;
        unite(a,b);
    }
    // we need all distinct parents 
    // a possible solution is adding an edge with the first parent to every other parent
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        A[i]=find_parent(i+1);
    }
    sort(A.begin(),A.end());
    A.resize(unique(A.begin(),A.end())-A.begin());
    cout<<A.size()-1<<endl;
    for(int i=1;i<A.size();i++)
    {
        cout<<A[0]<<" "<<A[i]<<endl;
    }







    return 0;
}