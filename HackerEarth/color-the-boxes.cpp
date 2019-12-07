    #include <bits/stdc++.h>
    #define ll long long
    #define rep(i,j,n) for(int i=j; i<n; i++)
    #define cases int test; cin>>test; while(test--)
     
    using namespace std;
     
    const int MAXN = 1e5+4;
    const int MOD = 1e9+7;
     
    int main()
    {
        int n,m;
        cin >> n >> m;
        ll ans = 1;
        for(int i=1; i<=m; i++)
        {
            ans = (ans%MOD*1LL*i%MOD) %MOD;
        }
        cout << ans << endl;
        return 0;
    }