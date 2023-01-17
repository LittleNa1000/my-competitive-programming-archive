//				30/4/2563
#include<bits/stdc++.h>
using namespace std;
unsigned char n;
string s;
bool v[9];
void f(){
	if(s.length()==(n*2)){
		cout<<s<<'\n';
		return ;
	}
	for(char i=0;i<n;i++){
		if(!v[i]){
			v[i]=1;
			s.push_back(i+1+'0');
			s.push_back(' ');
			f();
			s.erase(s.size()-2,s.size());
			v[i]=0;
		}
	}
}
main(){
	scanf("%d",&n); f();
}
