//				23/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[105];
int n,i,j,l;
int t[105][105];
int xk[105][105];
char temp[15];
string str,temp2;
void generate_ans(int i,int j){
	int k=xk[i][j];
	//printf("(%d,%d) (%d,%d)\n",i,k,k+1,j);
	str.insert(str.size(),"(");
	if(i!=k) generate_ans(i,k);
	else{
		str.insert(str.size(),"A");
		sprintf(temp,"%d",i);//
		temp2=temp;
		temp[0]=0;
		str.insert(str.size(),temp2);
	}
	str.insert(str.size(),"*");//MIDDLE
	if(k+1!=j) generate_ans(k+1,j);
	else{
		str.insert(str.size(),"A");
		sprintf(temp,"%d",j);//
		temp2=temp;
		temp[0]=0;
		str.insert(str.size(),temp2);
	}
	str.insert(str.size(),")");
}
main(){
	scanf("%d",&n);
	for(int a=0;a<=n;a++){
		scanf("%d",&arr[a]);
	}
	i=0;
	j=1;
	while(1){
		for(int k=i;k<j;k++){
			if(k==i||t[i][j]>t[i][k]+t[k+1][j]+(arr[i]*arr[k+1]*arr[j+1])){
				t[i][j]=t[i][k]+t[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]);
				xk[i][j]=k;
			}
		}
		//printf("(%d,%d) has selected A[%d,%d] * A[%d,%d]\n",i,j,i,xk[i][j],xk[i][j]+1,j);
		if(i==0&&j==n-1) break;
		if(j==n-1){
			i=0;
			j=1+(++l);
		}
		else{
			i++;
			j++;
		}
	}
	/*for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) printf("%d ",t[i][j]);
		printf("\n");
	}*/
	printf("%d\n",t[0][n-1]);
	generate_ans(0,n-1);
	//cout<<"((A0*(A1*A2))*(A3*A4))\n";
	cout<<str;
}
/*
16
12 
11
6
2
10
13
11
7
8 
13 
3 
10 
4 
8 
3 
5 
8
...
8
9
16
4 
1 
7 
2 
11 
4 
16
*/
