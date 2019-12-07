#include<bits/stdc++.h>
#define ll long long

const int MOD = 1e9+7;
using namespace std;

const int MAXN = 1e4 + 2;
const int MAXK = 1e2 + 2;
ll dp[MAXN][MAXK];

void preprocess() {
    
    for(int i=1;i<=100;i++)
	    dp[0][i]=1;
	
	for(int k=1; k<MAXK; k++)
	    for(int i=1;i<MAXN;i++)
		    for(int j=1;j<=min(i,k);j++)
			    dp[i][k]=(dp[i][k]+dp[i-j][k])%MOD;
			    
}

int main() {
	int t,x,k;
	cin>>t;
	
	preprocess();
	
	while(t--)
	{
		cin >> x >> k;
		cout << dp[x][k] << endl;
	}
	return 0;
}

