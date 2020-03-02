#include <iostream>
#include <vector>

using namespace std;

const int N = 1e2 + 2;
const int INF = 1e6;
vector<int> adj[N];
int low[N], disc[N], parent[N];
bool visited[N];
bool AP[N];
int tim;

void init(int n) {
    tim = 0;
    for(int i=0; i<=n; i++) {
        visited[i] = false;
        AP[i] = false;
        low[i] = disc[i] = INF;
        parent[i] = -1;
    }
}

void articulation_points(int u) {
    disc[u] = low[u] = tim++;
    int child = 0;
    visited[u] = true;
    
    for(int v: adj[u]) {

        if(!visited[v]) {
            child++;
            parent[v] = u;
            articulation_points(v);
            low[u] = min(low[u],low[v]);
            if(parent[u]!=-1 && low[v] >= disc[u]) {
                AP[u] = true;
            }
        } else if(parent[u]!=v) {
            low[u] = min(low[u],disc[v]);
        }
    }
    // cout << "node = " << u << " parent = " << parent[u] << endl;
    if(parent[u]==-1) {
        // cout << u << " " << parent[u] << endl;
        if(child>1)
            AP[u] = true;
        else
            AP[u] = false;
    }
    
}

int main() {
    int n,m,q,u,v;
    cin >> n >> m;
    for(int i=0; i<m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(n);

    for(int i=1; i<=n; i++) {
        if(!visited[i])
            articulation_points(i);
    }
    
    cin >> q;

    while(q--) {
        cin  >> u;
        if(AP[u]) {
            cout << "Satisfied " << adj[u].size() << endl;
        } else {
            cout << "Not Satisfied" << endl;
        }
    }

    return 0;
}