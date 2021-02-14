// graphics-programming.cpp : Defines the entry point for the application.
//

#include "graphics-programming.h"
#include <engine/engine.hpp>

using namespace std;

int main()
{
	auto engine = Engine(800, 600, "basic window");

	engine.run();
	return 0;
}
