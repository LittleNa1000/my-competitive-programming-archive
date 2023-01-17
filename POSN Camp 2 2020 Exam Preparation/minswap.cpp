//				12-13/8/2563 Problem by lnwTum
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int arr1[50005],arr2[50005],temp[50005];
bool s=1;
void mergesort(int arr[],int l,int m,int r){
	//printf("Merging [%d,%d] m=%d \n",l,r,m);
	int i=l,j=m+1,k=l;
	while(i<=m&&j<=r){
		if(arr[i]<=arr[j]) temp[k++]=arr[i++];
		else{
			temp[k++]=arr[j++];
			ans+=(m-i+1);
		}
	}
	while(i<=m) temp[k++]=arr[i++];
	while(j<=r) temp[k++]=arr[j++];
	for(i=l;i<=r;++i) arr[i]=temp[i];
}
void div(int arr[],int l,int r){
	//printf("div %d %d\n",l,r);
	if(l>=r) return ;
	int m=(l+r)/2;
	div(arr,l,m);
	div(arr,m+1,r);
	mergesort(arr,l,m,r);
}
main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		if(i%2==0) scanf("%d",&arr1[i/2]);
		else scanf("%d",&arr2[i/2]);
	}
	div(arr1,0,(n/2)+(n%2)-1);
	div(arr2,0,(n/2)-1);
	for(int i=0;i<n/2;++i){
		if(arr1[i]>arr2[i]){
			s=0; break;
		}
		if(i+1!=n/2+(n%2)&&arr2[i]>arr1[i+1]){
			s=0; break;
		}
	}
	if(s) printf("Yes\n%d",ans);
	else printf("No");
}
