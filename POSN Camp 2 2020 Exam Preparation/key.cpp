//		keyAB
#include<bits/stdc++.h>
using namespace std;
int n;
string x[9],temp;
bool yfirst(){
	int idx[9];
	idx[0]=0;
	idx[1]=0;
	bool b=1,error=0; //	0=x	1=y;
	for(int i=0;i<temp.length();){
		if(temp[i]!=x[b][idx[b]]){
			if(error){
				return 0;
			}
			else{
				error=1;
				b=!b;
			}	
		}
		else{
			//printf("b%d idx[b]%d i%d temp[i]%c ",b,idx[b],i,temp[i]);
			error=0;
			idx[b]++;
			i++;
		}
	}
	return 1;
}
bool check(){
	int idx[9];
	idx[0]=0;
	idx[1]=0;
	bool b=0,error=0; //	0=x	1=y;
	for(int i=0;i<temp.length();){
		if(temp[i]!=x[b][idx[b]]){
			if(error){
				return yfirst();
			}
			else{
				error=1;
				b=!b;
			}	
		}
		else{
			//printf("b%d idx[b]%d i%d temp[i]%c ",b,idx[b],i,temp[i]);
			error=0;
			idx[b]++;
			i++;
		}
	}
	return 1;
}
main(){
	cin>>x[0]>>x[1]>>n;
	//gets(x[1]);
	for(int i=0;i<n;i++){
		cin>>temp;
		if(check()) printf("Yes\n");
		else printf("No\n");	
	}
}
