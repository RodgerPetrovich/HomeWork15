#include <iostream>
#include "chat.h"
#include "sha1.h"

using namespace std;

int main()
{

	Chat x;
	
	x.reg("robert", "qwerty");
	x.reg("bob", "password11");
	x.reg("jack", "jack123");
	x.reg("roawbert", "qwerty");
	x.reg("bdgrob", "password11");
	x.reg("jfyjack", "jack123");
	x.reg("roawbjert", "qwerty");
	x.reg("bogukb", "password11");
	x.reg("jaserck", "jack123");
	x.reg("rohuljilbert", "qwerty");
	x.reg("bdrhgukob", "password11");
	x.reg("jagfykjck", "jack123");
	x.reg("robawgdert", "qwerty");
	x.reg("boftjjkyb", "password11");
	x.reg("jasaefrghck", "jack123");
	x.reg("bdrhgukob", "password11");
	x.reg("robguykhert", "qwerty");
	x.reg("b456yfdob", "password11");
	x.reg("jacsf43k", "jack123");
	x.deleteUser("bogukb");
	x.deleteUser("bogukb");
	
	x.showUsers();
	

	return 0;
}