//				21/4/2563 BROKEN
#include<bits/stdc++.h>
using namespace std;
vector<int> v,v2;
vector<int> result(300005,-1);
stack<int> st;
int n,ans=1,ub,temp,previous,data[300005];
void print_vec(vector<int> v){
    for(int i=0;i<n;i++) printf("%d ",v[i]);
    printf("\n");
}
void print_stack(){
	while(!st.empty()){
		printf("%d ",st.top());
		st.pop();
	}
}
void printresult(int idx){
	if(idx==-1) return print_stack();
	st.push(data[idx]);
	return printresult(result[idx]);
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		data[i]=temp;
		if(i==0){
			v.push_back(temp);
			v2.push_back(0);
		}
		else{
			ub=lower_bound(v.begin(),v.end(),temp)-v.begin();
			if(ub==v.size()){
				v.push_back(temp);
				v2.push_back(i);
				ans++;
				result[i]=v2[ub-1];
			}
			else if(v[ub]!=temp){
				v[ub]=temp;
				v2[ub]=i;
				if(ub>0) result[i]=v2[ub-1];
			}
		}
	}
	//print_vec(result);
	printf("%d\n",ans);
	while(1){
		if(result[n-1]==-1) n--;
		else{
			printresult(n-1);
			break;
		}
	}
}
/*
11
3 4 -1 5 8 2 3 12 7 9 10
*/
