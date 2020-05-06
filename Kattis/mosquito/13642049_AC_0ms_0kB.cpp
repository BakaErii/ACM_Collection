#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i;
	int M, P, L, E, R, S, N;
	int addM,addP,addL;
	while (~scanf("%d %d %d %d %d %d %d", &M, &P, &L, &E, &R, &S, &N)) {
		addM = addP = addL = 0;
		for (i = 0; i < N; i++) {
			addM = P/S;
			addP = L/R;
			addL = M*E;
			M = addM;
			P = addP;
			L = addL;
		}
		printf("%d\n", M );
	}
	return 0;
}