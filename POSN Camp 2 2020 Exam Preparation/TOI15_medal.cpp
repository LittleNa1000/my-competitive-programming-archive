//			3/6/2563 //TRY PQ
#include<bits/stdc++.h>
using namespace std;
vector<int> people,stand,mix;
int n,temp,arm;
long long int ans;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		people.push_back(temp);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		stand.push_back(temp);
	}
	sort(people.begin(),people.end());
	sort(stand.begin(),stand.end());
	for(int i=0;i<n;i++){
		mix.push_back(people[i]+stand[n-i-1]);
	}
	sort(mix.begin(),mix.end());
	arm=mix[0];
	for(int i=1;i<n;i++){
		ans+=mix[i]-arm;
		arm=mix[i];
	}
	printf("%lld",ans);
}
