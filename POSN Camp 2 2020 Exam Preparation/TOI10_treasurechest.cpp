//				27/4/2563
#include<bits/stdc++.h>
using namespace std;
int arr[200000000][4]; //2,3,5,7
int x,ans=INT_MIN,m,n,start,finish,anscount;
short int mul;
main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
	    scanf("%hd %d %d",&mul,&start,&finish);
	    if(mul==2){
	        for(int j=start;j<=finish;j++){
    	        arr[j][0]++;
    	    }
	    }
    	else if(mul==3){
	        for(int j=start;j<=finish;j++){
    	        arr[j][1]++;
    	    }
	    }
	    else if(mul==4){
	        for(int j=start;j<=finish;j++){
    	        arr[j][0]+=2;
    	    }
	    }
	    else if(mul==5){
	        for(int j=start;j<=finish;j++){
    	        arr[j][2]++;
    	    }
	    }
	    else if(mul==6){
	        for(int j=start;j<=finish;j++){
    	        arr[j][0]++;
    	        arr[j][1]++;
    	    }
	    }
	    else if(mul==7){
	        for(int j=start;j<=finish;j++){
    	        arr[j][3]++;
    	    }
	    }
	    else if(mul==8){
	        for(int j=start;j<=finish;j++){
    	        arr[j][0]+=3;
    	    }
	    }
	    else if(mul==9){
	        for(int j=start;j<=finish;j++){
    	        arr[j][1]+=2;
    	    }
	    }
	    else{
	        for(int j=start;j<=finish;j++){
    	        arr[j][0]++;
    	        arr[j][2]++;
    	    }
	    }
	}
	for(int i=0;i<n;i++){
		x=(arr[i][0]+1)*(arr[i][1]+1)*(arr[i][2]+1)*(arr[i][3]+1);
		if(ans<x){
			ans=x;
			anscount=1;
		}
		else if(ans==x){
			anscount++;
		}
	}
	printf("%d %d",ans,anscount);
}

