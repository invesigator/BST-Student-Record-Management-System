# Binary Search Tree - Student Record Management System

## Course Information
- **Course:** UCCD1024 Data Structures and Algorithmic Problem Solving
- **Assignment:** Assignment 2 - Binary Search Tree
- **Programming Language:** C++
- **Development Environment:** Microsoft Visual Studio 2019

## Project Overview

This project implements a comprehensive Binary Search Tree (BST) data structure for managing student records. The system provides efficient storage, retrieval, and manipulation of student information using BST algorithms.

## Features

The application includes the following core functionalities:

### 1. File Reading (`readFile`)
- Reads student records from a text file (`student.txt`)
- Parses student information including ID, name, address, DOB, phone number, course, and CGPA
- Stores records in BST structure sorted by student ID
- Displays count of successfully loaded records

### 2. Deepest Nodes Detection (`deepestNodes`)
- Identifies and prints all nodes at the deepest level of the BST
- Calculates tree height recursively
- Displays student IDs of deepest nodes

### 3. Tree Display (`display`)
- **Order Options:**
  - Ascending order (in-order traversal: left → root → right)
  - Descending order (reverse in-order: right → root → left)
- **Output Options:**
  - Screen display
  - File output (`student-info.txt`)
- Prints complete student information for each record

### 4. Subtree Cloning (`CloneSubtree`)
- Creates deep copy of subtree rooted at specified student ID
- Maintains original tree structure
- Supports independent manipulation of cloned subtree

### 5. Level-wise Node Printing (`printLevelNodes`)
- Displays nodes organized by tree levels
- Uses breadth-first traversal with queue implementation
- Shows tree structure level by level

### 6. Path Printing (`printPath`)
- Identifies and prints all external paths (root to leaf)
- Displays complete paths showing tree navigation routes
- Useful for understanding tree structure and search paths

## Data Structure

### Student Record Structure
```cpp
struct Student {
    char name[30];
    int id;              // Primary key for BST ordering
    char address[100];
    char DOB[20];        // Date of Birth
    char course[5];
    char phone_no[10];
    double cgpa;
}
```

### BST Implementation
- **Node Structure:** Each node contains a Student record and left/right pointers
- **Ordering:** Students are ordered by ID (ascending)
- **Operations:** Insert, remove, search, traversal
- **Helper Structures:** Queue for level-order operations

## File Structure

```
├── app.cpp           # Main application with menu system
├── BST.h/BST.cpp     # Binary Search Tree implementation
├── Student.h/Student.cpp # Student record structure
├── BTNode.h/BTNode.cpp   # Tree node implementation
├── Queue.h/Queue.cpp     # Queue for level operations
├── Node.h/Node.cpp       # Queue node structure
├── student.txt           # Sample input data
└── README.md            # This file
```

## Sample Data Format

The `student.txt` file follows this format:
```
Student Id = 28
Name = Matt Damon
Address = 465 Ripley Boulevard, Oscar Mansion, Malaysia 7666322
DOB = 10-10-1970
Phone Number = 790-3233
Course = CS
CGPA = 3.12076

Student Id = 22
Name = Ben Affleck
...
```

## Menu System

The application provides an interactive menu with the following options:

1. **Read data to BST** - Load student records from file
2. **Print deepest nodes** - Display nodes at maximum depth
3. **Display student** - Show records in ascending/descending order
4. **Clone Subtree** - Create copy of subtree
5. **Print Level Nodes** - Display tree structure by levels
6. **Print Path** - Show all root-to-leaf paths
7. **Exit** - Terminate program

## Key Algorithms Implemented

### Tree Traversal
- **Pre-order:** Root → Left → Right
- **In-order:** Left → Root → Right (for sorted output)
- **Post-order:** Left → Right → Root
- **Level-order:** Breadth-first using queue

### BST Operations
- **Insertion:** Recursive placement based on ID comparison
- **Deletion:** Handles three cases (leaf, one child, two children)
- **Search:** Binary search with O(log n) average complexity

### Advanced Features
- **Height Calculation:** Recursive depth computation
- **Deep Cloning:** Complete subtree duplication
- **Path Enumeration:** All root-to-leaf path identification

## Compilation and Execution

### Prerequisites
- Microsoft Visual Studio 2019
- C++11 or later standard

### Build Instructions
1. Open Visual Studio 2019
2. Create new C++ Console Application project
3. Add all `.h` and `.cpp` files to project
4. Ensure `student.txt` is in the same directory as executable
5. Build and run the project

## Sample Usage

1. **Load Data:**
   - Select option 1 to read `student.txt`
   - System displays number of records loaded

2. **View Records:**
   - Select option 3
   - Choose ascending (1) or descending (2) order
   - Choose screen (1) or file (2) output

3. **Analyze Structure:**
   - Use option 2 for deepest nodes
   - Use option 5 for level-wise view
   - Use option 6 for path analysis

## Technical Notes

### Time Complexity
- **Search/Insert/Delete:** O(log n) average, O(n) worst case
- **Traversal:** O(n) for all nodes
- **Height Calculation:** O(n)

### Space Complexity
- **Tree Storage:** O(n) for n student records
- **Recursive Operations:** O(h) stack space where h is tree height

### Error Handling
- File reading validation
- Empty tree checks
- Invalid menu option handling
- Memory allocation verification

## Future Enhancements

- Implement AVL or Red-Black tree for auto-balancing
- Add search functionality by name or other attributes
- Implement record modification capabilities
- Add data validation and error recovery
- Cross-platform compatibility improvements

## Academic Context

This assignment demonstrates understanding of:
- Binary Search Tree implementation and operations
- Recursive algorithm design
- File I/O operations in C++
- Memory management and pointer manipulation
- Queue-based algorithms for tree traversal
- Object-oriented programming principles

## Author Information

- **Course:** UCCD1024 Data Structures and Algorithmic Problem Solving
- **Institution:** Universiti Tunku Abdul Rahman
- **Academic Year:** 2023
- **Assignment:** Binary Search Tree Implementation

---

*This project is part of academic coursework and is intended for educational purposes. All implementation follows standard BST algorithms and best practices in C++ programming.*
