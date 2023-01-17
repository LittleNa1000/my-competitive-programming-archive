//				8/5/2563
#include<bits/stdc++.h>
using namespace std;
int l,r,n,k,t,temp,idx[200005];
bool in_q[200005];
vector<int> s,e;
vector<int> v;
bool f(){
	scanf("%d %d",&l,&r);
	l--;	r--;
	if(r-l+1<k) return 0;
	for(int i=0;i<s.size();i++){
		if(l<=s[i]&&r>=e[i]) return 1;
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&k,&t);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		if(temp<=k){
			if(!in_q[temp]){
				v.push_back(temp);
				in_q[temp]=1;
			}
			else{
				v.erase(find(v.begin(),v.end(),temp));
				v.push_back(temp);
			}
			idx[temp]=i;
		}
		//for(int j=0;j<v.size();j++) printf("%d:",v[j]);
		//printf("\n");
		if(v.size()==k){
			s.push_back(idx[v[0]]);
			e.push_back(i);
			in_q[v[0]]=0;
			v.erase(v.begin());
		}
	}
	/*for(int i=0;i<s.size();i++){
		printf("(%d,%d)\n",s[i],e[i]);
	}*/
	while(t--){
		if(f()) printf("YES\n");
		else printf("NO\n");
	}
}
