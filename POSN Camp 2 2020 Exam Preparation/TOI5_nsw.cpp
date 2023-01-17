//				31/3/2563
#include<bits/stdc++.h>
using namespace std;
int key,a,b,c;
string str;
int findvalue(int head,int add){
	int result=head+add-1;
	if(result>=10){
		result%=10;
		result++;
	}
	printf(" *%d* ",result);
	return result;
}
int decode(int x){
	x=findvalue(a,x);
	x=findvalue(b,x);
	return findvalue(c,x);
}
void resetabc(){
	a*=2;
	if(a>=10){
		a%=10;
		a++;
	}
	b--;
	if(b==0) b=9;
	c*=2;
	if(c>=10){
		c%=10;
		c++;
	}
}
main(){
	scanf("%d",&key);
	a=key/100;
	b=(key%100)/10;
	c=key%10;
	cin>>str;
	for(int i=0;i<str.length();i++){
		printf("Now a=%d b=%d c=%d",a,b,c);
		printf("%d\n",decode(str[i]-'0'));
		resetabc();
		//printf("After Reset: a=%d b=%d c=%d\n",a,b,c);
	}
}
