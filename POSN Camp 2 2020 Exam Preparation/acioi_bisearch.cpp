#include<bits/stdc++.h>
using namespace std;
int arr[1001000];
//bool tf[1001000];
void findmin(int first,int last){
	int i,min=first;
	for(i=first;i<last;i++){
		if(arr[min]>arr[i]) min=i;
	}
	int temp=arr[first];
	arr[first]=arr[min];
	arr[min]=temp;
}
void binarysearch(int target,int right,int tc){
	int left=0,mid;
	while(left<=right){
		mid=left+(right-left)/2;
		if(arr[mid]==target){
			//tf[tc]=1;
			printf("Y");
			return;
		}
		if(arr[mid]<target){
			left=mid+1;
		}
		else{
			right=mid-1;
		}
	}
	//tf[tc]=0;
	printf("N");
	return;
}
main(){
	int arrsize,i,target,tc;
	scanf("%d",&arrsize);
	for(i=0;i<arrsize;i++) scanf("%d",&arr[i]);
	for(i=0;i<arrsize-1;i++){
		findmin(i,arrsize);
	}
	scanf("%d",&tc);
	for(i=0;i<tc;i++){
		scanf("%d",&target);
		binarysearch(target,arrsize-1,i);
	}
	//for(i=0;i<tc;i++){
	//	if(tf[i]) printf("Y");
	//	else printf("N");
	//}
}
