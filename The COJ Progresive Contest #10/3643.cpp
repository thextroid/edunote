#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define FOR(i,a,b)for(int i =a ; i < b;++i)
#define FORba(i,b,a)for(int i = b ; i >=a;--i)
#define MAX 450
#define N 100003
using namespace std;
int v[MAX],res[N+1];
int main(){
	int n,temp,m,ans,diff;
	fill(res,res+N+1,10);
	res[0]=v[0]=0;
	FOR(i,1,MAX){
		v[i]=v[i-1]+i;
		res[v[i]] = 1;
	}
	FOR(i,1,MAX-2)printf("%d ", v[i]);
	printf("\n");
	// int *it = lower_bound(v,v+MAX,N>>1);
	// m = it-v;
	res[53]=res[398]=res[644]=res[938]=res[986]=res[1250]=res[1505]=res[1545]=res[1667]=res[1829]=res[1910]=res[2000]=res[2255]=res[3155]=res[3560]=res[3890]=res[4535]=res[5237]=res[5975]=res[6476]=res[6503]=res[7643]=res[8432]=res[9890]=res[10745]=res[10980]=res[11654]=res[12818]=res[13544]=res[15833]=res[16238]=res[16760]=res[17093]=res[20018]=res[20543]=res[20573]=res[25040]=res[26045]=res[27833]=res[30380]=res[36413]=res[39425]=res[42944]=res[46223]=res[68018]=res[78449]=res[83273]=res[94298]=4;
	FOR(i,1,MAX){
		FOR(j,i,MAX){
			if(v[i]+v[j]>N)break;
			FOR(k,j,MAX){
				if(v[i]+v[j]+v[k]>N)break;
				// if(v[i]+v[j]+v[k]==100000)printf(">>(%d) %d %d %d\n",100000, v[i],v[j],v[k]);
				// if(v[i]+v[j]+v[k]==53)printf(">>(%d) %d %d %d\n", 53,v[i],v[j],v[k]);
				res[v[i]+v[j]+v[k]]=min(res[v[i]+v[j]+v[k]],3);
			}
		}
	}
	FOR(i,1,MAX){
		FOR(j,i,MAX){
			if(v[i]+v[j]>N)break;
			// if(v[i]+v[j]==53)printf(":: %d %d\n", v[i],v[j]);
			res[v[i]+v[j]]=min(res[v[i]+v[j]],2);
		}
	}
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while( scanf("%d",&n) > 0 ){
		printf("%d\n", res[n]);
	}
	return 0;
}