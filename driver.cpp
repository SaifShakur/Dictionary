//Saif Shakur

#include<iostream>
#include<string>
#include"Dictionary.h"

int main(){

	std::string str = "dcgfehc";

	Dictionary<char,unsigned short> dict;

	std::cout << "Testing IsEmpty(): ";
	if(dict.IsEmpty()) std::cout << "Works!" << std::endl;	//Message should appear on the screen

	for(int i = 0; i< str.size(); i++){

		if(dict.Count(str[i]) == 0) 
			dict[str[i]] = 1;
		else 
			dict[str[i]] += 1;
	}
	
	

	std::cout << "Testing Size(): " << dict.Size() << std::endl; 		//Should show 6
	std::cout << "Testing Height(): " << dict.Height() << std::endl;	//Should show 3
	std::cout << std::endl;

	std::cout << "Testing operator []: the letter \"d\" happens: " << dict['d'] << " time(s)." << std::endl; //Should show 1
	std::cout << std::endl;

	std::cout << "Testing operator []: the letter \"c\" happens: " << dict['c'] << " time(s)." << std::endl; //Should show 2
	std::cout << std::endl;

	std::cout << "Testing Remove(const KeyType&): Removing \"g\": ";
	dict.Remove('c');	//Testing removing a node with 2 children.
	if(dict.Count('c') == 0)
		std::cout << "Works!" << std::endl;
	std::cout << std::endl;

	std::cout << "Size: " << dict.Size() << " ";
	std::cout << "Height: " << dict.Height() << std::endl;	//Size: 5. Height: 2

	std::cout<<"The letter d happened "<<dict['d']<<" times" << std::endl;	//Should show 1

	if(dict.Count('g') == 0) 
		std::cout<<"Now the letter 'g' is absent" << std::endl; 	//Message should appear on the screen

	std::cout << std::endl;

	std::cout << "Testing Balance(): " << std::endl;
	dict.Balance();
	std::cout << "Size: " << dict.Size() << " Height: " << dict.Height() << std::endl;	//Size: 5. Height: 2.

	std::cout << std::endl;

	std::cout << "Testing Clear(): " << std::endl;
	dict.Clear();
	std::cout << "Size: " << dict.Size() << " Height: " << dict.Height() << std::endl;	//Size: 0. Height: 0

	std::cout << std::endl;

	return 0;
}
