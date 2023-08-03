#include <iostream>
#include <vector>

void display(std::vector<std::vector<int>> vec) {
	for (std::vector<int> vect1D : vec)
	{
		for (int x : vect1D)
		{
			std::cout << x << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {


	std::vector<std::vector<int>> r{
		{2,4},
		{-1,3}
	};



	std::vector<std::vector<int>> p{ // u matrix
		{4,1},
		{1,0}
	};

	std::vector<std::vector<int>> q{ // u^-1 matrix
		{0,1},
		{1,-4}
	};


	std::vector<std::vector<int>> res_r; // r'ij




	std::cout << "matrix r:\n";
	display(r);



	std::cout << "r'ij:\n";
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			int res(0);
			std::cout << "r'" << j + 1 << i + 1 << " = ";
			for (size_t a = 0; a < 2; ++a) {
				for (size_t b = 0; b < 2; ++b) {
					res += p[a][i] * q[j][b] * r[b][a];
					(b != 1 || a != 1) ? std::cout << p[a][i] << " * " << q[j][b] << " * " << r[b][a] << " + " : std::cout << p[a][i] << " * " << q[j][b] << " * " << r[b][a];
				}
			}
			std::cout << " = " << res << std::endl;
			res_r.push_back(std::vector<int>());
			res_r[j].push_back(res);
		}
	}
	std::cout << std::endl;

	std::cout << "matrix r'ij:\n";
	display(res_r);

	

	return 0;
}
