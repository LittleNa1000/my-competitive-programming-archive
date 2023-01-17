//			18/3/2020
#include<bits/stdc++.h>
using namespace std;
int c=19,n;
string str;
main(){
	do{
		scanf("%d",&n);
		cin>>str;
		if(str=="00") printf("no\n");
		else if(str[0]!='0') printf("no\n");
		else printf("yes\n");
	}while(c--);
}
