#include "machine.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


#ifndef CODE
#define CODE (CodeBuffer::instance())
#endif

RegisterManager manager;


int main(){
	
	std::cout << manager.getRegAndPromote() << std::endl;d
	std::cout << manager.getRegAndPromote() << std::endl;
}

