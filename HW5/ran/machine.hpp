#include <vector>
#include <string>
#include <assert.h>
#include <iostream>
#include <sstream>
using namespace std;

#define FIRST_REGISTER (25)
#define LAST_REGISTER (8)

string toString(int num)
{
    ostringstream os;
	os << num;
    return os.str();
}

void my_assert(bool condition){
	#ifdef MY_DEBUG_FLAG
	if(!assertion) {
		cout << "assertion failed" << endl;
		CODE.printCodeBuffer();sdds
	}
	assert(condition);
	#endif
}


class RegisterManager{
	int currentReg; 
public:
	RegisterManager(){
		currentReg = FIRST_REGISTER;
	}
	string getCurrReg() {
		return "$" + toString(currentReg);
	}
	string getRegAndPromote(){
		string ret = getCurrReg();
		currentReg--;
		return ret;
	}
};

