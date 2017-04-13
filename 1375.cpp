#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b)for (int i = (a); i < (b); ++i)
using namespace std;
char reverse['z'];
void render(string& s){
	FOR(i,0,s.size())
		if(s[i]=='0')
			s[i]='O';
}
bool isPalindrome(string& s){
	int t = s.size();
	FOR(i,0,t/2)
		if(s[i]!=s[t-i-1])
			return false;
	return true;
}
bool isMirrored(string& s){
	char tx[s.size()+2];
	s.copy(tx,s.size());
	tx[s.size()]='\0';
	int t = strlen(tx);
	FOR(i,0,t){
		if(reverse[tx[i]]!=0){
			tx[i] = reverse[tx[i]];
		}
		else{
			tx[i] = ' ';// note: <space> if not have reverse
		}
	}
	FOR(i,0,t/2)
		swap(tx[i],tx[t-i-1]);
	return s.compare(tx)==0;
}
int main(){
	memset(reverse,0,sizeof reverse);
	reverse['A']='A';reverse['E']='3';reverse['H']='H';
	reverse['I']='I';reverse['J']='L';reverse['L']='J';
	reverse['M']='M';reverse['O']='O';reverse['T']='T';
	reverse['U']='U';reverse['V']='V';reverse['W']='W';
	reverse['X']='X';reverse['Y']='Y';reverse['Z']='5';
	reverse['1']='1';reverse['2']='S';reverse['3']='E';
	reverse['5']='Z';reverse['8']='8';
	string str;
	while(cin>>str){
		render(str);
		bool isPal = isPalindrome(str);
		bool isMir = isMirrored(str);
		if(isPal && isMir){
			printf("%s -- is a mirrored palindrome.\n", &str[0]);
		}
		else if(isPal){
			printf("%s -- is a regular palindrome.\n", &str[0]);
		}
		else if(isMir){
			printf("%s -- is a mirrored string.\n", &str[0]);
		}
		else{
			printf("%s -- is not a palindrome.\n", &str[0]);
		}
		printf("\n");
	}
	return 0;
}
