//				15/4/2563
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int temp,n;
void print_vec(vector<int> v){
    for(int i=0;i<v.size();i++) printf("%d\n",v[i]);
    //printf("\n");
}
void merge(int left,int mid,int right){
	vector<int> t;
	int i=left,j=mid+1;
	while(i<=mid&&j<=right){
		if(v[i]<=v[j]){
			t.push_back(v[i]);
			i++;
		}
		else{
			t.push_back(v[j]);
			j++;
		}
	}
	while(i<=mid){
		t.push_back(v[i]);
		i++;
	}
	while(j<=right){
		t.push_back(v[j]);
		j++;
	}
	for(int a=0;a<t.size();a++) v[left+a]=t[a];
}
void divide(int left,int right){
	if(left<right){
		int mid=(left+right)/2;
		divide(left,mid);
		divide(mid+1,right);
		merge(left,mid,right);
	}
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		v.push_back(temp);
	}
	divide(0,n-1);
	print_vec(v);
}
