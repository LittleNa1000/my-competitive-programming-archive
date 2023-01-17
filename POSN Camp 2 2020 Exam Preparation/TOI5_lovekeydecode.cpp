//				31/3/2563
#include<bits/stdc++.h>
using namespace std;
string str,a;
vector<bool> b;
short status=1,n;
char ans;
void binary_to_ascii(){
	for(int i=0;i<8;i++){
		ans+=b[i]*pow(2,7-i);
	}
	printf("%c",ans);
	ans=0;
}
void romeo(){
	for(int i=0;i<str.length();i+=2){
		a.push_back(str[i]);
		a.push_back(str[i+1]);
		//cout<<"a ="<<a<<"\n";
		if(a=="00"){
			if(status==1){
				b.push_back(0);
			}
			else{
				status=2;
				b.push_back(1);
			}
		}
		else if(a=="01"){
			if(status==2){
				status=4;
				b.push_back(1);
			}
			else{
				status=3;
				b.push_back(0);
			}
		}
		else if(a=="10"){
			if(status==2){
				status=3;
				b.push_back(0);
			}
			else{
				b.push_back(1);
			}
		}
		else{
			if(status==1){
				status=2;
				b.push_back(1);
			}
			else{
				status=1;
				b.push_back(0);
			}
		}
		a.clear();
	}
	if(b.size()==8){
		binary_to_ascii();
		//for(int i=0;i<b.size();i++) printf("%d",b[i]);
		//printf("\n");
	}
	b.clear();
}
main(){
	scanf("%d",&n);
	for(short i=0;i<n;i++){
		cin>>str;
		romeo();
	}
}
