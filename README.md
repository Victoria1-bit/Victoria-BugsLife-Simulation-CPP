# A Bug’s Life Simulation – C++ CA

## Project Overview

This project is a console-based simulation developed in C++ that models different types of bugs moving around a 10x10 game board.

The application demonstrates object-oriented programming principles including inheritance, polymorphism, abstraction, encapsulation, and dynamic memory management. Bugs are loaded from a text file and interact within the simulation through movement and combat mechanics.

---

# Project Objectives

The purpose of this project is to:

- Simulate bug movement on a board
- Implement multiple derived bug classes
- Store bugs polymorphically using base-class pointers
- Track bug movement history
- Simulate bug fights and eliminations
- Provide a menu-driven user interface
- Read and write data using files

---

# Bug Types

## 1. Crawler

Crawler bugs move one square at a time in their current direction.

### Features
- Moves one step
- Changes direction randomly
- Stores movement history

---

## 2. Hopper

Hopper bugs move multiple squares depending on their hop length.

### Features
- Jumps several spaces per move
- Uses hop length value from file
- Stores movement history

---

## 3. DiagonalBug

DiagonalBug is the additional bug type added to extend the project functionality.

### Features
- Moves diagonally across the board
- Inherits from the Bug base class
- Uses polymorphic movement

---

# Main Classes

## Bug (Abstract Base Class)

The Bug class stores all shared bug information.

### Data Stored
- Bug ID
- Position
- Direction
- Health
- Alive status
- Path history

### Main Functions
- `move()`
- `display()`
- `getId()`
- `getPosition()`
- `getHealth()`
- `getPath()`
- `kill()`
- `setDirection()`

---

## Board Class

The Board class manages the simulation.

### Responsibilities
- Load bugs from file
- Display all bugs
- Move bugs
- Run simulations
- Detect bug fights
- Display board cells
- Save life history to file

---

# STL Containers Used

## vector<Bug*>

Used to store all bug objects polymorphically.

### Reason
Allows different derived bug types to be stored together while still using overridden functions.

---

## list<pair<int,int>>

Used to store each bug’s movement history.

### Reason
Efficient insertion of movement positions throughout the simulation.

---

# File Input

The program reads bug data from `bugs.txt`.

## Example Data

```txt
C;101;0;0;4;10
H;102;9;0;1;8;2
D;107;4;4;1;20
File Format
Type;ID;X;Y;Direction;Health;HopLength
Direction Values
Value	Direction
1	North
2	East
3	South
4	West
Program Features
File loading
Menu-driven interface
Bug movement simulation
Random direction changes
Bug combat system
Life history tracking
Board display system
Automatic simulation mode
Save life history to file
Winner detection
Additional custom bug type
Menu System
1. Initialize Bug Board
2. Display all Bugs
3. Find a Bug
4. Tap the Bug Board
5. Display Life History
6. Display all Cells
7. Run Simulation
8. Exit
Simulation Logic

During simulation:

Bugs change direction randomly
Bugs move across the board
Bugs that land on the same position fight
Bugs with lower health are removed
Simulation continues until one bug remains or max steps reached
Output Files
life_history.txt

Stores the movement history of every bug during execution.

Generated automatically when the program exits.

Technologies Used
C++
CLion
CMake
STL Containers
Object-Oriented Programming
Author

Victoria

C++ Continuous Assessment
A Bug’s Life Simulation
