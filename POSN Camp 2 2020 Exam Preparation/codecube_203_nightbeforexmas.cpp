//				14/8/2563
#include<bits/stdc++.h>
using namespace std;
string str,ans;
main(){
	cin>>str;
	for(int i=0;i<str.length()-1;++i){
		ans.push_back('x');
		if(str[i]=='?'){
			if(str[i+1]=='2'||str[i+1]=='?'||(str[i+1]=='1')){
				ans.push_back('-');
				if(str[i+1]!='?') --str[i+1];
			}
			else{
				ans.push_back('.');
			}
		}
		else{
			if(str[i]>'0'&&(str[i+1]>'0'||str[i+1]=='?')){
				ans.push_back('-');
				--str[i];
				if(str[i+1]!='?') --str[i+1];
			}
			else{
				ans.push_back('.');
			}	
		}
	}
	cout<<ans<<'x';
}
/*
1?11
x-x-x.x
1?121
x-x-x.x-x
1211?121
x-x-x.x-x-x.x-x
1211?111
correct x-x-x.x-x-x.x-x
1211?110 
x-x-x.x-x-x.x.x -> x-x-x.x-x.x-x.x
*/
