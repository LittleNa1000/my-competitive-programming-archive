//				15/4/2563
#include<bits/stdc++.h>
using namespace std;
short int n,h;
string str;
bool print;
main(){
	scanf("%hd",&n);
	for(int a=0;a<pow(2,n);a++){
		h=0;
		print=1;
		str.clear();
		for(int i=0;i<n;i++){
			if(h==n){
				for(;i<n;i++){
					if(a&(1<<i)){
						print=0;
						break;
					}
				}
			}
			else{
				if(a&(1<<i)){
					str.push_back('-');
					str.push_back('-');
					str.push_back('\n');
					h++;
				}
				else{
					if(h+2<=n){
						str.push_back('|');
						str.push_back('|');
						str.push_back('\n');
						h+=2;
					}
					else{
						print=0;
						break;
					}
				}
			}
		}
		if(print){
			cout<<str<<"E"<<'\n';
		}
	}
}
