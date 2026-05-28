# User Management System (C Programming CRUD Assignment)

This repository contains a console-based User Management System written in standard C. The application demonstrates a fundamental CRUD (Create, Read, Update, Delete) architecture tailored specifically to strictly adhere to specific academic programming constraints.

## Project Constraints Followed
* **No Pointers:** Relies strictly on value copying and direct array index referencing.
* **No Dynamic Memory Allocation:** Avoids `malloc()`, `calloc()`, or `free()`. Memory is allocated statically at compile time.
* **Structured & Modular:** Utilizes custom functions and standard C structure components (`struct`) to manage structured objects.

---

## How the Code Works

### 1. Data Structure (`struct User`)
A user blueprint is declared using a structural format. It aggregates multiple related data points into a single entity variable:
* `name` (Character Array / String)
* `age` (Integer)
* `address` (Character Array / String)

### 2. Static Memory Management
An array of elements `struct User userList[MAX_USERS]` is allocated inside the `main()` scope. The size boundary is configured statically at `100` total items maximum. Track status is observed dynamically via a local scalar integer integer tracking value (`userCount`).

### 3. Core Operational Logic (Functions)
* **`displayMenu()`**: Standard input/output command interface to prompt choices (Options 1-4, and 0 for exit control loop).
* **`createUser()`**: Evaluates database overflow limits, captures input streams via `fgets()` safely handling buffer overhead, strips trailing newline variables (`\n`) and adds new structured details directly inside the next open slot.
* **`readAllUsers()`**: Validates if collection states contain records and prints entries incrementally inside a structured index listing loop.
* **`updateUser()`**: Maps active user index ranges against raw input numbers, overrides original struct records inside target sequential indices instantly.
* **`deleteUser()`**: Erases target rows without dynamic allocation. To clear specific array slots safely, subsequent index rows shift backwards progressively to automatically overwrite targeting blocks, decrementing tracking values by one.

---

## How to Run the Program

1. Clone or download the source code file `User_Management.c`.
2. Compile the application using standard `gcc`:
   ```bash
   gcc User_Management.c -o User_Management
