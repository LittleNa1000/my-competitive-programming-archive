//				9/4/2563
#include<bits/stdc++.h>
using namespace std;
short int m,finish,n;
bool road[105][45],b;
void print_path(vector<char> v){
	for(int i=v.size()-1;i>=0;i--){
		printf("%d\n",v[i]);
	}
}
void find_path(short int i,short int j,vector<char> v){
	if(b) return ;
	if(i==0){
		if(j-1==finish){
			b=1;
			v.push_back(2);
		}
		else if(j+1==finish){
			b=1;
			v.push_back(1);
		}
		else if(j==finish){
			b=1;
			v.push_back(3);
		}
		if(b){
			print_path(v);
		}
		return ;
	}
	if(j>0&&!road[i-1][j-1]){
		v.push_back(2);
		find_path(i-1,j-1,v);
		v.pop_back();
	}
	if(j<m-1&&!road[i-1][j+1]){
		v.push_back(1);
		find_path(i-1,j+1,v);
		v.pop_back();
	}
	if(!road[i-1][j]){
		v.push_back(3);
		find_path(i-1,j,v);
		v.pop_back();
	}
}
main(){
	scanf("%hd %hd %hd",&m,&finish,&n);
	finish--;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&road[i][j]);
		}
	}
	for(int j=0;j<m;j++){
		if(!road[n-1][j]){
			find_path(n-1,j,{});
		}
	}
	
}
