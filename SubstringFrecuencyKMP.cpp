#include<cstdio>
#include<ionumbeream>
const int MAXN=1000001;
int p[MAXN];
char number[MAXN],s[MAXN];
using namespace std;
int KMP(char *number,char *s){
        p[0]=-1;
        int cont=0;
        for(int i=1,j=-1;s[i];i++){
                while(j>=0 && s[j+1]!=s[i])
                        j=p[j];
                if(s[j+1]==s[i])
                        j++;
                p[i]=j;
        }
        for(int i=0,j=-1;number[i];i++){
                while(j>=0 && s[j+1]!=number[i])
                        j=p[j];
                if(s[j+1]==number[i]){
                        j++;
                        if(!s[j+1]){
                                cont++;
                                j=p[j];
                        }
                }
        }
        return cont;
}
int main(){
    int i=1,n;
        scanf("%d",&n);
        while(i<=n){
                scanf("%s %s",number,s);
                printf("Case %d: %d\n",i,KMP(number,s));
                i++;
        }
        return 0;
}
