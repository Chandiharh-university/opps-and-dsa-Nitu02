//Name: Nitu
//UID: 22BCS10707
// Section: 22BCS-631/B


// Sum of Natural Numbers up to N
#include <iostream>
using namespace std;

class Solution {
public:
    int sumOfNaturals(int n) {
        return n * (n + 1) / 2; 
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Sum of first " << n << " natural numbers is: " << solution.sumOfNaturals(n) << endl;

    return 0;
}


//  Count Digits and Characters in a Number
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void countDigitsAndChars(const string& s) {
        int digitCount = 0;
        int charCount = 0;

        for (char c : s) {
            if (isdigit(c)) {
                digitCount++;
            } else {
                charCount++;
            }
        }

        cout << "Digits: " << digitCount << endl;
        cout << "Characters: " << charCount << endl;
    }
};

int main() {
    Solution solution;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    solution.countDigitsAndChars(s);

    return 0;
}


// Function Overloading for Calculating Area
#include <iostream>
#include <cmath>
using namespace std;

double area(double radius) {
    return 3.14159 * radius * radius;
}

int area(int length, int breadth) {
    return length * breadth;
}

double area(double base, double height, bool isTriangle) {
    return 0.5 * base * height;
}

int main() {
    double radius, base, height;
    int length, breadth;

    cin >> radius;
    cin >> length >> breadth;
    cin >> base >> height;

    cout << area(radius) << endl;
    cout << area(length, breadth) << endl;
    cout << area(base, height, true) << endl;

    return 0;
}

// Check if a number is palindrome or not by converting integer into string
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string str = to_string(x);
        int start = 0;
        int end = str.length() - 1;

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
};

int main() {
    Solution solution;
    int x;

    cout << "Enter a number: ";
    cin >> x;

    cout << (solution.isPalindrome(x) ? "Yes" : "No") << endl;

    return 0;
}


// Check if a number is prime or not
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) return false; 
        if (n == 2) return true;  
        if (n % 2 == 0) return false; 

        
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (solution.isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}

