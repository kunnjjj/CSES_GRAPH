// Author      : Kunj Arora
// Codeforces  : kunnjjj
// github      : https://github.com/kunnjjj

// ALGORITHM:
// We run dfs from every node which is currently '.' to every neighbouring node which is '.'
// whenever we jump to a new node we mark it as '#' denoting that we will never count it again
// we effectively need to find number of connected components

#include<bits/stdc++.h>
using namespace std;
int n,m; 
vector<string> v;
int dx[]={0,+1,-1,0};
int dy[]={+1,0,0,-1};
bool is_safe(int i,int j)
{
    return i>=0 && j>=0 && i<n && j<m && v[i][j]=='.';
}
void dfs(int i,int j)
{
    v[i][j]='#';
    for(int k=0;k<4;k++)
    {
        if(is_safe(i+dx[k],j+dy[k]))
        {
            dfs(i+dx[k],j+dy[k]);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]=='.')
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    // for(int i=0;i<n;i++) cout<<v[i]<<endl;
    cout<<cnt<<'\n';









    return 0;   
}