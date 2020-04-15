# The-Game-of-Life
A c++ code that implements coways game of life

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970

The game is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine. 

Rules
The universe of the Game of Life is an infinite, two-dimensional orthogonal grid of square cells, each of which is in one of two possible states, alive or dead, (or populated and unpopulated, respectively). Every cell interacts with its eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. At each step in time, the following transitions occur:

 1.   Any live cell with fewer than two live neighbours dies, as if by underpopulation.
 2.   Any live cell with two or three live neighbours lives on to the next generation.
 3.   Any live cell with more than three live neighbours dies, as if by overpopulation.
 4.   Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

These rules, which compare the behavior of the automaton to real life, can be condensed into the following:

 1.   Any live cell with two or three live neighbors survives.
 2.   Any dead cell with three live neighbors becomes a live cell.
 3.   All other live cells die in the next generation. Similarly, all other dead cells stay dead.
 
 
I have written a simpl C++ code that shows the game of life using a 10x10 matrix
