//				17/4/2563 COPIED FROM ACIOI_ANIMAL ON 9/6/2563 
#include<bits/stdc++.h>
using namespace std;
short int n,s;
int c;
bool n_a[15];
short int arr[15][15];
/*void print_vec(vector<short int> v){
	for(int i=0;i<v.size();i++) printf("%hd ",v[i]+1);
	printf("\n");
}*/
/*void print_arr(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}*/
/*bool valid(vector<short int> v,short int j){
	if(n_a[j]) return 0;
	s=v.size();
	for(int k=s-1;k>=0;k--){
		if(v[k]==j-(s-k)||v[k]==j+(s-k)) return 0;
	}
	return 1;
}*/
void nq(vector<short int> v){
	if(v.size()==n){
		c++;
		//if(c<=3) print_vec(v);
		return;
	}
	for(short int i=0;i<n;i++){
		if(v.empty()||(!n_a[i]&&arr[v.size()][i]==0)){
			n_a[i]=1;
			v.push_back(i);
			s=v.size();
			for(short int j=s;j<n;j++){
				if(i-(j-s+1)>=0) arr[j][i-(j-s+1)]++;
				if(i+(j-s+1)<n) arr[j][i+(j-s+1)]++;
			}
			//print_arr();
			nq(v);
			n_a[i]=0;
			s=v.size();
			for(short int j=s;j<n;j++){
				if(i-(j-s+1)>=0) arr[j][i-(j-s+1)]--;
				if(i+(j-s+1)<n) arr[j][i+(j-s+1)]--;
			}
			//print_arr();
			v.pop_back();
		}
	}
}
main(){
	scanf("%hd",&n);
	nq({});
	printf("%d",c);
}
