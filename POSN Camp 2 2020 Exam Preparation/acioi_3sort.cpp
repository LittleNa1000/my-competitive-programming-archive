//				27/3/2563 Last Edited: 13/4/2563
#include<bits/stdc++.h>
using namespace std;
int n,arr[100005],one,two,three,result,a,b,c;
int f(int start,int finish,int x){
	result=0;
	for(int i=start;i<=finish;i++){
		if(arr[i]!=x) result++;
	}
	return result;
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		if(arr[i]==1) one++;
		else if(arr[i]==2) two++;
	}
	a=f(0,one-1,1);
	b=f(one,one+two-1,2);
	c=f(one+two,n-1,3);
	if(a>=b&&a>=c){
		printf("%d",b+c);
	}
	else if(b>=a&&b>=c){
		printf("%d",a+c);
	}
	else{
		printf("%d",b+a);
	}
}

