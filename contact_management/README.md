# 📞 Contact Management System (C++)

A simple console-based Contact Management System built using C++ and file handling. This project demonstrates real-world CRUD operations and basic data management using text files.

---

## 🧠 Overview

This project is a menu-driven console application that allows users to efficiently manage contact information such as names and phone numbers.

All data is stored in a local file (`data.txt`), ensuring that contacts remain saved even after the program is closed.

---

## ⚙️ Features

### 📌 Core Functions

* Add new contact (Name & Number)
* Show all saved contacts
* Search contact by name or number

### ✏️ Management

* Update existing contact information
* Delete individual contact
* Delete all contacts at once

### 🔒 Safety & Validation

* Prevent duplicate name or number entries
* Input validation for safe user interaction

### 💾 Data Handling

* Persistent data storage using file handling

---

## 📁 Project Structure

```bash id="structure_final"
contact_management/
│
├── main.cpp   # Main source code of the application
└── data.txt   # Stores all contact data
```

---

## 🚀 How to Run

### Step 1: Compile the program

```bash id="compile_final"
g++ main.cpp -o contact_app
```

### Step 2: Run the program

```bash id="run_final"
./contact_app
```

---

## 💡 Alternative (Run from outside folder)

```bash id="alt_final"
g++ contact_management/main.cpp -o contact_app
./contact_app
```

---

## 🗂️ Data Storage Format

Contacts are stored in the following format inside `data.txt`:

```text id="format_final"
Name    Number
```

### Example:

```text id="example_final"
Hm Swapon  017XXXXXXXX
Trisha     018XXXXXXXX
```

---

## 🎯 Learning Outcomes

* File handling in C++
* CRUD operations implementation
* Menu-driven console applications
* String manipulation techniques
* Input validation handling
* Real-world mini project development

---

## 🚀 Future Improvements

* Add GUI using Qt framework
* Integrate database (MySQL / SQLite)
* Add contact categories (Family, Friends, Work)
* Add advanced search & sorting system
* Add password protection system
* Export contacts to CSV/PDF

---

## 👨‍💻 Author

**Md Harun Or Rashid Swapon**
C++ Programmer | Competitive Programmer | Problem Solver
