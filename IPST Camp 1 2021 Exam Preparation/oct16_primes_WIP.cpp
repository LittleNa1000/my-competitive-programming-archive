//      10/2/2564 or Another Prime num algo
// check: placing 4th digit must not make 5th digit an even number
#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int n,k,sum;
int arr[5][5];
bool valid(int num1,int num2,int num3,int num4,int num5){
    sum=(num1*10000)+(num2*1000)+(num3*100)+(num4*10)+(num5*1);
    for(int i=2;i<=sqrt(sum);++i){
        if(sum%i==0) return 0;
    }
    return 1;
}
void print(){
    for(int i=0;i<5;++i){
        for(int j=0;j<5;++j){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n"); return ;
}
bool chkvalid(int i,int j){
    int sum_i=n-(arr[0][j]+arr[1][j]+arr[2][j]+arr[3][j]+arr[4][j]);
    int sum_j=n-(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]+arr[i][4]);
    int sum_di1=INT_MAX;
    int sum_di2=INT_MAX;
    if(i==j){
        int sum_di1=n-(arr[0][0]+arr[1][1]+arr[2][2]+arr[3][3]+arr[4][4]);
    }
    else if(i+j==4){
        int sum_di2=n-(arr[0][4]+arr[1][3]+arr[2][2]+arr[3][1]+arr[4][0]);
    }
    if(i==4){
        if(!valid(arr[0][j],arr[1][j],arr[2][j],arr[3][j],arr[4][j])||sum_i!=0){
            return 0;
        }
    }
    if(j==4){
        if(!valid(arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4])||sum_j!=0){
            return 0;
        }
    }
    if(i==4&&j==0){
        if(!valid(arr[4][0],arr[3][1],arr[2][2],arr[1][3],arr[0][4])||sum_di2!=0){
            return 0;
        }
    }
    if(i==4&&j==4){
        if(!valid(arr[0][0],arr[1][1],arr[2][2],arr[3][3],arr[4][4])||sum_di1!=0){
        }
        else{
            print();
        }
        return 0;
    }
    return 1;
}
void f(int i,int j){
    if(j==5){
        j=0;
        ++i;
    }
    
    
    int sum_i=n-(arr[0][j]+arr[1][j]+arr[2][j]+arr[3][j]+arr[4][j]);
    int sum_j=n-(arr[i][0]+arr[i][1]+arr[i][2]+arr[i][3]+arr[i][4]);
    int sum_di1=INT_MAX;
    int sum_di2=INT_MAX;
    if(i==j){
        int sum_di1=n-(arr[0][0]+arr[1][1]+arr[2][2]+arr[3][3]+arr[4][4]);
    }
    if(i+j==4){
        int sum_di2=n-(arr[0][4]+arr[1][3]+arr[2][2]+arr[3][1]+arr[4][0]);
    }
    //print();
    if(arr[0][0]==1&&arr[0][1]==1&&arr[0][2]==3&&arr[0][3]==5&&arr[0][4]==1){
        Sleep(500);
        print();
    }
    
    //Sleep(500);
    //printf("(%d,%d) %d %d %d %d \n",i,j,sum_i,sum_j,sum_di1,sum_di2);
    if(i==0&&j==4) return f(i,j+1);
    for(int x=0;x<=9;++x){
        if((i==0||j==0)&&x==0) continue ;
        if(x>sum_i||x>sum_j||x>sum_di1||x>sum_di2) return ;
        arr[i][j]=x; // can do better than this (5th must be forced)
        // if(arr[0][0]==1&&arr[0][1]==1&&arr[0][2]==3&&arr[0][3]==5&&arr[0][4]==1&&arr[1][0]==1&&arr[1][1]==4){
        //     Sleep(500);
        //     print();
        // }
        if(!chkvalid(i,j)) continue ;
        f(i,j+1);
        arr[i][j]=0;
    }
}
int main(){
    scanf("%d %d",&n,&k);
    arr[0][4]=k;
    f(0,0);
}