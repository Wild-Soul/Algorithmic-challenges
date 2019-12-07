    #include <iostream>
    using namespace std;
     
    #define ull unsigned long long
    #define ll long long
     
    int main() {
        int t;
        cin >> t;
        ll n,k,ans;
        while(t--){
            ans = 0;
            cin >> n >> k;
            if(n==k){
                cout << "Arpa" << endl;
                continue;
            }else if( k == n-1){
                cout << "Dishant" << endl;
                continue;
            }else{
                bool flag = true;
                if ( (n%2==0 && k == 1) || (n%3 == 0 && k == 2) ){
                    flag = false;
                }
                int tk = 1;
                if( n%(k+1) == 0)
                    flag = false;
                if(flag)
                    cout << "Arpa" <<endl;
                else
                    cout << "Dishant" << endl;
            }
        }
        return 0;
    }