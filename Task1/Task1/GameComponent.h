#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class GameComponent {
public:
	GameComponent() {
		id = ++instances;
	};
	~GameComponent() {
		--id;
	};
	virtual void Update(const tm* eventTime);
private:
	int id;
	static int instances;
};

//Set the value of instances to be 0 by default
int GameComponent::instances;

//Output the entities unique ID and the time in the format HH:MM:SS
void GameComponent::Update(const tm* eventTime) {
	cout << "ID: " << id << " Updated: " << put_time(eventTime, "%T") << endl;
};
