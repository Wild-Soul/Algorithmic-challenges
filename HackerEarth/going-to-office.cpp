include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define REP(i,j,n) for(int i=j; i<n; i++)
#define cases int test; cin>>test; while(test--)
 
using namespace std;
 
const int MAXN = 1e5+4;
const int MOD = 1e9+7;
 
int main()
{
    ll Oc,Of,Od,D;
    ll Cs,Cb,Cm,Cd;
    cin >> D;
    cin >> Oc >> Of >> Od;
    cin >> Cs >> Cb >> Cm >> Cd;
    
    // calculate the cost of an online taxi.
    ll On = Oc;
    if( D > Of ) {
        On += (D-Of)*1LL*Od;
    }
    cerr << "ONLINE COST " << On << endl;
    
    // calculate the cost of an offline taxi.
    ll Off = Cb;
    Off += (ll)(D/Cs)*1LL*Cm;
    Off += D*1LL*Cd;
    cerr << "OFFLINE COST " << Off << endl;
    
    if(On > Off)
        cout << "Classic Taxi" << endl;
    else
        cout << "Online Taxi" << endl;
    return 0;
}