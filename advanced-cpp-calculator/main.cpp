
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <iomanip>

using namespace std;

// ===== Integer Validation =====
int getInt() {

    int num;

    while (true) {

        if (cin >> num) {
            return num;
        }

        cout << "Invalid input! Integer only.\n";

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Enter again: ";
    }
}

// ===== Double Validation =====
double getDouble() {

    double num;

    while (true) {

        if (cin >> num) {
            return num;
        }

        cout << "Invalid input! Number only.\n";

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Enter again: ";
    }
}

// ===== Time Function =====
string getTimeStamp() {

    time_t now = time(0);

    string dt = ctime(&now);

    dt.pop_back();

    return dt;
}

// ===== Save History =====
void saveHistory(string expression) {

    ofstream file("data.txt", ios::app);

    if (file.is_open()) {

        file << "[" << getTimeStamp() << "] "
             << expression << endl;

        file.close();
    }
}

// ===== Show History =====
void showHistory() {

    ifstream file("data.txt");

    string line;

    cout << "\n========== HISTORY ==========\n";

    if (!file || file.peek() == EOF) {

        cout << "No history found.\n";
    }
    else {

        int count = 1;

        while (getline(file, line)) {

            cout << count << ". " << line << endl;

            count++;
        }
    }

    file.close();
}

// ===== Clear History =====
void clearHistory() {

    ofstream file("data.txt", ios::trunc);

    file.close();

    cout << "\nHistory Cleared Successfully.\n";
}

int main() {

    system("color 0A");

    int choice;

    double lastAnswer = 0;

    do {

        cout << "\n=====================================\n";
        cout << "        ADVANCED CALCULATOR\n";
        cout << "=====================================\n";

        cout << "1. Addition\n";
        cout << "2. Subtraction\n";
        cout << "3. Multiplication\n";
        cout << "4. Division\n";
        cout << "5. Modulus\n";
        cout << "6. Square Root\n";
        cout << "7. Power\n";
        cout << "8. Percentage\n";
        cout << "9. Average\n";
        cout << "10. Factorial\n";
        cout << "11. Sine\n";
        cout << "12. Cosine\n";
        cout << "13. Tangent\n";
        cout << "14. Log\n";
        cout << "15. Show History\n";
        cout << "16. Clear History\n";
        cout << "17. Show Last Answer\n";
        cout << "0. Exit\n";

        cout << "\nSelect Option: ";

        choice = getInt();

        vector<double> numbers;

        // ===== ADDITION =====
        if (choice == 1) {

            cout << "\n--- Addition (0 to stop) ---\n";

            int i = 1;

            while (true) {

                cout << "Enter n" << i << ": ";

                double num = getDouble();

                if (num == 0) {
                    break;
                }

                numbers.push_back(num);

                i++;
            }

            if (numbers.size() < 2) {

                cout << "Minimum 2 numbers required!\n";
            }
            else {

                double sum = 0;

                string expression = "";

                for (int i = 0; i < numbers.size(); i++) {

                    sum += numbers[i];

                    expression += to_string(numbers[i]);

                    if (i != numbers.size() - 1) {
                        expression += " + ";
                    }
                }

                expression += " = " + to_string(sum);

                lastAnswer = sum;

                saveHistory(expression);

                cout << "\nResult: " << sum << endl;
            }
        }

        // ===== SUBTRACTION =====
        else if (choice == 2) {

            cout << "\n--- Subtraction (0 to stop) ---\n";

            int i = 1;

            while (true) {

                cout << "Enter n" << i << ": ";

                double num = getDouble();

                if (num == 0) {
                    break;
                }

                numbers.push_back(num);

                i++;
            }

            if (numbers.size() < 2) {

                cout << "Minimum 2 numbers required!\n";
            }
            else {

                double sub = numbers[0];

                string expression = to_string(numbers[0]);

                for (int i = 1; i < numbers.size(); i++) {

                    sub -= numbers[i];

                    expression += " - " + to_string(numbers[i]);
                }

                expression += " = " + to_string(sub);

                lastAnswer = sub;

                saveHistory(expression);

                cout << "\nResult: " << sub << endl;
            }
        }

        // ===== MULTIPLICATION =====
        else if (choice == 3) {

            cout << "\n--- Multiplication (0 to stop) ---\n";

            int i = 1;

            while (true) {

                cout << "Enter n" << i << ": ";

                double num = getDouble();

                if (num == 0) {
                    break;
                }

                numbers.push_back(num);

                i++;
            }

            if (numbers.size() < 2) {

                cout << "Minimum 2 numbers required!\n";
            }
            else {

                double mul = 1;

                string expression = "";

                for (int i = 0; i < numbers.size(); i++) {

                    mul *= numbers[i];

                    expression += to_string(numbers[i]);

                    if (i != numbers.size() - 1) {
                        expression += " * ";
                    }
                }

                expression += " = " + to_string(mul);

                lastAnswer = mul;

                saveHistory(expression);

                cout << "\nResult: " << mul << endl;
            }
        }

        // ===== DIVISION =====
        else if (choice == 4) {

            double a, b;

            cout << "Enter first number: ";
            a = getDouble();

            cout << "Enter second number: ";
            b = getDouble();

            if (b == 0) {

                cout << "Cannot divide by zero!\n";
            }
            else {

                double result = a / b;

                string expression =
                    to_string(a) + " / " +
                    to_string(b) + " = " +
                    to_string(result);

                lastAnswer = result;

                saveHistory(expression);

                cout << "\nResult: " << result << endl;
            }
        }

        // ===== MODULUS =====
        else if (choice == 5) {

            int a, b;

            cout << "Enter first integer: ";
            a = getInt();

            cout << "Enter second integer: ";
            b = getInt();

            if (b == 0) {

                cout << "Cannot modulus by zero!\n";
            }
            else {

                int result = a % b;

                string expression =
                    to_string(a) + " % " +
                    to_string(b) + " = " +
                    to_string(result);

                lastAnswer = result;

                saveHistory(expression);

                cout << "\nResult: " << result << endl;
            }
        }

        // ===== SQUARE ROOT =====
        else if (choice == 6) {

            double num;

            cout << "Enter number: ";
            num = getDouble();

            if (num < 0) {

                cout << "Negative number not allowed!\n";
            }
            else {

                double result = sqrt(num);

                string expression =
                    "sqrt(" + to_string(num) + ") = " +
                    to_string(result);

                lastAnswer = result;

                saveHistory(expression);

                cout << "\nResult: " << result << endl;
            }
        }

        // ===== POWER =====
        else if (choice == 7) {

            double base, exponent;

            cout << "Enter base: ";
            base = getDouble();

            cout << "Enter exponent: ";
            exponent = getDouble();

            double result = pow(base, exponent);

            string expression =
                to_string(base) + " ^ " +
                to_string(exponent) + " = " +
                to_string(result);

            lastAnswer = result;

            saveHistory(expression);

            cout << "\nResult: " << result << endl;
        }

        // ===== PERCENTAGE =====
        else if (choice == 8) {

            double value, total;

            cout << "Enter value: ";
            value = getDouble();

            cout << "Enter total: ";
            total = getDouble();

            if (total == 0) {

                cout << "Cannot divide by zero!\n";
            }
            else {

                double result = (value / total) * 100;

                string expression =
                    to_string(value) + "% of " +
                    to_string(total) + " = " +
                    to_string(result);

                lastAnswer = result;

                saveHistory(expression);

                cout << "\nResult: " << result << "%" << endl;
            }
        }

        // ===== AVERAGE =====
        else if (choice == 9) {

            int count;

            cout << "How many numbers: ";
            count = getInt();

            double sum = 0;

            for (int i = 1; i <= count; i++) {

                cout << "Enter n" << i << ": ";

                double num = getDouble();

                sum += num;
            }

            double avg = sum / count;

            lastAnswer = avg;

            string expression = "Average = " + to_string(avg);

            saveHistory(expression);

            cout << "\nAverage: " << avg << endl;
        }

        // ===== FACTORIAL =====
        else if (choice == 10) {

            int num;

            cout << "Enter integer: ";
            num = getInt();

            if (num < 0) {

                cout << "Negative factorial not possible!\n";
            }
            else {

                long long fact = 1;

                for (int i = 1; i <= num; i++) {
                    fact *= i;
                }

                lastAnswer = fact;

                string expression =
                    to_string(num) + "! = " +
                    to_string(fact);

                saveHistory(expression);

                cout << "\nResult: " << fact << endl;
            }
        }

        // ===== SIN =====
        else if (choice == 11) {

            double degree;

            cout << "Enter degree: ";
            degree = getDouble();

            double radian = degree * 3.14159265359 / 180;

            double result = sin(radian);

            lastAnswer = result;

            string expression =
                "sin(" + to_string(degree) + ") = " +
                to_string(result);

            saveHistory(expression);

            cout << "\nResult: " << result << endl;
        }

        // ===== COS =====
        else if (choice == 12) {

            double degree;

            cout << "Enter degree: ";
            degree = getDouble();

            double radian = degree * 3.14159265359 / 180;

            double result = cos(radian);

            lastAnswer = result;

            string expression =
                "cos(" + to_string(degree) + ") = " +
                to_string(result);

            saveHistory(expression);

            cout << "\nResult: " << result << endl;
        }

        // ===== TAN =====
        else if (choice == 13) {

            double degree;

            cout << "Enter degree: ";
            degree = getDouble();

            double radian = degree * 3.14159265359 / 180;

            double result = tan(radian);

            lastAnswer = result;

            string expression =
                "tan(" + to_string(degree) + ") = " +
                to_string(result);

            saveHistory(expression);

            cout << "\nResult: " << result << endl;
        }

        // ===== LOG =====
        else if (choice == 14) {

            double num;

            cout << "Enter number: ";
            num = getDouble();

            if (num <= 0) {

                cout << "Log undefined!\n";
            }
            else {

                double result = log10(num);

                lastAnswer = result;

                string expression =
                    "log(" + to_string(num) + ") = " +
                    to_string(result);

                saveHistory(expression);

                cout << "\nResult: " << result << endl;
            }
        }

        // ===== SHOW HISTORY =====
        else if (choice == 15) {

            showHistory();
        }

        // ===== CLEAR HISTORY =====
        else if (choice == 16) {

            clearHistory();
        }

        // ===== LAST ANSWER =====
        else if (choice == 17) {

            cout << "\nLast Answer = " << lastAnswer << endl;
        }

        // ===== INVALID =====
        else if (choice != 0) {

            cout << "\nInvalid Option!\n";
        }

        cout << "\n-------------------------------------\n";

    } while (choice != 0);

    cout << "\nCalculator Closed Successfully.\n";

    return 0;
}
