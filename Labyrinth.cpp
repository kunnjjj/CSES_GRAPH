// Author      : Kunj Arora
// Codeforces  : kunnjjj
// github      : https://github.com/kunnjjj

// ALGORITHM:
// We will run bfs from starting vertex and try finding destination vertex
// we need to maintain parent of every vertex visited, I here define parent as:
// parent of a node: the node which calls this node
// we keep track of using which direction(L,R,U,D) we jump from parent to current node(see implementation)
// to generate the ans string we jump from destination to its parents and continue moving to the parent until we reach source
// (this ans would be in reverse(think yourself why?))
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> A;
pair<int,int> src={-1,-1};
pair<int,int> dest={-1,-1};
char spells[1001][1001];

map<pair<int,int>,pair<int,int>> parent;
queue<pair<int,int>> q;
bool is_safe(int i,int j)
{
    if(i==dest.first && j==dest.second) return true;

    return i>=0 && j>=0 && i<n && j<m && A[i][j]=='.' && spells[i][j]=='0';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    
    A.resize(n);
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++){
        spells[i][j]='0';
        char ch; cin>>ch;
        A[i].push_back(ch);
        if(ch=='A') src={i,j};
        if(ch=='B') dest={i,j};
        }
    }

    
    q.push({src});
    while(!q.empty())
    {
        pair<int,int> par=q.front();
        // cout<<par.first<<" "<<par.second<<endl;
        q.pop();
        if(par==dest) break;
        if(is_safe(par.first+0,par.second+1)) // 0,+1 right
        {
            
            parent[{par.first+0,par.second+1}]=par;
            spells[par.first+0][par.second+1]='R';
          
            
            q.push({par.first+0,par.second+1});

        }
        if(is_safe(par.first+1,par.second+0)) // +1,0 down
        {
            parent[{par.first+1,par.second+0}]=par;
            
            spells[par.first+1][par.second+0]='D';
            q.push({par.first+1,par.second+0});
        }
        if(is_safe(par.first+0,par.second-1)) // 0,-1 left
        {
            parent[{par.first+0,par.second-1}]=par;
           
            spells[par.first+0][par.second-1]='L';
            q.push({par.first+0,par.second-1});
        }
        if(is_safe(par.first-1,par.second+0)) // -1,0 up
        {
            parent[{par.first-1,par.second+0}]=par;
            
            spells[par.first-1][par.second+0]='U';
            q.push({par.first-1,par.second+0});
        }
        
    }
    if(spells[dest.first][dest.second]=='0')
    {
        cout<<"NO"<<endl;
    }
    else
    {  
        string ans="";
        pair<int,int> cur=dest;
        // int i=0;
        while(cur!=src)
        {
            ans+=spells[cur.first][cur.second];
            cur=parent[cur];
            // cout<<ans<<endl;
            // i++;
            // if(i==10) break;
        }
        cout<<"YES"<<endl;
        reverse(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        cout<<ans<<endl;


    }







    return 0;
}