#pragma once
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include "GameComponent.h"

using namespace std;

class Game {
public:
	Game(int mComponents) {
		this->maxComponents = mComponents;
	};
	void Add(GameComponent* gameComponent);
	void Run();
	void SetInitialise(void(*init)());
	void SetTerminate(void(*term)());
private:
	int componentCount = 0;
	int maxComponents;
	GameComponent* components[10];
	void(*initialise)();
	void(*terminate)();
	const int TICKS_1000MS = 1000;
	const int MAX_LOOPS = 5;
};

//Add the new entity instances to the components object
void Game::Add(GameComponent* gameComponent) {
	if (componentCount == maxComponents) {
		cout << "Cannot add more than " << maxComponents << " game component(s)" << endl;
		return;
	} else {
		components[componentCount] = gameComponent;
		componentCount++;
	}
};

void Game::Run() {
	(*initialise)();

	//Loop through the max number of times the entity will be called
	for (int x = 0; x < MAX_LOOPS; x++) {
		//Loop through each entity
		for (int i = 0; i < componentCount; i++) {
			//Get the current local time
			time_t t = time(0);
			tm* now = localtime(&t);
			components[i]->Update(now);
		}
		this_thread::sleep_for(chrono::milliseconds(TICKS_1000MS));
	}

	(*terminate)();
};

void Game::SetInitialise(void (*init)()) {
	initialise = *init;
};

void Game::SetTerminate(void (*term)()) {
	terminate = *term;
};
