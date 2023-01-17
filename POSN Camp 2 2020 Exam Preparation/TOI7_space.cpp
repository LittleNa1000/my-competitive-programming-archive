//				30/4/2563
#include<bits/stdc++.h>
using namespace std;
string str;
short int n;
void f2(){
	for(short int i=1;i<=n;i++){
		if(str[n+i]=='0'){
			str[n+i]='1';
			cout<<str<<'\n';
			str[n+i]='0';
		}
	}
}
void f(){
	if(str.size()==n){
		str.push_back(' ');
		str.insert(str.size(),str);
		f2();
		str.erase(str.begin()+n,str.begin()+str.size());
		return ;
	}
	str.push_back('0');
	f();
	str.erase(str.begin()+str.size()-1);
	str.push_back('1');
	f();
	str.erase(str.begin()+str.size()-1);
	
}
main(){
	scanf("%d",&n);
	 f();
}
