    #include <iostream>
    #include <vector>
    #include <cstring>
    using namespace std;
     
    const int N = 2e5 + 4;
    vector<int> adj[N];
    int ter[N];
     
    int dfs(int v, vector<bool>& visited) {
        
        if(ter[v]) {
            
            int cnt = 1;
            for(int j=0; j<(int)adj[v].size(); j++) {
                // if the node we are looking at is not visited.
                if(!visited[adj[v][j]]) {
                    visited[adj[v][j]] = true;
                    cnt += dfs(adj[v][j], visited);
                }
            }
            //cout << "encountered terminal " << v  << " with cnt = " << cnt << endl;
            return cnt;
        }
        
        //cout << "current node " << v << endl;
        int cnt = 0;
        for(int i=0; i<adj[v].size(); i++) {
            if(!visited[adj[v][i]]) {
                visited[adj[v][i]] = true;
                cnt += dfs(adj[v][i],visited);
            }
        }
        if(cnt !=0)cnt++;
        //cout << cnt << " for node " << v << endl;
        return cnt;
    }
     
    int main() {
        
        int n,k,u,v;
        cin >> n >> k;
        memset(ter,0,(n+1)*sizeof ter[0]);
        
        for(int i=1; i<n; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> t;
        for(int i=0; i<k; i++) {
            cin >> u;
            ter[u] = 1;
            t.push_back(u);
        }
        int ans = 0;
        vector<bool> visited(n+1,false);
        
        for(int i=0; i<(int)t.size(); i++) {
            int cnt = 0;
            visited[t[i]] = true;
            for(int j=0; j<(int)adj[t[i]].size(); j++) {
                // if the node we are looking at is not visited.
                if(!visited[adj[t[i]][j]]) {
                    visited[adj[t[i]][j]] = true;
                    cnt += dfs(adj[t[i]][j], visited);
                }
                
            }
            cnt = cnt+1;//add the terminal node.
            ans = max(ans,cnt);
        }
        
        cout << ans << endl;
        return 0;
    }