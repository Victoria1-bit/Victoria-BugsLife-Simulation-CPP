# A Bug's Life Simulation (C++)

## Overview
This project is a C++ console application that simulates bugs moving on a 10x10 bug board.

The project uses object-oriented programming concepts such as:
- inheritance
- polymorphism
- abstract classes
- vectors of base-class pointers
- file input and output
- STL containers

---

## Bug Types

### Crawler
A Crawler moves one square at a time in its current direction.

### Hopper
A Hopper moves multiple squares at a time using its hop length.

### DiagonalBug
A DiagonalBug is the extra bug type added to the project.  
It moves diagonally across the board and still uses the shared `Bug` base class.

---

## Main Classes

### Bug
Abstract base class.

Stores:
- id
- position
- direction
- health
- alive status
- path history

### Crawler
Derived from `Bug`.

Overrides:
- `move()`
- `display()`

### Hopper
Derived from `Bug`.

Overrides:
- `move()`
- `display()`

### DiagonalBug
Derived from `Bug`.

Overrides:
- `move()`
- `display()`

### Board
Controls the simulation.

Responsibilities:
- load bugs from file
- display all bugs
- find a bug by ID
- tap the board
- run fights
- display life history
- display all cells
- run simulation
- save life history to file

---

## Input File Format

The program reads bug data from `bugs.txt`.

### Crawler

```txt
C;101;0;0;4;10
Hopper
H;102;9;0;1;8;2
DiagonalBug
D;107;4;4;1;20

Format:

Type;ID;X;Y;Direction;Health;HopLength(optional)

Direction values:

1 = North
2 = East
3 = South
4 = West
Menu Options
1. Initialize Bug Board
2. Display all Bugs
3. Find a Bug
4. Tap the Bug Board
5. Display Life History
6. Display all Cells
7. Run Simulation
8. Exit
Features Implemented
Load bug data from file
Display all bugs
Find a bug by ID
Move bugs using polymorphism
Tap board movement
Fight system
Track path history
Display life history
Display all cells on the 10x10 grid
Run automatic simulation
Save life history on exit
Added extra bug type: DiagonalBug
Data Structures Used
vector<Bug*> stores all bugs polymorphically
list<pair<int,int>> stores each bug's path history
pair<int,int> stores grid positions
How to Run
Open the project in CLion
Build the project
Run the executable
Use the menu options to control the simulation
Author

Victoria
C++ Continuous Assessment
A Bug's Life Simulation
