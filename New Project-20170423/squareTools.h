void printSquare(std::vector<int> square){
//	for(int i = 0; i < square.size(); i++) square[i] = square[i]*square[i];
	std::cout << square[0] << "² | " << square[1] << "² | " << square[2] << "²\n";
	std::cout << square[3] << "² | " << square[4] << "² | " << square[5] << "²\n";
	std::cout << square[6] << "² | " << square[7] << "² | " << square[8] << "²\n";
	
	std::cout << "Sum = " << square[0] + square[1] + square[2] << "\n" << std::endl;
}

bool verify(std::vector<int> square){
	bool horizontal = false, vertical = false, diagonal = false;
	//for(int i = 0; i < square.size(); i++) square[i] = square[i]*square[i];

	int sum = square[0] + square[1] + square[2];
	
	if(square[3] + square[4] + square[5] == sum){//horizontal
		if(square[6] + square[7] + square[8] == sum){
			horizontal = true;
		}
	}
	
	if(square[0] + square[3] + square[6] == sum){//vertical
		if(square[1] + square[4] + square[7] == sum){
			if(square[2] + square[5] + square[8] == sum){
				vertical = true;
			}
		}
	}
	
	if(square[0] + square[4] + square[8] == sum){//diagonal
		if(square[2] + square[4] + square[6] == sum){
			diagonal = true;
		}
	}
	
	if(vertical && horizontal && diagonal){
		return true;
	}
	else{
		return false;
	}
}