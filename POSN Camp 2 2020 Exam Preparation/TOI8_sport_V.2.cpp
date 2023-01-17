//				29/4/2563
#include<bits/stdc++.h>
using namespace std;
short int n,win,lose;
string str;
void f(){
	if(win==n||lose==n){
		cout<<str<<'\n';
		return ;
	}
	if(win+1<=n){
		str.push_back('W');
		str.push_back(' ');
		win++;
		f();
		win--;
		str.erase(str.begin()+str.size()-2,str.begin()+str.size());
	}
	if(lose+1<=n){
		str.push_back('L');
		str.push_back(' ');
		lose++;
		f();
		lose--;
		str.erase(str.begin()+str.size()-2,str.begin()+str.size());
	}
}
main(){
	scanf("%hd %hd %hd",&n,&win,&lose);
	f();
}
