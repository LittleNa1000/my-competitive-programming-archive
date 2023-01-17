//				2/4/2563 SHORT VERSION OF V1
#include<bits/stdc++.h>
using namespace std;
//string str,a;
//vector<bool> b;
//short int status=1,n;
char str[17],a[3],status=1,n;
bool b[9];
void binary_to_ascii(){
	/*for(int i=0;i<8;i++){
		ans+=b[i]*pow(2,7-i);
	}
	printf("%c",ans);
	ans=0;*/
	a[0]=b[7]*pow(2,0)+b[6]*pow(2,1)+b[5]*pow(2,2)+b[4]*pow(2,3)+b[3]*pow(2,4)+b[2]*pow(2,5)+b[1]*pow(2,6)+b[0]*pow(2,7);
	printf("%c",a[0]);
}
void romeo(){
	for(int i=0;i<strlen(str);i+=2){
		//a.push_back(str[i]);
		//a.push_back(str[i+1]);
		a[0]=str[i];
		a[1]=str[i+1];
		//cout<<"a ="<<a<<"\n";
		if(a[0]=='0'&&a[1]=='0'){
			if(status==1){
				b[i/2]=0;
			}
			else{
				status=2;
				b[i/2]=1;
			}
		}
		else if(a[0]=='0'&&a[1]=='1'){
			if(status==2){
				status=4;
				b[i/2]=1;
			}
			else{
				status=3;
				b[i/2]=0;
			}
		}
		else if(a[0]=='1'&&a[1]=='0'){
			if(status==2){
				status=3;
				b[i/2]=0;
			}
			else{
				b[i/2]=1;
			}
		}
		else{
			if(status==1){
				status=2;
				b[i/2]=1;
			}
			else{
				status=1;
				b[i/2]=0;
			}
		}
		//a.clear();
	}
	if(strlen(str)==16){
		binary_to_ascii();
		//for(int i=0;i<b.size();i++) printf("%d",b[i]);
		//printf("\n");
	}
	//b.clear();
}
main(){
	scanf("%d",&n);
	for(short i=0;i<n;i++){
		cin>>str;
		romeo();
	}
}
