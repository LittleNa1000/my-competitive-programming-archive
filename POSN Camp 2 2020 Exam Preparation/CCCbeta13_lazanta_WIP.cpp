//				13/8/2563
#include<bits/stdc++.h>
using namespace std;
int V,E,card;
bool get[4];
string str;
int pos[4];
main(){
	scanf("%d %d",&V,&E);
	cin>>str;
	for(int i=0;i<str.length();++i){
		if(str[i]=='X'){
			++card;
			get[0]=1;
		}
		else if(str[i]=='M'){
			++card;
			get[1]=1;
		}
		else if(str[i]=='A'){
			++card;
			get[2]=1;
		}
		else if(str[i]=='S'){
			++card;
			get[3]=1;
		}
	}
	//printf("%d %d %d %d %d\n",card,get[0],get[1],get[2],get[3]);
	cin>>str;
	for(int i=0;i<str.length();++i){
		if(str[i]=='X'&&!get[0]) pos[0]=i+1;
		else if(str[i]=='M'&&!get[1]) pos[1]=i+1;
		else if(str[i]=='A'&&!get[2]) pos[2]=i+1;
		else if(str[i]=='S'&&!get[3]) pos[3]=i+1;
	}
}
