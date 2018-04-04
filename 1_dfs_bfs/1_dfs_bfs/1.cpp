#include <iostream>

int main(){
	int n;
	std::cin >> n;
	bool x;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> x;
			if((i >= j) && x){
				std::cout << i + 1 << ' ' << j + 1 << '\n';	
			}		
		}
	}
	return 0;
}
