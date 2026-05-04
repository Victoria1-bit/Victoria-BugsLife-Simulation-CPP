✅ README.md (FULL FILE)
# A Bug's Life Simulation (C++)

## 📌 Overview
This project is a C++ simulation of a “Bug Board” where different types of bugs move, interact, and fight on a 10x10 grid.

The system models object-oriented programming concepts such as:
- Inheritance
- Polymorphism
- Encapsulation
- Dynamic memory allocation

The simulation continues until one bug remains or a maximum number of steps is reached.

---

## 🎯 Objectives
- Simulate movement of bugs on a grid
- Handle collisions and fights between bugs
- Track the path (life history) of each bug
- Provide a menu-driven interface for user interaction

---

## 🐞 Bug Types

### 1. Crawler
- Moves 1 step at a time
- Follows its current direction
- Changes direction randomly if blocked

### 2. Hopper
- Moves multiple steps based on its `hopLength`
- Can hit walls and stop early
- Changes direction if movement is blocked

---

##  System Design

### Base Class: `Bug`
Contains shared attributes:
- ID
- Position `(x, y)`
- Direction
- Health
- Alive/Dead status
- Path history (list of positions)

### Derived Classes:
- `Crawler`
- `Hopper`

Each overrides the `move()` function to implement its own behavior.

---

## 🗂️ Files

- `main.cpp` → Program entry + menu system  
- `Board.h / Board.cpp` → Handles all bug logic and simulation  
- `Bug.h / Bug.cpp` → Base class  
- `Crawler.h / Crawler.cpp` → Crawler bug behavior  
- `Hopper.h / Hopper.cpp` → Hopper bug behavior  
- `bugs.txt` → Input file with bug data  
- `README.md` → Project documentation  

---

## 📥 Input File Format (`bugs.txt`)

Each bug is defined on one line:


C;101;0;0;4;10
H;102;9;0;1;8;2


### Format:

Type;ID;X;Y;Direction;Health;HopLength(optional)


- `C` = Crawler  
- `H` = Hopper  

---

## ⚙️ Features Implemented

### ✅ Core Features
- Load bugs from file
- Display all bugs
- Find bug by ID
- Move all bugs (Tap Board)
- Fight system (stronger bug survives)
- Display bug life history (path taken)
- Display all grid cells
- Run automatic simulation
- Save life history to file

---

## 🧠 Key Concepts Used

- **Polymorphism**
  - `virtual move()` allows different behavior for each bug type

- **Dynamic Memory**
  - Bugs stored as `vector<Bug*>`

- **STL Containers**
  - `vector` for bug storage
  - `list` for path tracking

- **File Handling**
  - Reading input from file
  - Writing output to file

---

## ▶️ How to Run

1. Compile the project
2. Run the executable
3. Use the menu options:

Initialize Bug Board
Display all Bugs
Find a Bug
Tap the Bug Board
Display Life History
Display all Cells
Run Simulation
Exit

---

## 🧪 Example Output


Bug 101 | Position: (3,4) | Health: 18 | Direction: East | Status: Alive


---

## 📊 Simulation

- Bugs move every "tap"
- If bugs land on the same cell:
  - They fight
  - The bug with higher health survives
- Simulation runs automatically with delay until:
  - One bug remains OR
  - Max steps reached

---

## 💾 Output File

Life history is saved as:


life_history_YYYYMMDD_HHMMSS.txt


Example:

Bug 101 path: (0,0) (1,0) (2,0)


---

## 🚀 Possible Improvements

- Add more bug types
- Improve fight system (multi-round battles)
- GUI interface instead of console
- Better simulation visualization

---



Student Project  
Year 2 – C++ Continuous Assessment  
