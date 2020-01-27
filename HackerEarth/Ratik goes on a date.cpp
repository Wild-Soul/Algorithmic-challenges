#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int binary(int x, pair<int,int> b[], int n) {
    int lo = 0, hi = n;
    
    while(lo<hi) {
        int mid = lo + (hi-lo)/2;
        if(b[mid].first < x) {
            lo = mid+1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

int main() {
    fastio;
    int n,k,x,y;
    cin >> n >> k;
    pair<int,int> a[n];
    pair<int,int> b[n];
    
    for(int i=0; i<n; i++) {
        cin >> a[i].first;
        assert(a[i].first > 0);
        a[i].second = 0;
        b[i].first = a[i].first;
        b[i].second = i;
    }
    
    while(k--) {
        cin >> x >> y;
        x--, y--;
        if(a[x].first > a[y].first) {
            a[x].second++;
        } else if( a[y].first > a[x].first) {
            a[y].second++;
        }
    }

    stable_sort(b,b+n);
    int ans[n];
    
    for(int i=0; i<n; i++) {
        int x = binary ( b[i].first, b, n);
        // cout << "Talking about " << b[i].first << " at " << b[i].second << endl;
        // cout << "Stronger than " << x << endl;
        // cout << "Weak friends " << a[b[i].second].second << endl;

        ans[b[i].second] = x - a[b[i].second].second;
        if(ans[i]<0)ans[i] = 0;
    }
    
    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}