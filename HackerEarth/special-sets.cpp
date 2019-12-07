    #include <bits/stdc++.h>
    #define ll long long
    #define REP(i,j,n) for(int (i)=(j); (i)<(n); (i)++)
    #define cases int test; cin>>test; while(test--)
    const int MAXN = 2004;
    const int MOD = 1e9+7;
    using namespace std;
     
    ll fact[MAXN];
     
    void factorial()
    {
        fact[0] = 1;
        for(int i=1; i<MAXN; i++)
            fact[i] = (fact[i-1]*1LL*i)%MOD;
    }
     
    int main()
    {
        int n;
        cin >> n;
        
        factorial();
        int cardinality = (n+1)/2;
        ll ans = n;
        vector<ll> a,b;
        REP(i,1,n-1)
            a.push_back(i);
        
        int c = 0;
        ll x = n-2;
        if(x%2==0)
            x = ((x/2)%MOD* 1LL * (x+1)%MOD)%MOD;
        else
            x = ( x%MOD *1LL* ((x+1)/2)%MOD )%MOD;
        ans = (ans + (x*1LL*fact[2])%MOD )%MOD;
        REP(i,3,cardinality+1)
        {
            ll sum = 0;
            b.clear();
            if(a.empty())break;
            
            b.push_back(a[0]);
            sum = b[0];
            REP(j,1,a.size()-2) {
                b.push_back( (b[j-1] + a[j])%MOD );
                sum = (sum+b[j])%MOD;
            }
            /*
            cout << "|S| = " << i << " sum " << sum << endl;
            REP(j,0,b.size())
                cout << b[j] << " ";
            cout << endl;
            */
            ans = (ans + sum*fact[i])%MOD;
            a = b;
        }
        
        cout << ans << endl;
        return  0;
    }