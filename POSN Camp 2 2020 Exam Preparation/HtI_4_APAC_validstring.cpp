//				9/8/2563
#include<bits/stdc++.h>
using namespace std;
//char str[1000005];
string str;
int n,i,ans,valid,sz;
int main(){
	//cin>>str;
	getline(cin,str);
	//scanf("%s",&str);
	sz=str.length();
	scanf("%d",&n);
	for(;i<n;++i){
		if(str[i]=='1'){
			++valid;
		}
	}
	if(valid==0){
		str[i-1]='1';
		++ans;
		++valid;
	}
	for(;i<sz;++i){
		if(str[i]=='1') ++valid;
		if(str[i-n]=='1') --valid;
		//printf("i=%d valid=%d\n",i,valid);
		if(valid==0){
			str[i-1]='1';
			++ans;
			++valid;
		}
	}
	printf("%d strlen%d ms%d",ans,sz,str.max_size());
}
