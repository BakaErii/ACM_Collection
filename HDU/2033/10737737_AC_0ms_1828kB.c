#include <stdio.h>

int main(void)
{
	int line, i, h, m, s, h1, m1, s1, h2, m2, s2;
	scanf("%d",&line);
	for (i = 0; i < line; i++)
	{
		scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
		s = s1 + s2;
		m = m1 + m2;
		h = h1 + h2;
		if (s >= 60)
		{
			s = s - 60;
			m = m + 1;
		}
		if (m >= 60)
		{
			m = m - 60;
			h = h + 1;
		}
		printf("%d %d %d\n", h, m, s);
	}
	return 0;
}