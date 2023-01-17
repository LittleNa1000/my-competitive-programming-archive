//				23/4/2563
#include<bits/stdc++.h>
using namespace std;
int n,k,decimal;
string str,ans;
int temp=1;
main(){
	scanf("%d %d",&n,&k);
	cin>>str;
	for(int i=str.size()-1;i>=0;i--){
		if(str[i]>='0'&&str[i]<='9') decimal+=(temp*(str[i]-'0'));
		else decimal+=(temp*(str[i]-'A'+10));
		temp*=n;
	}
	//printf("%d",decimal);
	while(1){
		if(!decimal) break;
		temp=decimal%k;
		if(temp>=0&&temp<=9) ans.insert(0,1,temp+'0');
		else ans.insert(0,1,temp+'A'-10);
		decimal/=k;
	}
	cout<<ans;
}
