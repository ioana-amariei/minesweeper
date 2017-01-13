#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class TerminalColoring {
public:

	static const int BLUE;
	static const int GREEN;
	static const int RED;
	static const int WHITE;

	TerminalColoring();

	void setColour(int);

	void resetColour();

	void printColored(string, int);

	~TerminalColoring();
};