#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

class TerminalColoring {
public:

	static int BLUE;
	static int GREEN;
	static int RED;
	static int WHITE;

	TerminalColoring();

	void setColour(int);

	void resetColour();

	void printColored(string, int);

	~TerminalColoring();
};