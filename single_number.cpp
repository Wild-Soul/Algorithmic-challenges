#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t,n,x;
	cin >> t;
	
	while(t--) {
		cin >> n;
		int ans = 0;
		for(int i=0; i<n; i++) {
			cin >> x;
			ans = ans ^ x;
		}
		cout << ans << endl;
	}
	return 0;
}