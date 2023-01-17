//			21/3/2020
#include<bits/stdc++.h>
using namespace std;
long long  ans;
void mergeV(long long  arr[],long long  temp[],long long  left,long long  mid,long long  right){
	//printf("Merging with left(i and k)=%d right=%d mid(j)=%d",left,right,mid);
	long long  i=left,j=mid,k=left;
	while((i<=mid-1)&&(j<=right)){
		if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else { 
            temp[k++] = arr[j++]; 
            ans=ans+ (mid - i); 
		}
	}
	while(i<=mid-1) temp[k++]=arr[i++];
	while(j<=right) temp[k++]=arr[j++];
	for(i=left;i<=right;i++) arr[i]=temp[i]; 
	//printf(" Returning ans which is %d from 'mergeV'\n",ans);
	//return ans;
}
void mergesort(long long  arr[],long long  temp[],long long  left,long long  right){
	//printf("long long o func 'mergesort' with left=%d right=%d mid=%d\n",left,right,(left+right)/2);
	long long  mid;
	if(left>=right) {
		//printf("Returning ans which is %d from 'mergesort'\n",ans);
		return ;
	}
	mid=left+(right-left)/2;
	mergesort(arr,temp,left,mid);
	mergesort(arr,temp,mid+1,right);
	mergeV(arr,temp,left,mid+1,right);
}

int main(){
	long long  n;
	long long  arr[100010],temp[100010];
	scanf("%lld",&n);
	for(long long  i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	mergesort(arr,temp,0,n-1);
	printf("%lld",ans);
}
