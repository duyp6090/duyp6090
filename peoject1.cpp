#include<bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
void solve(){
    int n,k;cin>>n;
    ll a[n];
    int mark[n+1]={0};
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
	int cnt=0;
	ll del=0;
	for(int i=n-2;i>=1;i--){
		if(a[i]-a[i-1]>n){
			cnt++;
			del=a[i]-a[i-1];
			if(cnt>1){
				cout<<"no\n";
				return;
			}
		}
		else mark[a[i]-a[i-1]]++;
	}
	if(cnt==1){
		int ok=1;
		for(int i=1;i<=n;i++){
			if(mark[i]>1||mark[i]==0&&ok==0){
				cout<<"no\n";
				return ;
			}
			else if(mark[i]==0){
				if(del-i>n){
					cout<<"no\n";
					return ;
				}
				else{
					mark[i]++;
					mark[del-i]++;
					ok=0;
				}
			}
		}
		cout<<"yes\n";
	}
	else{
			for(int i=1;i<=n;i++){
				if(mark[i]==0){
					mark[i]=1;
					mark[a[0]-i]=1;
					break;
				}
			}
			for(int i=1;i<=n;i++){
				if(mark[i]!=1){
					cout<<"no\n";
					break;
				}
			}
			cout<<"yes\n";
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    int tt;cin>>tt;
    while(tt--){
    	solve();
	}
	return 0;
}
