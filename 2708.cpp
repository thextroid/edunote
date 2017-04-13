#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int morse[2223];
int dig(int n){
	int c=0;
	while(n){
		c++;
		n/=10;
	}
	return c;
}
int main(){
	int dec[5];
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	morse[12] 	= 'A';morse[(int)'A'] 	= 12;
	morse[2111] 	= 'B';morse[(int)'B'] 	= 2111;
	morse[2121] 	= 'C';morse[(int)'C'] 	= 2121;
	morse[211] 	= 'D';morse[(int)'D'] 	= 211;
	morse[1] 		= 'E';morse[(int)'E'] 	= 1;
	morse[1121] 	= 'F';morse[(int)'F'] 	= 1121;
	morse[221] 	= 'G';morse[(int)'G'] 	= 221;
	morse[1111] 	= 'H';morse[(int)'H'] 	= 1111;
	morse[11] 	= 'I';morse[(int)'I'] 	= 11;
	morse[1222] 	= 'J';morse[(int)'J'] 	= 1222;
	morse[212] 	= 'K';morse[(int)'K'] 	= 212;
	morse[1211] 	= 'L';morse[(int)'L'] 	= 1211;
	morse[22] 	= 'M';morse[(int)'M'] 	= 22;
	morse[21] 	= 'N';morse[(int)'N'] 	= 21;
	morse[222] 	= 'O';morse[(int)'O'] 	= 222;
	morse[1221] 	= 'P';morse[(int)'P'] 	= 1221;
	morse[2212] 	= 'Q';morse[(int)'Q'] 	= 2212;
	morse[121] 	= 'R';morse[(int)'R'] 	= 121;
	morse[111] 	= 'S';morse[(int)'S'] 	= 111;
	morse[2] 		= 'T';morse[(int)'T'] 	= 2;
	morse[112] 	= 'U';morse[(int)'U'] 	= 112;
	morse[1112] 	= 'V';morse[(int)'V'] 	= 1112;
	morse[122] 	= 'W';morse[(int)'W'] 	= 122;
	morse[2112] 	= 'X';morse[(int)'X'] 	= 2112;
	morse[2122] 	= 'Y';morse[(int)'Y'] 	= 2122;
	morse[2211] 	= 'Z';morse[(int)'Z'] 	= 2211;
	morse[1122] 	= '_';morse[(int)'_'] 	= 1122;
	morse[2221] 	= '.';morse[(int)'.'] 	= 2221;
	morse[1212] 	= ',';morse[(int)','] 	= 1212;
	morse[2222] 	= '?';morse[(int)'?'] 	= 2222;
	char s[1001],str[4004];
	int d[1001],n,x,ii,k,j;
	while(scanf("%s",s)!=EOF){
		n = strlen(s);
		k=0;
		for(int i = 0 ;i<n;++i){
			d[n-1-i] = dig(morse[s[i]]);
			x = morse[s[i]];
			j=0;
			while(x){
				dec[j++]= x%10;
				x/=10;
			}
			while(j>0)
				str[k++] = dec[--j]+'0';
		}
		k=0;
		for(int i = 0 ;i<n;++i){
			x = d[i];
			ii=0;
			while(x--)
				ii = ii*10 + (str[k++]-'0');
			printf("%c", morse[ii]);
		}
		printf("\n");
	}
	return 0;
}