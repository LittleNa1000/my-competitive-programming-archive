#include<bits/stdc++.h>
using namespace std;
int tc,n,pos;
string str;
bool b;
int main(){
	scanf("%d",&tc);
	while(tc--){
		scanf("%d",&n);
		cin>>str;
		//cout<<n<<str<<'\n';
		b=1;
		pos=0;
		for(int i=0;i<str.length();++i){
			if(str[i]=='f') ++pos;
			else --pos;
			if(pos<0||pos>n){
				b=0;
				break;
			}
		}
		if(!b){
			printf("NO\n");
			continue;
		}
		if(pos==n) printf("YES\n");
		else printf("NO\n");
	}
}
