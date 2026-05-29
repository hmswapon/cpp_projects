# 📞 Contact Management System (C++)

A simple yet powerful **console-based Contact Management System** built using **C++ programming language** with file handling. This project demonstrates real-world CRUD operations (Create, Read, Update, Delete) and basic data management using text files.

---

## 🧠 Overview

This application allows users to store, manage, and organize contact information efficiently. All data is saved in a local file (`data.txt`), ensuring that contacts remain stored even after the program is closed.

It is designed as a **menu-driven console application** to make it easy to use and understand.

---

## ⚙️ Features

✔ Add new contact (Name & Phone Number)
✔ Display all saved contacts
✔ Search contact by name or number
✔ Update existing contact information
✔ Delete individual contact
✔ Delete all contacts at once
✔ Prevent duplicate name or number entries
✔ Input validation for safe user interaction
✔ Persistent data storage using file handling

---

## 🚀 How to Run

### Step 1: Compile the program

```bash id="compile1"
g++ main.cpp -o contact_app
```

### Step 2: Run the program

```bash id="run1"
./contact_app
```

---

## 📁 Project Structure

```bash id="structure1"
contact_manager/
│
├── main.cpp       # Main source code
├── data.txt       # Stores contact information
└── README.md      # Project documentation
```

---

## 🗂️ Data Storage Format

All contacts are stored in a text file in the following format:

```id="format1"
Name    Number
```

### Example:

```id="example1"
Hm Swapon  017XXXXXXXX
Trisha   018XXXXXXXX
```

---

## 🎯 Learning Objectives

This project helps to understand:

* File handling in C++
* CRUD operations implementation
* Menu-driven console applications
* String manipulation
* Input validation techniques
* Real-world problem solving

---

## 💡 Future Improvements

* Add GUI using Qt framework
* Store data in database (MySQL / SQLite)
* Add contact groups (Family, Friends, Work)
* Add sorting and advanced search system
* Add password protection system

---

## 👨‍💻 Author

**Md Harun Or Rashid Swapon**
C++ Developer | Computer Engineering Student
