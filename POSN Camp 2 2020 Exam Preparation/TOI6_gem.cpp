//			5/4/2563 //OR USE ARRAY INSTEAD OF VECTOR
#include<bits/stdc++.h>
using namespace std;
int n,m,d,a,b,temp,temp1;
char c=5;
vector<int>::iterator it;
void testcase(){
	vector<int> v[50000];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&temp,&temp1);
		a=min(temp,temp1);
		b=max(temp,temp1);
		v[a].push_back(b);
	}
	for(int i=0;i<m/2;i++){
		scanf("%d %d",&temp,&temp1);
		a=min(temp,temp1);
		b=max(temp,temp1);
		it=find(v[a].begin(),v[a].end(),b);
		if(it!=v[a].end()){
			d++;
		}
	}
	//printf("\nn=%d d=%d m=%d\n",n,d,m);
	if(n-d>=m) printf("N");
	else printf("Y");
}
main(){
	while(c--){
		d=0;
		testcase();
	}
}
