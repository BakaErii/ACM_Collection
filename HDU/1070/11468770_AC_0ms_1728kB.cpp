/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-08 19:05:01
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

struct smilk
{
	char name[101];
	int p;
	int v;
	double cp;
} milk[100];

bool cmp(smilk a, smilk b);

int main(void) {
	int T, N, i, j;
	while (cin >> T)
		for (i = 0; i < T; i++)
		{
			cin >> N;
			for (j = 0; j < N; j++)
			{
				scanf("%s", milk[j].name);
				scanf("%d %d", &milk[j].p, &milk[j].v);
				//此时cp是牛奶的性价比(价格/能喝的天数)
				if (milk[j].v > 1000)
					milk[j].cp = milk[j].p / 5.0;
				else
					milk[j].cp = (double) milk[j].p / (milk[j].v / 200);
			}
			sort(milk, milk + N, cmp);
			// for (j = 0; j < N; j++)
			// {
			// 	cout<<milk[j].name<<" "<<milk[j].p<<" "<<milk[j].v<<" "<<milk[j].cp<<endl;
			// }
			cout<<milk[0].name<<endl;
		}
	return 0;
}

bool cmp(smilk a, smilk b) {
	if (a.cp == b.cp)
		return a.v > b.v;
	return a.cp < b.cp;
}