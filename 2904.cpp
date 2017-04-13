#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char num[53];
int 	a[53],diff[53],n,m;
void add(int *diff,int *a){
	int carry=0,i,temp;
	for( i = 0 ;i<n;++i){
		temp = diff[i]+a[i] + carry;
		diff[i] = (temp)%10;
		carry = (temp)/10;
	}
	for( i =  n ;carry!=0;i++){
		temp = diff[i]+carry;
		diff[i] = temp%10;
		carry = temp/10;
	}
}
void print(int *N){
	int i;
	for ( i = 52; N[i]==0; --i);
	while(i>=0)printf("%d", N[i--]);
	printf("\n");
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	memset(diff,0,sizeof(diff));
	int t;
	scanf("%d",&t);
	m=0;
	while(t--){
		scanf("%s",num);
		n = strlen(num);
		for(int i = 0 ;i<n;i++)
			a[n-i-1]= num[i]-'0';
		add(diff,a);
	}
		print(diff);
	
	return 0;
}