/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 18:40:45
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int N, n, m, i, add, ai, bi, r;
	double tmp;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		add = 1;
		while (cin >> n >> m) {
			if (n == 0 && m == 0)
				break;
			r = 0;
			for (ai = 1; ai <n - 1; ai++)
			{
				for (bi = ai + 1; bi < n; bi++)
				{
					tmp = (ai * ai + bi * bi + m) / ((double)ai * bi);
					//cout << "a=" << ai << "b=" << bi << "|" << tmp << "[" << (int)tmp << "]" << endl;;
					if (tmp == (int)tmp)
					{
						r++;
					}
				}
			}
			cout << "Case " << add++ << ": " << r << endl;
		}
		if (i!=N-1)
		{
			cout<<endl;
		}
	}
	return 0;
}