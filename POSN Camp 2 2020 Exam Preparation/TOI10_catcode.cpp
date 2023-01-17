//				1/4/2563	April Fool's Day :P
#include<bits/stdc++.h>
using namespace std;
vector<int> code,ans;
vector<int>::iterator it;
string str,temp;
int n,m,t,len,result,check;
bool have_code;
int binary_to_decimal(string temp){
	result=0;
	for(int i=0;i<m;i++){
		result+=(temp[i]-'0')*pow(2,m-1-i);
	}
	//cout<<"Result from String: "<<temp<<" is "<<result<<"\n";
	return result;
}
main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>temp;
		code.push_back(binary_to_decimal(temp));
	}
	scanf("%d",&t);
	while(t--){
		have_code=0;
		ans.clear();
		scanf("%d",&len);
		cin>>str;
		for(int i=0;i<len-m+1;i++){
			check=binary_to_decimal(str.substr(i,m));
			it=find(code.begin(),code.end(),check);
			if(it!=code.end()){
				have_code=1;
				ans.push_back(distance(code.begin(),it)+1);
			}
		}
		sort(ans.begin(),ans.end());
		if(!have_code) printf("OK");
		else{
			for(int i=0;i<ans.size();i++){
				printf("%d ",ans[i]);
			}
		}
		printf("\n");
	}
}
