#include <iostream>


int main() {
	
	std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Quit\n";	
	int choice;

	float a, b;
	float res;

	bool  is_running = true;

	while (is_running) {
		std::cout << "\n> ";


		// Taking integer input		
		std::cin >> choice;

		// Handling choices
		if (choice == 5) {
			is_running = false;
			break;
		}

		else if ((choice < 1) || (choice > 5)) {
			std::cout << "Invalid Choice\n";
			continue;
		}

		std::cout << "a: ";
		std::cin >> a;
		
		std::cout << "b: ";
		std::cin >> b;
		

		std::cout << '\t';

		switch (choice) {
			case 1:
				std::cout << a << " + " << b << '\n';
				res = a+b;
				break;

			case 2: 
				std::cout << a << " - " << b << '\n';
				res = a-b;
				break;

			case 3: 
				std::cout << a << " x " << b << '\n';
				res = a*b;
				break;

			case 4:
				std::cout << a << " / " << b << '\n';
				res = a/b;
				break;
		}

		std::cout << "=\t" << res << '\n';
	}
}