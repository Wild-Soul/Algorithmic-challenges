#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
 
const int N = 1e5 + 2;
const int INF = 1e5 + 2;
int t = 0;
vector<pair<int,int>> adj[N];
int visited[N], parent[N], low[N], disc[N];
set<int> bridges;
 
void init( int n ) {
    for(int i=0; i<=n; i++) {
        low[i] = disc[i] = INF;
        parent[i] = -1;
        visited[i] = false;
    }
}
 
void dfs(int u) {
    visited[u] = true;
    low[u] = disc[u] = t++;
    
    for(pair<int,int> p:adj[u]) {
        int v = p.first;
        int z = p.second;
        
        if(!visited[v]) {
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) {
                bridges.insert(z);
            }
        } else if( parent[u] != v ) {
            low[u] = min(low[u],disc[v]);
        }
    }
}
 
int main() {
    fastio;
    int n,m,q;
    int u,v,z;
    
    cin >> n >> m >> q;
    init(n);
    
    while(m--) {
        cin >> u >> v >> z;
        adj[u].push_back({v,z});
        adj[v].push_back({u,z});
    }
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    while(q--) {
        cin >> z;
        if(bridges.find(z) != bridges.end()) {
            cout << "YES" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }
}