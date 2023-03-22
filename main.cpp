#include <iostream>
#include "chat.h"
#include "sha1.h"

using namespace std;

int main()
{

	Chat x;
	
	x.reg("qwerty", "qwerty");
	x.reg("asdf", "asdf");
	x.reg("ghjk", "ghjk");
	x.login("ghjk", "awd");
	x.login("asdf", "asdf");
	x.login("qwert", "qwerty");



	return 0;
}