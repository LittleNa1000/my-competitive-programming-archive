//		Knapsack
#include<bits/stdc++.h>
using namespace std;
vector<int> v,w;
long long int opt(int i,int j){
	//printf("HELLO");
	if(i<0||j==0) return 0;
	if(j>=w[i]) {
		return max(opt(i-1,j),opt(i-1,j-w[i])+v[i]);
	}
	return opt(i-1,j);
}
main(){
	int item,maxW,temp1,temp2;
	scanf("%d %d",&item,&maxW);
	for(int i=0;i<item;i++){
		scanf("%d",&temp1);
		v.push_back(temp1);
	}
	for(int i=0;i<item;i++){
		scanf("%d",&temp1);
		w.push_back(temp1);
	}
	
	printf("%lld",opt(item-1,maxW));
}
/*
int a=opt(i-1,j),b=opt(i-1,j-w[i])+v[i];
		if(a>=b){
			printf("Choose Item #%d for Knapsack\n",i);
			return a;
		}
		else{
			printf("Don't choose item #%d\n",i);
			return b;
		}
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

