#include <iostream>
#include <vector>
#include <sstream>
#include <string>

class HashTable{
private:

	struct slot{
		char status; // N = not used, T = tombstone, O = occupied
		std::string key;
	};

	static const int size = 26;

	slot* table[size];

public:

	HashTable(){
		for(int i = 0; i < size; i++){
			table[i] = new slot;
			table[i]->status = 'N';
			table[i]->key = "";
		}
	}

	~HashTable(){
		for(int i = 0; i < size; i++){
			delete table[i];
		}
	}

	bool search(std::string target){
		int index = hash(target);
		for(int i = 0; i < size; i++){
			if(table[index]->status == 'O'){
				if(table[index]->key == target){
					return 1;
				}
			}
			index++;
			if(index == 26){
				index = 0;
			}
		}
		return 0;
	}

	bool insert(std::string key){

		if(!search(key)){
			int index = hash(key);
			for(int i = 0; i < size; i++){
				if(table[index]->status == 'O'){
					index++;
					if(index == 26){
						index = 0;
					}
				} else {
					table[index]->status = 'O';
					table[index]->key = key;
					return 1;
				}
			}
		} 
		return 0;
	}

	bool remove(std::string key){
		if(search(key)){
			int index = hash(key);
			for(int i = 0; i < size; i++){
				if(table[index]->key == key){
					table[index]->status = 'T';
					table[index]->key = "";
					return 1;
				}
				index++;
				if(index == 26){
					index = 0;
				}
			}
		}
		return 0;
	}

	// returns the last letter's position in the alphabet 0 based
	int hash(std::string key){
		return std::toupper(key[key.length() - 1]) - 65;
	}

	void print(){

		int index = 0;
		while(table[index]->status != 'O' && index < 25){
			index++;
		}
		if(table[index]->status == 'O'){
			std::cout << table[index]->key;
			index++;
			for(int i = index; i < size; i++){
				if(table[i]->status == 'O'){
					std::cout << " " << table[i]->key;
				}
			}
		}

		std::cout << std::endl;

		return;
	}
};

int main(){

	//get input and add it to vector of inserts and removes

	//getline of input
	std::string inputline;
	getline(std::cin, inputline);

	//seperate line into vector of strings
	std::istringstream iss(inputline);
	std::vector<std::string> input;
	std::string temp;
	while(iss >> temp){
		input.push_back(temp);
	}

	// input.push_back("Dg");
	// input.push_back("Dvqz");
	// input.push_back("Aixrpddzpl");
	// input.push_back("Awnq");
	// input.push_back("De");
	// input.push_back("Djyibf");
	// input.push_back("Dkmjfqwlt");
	// input.push_back("Akqtp");
	// input.push_back("Dlp");
	// input.push_back("Dkcyufdqm");
	// input.push_back("Dlimklf");
	// input.push_back("Dtgyg");
	// input.push_back("Atnhcvpfd");
	// input.push_back("Arpzlkvsh");
	// input.push_back("Dwshtdgm");
	// input.push_back("Dbk");
	// input.push_back("Ac");
	// input.push_back("Dumon");
	// input.push_back("Dvyt");
	// input.push_back("Dtn");
	// input.push_back("Dh");
	// input.push_back("Aj");
	// input.push_back("Dtgngcwkuz");

	HashTable h;

	for(int i = 0; i < input.size(); i++){
		if(input[i][0] == 'A'){
			h.insert(input[i].substr(1, input[i].length() - 1));
		} else if(input[i][0] == 'D'){
			h.remove(input[i].substr(1, input[i].length() - 1));
		}
	}

	h.print();

	return 0;
}