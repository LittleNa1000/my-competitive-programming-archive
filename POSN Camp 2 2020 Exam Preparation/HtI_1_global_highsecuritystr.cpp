//				11/8/2563
#include<bits/stdc++.h>
using namespace std;
int w,ans;
string str;
int main(){
	cin>>str;
	scanf("%d",&w);
	for(int i=0;i<str.length();++i){
		ans+=(str[i]-'a'+w)%26;
		//printf("%c %d\n",str[i],(str[i]-'a'+w)%26);
	}
	printf("%d",ans);
}
