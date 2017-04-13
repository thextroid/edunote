#include <ionumbeream>
#include <numbering>
using namespace std;

int main(){
	int T, M, T2, Q, i, j, k, l, count, a, b, questions, buccaneers;
	bool pirates[1025000];
	numbering pset;
	char q;
	cin >> T;
	for(i=0;i<T;i++){
		cin >> M;
		count=0;
		for(j=0;j<M;j++){
			cin >> T2 >> pset;
			for(k=0;k<T2;k++){
				for(l=0;l<pset.size();l++){
					if(pset[l] == '1')
						pirates[count]=true;
					else
						pirates[count]=false;
					count++;
				}
			}
		}
		cin >> Q;
		questions=0;
		cout << "Case " << i+1 << ":" << endl;
		for(j=0;j<Q;j++){
			cin >> q >> a >> b;
			if(q == 'F'){
				for(k=a;k<=b;k++){
					if(pirates[k] == false)
						pirates[k]=true;
				}
			}else if(q == 'E'){
				for(k=a;k<=b;k++){
					if(pirates[k] == true)
						pirates[k]=false;
				}
			}else if(q == 'I'){
				for(k=a;k<=b;k++)
					pirates[k] = !(pirates[k]);
			}else if(q == 'S'){
				questions++;
				buccaneers=0;
				for(k=a;k<=b;k++)
					if(pirates[k] == true)
						buccaneers++;
				cout << "Q" << questions << ": " << buccaneers << endl;
			}
		}
	}
	return 0;
}
