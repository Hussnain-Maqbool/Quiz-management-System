# Quiz Management System (C++)

A console-based **Quiz Management System** written in C++ as a Programming Fundamentals project. It supports three roles (**Admin**, **Teacher** and **Student**) and stores all data in plain text files, so no database is needed.

## Features

### Registration and Login
- Register new users with input validation (username, password, email, phone, designation, role)
- Role-based login that opens the Admin, Teacher or Student dashboard

### Admin
- Register new users
- Update user information
- View a user's credentials by ID
- Access the Teacher dashboard

### Teacher
- Create quizzes (10 multiple-choice questions, 4 options each)
- Edit existing quizzes
- Assign quizzes to students
- View student results

### Student
- View assigned quizzes
- Attempt quizzes and get an instant score
- View results and letter grades (A to F)

## Grading Scale

| Score (out of 10) | Grade |
|-------------------|-------|
| 9 - 10 | A |
| 7 - 8  | B |
| 5 - 6  | C |
| 3 - 4  | D |
| 0 - 2  | F |

## Concepts Used
- Structures (`struct`) and arrays
- File handling with `fstream`
- Functions and modular design
- Loops, menus and input validation

## Data Files
The program creates these files automatically in its working folder:

| File | Purpose |
|------|---------|
| `user.txt` | Registered users |
| `quiz.txt` | Created quizzes |
| `assignments.txt` | Quizzes assigned to students |
| `results.txt` | Student scores |

## Requirements
- Windows OS (uses `windows.h`, `conio.h` and `system("cls")`)
- A C++ compiler such as g++ (MinGW) or MSVC

## How to Run
```
g++ ProgrammingFundamentalProject.cpp -o QuizSystem
.\QuizSystem
```

## Getting Started
1. Run the program and choose **1** to register your first user. Choose the designation `admin`, `teacher` or `student`.
2. Choose **2** to log in with the username and password you created.
3. Use the dashboard for your role.

## Author
**Hussnain Maqbool**
BSc Artificial Intelligence student, UET Lahore
GitHub: [Hussnain-Maqbool](https://github.com/Hussnain-Maqbool)
