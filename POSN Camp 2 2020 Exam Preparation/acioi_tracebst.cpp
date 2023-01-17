//				19/4/2563 WIP
#include<bits/stdc++.h>
using namespace std;
string str;
int n,middle;
void tracebst(int left,int right,int idx){
	middle=(left+right)/2;
	if(str[idx]=='*'){
		printf("%d\n",middle);
	}
	else if(str[idx]=='L'){
		tracebst(left,middle,idx+1);
	}
	else{
		tracebst(middle+1,right,idx+1);
	}
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>str;
		tracebst(0,n-1,0);
	}
}
