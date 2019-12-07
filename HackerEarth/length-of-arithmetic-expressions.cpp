    /*
        author : Rohit Kumar
        complexity : O(n^2)
        weak testcases :(
    */
    
    #include <iostream>
    #include <vector>
    #define ll long long
     
    using namespace std;
     
    int main() {
        int n,q,l,r,diff;
        cin >> n >> q;
        int a[n];
        for(int i=0; i<n; i++) cin >> a[i];
        
        vector<int> st(n,0),end(n,0),d(n,0);
        int d_i=1;
        
        for(int i=1; i<n; i++) {
            if(i==1) {
                st[i] = 0;
                end[i] = 1;
                d[i] = a[i]-a[i-1];
                d_i++;
                continue;
            }
            if(a[i]-a[i-1]==d[d_i-1]) {
                end[d_i-1]=i;
            } else {
                st[d_i] = i-1;
                end[d_i] = i;
                d[d_i] = a[i]-a[i-1];
                d_i++;
            }
            
        }
        
        while(q--) {
            cin >> l >> r >> diff;
            l--;r--;
            int ans = 1;
            
            for(int i=1; i<d_i; i++) {
                if(diff != d[i])continue;
                if(l>end[i])continue;
                if(r<st[i])break;
                ans = max(ans, min(end[i],r)-max(l,st[i]) + 1);
            }
            cout << ans << endl;
        }
        return 0;
    }