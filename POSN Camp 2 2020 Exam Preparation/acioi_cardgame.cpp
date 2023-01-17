//				4/4/2563 NO LINKED LIST FK U Last Edited: 9/4/2563
#include<bits/stdc++.h>
using namespace std;
int pos[100005],ptr[100005];//Something that I use instead of FKing POINTERS
int n,m,previous,selected=1;
void create_circle(int n){
	for(int i=1;i<=n;i++){
		pos[i]=i;
		ptr[i]=i+1;
	}
	ptr[n]=1;
	/*for(int i=1;i<=n;i++){
		printf("pos%d ptr%d\n",pos[i],ptr[i]);
	}*/
}
main(){
	scanf("%d",&n);
	create_circle(n);
	for(int i=0;i<n-1;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			previous=selected;
			selected=ptr[selected];
		}
		if(i+1==n-1) printf("%d",pos[ptr[selected]]);
		ptr[previous]=ptr[selected];
		selected=previous;
	}
}
