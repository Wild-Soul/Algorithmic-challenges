    #include <bits/stdc++.h>
    #define ll long long
    #define REP(i,j,n) for(int (i)=(j); (i)<(n); (i)++)
    #define REPB(i,n,j) for(int (i)=(n); (i)>=(j); (i)--)
    #define ull unsigned long long
    #define cases int test_cases; cin >> test_cases; while(test_cases--)
    #define pii pair<int,int>
    #define vi vector<int>
    #define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
     
    const int mod = 1e9+7;
    const int INF = 1e9+1;
    const ll LINF = 1e18+1;
     
    ll pow(ll x, ll y) {
        ll res = 1;
        while(y) {
            if(y&1)res = res*x;
            x = x*x;
            y = y/2;
        }
        return res;
    }
    ll powmod(ll x, ll y) {
        ll res = 1;
        while(y) {
            if(y&1)res = (res*x)%mod;
            x = (x*x)%mod;
            y = y/2;
        }
        return res%mod;
    }
    ll modInv( ll x) {
        return powmod(x, mod-2);
    }
    using namespace std;
     
    // *************************** TEMPLATE ENDS HERE ***************************
    int main() {
        int n,k,m;
        cin >> n >> k >> m;
        string s;
        cin >> s;
        int c=0;
        int ans = 0;
        int x;
        stack<int> st;
        for(int i=0; i<k; i++) {
            if(s[i]=='1') {
                st.push(i);
                c++;
            }
        }
        while(c>m) {
            x = st.top();
            st.pop();
            s[x] = '0';
            c--;
            ans++;
        }
        
        for(int i=k; i<n; i++) {
            if(s[i-k]=='1')c--;
            if(s[i]=='1') {
                st.push(i);
                c++;
                if(c>m) {
                    x = st.top();st.pop();
                    s[x]='0';
                    c--;
                    ans++;
                }
            }
        }
        cout << ans << endl;
        cout << s << endl;
        return 0;
    }