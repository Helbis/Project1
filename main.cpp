#include <iostream>
#include "./menu.hpp"
#include "./university.hpp"
#include "./student.hpp"
#include "./title.hpp"


int main(int argc, char *argv[]){
	std::string str = "";
	str.insert(0, 20, '='); 

	std::cout << str << '\n';


	return 0;
}
