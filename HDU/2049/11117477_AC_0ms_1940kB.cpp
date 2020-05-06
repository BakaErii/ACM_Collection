/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-18 12:35:50
 *
 */

#include <iostream>

int main(void) {
	int c, n, m, i, times;
	//推导出错排公式的数组
	unsigned long long array[20], tmp1, tmp2, r;
	array[0] = 0;
	array[1] = 1;
	for (i = 0; i < 19; i++)
	{
		array[i + 2] = (i + 2) * (array[i + 1] + array[i]);
	}
	// for (i = 0; i < 20; i++)
	// {
	// 	std::cout << array[i]<<std::endl;
	// }
	//读入数据
	std::cin >> c;
	while (c--) {
		std::cin >> n >> m;
		//从N中选择M个元素
		//先判断相乘的次数 防止爆ull
		if (n == m)
		{
			//两数相等 结果为1 直接输出
			std::cout << array[m - 1] << std::endl;
			continue;
		} else {
			if (m < n / 2)
			{
				times = m;
			} else {
				times = n - m;
			}
		}
		//初始化变量并组合排序
		tmp1 = n;
		tmp2 = 1;
		//实际执行次数去掉第一次 i从1开始
		for (i = 1; i < times ; i++)
		{
			tmp1 *= (n - i);
			tmp2 *= (i + 1);
		}
		r = tmp1 / tmp2;
		r *= array[m - 1];
		std::cout << r << std::endl;
	}
	return 0;
}