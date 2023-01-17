//		Knapsack
#include<bits/stdc++.h>
using namespace std;
vector<int> v,w;
long long int arr[105][100000];
long long max(long long a,long long b){
	if(a>b) return a;
	return b;
}
main(){
	//printf("WTF");
	int item,maxW,temp1,temp2;
	scanf("%d %d",&item,&maxW);
	for(int i=0;i<item;i++){
		scanf("%d %d",&temp1,&temp2);
		w.push_back(temp1);
		v.push_back(temp2);
	}
	/*for(int i=0;i<item;i++){
		scanf("%d",&temp1);
		v.push_back(temp1);
	}
	for(int i=0;i<item;i++){
		scanf("%d",&temp1);
		w.push_back(temp1);
	}*/
	for(int i=0;i<item;i++){
		for(int j=1;j<=maxW;j++){
			
			if(j>=w[i]){
				
				if(i==0) arr[i][j]=v[i];
				else arr[i][j]=max(arr[i-1][j],arr[i-1][j-w[i]]+v[i]);
				
			}
			else{
				if(i==0) arr[i][j]=0;
				else arr[i][j]=arr[i-1][j];
			}
		}
	}
	printf("%lld",arr[item-1][maxW]);
}
/*
10 165
92
   57
   49
   68
   60
   43
   67
   84
   87
   72
   23
   31
   29
   44
   53
   38
   63
   85
   89
   82
*/
/*
24 6404180
825594
1677009
1676628
1523970
943972
97426
69666
1296457
1679693
1902996
1844992
1049289
1252836
1319836
953277
2067538
675367
853655
1826027
65731
901489
577243
466257
369261
382745
799601
909247
729069
467902
44328
34610
698150
823460
903959
853665
551830
610856
670702
488960
951111
323046
446298
931161
31385
496951
264724
224916
169684
*/

