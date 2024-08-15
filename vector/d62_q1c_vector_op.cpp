#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

auto main(int argc, char *argv[]) -> signed {
	int q;
	std::cin >> q;
	std::vector<int> v;
	
	while(q--) {
		std::string opr;
		std::cin >> opr;
		if(opr == "pb") {
			int x;
			std::cin >> x;
			v.emplace_back(x);
		}
		else if(opr == "sa") {
			std::sort(v.begin(), v.end());
		}
		else if(opr == "sd") {
			std::sort(v.begin(), v.end(), std::greater<int> ());
		}
		else if(opr == "r") {
			std::reverse(v.begin(), v.end());
		}
		else {
			int pos;
			std::cin >> pos;
			v.erase(v.begin() + pos);
		}
	}
	for(auto val: v) {
		std::cout << val << " ";
	}
	std::cout << std::endl;
}
