#include<iostream>

using namespace std;

class GameParameters {
public:
	int rows;
	int columns;
	char difficulty;

	GameParameters();

	~GameParameters();
};