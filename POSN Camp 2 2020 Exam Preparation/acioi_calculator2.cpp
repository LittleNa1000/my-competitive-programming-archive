//				24/4/2563 
#include<bits/stdc++.h>
using namespace std;
int idx,x,temp;
char num[405];
string str;
bool b_a,b_b;
int ascii_to_int(){
	int x=0;
	while(1){
		if(idx>=str.size()||str[idx]<'0'||str[idx]>'9'){
			temp=atoi(num);
			for(int i=0;i<405;i++) num[i]=0;
			//printf("%d\n",temp);
			return temp;
		}
		num[x++]=str[idx++];
	}
}
int calculator(){
	int result=0;
	while(1){
		if(idx>=str.size()) return result;
		if(str[idx]==')'){
			idx++;
			return result;
		}
		if(str[idx]>='0'&&str[idx]<='9'){
			result=ascii_to_int();
		}
		else if(str[idx]=='('){
			idx++;
			result=calculator();
		}
		else if(str[idx]=='+'){
			idx++;
			if(str[idx]!='(') result+=ascii_to_int();
			else{
				idx++;
				result+=calculator();
			}
		}
		else if(str[idx]=='-'){
			idx++;
			if(str[idx]!='(') result-=ascii_to_int();
			else{
				idx++;
				result-=calculator();
			}
		}
		else if(str[idx]=='*'){
			idx++;
			if(str[idx]!='(') result*=ascii_to_int();
			else{
				idx++;
				result*=calculator();
			}
		}
		else{
			idx++;
			if(str[idx]!='(') result/=ascii_to_int();
			else{
				idx++;
				result/=calculator();
			}
		}
		//idx++;
	}
}
main(){
	cin>>str;
	if(str[0]=='-'||str[0]=='+') str.insert(0,"0");
	for(int i=0;i<str.size();i++){// -4+9*5+8 => 0-4+(9*5)+8
		if(str[i]=='*'||str[i]=='/'){
			b_a=0;
			b_b=0;
			for(int j=1;i-j!=0&&i+j!=str.size();j++){
				//cout<<str<<'\n';
				//printf("%d \n",j);
				if(str[i-j]=='('||str[i-j]==')'||str[i+j]=='('||str[i+j]==')') break;
				if(!b_a&&(str[i-j]=='+'||str[i-j]=='-'||str[i-j]=='*'||str[i-j]=='/')){
					b_a=1;
					str.insert(i-j+1,"(");
				}
				//else if(!b_a&&(str[i-j]=='('||str[i-j]==')')) b_a=1;
				if(!b_b&&(str[i+j]=='+'||str[i+j]=='-'||str[i+j]=='*'||str[i+j]=='/')){
					b_b=1;
					str.insert(i+j,")");
				}
				//else if(!b_b&&(str[i+j]=='('||str[i+j]==')')) b_b=1;
				if(b_a&&b_b) break;
			}
			i+=2;
		}
	}
	//cout<<str<<'\n';
	printf("%d",calculator());
}
