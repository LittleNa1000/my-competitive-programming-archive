//				24/4/2563
#include<bits/stdc++.h>
using namespace std;
int t,sz,digit;
unsigned long long int mem;
string number,data,data2,temp;
main(){
	scanf("%d",&t);
	while(t--){
		cin>>number>>data;
		for(int i=number.size()-2;i>=0;i--){
			if(i==number.size()-2){
				if(number[i]>='0'&&number[i]<='9') mem+=((number[i]-'0')*pow(10,digit++));
			}
			else mem+=((number[i]-'0')*pow(10,digit++));
		}
		if(data=="long"){
			cin>>data2;
			if(data2=="long"){
				cin>>temp;
				sz=sizeof(long long int);
			}
			else sz=sizeof(long int);
		}
		else if(data=="bool"){
			sz=sizeof(bool);
		}
		else if(data=="char"){
			sz=sizeof(char);
		}
		else if(data=="short"){
			cin>>temp;
			sz=sizeof(short int);
		}
		else if(data=="float"){
			sz=sizeof(float);
		}
		else if(data=="double"){
			sz=sizeof(double);
		}
		if(number[number.size()-2]=='M') {
			mem=mem*1048576;
		}
		else if(number[number.size()-2]=='K'){
			mem=mem*1024;
		}
		mem=mem/sz;
		printf("%llu\n",mem);
		mem=0;
		digit=0;
	}
}
