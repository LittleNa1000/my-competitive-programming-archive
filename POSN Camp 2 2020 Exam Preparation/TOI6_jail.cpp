//				4/4/2563 NO LINKED LIST FK U
#include<bits/stdc++.h>
using namespace std;
int data[1000005],ptr[1000005];//Something that I use instead of FKing POINTERS
int n,m,previous,selected;
void create_circle(int n){
	for(int i=0;i<n;i++){
		data[i]=i;
		ptr[i]=i+1;
	}
	ptr[n-1]=0;
}
main(){
	scanf("%d %d",&n,&m);
	create_circle(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			previous=selected;
			selected=ptr[selected];
		}
		if(data[selected]==0) data[selected]=n;
		printf("%d ",data[selected]);
		ptr[previous]=ptr[selected];
	}
}
