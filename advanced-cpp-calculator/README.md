🧮 Advanced C++ Calculator

A feature-rich console-based calculator built using C++ and file handling. This project demonstrates real-world mathematical operations, input validation, and data persistence using text files.

---

🧠 Overview

This project is a menu-driven console application that allows users to perform basic, scientific, and trigonometric calculations efficiently.

All calculation history is stored in a local file (data.txt), ensuring results are saved even after closing the program.

---

⚙️ Features

📌 Core Functions
- Addition (+)
- Subtraction (-)
- Multiplication (*)
- Division (/)
- Modulus (%)

🔬 Scientific Operations
- Square Root (√)
- Power (x^y)
- Percentage (%)
- Average
- Factorial (!)

📐 Trigonometry Functions
- Sine (sin)
- Cosine (cos)
- Tangent (tan)

📊 Logarithmic Function
- Logarithm (log)

📜 History System
- Store all calculations in `data.txt`
- View full calculation history
- Clear history anytime

🧠 Extra Features
- Show last calculated result
- Reuse previous answer
- Continuous calculation menu system

🔒 Safety & Validation
- Input validation for numbers only
- Prevent invalid operations
- Division by zero protection
- Error-safe user interaction

---

📁 Project Structure

cpp-calculator/
│
├── main.cpp   # Main source code of the calculator
├── data.txt   # Stores calculation history
└── README.md  # Project documentation

---

🚀 How to Run

Step 1: Compile the program
g++ main.cpp -o calculator

Step 2: Run the program
./calculator

💡 Alternative (Run from outside folder)
g++ cpp-calculator/main.cpp -o calculator
./calculator

---

🗂️ Data Storage Format

All calculations are stored in `data.txt` in the following format:

Example:
10 + 5 = 15  
20 / 4 = 5  
5 * 6 = 30  

---

🎯 Learning Outcomes

- File handling in C++
- Menu-driven console application design
- Implementation of scientific calculations
- Input validation and error handling
- Real-world mini project development
- Structuring large switch-case systems

---

🚀 Future Improvements

- Expression parser (e.g., 5+3*2)
- GUI version using Qt or SFML
- Advanced statistics system
- Theme-based console UI
- Memory functions (M+, M-, MR, MC)
- Multi-session history tracking

---

👨‍💻 Author

Hm Swapon  
Computer Engineer | C++ Developer | Problem Solver