#include<bits/stdc++.h>
using namespace std;
string str,temp1,temp2,temp3;
char num[15];
long int quiz,idx,l,size,arr,mul;
main(){
	scanf("%ld",&quiz);
	for(int i=0;i<quiz;i++){
		cin>>str>>temp1;
		str+=temp1;
		if(temp1=="long"){
			cin>>temp2;
			str+=temp2;
			if(temp2=="long"){
				cin>>temp3;
			}
		}
		//cout<<str<<'\n';
		num[0]=0;
		idx=0;
		l=0;
		size=0;
		mul=1;
		//printf("[%s]",num);
		for(int i2=0;i2<str.length();i2++){
			if(str[i2]>='0'&&str[i2]<='9'){
				num[idx]=str[i2];
				//printf("num[%d] = %c ",idx,str[i2]);
				num[++idx]=0;
			}
			else if(str[i2]=='K'){
				mul=1024;
			}
			else if(str[i2]=='M'){
				mul=1048576;
			}
			else if(str[i2]=='b'){
				size=sizeof(bool);
				break;
			}
			else if(str[i2]=='c'){
				size=sizeof(char);
				break;
			}
			else if(str[i2]=='s'){
				size=sizeof(short int);
				break;
			}
			else if(str[i2]=='f'){
				size=sizeof(float);
				break;
			}
			else if(str[i2]=='d'){
				size=sizeof(double);
				break;
			}
			else if(str[i2]=='l'){
				l++;
			}
		}
		//if(size==0){
			if(l==1) size=sizeof(long int);
			else if(l==2) size=sizeof(long long int);
			//else if(l==0) printf("NO");
		//}
		//printf("<%s>",num);
		arr=atoi(num);
		//printf("*%ld* ",arr);
		printf("%ld\n",(arr/size)*mul);
	}
}
