# Inverted Search Engine in C

## 📌 Project Overview

The Inverted Search Engine is a C programming project that organizes and retrieves words from multiple text files. It uses a hash table and linked lists to store words, the filenames in which they appear, and their frequency of occurrence.

This project demonstrates the practical application of data structures, file handling, pointers, and dynamic memory allocation.

## 🎯 Features

- Validates input text files and checks for duplicate filenames.
- Creates an inverted index using a hash table and linked lists.
- Stores words along with their associated filenames and word counts.
- Provides a menu-driven interface for database operations.
- Uses modular programming to organize the code into separate functions.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Data Structures:** Hash Tables, Singly Linked Lists
- **Concepts:** File Handling, Pointers, Structures, Dynamic Memory Allocation
- **Compiler:** GCC
- **Platform:** Linux

## ⚙️ How to Compile

Open the terminal in the project directory and compile the source files:

```bash
gcc main.c create.c inverted.c display.c save.c search.c update.c -o inverted_search
```

## ▶️ How to Run

```bash
./inverted_search file1.txt file2.txt
```

Replace `file1.txt` and `file2.txt` with your own valid text filenames.

## 📚 Key Learnings

- Understanding how hash tables and linked lists work together.
- Handling multiple files using C file operations.
- Managing memory dynamically using pointers and structures.
- Developing a menu-driven application using modular programming.

## 👩‍💻 Author

Developed as a C programming project to strengthen my understanding of data structures and file handling.
