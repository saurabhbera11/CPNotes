//problem link https://www.codechef.com/submit/TREECLR?tab=statement
//Upsolving CC LTIME11
//DFS 


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void dfs(ll i, vector<ll> adj[], bool v[], ll parent[], ll child_colored[], ll ways[], ll c){
    v[i]=true;

    ll j, l=adj[i].size();

    if(i!=1){
        if(parent[i]!=1){
            ways[i]=c-child_colored[parent[i]]-1-1; ///coz 2 parents are possible
            child_colored[parent[i]]++; /// coz only one parent
        }else{
            ways[i]=c-child_colored[parent[i]]-1;
            child_colored[parent[i]]++;
        }
    }

    for(auto itr:adj[i]){
        if(v[itr]==false){
            parent[itr]=i;
            dfs(itr, adj, v, parent, child_colored, ways, c);
        }
    }

}
int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    ll n, c, i, j, m;
    //n number of nodes
    //c number of colors


    cin>>n>>c;

    ll ans=0;
    bool v[n+1];
    ll ways[n+1];
    vector<ll> adj[n+1];
    ll parent[n+1];




    ll child_colored[n+1];

    for(i=0; i<=n; i++){
        v[i]=false;
        ways[i]=0;
        parent[i]=0;
        child_colored[i]=0;
    }

    m=n-1;

    while(m--){
        cin>>i>>j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

    parent[1]=0;
    ways[1]=c;

    dfs(1, adj, v, parent, child_colored, ways, c);

    ans=1;
    for(i=1; i<=n; i++){
        ans=(ans*ways[i])%mod;
    }

    cout<<ans<<endl;



}
