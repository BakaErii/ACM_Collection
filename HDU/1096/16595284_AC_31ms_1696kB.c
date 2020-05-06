/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date    2018-10-22 21:48:32
 *
 */

#include <stdio.h>

int main(void) {
	int n, t, tmp, sum;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		if (t != 0)
			printf("%d\n\n", sum );
		else
			printf("%d\n", sum );
	}
	return 0;
}