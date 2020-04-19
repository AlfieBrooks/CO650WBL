#pragma once
#include <iostream>
#include <string>
#include "GameComponent.h"

using namespace std;

enum Direction {
	Left,
	Right,
	Up,
	Down
};

class DrawableGameComponent : public GameComponent {
public:
	DrawableGameComponent(int xValue, int yValue) {
		direction = Right;
		directionString = "Right";
		x = xValue;
		y = yValue;
	};
	Direction direction;
	const int SCREEN_HEIGHT = 20;
	const int SCREEN_WIDTH = 80;
	void Update(const tm* eventTime) override;
private:
	void UpdatePositions();
	void ChangeDirection();
	void Draw();
	int GetRandomNum();
	int x, y;
	string directionString;
};

void DrawableGameComponent::Update(const tm* eventTime) {
	GameComponent::Update(eventTime);
	UpdatePositions();
	Draw();
	ChangeDirection();
};

//Update x & y values based off direction
void DrawableGameComponent::UpdatePositions() {
	switch (direction) {
	case Left:
		x--;
		if (x < 0) {
			x = 0;
		}
		directionString = "Left";
		break;
	case Right:
		x++;
		if (x > SCREEN_WIDTH) {
			x = SCREEN_WIDTH;
		}
		directionString = "Right";
		break;
	case Up:
		y++;
		if (y > SCREEN_HEIGHT) {
			y = SCREEN_HEIGHT;
		}
		directionString = "Up";
		break;
	case Down:
		y--;
		if (y < 0) {
			y = 0;
		}
		directionString = "Down";
		break;
	default:
		x = 0;
		y = 0;
		break;
	}
}

//Generate a random number for 0 to 3
int DrawableGameComponent::GetRandomNum() {
	srand(time(NULL));
	return rand() % 4;
}

//Assign direction a new value that is different from the previous state
void DrawableGameComponent::ChangeDirection() {
	int randomNumber = GetRandomNum();
	
	while (randomNumber == direction) {
		randomNumber = GetRandomNum();
	}

	direction = static_cast<Direction>(randomNumber);
};

void DrawableGameComponent::Draw() {
	cout << directionString << " : " << "X: " << x << " Y: " << y << endl;
};
