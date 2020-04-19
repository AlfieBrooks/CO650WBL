//Used to hide the localtime() deprecation warning
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "Game.h"
#include "GameComponent.h"
#include "DrawableGameComponent.h"

using namespace std;

void Initialise() {
	cout << "Initialising game" << endl;
};

void Terminate() {
	cout << "Terminating game" << endl;
};

int main() {
	Game game(2);

	//Create instances of 2 new entities
	GameComponent *GC = new GameComponent();
	DrawableGameComponent *DGC = new DrawableGameComponent(0, 0);

	//Assign the stand alone functions to the Game instance
	game.SetInitialise(*Initialise);
	game.SetTerminate(*Terminate);

	//Add the Entities
	game.Add(GC);
	game.Add(DGC);

	game.Run();

	return 0;
}
