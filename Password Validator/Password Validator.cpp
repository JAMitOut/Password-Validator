#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

using namespace std;

bool valid_password(const string& password){
	//Rule 1: Must be 8 Characters Long
	if (password.size() < 8) {
		cout << "Password: \"" << password
			 << "\" The password must be 8 characters long." << endl;
		return false;
	}

	//Rule 2/3/4
	short num_count = 0;
	short upper_char = 0;
	short special_char = 0;

	for (char ch : password) {
		if (isdigit(ch)) num_count++;
		if (isupper(ch)) upper_char++;
		if (ispunct(ch)) special_char++;
	}

	if (num_count < 2) {
		cout << "Password: \"" << password
			 << "\" The password must contain at least 2 numbers" << endl;
		return false;
	}
	if (upper_char < 1) {
		cout << "Password: \"" << password
			 << "\" The password must contain at least 1 Upper case Letter" << endl;
		return false;
	}
	if (special_char < 1) {
		cout << "Password: \"" << password
			 << "\" The password must contain at least 1 special character" << endl;
		return false;
	}

	cout << "Password: \"" << password << "\" Valid" << endl;
	return true;
}

int main() {
	assert(!valid_password("Ab1!")); //Too Short
	assert(!valid_password("Abcdefg!")); //Missing Numbers
	assert(!valid_password("Abcdefg1!")); //Not Enough Numbers
	assert(!valid_password("abcdefg12!")); //Missing an Uppercase
	assert(!valid_password("Abcdefg12")); //Missing a Special Character
	assert(valid_password("Abcdefg12!")); //Valid Password

	cout << "\nAll tests Passed the Password Validator\n";

	return 0;
}
