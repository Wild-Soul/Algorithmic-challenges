    #include <bits/stdc++.h>
    using namespace std;
     
    int main () {
        int t;
        string str;
        cin >> t;
        
        while(t--) {
            cin >> str;
            stack<char> s;
            int cnt = 0;
            int ans = 0;
            bool flag = false;
            for(int i=0; i<str.length()/2; i++) {
                if( str[i] == '(') {
                    cnt ++;
                }
            }
            cout << cnt * 2 << endl;
        }
    }