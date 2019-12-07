    #include <bits/stdc++.h>
    #define ll long long
    #define REP(i,j,n) for(int (i) = (j); (i)<(n); (i)++)
    #define REPB(i,n,j) for(int (i) = (n); (i)>=(j); (i)--)
    #define cases int testcases; cin >> testcases; while(testcases--)
    #define pii pair<int,int> 
    #define pb push_back
    #define ff first
    #define ss second
    #define ull unsigned long long
    #define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
     
    using namespace std;
    const int INF = 1e9;
    const int N = 1e5+2;
     
    int main() {
        fastio;
        int n;
        ll fact[11];
        fact[0] = 1;
        REP(i,1,11) {
            fact[i] = fact[i-1]*1LL*i;
        }
        cases {
            cin >> n;
            ll ans=0;
            REP(i,1,n+1)
                ans = ans + n-i;
            cout << ans*1LL*fact[n] << endl;
        }
        return 0;
    }