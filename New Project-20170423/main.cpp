#include <iostream>
#include <vector>
#include <algorithm>
#include "squareTools.h"

using namespace std;
int repeatedIndex(vector<int> arr){
	vector<int> sorted = arr;
	std::sort(sorted.begin(), sorted.end());
	
	int duplicate = -1; 
	
	for(int i = 0; i < sorted.size()-1; i++){
		if(sorted[i] == sorted[i+1]) duplicate = sorted[i];
	}
	
	if(duplicate == -1) return arr.size()-1;
	
	for(int i = arr.size()-1; i >= 0; i--){
		if(arr[i] == duplicate) return i;
	}
}

bool isUnique(vector<int> arr){
	std::sort(arr.begin(), arr.end());
	
	for(int i = 0; i < arr.size()-1; i++){
		if(arr[i] == arr[i+1]) return false;
	}
	
	return true;
}


bool increment(vector<int> &square, int offset = 0, int start = 1, int limit = 9){
	square[square.size()-1-offset]++;
	for(int i = 1; i < square.size()-offset; i++){
		if(square[square.size()-i-offset] > limit){
			square[square.size()-i-offset] = start;
			square[square.size()-i-1-offset]++;
		}
	}
	
	if(square[0] > limit) return false;
	else return true;
}

int main(){
	vector<int> square;
	for(int i = 1; i <= 9; i++) square.push_back(i);
	
	
	int offsetIndex = 8;
	while(increment(square, 8-offsetIndex, 1, 100)){
		offsetIndex = repeatedIndex(square);
		if(isUnique(square)){
			if(verify(square)){
				printSquare(square);
			}
		}
	}
	return 0;
}