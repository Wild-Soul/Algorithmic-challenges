#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 1e8;
const int N = 12;
int parent[N];
bool visited[N],AP[N];
int low[N];
int disc[N];
int ap[N];
int t;
vector<int> adj[N];
vector< pair<int,int>> bridges;

void find_articulation_points(int u) {
    
    // cout << "VISITING NODE " << u << endl;
    disc[u] = low[u] = t++;
    visited[u] = true;
    
    int child = 0;
    for(auto v : adj[u]) {
        if(!visited[v]) {
            
            child++;
            parent[v] = u;
            
            find_articulation_points(v);
            low[u] = min(low[u], low[v]);
            
            if (parent[u]!=-1 && low[v] >= disc[u]) {
                AP[u] = true;
            }
            if(low[v] > disc[u])
                bridges.push_back({u,v});
            
        } else if (parent[u] != v) {
            low[u] = min( low[u], disc[v] );
        }
    }
    
    if(parent[u] == -1 && child > 1) {
        AP[u] = true;
    }
}

void init(int n) {
    for(int i=0; i<=n; i++) {
        visited[i] = false;
        AP[i] = false;
        parent[i] = -1;
        low[i] = disc[i] = INF;
    }
}

bool compare( const pair<int,int>& a, const pair<int,int>& b) {
    return a.first < b.first || (a.first == b.first && a.second < b.second);
}

int main() {
    t = 0;
    
    int n,m,u,v;
    cin >> n >> m;
    init(n);
    
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<n; i++)
        if(!visited[i])
            find_articulation_points(i);
    
    
    // cout << "ARTICULATION PoiNTS are :-\n";
    // for(int i=1; i<=n; i++)
    //     if( AP[i] )
    //         cout << i << " ";
    int ap=0;
    for(int i=0; i<n; i++) {
        if( AP[i] ) {
            ap++;
        }
    }
    
    cout << ap << endl;
    for(int i=0; i<n; i++) {
        if (AP[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    
    sort(bridges.begin(),bridges.end(),compare);
    cout << bridges.size() << endl;
    for(auto a:bridges) {
        cout << a.first << " " << a.second << endl;
    }
    return 0;
}