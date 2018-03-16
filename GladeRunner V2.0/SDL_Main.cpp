#include <iostream>
#include <string>
#include <Windows.h>
#include <SDL.h>
#include "GameSystem.h"

using namespace std;

int main(int argc, char **argv)
{

	GameSystem *GameSys = new GameSystem();

	GameSys->Loop();

	return 0;
}