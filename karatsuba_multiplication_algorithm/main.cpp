/*
Implementation of School Sum, School Subtraction (for use in Karatsuba only (a > b)),
and Karatsuba Multiplication. Functions work with any length string.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>

std::string schoolSum(std::string a, std::string b, int B){

	std::string big;
	std::string small;

	if(a.length() > b.length()){
		big = a;
		small = b;
	} else {
		big = b;
		small = a;
	}

	std::string padding(big.length() - small.length(), '0');

	small = "0" + padding + small;
	big = "0" + big;

	int carry = 0;
	std::string result = "";

	for(int i = big.length()-1; i >= 0; i--){

		int sum = (int)(big[i] - '0') + (int)(small[i] - '0') + carry;
		
		if(sum >= B){
			carry = 1;
			sum = sum - B;
		} else {
			carry = 0;
		}

		result = std::to_string(sum) + result;

	}

	result.erase(0, std::min(result.find_first_not_of('0'), result.size()-1));

	return result;
}

std::string schoolSub(std::string a, std::string b, int B){

	//possible cause for errors if value has same digits but a < b
	//assuming a > b all should be good

	std::string padding(a.length() - b.length(), '0');

	b = "0" + padding + b;
	a = "0" + a;

	int borrow = 0;
	std::string result = "";

	for(int i = a.length()-1; i >= 0; i--){

		int sub = (int)(a[i] - '0') - borrow - (int)(b[i] - '0');
		
		if(sub < 0){
			borrow = 1;
			sub = sub + B;
		} else {
			borrow = 0;
		}

		result = std::to_string(sub) + result;

	}

	result.erase(0, std::min(result.find_first_not_of('0'), result.size()-1));

	return result;
}

std::string karatsubaProduct(std::string a, std::string b, int B){

	std::string big;
	std::string small;

	if(a.length() >= b.length()){
		big = a;
		small = b;
	} else {
		big = b;
		small = a;
	}



	int n = big.length();
	int k = floor(n/2);

	// std::cout << big << " : " << small << " : " << std::endl;

	if(n <= 3){

		int iBig = std::stoi(big, nullptr, B);
		int iSmall = std::stoi(small, nullptr, B);

		int iProd = iBig * iSmall;
		
		std::string result = "";
		std::string bases = "0123456789";

		while(iProd > 0){
			result = bases[iProd % B] + result;
			iProd /= B;
		}

		if(result.length() == 0){
			result = "0";
		}

		return result;
	}

	std::string padding(big.length() - small.length(), '0');

	small = padding + small;

	std::string a1 = big.substr(0, n - k);
	std::string a0 = big.substr(n - k);
	std::string b1 = small.substr(0, n - k);
	std::string b0 = small.substr(n - k);


	
	std::string p2 = karatsubaProduct(a1, b1, B); //p1
	std::string p1 = karatsubaProduct(schoolSum(a1, a0, B), schoolSum(b1, b0, B), B);
	std::string p0 = karatsubaProduct(a0, b0, B); //p0

	//std::cout << p2 << " : " << p1 << " : " << p0 << std::endl;

	std::string b2k0s(2 * k, '0');
	std::string bk0s(k, '0');

	std::string product = schoolSum(p2 + b2k0s, schoolSum(schoolSub(p1, schoolSum(p2, p0, B), B) + bk0s, p0, B), B);

	return product;
}

int main(){

	std::string I1;
	std::string I2;
	int B;
	std::cin >> I1;
	std::cin >> I2;
	std::cin >> B;

	std::cout << schoolSum(I1, I2, B) << " ";
	std::cout << karatsubaProduct(I1, I2, B) << std::endl;

	return 0;
}