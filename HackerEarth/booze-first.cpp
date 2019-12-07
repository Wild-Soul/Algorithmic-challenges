#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+7;
const int N = 1e5 + 3;
typedef pair<int,int> pi;
vector< pair<int,int> > adj[N];
int dist[N];
int visited[N];

void solve(int n) {

    priority_queue<pi, vector<pi>, greater<pi>> qp;
    
    for(int i=1; i<=n; i++) {
        if(dist[i] == 0)
            qp .push({0,i});
    }
    
    while(!qp.empty()) {
        pi p = qp.top();
        qp.pop();
        int wei = p.first, v = p.second;
        if(visited[v])
            continue;
        visited[v] = 1;
        
        //cout << "current node is " << v << endl;
        
        for( auto i : adj[v] ) {
            if(dist[i.first] > wei + i.second) {
                dist[i.first] = wei + i.second;
                qp .push({dist[i.first], i.first});
            }
        }
    }
    
}

void init( int n ) {
    for(int i=0; i<=n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
}

int main() {
    int n,m,u,v,w,b;
    cin >> n >> m;
    
    init(n);
    
    for(int i=0; i<m; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    cin >> b;
    for(int i=0; i<b; i++) {
        cin >> u;
        dist[u] = 0;
    }
    
    solve(n);
    for(int i=1; i<=n; i++) {
        cout << dist[i] << "\n";
    }
    
}