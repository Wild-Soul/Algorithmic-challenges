    #include <iostream>
    #include <cmath>
    using namespace std;
     
    int main(){
        int n;
        string s,t;
        cin >> n;
        cin >> s >> t;
        int len = -1;
        int ans = n;
        int start=-1;
        int l =0;
        for(int i=0; i<n && l<n; i++) {
            if(s[i] == t[l]){
                //cout << start << endl;
                //cout << s[i] << " " << t[l] << endl;
                if(start<0)start = i;
                l++;
                if( (start+n-i-1) == (n-l) )
                    ans = min(ans, n-l);
            }
            else{
                l = 0;
                if(start>0)
                    i = start+1;
                start = -1;
            }
        }
        if(ans == (n-1))
            cout << n << endl;
        else
            cout << ans << endl;
        return 0;
    }