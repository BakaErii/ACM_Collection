#include <iostream>

int main(void) {
	int n, a, b;
	std::cin >> n;
	while (n--) {
		std::cin >> a >> b;
		std::cout << a + b << std::endl;
	}
	return 0;
}