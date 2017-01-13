#include"TerminalColoring.h"

// Initializing static variables
const int TerminalColoring::BLUE = 11;
const int TerminalColoring::GREEN = 10;
const int TerminalColoring::RED = 12;
const int TerminalColoring::WHITE = 15;


TerminalColoring::TerminalColoring() {
}

void TerminalColoring::setColour(int colour) {
	HANDLE handleConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handleConsole, colour);
}

void TerminalColoring::resetColour() {
	int white = 15;
	setColour(white);

}

void TerminalColoring::printColored(string text, int colour) {
	setColour(colour);
	cout << text;
	resetColour();
}

TerminalColoring::~TerminalColoring() {

}