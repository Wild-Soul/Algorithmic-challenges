    #include <bits/stdc++.h>
    using namespace std;
     
    int main () {
        int n;
        cin >> n;
        int a = n-2;
        while(a) {
            if(__gcd(a,n) == 1){
                cout << a << endl;
                break;
            }
            a--;
        }
        return 0;
    }