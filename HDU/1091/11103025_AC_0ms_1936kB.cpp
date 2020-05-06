#include <iostream>

int main(void) {
	int a, b;
	while (std::cin >> a >> b && !(a == 0 && b == 0)) {
		std::cout << a + b << std::endl;
	}
	return 0;
}