//				27/4/2563
#include<bits/stdc++.h>
using namespace std;
double book_sold,result,mn;
int maincost;
unsigned char i,ans_i;
short int j,ans_j;
double roi(){
	book_sold=(100-(0.8569*exp(0.09*(i-100))))*j/100;
	return (book_sold*i)-maincost-(j*(100-((j-1000)/500)));
}
main(){
	scanf("%d",&maincost);
	for(i=74;i<=144;i++){
		for(j=1000;j<=15000;j+=500){
			result=roi();
			//printf("%d %hd %.2lf\n",i,j,result);
			if(result>0){
				if(result<mn||mn==0){
					mn=result;
					ans_i=i;
					ans_j=j;
				}
			}
		}
	}
	printf("%d\n%hd\n%.2lf",ans_j,ans_i,mn);
}
