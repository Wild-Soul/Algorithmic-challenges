    #include <bits/stdc++.h>
    #define ll long long
    #define REP(i,j,n) for(int i=j; i<n; i++)
    #define cases int test; cin>>test; while(test--)
    const int INF = 1e9;
    using namespace std;
     
    const int MAXN = 1e5+4;
    const int MOD = 1e9+7;
     
    int main()
    {
        int a,b,c;
        cin >> a >> b >> c;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        vector< pair<char,int>> s(b);
        
        REP(i,0,b) 
            s[i] = {s2[i],i};
        sort(s.begin(),s.end());
        /*
        REP(i,0,b)
            cout << s[i].first << " " << s[i].second << endl;
        */
        
        char z = '1';
        int i=1;
        while(i<c && s3[i] == s3[i-1])
            i++;
        if(i<c)z=s3[i];
        /*
        REP(i,0,b)
            cout << s[i].first << " " << s[i].second << endl;
        */
        int prev = -INF;
        REP(i,0,b)
        {
            if( s[i].first < s3[0] && s[i].second > prev ) {
                s1+=s[i].first;
                prev = s[i].second;
            }
            else if(s[i].first == s3[0] && z!='1' && s[i].first < z && s[i].second > prev) {
                s1+=s[i].first;
                prev = s[i].second;
            }
        }
        s1 = s1+s3;
        cout << s1 << endl;
        return 0;
    }