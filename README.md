# 🐍 Snake Game — C++

A simple **Snake game built in C++** that runs directly in the **Windows Command Prompt**.

The game allows the player to customize the playing area, snake speed, winning target, and keyboard layout before starting.

## 🎮 Features

* Classic Snake gameplay
* Keyboard-controlled movement
* Customizable playing area size
* Adjustable snake speed
* Customizable target score
* QWERTY and AZERTY keyboard support
* Random food generation
* Collision detection
* Replay option
* Hidden console cursor for smoother display


## ⚙️ Game Configuration

Before playing, you can choose:

* Rows — height of the playing area
* Columns — width of the playing area
* Snake speed — from 1 to 5
* Target score — number of food items required to win
* Keyboard layout — QWERTY or AZERTY

The game checks that the selected playing area fits inside the current console window.

## 🧠 Concepts Used

This project was built to practice:

* `vector` and `deque`
* Functions and references
* Structures
* Operator overloading
* Random number generation
* Console input handling
* Windows Console API
* Multithreading and delays
* Collision detection
* Dynamic game-board management

## 🛠️ Technologies

* C++
* Windows Command Prompt
* Windows API
* MinGW / g++

### Main Libraries

```cpp
#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <conio.h>
#include <windows.h>
```

## 🚀 How to Run

This project is designed for **Windows** because it uses:

```cpp
#include <windows.h>
#include <conio.h>
```

Compile with `g++`:

```bash
g++ main.cpp -o snake
```

Then run:

```bash
snake
```

## 📂 Project Structure

```text
Snake-Game/
│
├── main.cpp
└── README.md
```

## 🎯 Purpose

This project was created as a practical exercise to improve my understanding of **C++ programming and game logic**.

The goal was to build a playable game using the **Windows console**, without relying on a graphical game engine.

## 👨‍💻 Author

**Abdelmalek Miloudi Achour**

