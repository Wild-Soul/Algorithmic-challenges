#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int INF = 1e6;
vector<int> adj[N];
bool visited[N];
int disc[N],low[N],t = 0;
int parent[N];
vector<int> h[N];

void init(int n) {
    for(int i=0; i<=n; i++) {
        low[i] = disc[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
}

void dfs(int u) {
    visited[u] = true;
    low[u] = disc[u] = t++;
    int child = 0;

    for(int v : adj[u]) {
        
        if(!visited[v]) {
            child++;
            parent[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(disc[u] < low[v]) {
                h[u].push_back(v);
            }

        } else if (parent[u]!=v) {
            low[u] = min(low[u],disc[v]);
        }
    }
}

int main() {
    int n,m,q,u,v;
    
    cin >> n >> m;
    init(n);
    vector< pair<int,int> > edges;

    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v});
    }
    
    for(int i=1; i<=n; i++) {
        if(!visited[i])
            dfs(i);
    }
    cin >> q;
    while(q--) {
        cin >> u;
        u--;
        int a = edges[u].first;
        int b = edges[u].second;
        bool flag = false;
        for(int i : h[a]) {
            if(i==b)
                flag = true;
        }
        if(!flag) {
            for(int i: h[b]) {
                if(i==a)
                    flag = true;
            }
        }
        if(flag) {
            cout << "Unhappy" << endl;
        } else {
            cout << "Happy" << endl;
        }
    }
}