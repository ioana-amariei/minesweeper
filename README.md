## Minesweeper
___


### Contents

* Description
* Functionalities
* How to play
* Shortcomings
* License information


### Description
This game was developed as a requirement for a school project.
The goal of the game is to uncover all the squares that do not contain mines without being "blown up" by clicking on a square with a mine underneath. The location of the mines is discovered using clues as a deductive method. 


### Functionalities
* Random mines generator, with a limit of bombs;
* Option to mark a particular square with a flag;
* Reveal all adjacent squares, if no mines are adjacent.


### How to play:

####Game instructions: 

* Entering game parameters
The player is asked to select desired options on the game board height(rows) and width(columns), respectively its difficulty. In terms of difficulty, the chosen number represents the percentage of mines located randomly on the game board.
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/enter-game-parameters.png)

* Initial board
The player is initially presented with a grid of "undifferentiated squares" marked by '-'. Some of these squares are designated to contain mines, some are blank, but some contain numbers (1 to 8), each number being the number of mines adjacent to the uncovered square. 
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/initial-board.png)

* Play time
- The player moves on the board game using 'UP', 'RIGHT', 'DOWN' and 'LEFT' keys. 
- Pressing the 'SPACE key' will reveal what is hidden underneath the chosen square. 
- If no mine is revealed, a digit is instead displayed, indicating how many adjacent squares contain mines. 
- If no mines are adjacent, all adjacent squares will be recursively revealed. 
- To help avoid hitting a mine, the location of a suspected mine can be marked by flagging it by pressing 'f key'. Those will appear marked with '@'. 
The player uses this information to deduce the contents of other squares, and may either safely reveal each square or mark the square as containing a mine.
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/making-moves.png)

* Losing
A game is lost when the player mistakenly reveal a square that contains a mine. In that moment, the game board displays all mines locations.
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/game-over.png)

* Another chance
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/play-again.png)

* Winning
The game is won once all blank squares have been uncovered without hitting a mine. There is also an indicator regarding the number of remaining cells without mines that decreases during game.
![alt text](https://github.com/ioanabirsan/minesweeper/raw/master/screenshots/win-game.png)

If you want to improve your skills, try some good advice from here: [Strategy](http://www.minesweeper.info/wiki/Strategy)


### Shortcomings
* command line interface ([CLI](https://en.wikipedia.org/wiki/Command-line_interface))
* flickering