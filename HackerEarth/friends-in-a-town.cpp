    #include <bits/stdc++.h>
    #define REP(i,j,n) for(int (i)=(j); (i)<(n); (i)++)
    #define ll long long
    #define cases int test; cin >> test; while(test--)
    #define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
    using namespace std;
    const int MAXN = 1e5 + 2;
    vector<ll> adj[MAXN];
    vector<bool> isHappy(MAXN,false);
    ll reward[MAXN];
    ll day[MAXN];
     
    int main()
    {
        ll n,m,k,q;
        cin >> n >> m >> k;
        ll u,v;
        REP(i,0,m)
        {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cin >> q;
        REP(i,1,q+1)
        {
            cin >> u >> v;
            
            for(int w:adj[u])  {
                reward[w] += v;
                if( reward[w] >= k && !isHappy[w] )
                {
                    isHappy[w] = true;
                    day[w] = i;
                }
            }
        }
        REP(i,1,n+1) {
            if(day[i])
                cout << day[i] << " ";
            else
                cout << -1 << " " ;
        }
        cout << endl;
    }