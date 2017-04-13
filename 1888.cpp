/*
* Name        : Evil Numbers.cpp
* @author     : thextroid
* Version     : 1
* Copyright   : Your copyright notice
* Description : Hello World in C++, Ansi-style#include <iostream>
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int st,s,i;
bool hasSix;
int main() {
	string N;
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
    while(cin>>N){
        hasSix = 0;
        i = N[0] == '-';
        for(s= st = 0; i < N.size(); ++i){
            s+=N[i] - '0';
            st = 10*st + N[i]-'0';
            st%=6;
            if(N[i] == '6') hasSix = 1;
        }
        if(hasSix && !st && s%6 == 0)        cout<<"EVIL"<<'\n';
        else            cout<<"GOOD"<<'\n';
    }
    return 0;
}