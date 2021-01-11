//
// Created by Danila Gvozdikov on 24.12.2020.
//

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

void throwErr(const string& message) {
    throw runtime_error(message);
}

void throwLeqZero(const int value, const string& valueName) {
    if (value <= 0) {
        throwErr(valueName + " должна(ен) быть больше 0.");
    }
}

void throwLeqZero(const double value, const string& valueName) {
    if (value <= 0) {
        throwErr(valueName + " должна(ен) быть больше 0.");
    }
}


// sum of two functions
class TProgram1 {
public:
    double run(double num) const {
        // check that number is greater then 0;
        throwLeqZero(num, "Число");

        // then count sqrt of number + cube of number and return it
        return sqrt(num) + pow(num, 3);
    }

};

// return integer part of a number from program 1
class TProgram2 {
public:
    int run(double num) {
        // ceil trunks all numbers after comma.
        return ceil(num);
    }
};

// Count volume of several spheres with R, R + deltaR, R + 2deltaR, ..., R*k
class TProgram3 {
public:
    void run(double radius, double delta, double k) const {
        // check input
        throwLeqZero(radius, "Радиус");
        throwLeqZero(delta, "Дельта");
        throwLeqZero(k, "Коэффициент k");

        // count required variables
        double last = radius * k;
        double cur = radius;
        long double result = 0.0;
        int i = 1;

        // and count volumes in cycle until we find radius bigger than k*R
        while (cur < last) {
            double volume = (4 * M_PI * cur * cur * cur) / 3;
            cout << fixed;
            cout.precision(4);
            cout << "Объем шара #" << i++ << ": " << volume << endl;
            result += volume;
            cur += delta;
        }

        cout << "Cумма объемов: " << result << endl;
    }
};

// maximum of three numbers and check if all of them are greater than 0
class TProgram4 {
public:
    void run(int num1, int num2, int num3) const {
        int max = 0;

        // find max number
        if (num1 >= num2 && num1 >= num3) {
            max = num1;
        } else if (num2 >= num1 && num2 >= num3) {
            max = num2;
        } else {
            max = num3;
        }

        cout << "Максимальное число: " << max << endl;

        // check if all are more then 0
        if (num1 > 0 && num2 > 0 && num3 > 0) {
            cout << "Все числа положительные." << endl;
        }
    }
};

// value of three variables L1, L2, L3
class TProgram5 {
public:
    void run() {
        bool T = true;
        bool L1 = false;
        bool L2 = T && L1;
        L1 = !L2 || !L1;
        bool L3 = L1 && L2 && T;
        cout << "L1 = " << L1 << "; L2 = " << L2 << "; L3 = " << L3 << endl;
    }
};

// value of boolean expression
class TProgram6 {
public:
    void run() {
        int a = 7;
        int b = 9;
        int c = 5;

        // replaced not (c <> b) with (c == b)
        bool res = (a > b) && (b == a + 2) || (c == b);
        cout << "Значение выражения: " << res << endl;
        cout << "Изменененное выражение: " << !res;
    }
};

// print alphabet
class TProgram7 {
public:
    void run() {
        // use simple string to print letters
        // actually i was lazy to print it in right order, but there was no such condition anyway
        string alphabet = "qwertyuiopasdfghjklzxcvbnm";
        cout << "В строку: " << alphabet << endl;
        cout << "В столбик: " << endl;

        for (const auto &i : alphabet) {
            cout << i << endl;
        }
    }
};

// count letters
class TProgram8 {
public:
    void run(const string &s, const char &letter) {
        cout << "общее кол-во символов: " << s.length() << endl;

        size_t count = 0;
        for (const auto &i : s) {
            // case sensitive actually
            if (letter == i) {
                ++count;
            }
        }
        cout << "Число повторений символа \"" << letter << "\": " << count << endl;
    }
};

// returns all simple divisors of number as vector of integer.
vector<int> simplify(const int num) {
    if (num == 1) {
        return {1};
    }
    int proc = num;
    int mult = 2;
    vector<int> result;
    while (proc != 1) {
        if (proc % mult == 0) {
            proc = proc / mult;
            result.push_back(mult);
            mult = 2;
        } else {
            mult += 1;
        }
    }

    return result;
}

bool is_simple(const int num) {
    // 1, 2, 3 are simple numbers
    if (num == 1 || num == 2 || num == 3) {
        return true;
    }

    // if number can be divided by 2 or 3 it's simple
    if ((num % 2 == 0) || (num % 3 == 0)) {
        return false;
    }

    // simple divisors starts by 3
    for (int k = 3; k < num; k++) {
        // we can skip divisors that can be divided by 3 or 2 to make faster counts
        if ((k % 3 == 0) || (k % 2 == 0)) {
            continue;
        }

        if (num % k == 0) {
            return false;
        }
    }
    return true;
}

// Check if the number is simple
class TProgram9 {
public:
    void run(int num) {
        cout << num << " - ";
        if (is_simple(num)) {
            cout << "простое число.";
        } else {
            cout << "не простое число";
        }
        cout << endl;
    }
};

// print all simple numbers less then N
class TProgram10 {
public:
    void run(int num) {
        for (int i = 1; i < num; i++) {
            if (is_simple(i)) {
                cout << "Простое число: " << i << "\n";
            }
        }
    }
};

// print simple multipliers
class TProgram11 {
public:
    void run(int num) {
        vector<int> simple = simplify(num);
        cout << "Простые множетели: ";
        for (const auto &i : simple) {
            cout << i << " ";
        }
        cout << endl;
    }
};

// print simple numbers in (n, m);
class TProgram12 {
public:
    void run(int n, int m) {
        for (int i = n; i < m; i++) {
            if (is_simple(i)) {
                cout << "Простое число: " << i << "\n";
            }
        }
        cout << endl;
    }
};

// find simple number less then num
class TProgram13 {
public:
    void run(int num) {
        if (num <= 1) {
            cout << "Таких натуральных чисел нет." << endl;
            return;
        }
        for (int i = num - 1; i > 1; i--) {
            if (is_simple(i)) {
                cout << "Простое число: " << i << endl;
                return;
            }
        }
    }

};

// returns vector of all divisors of number
vector<int> divisors(int num) {
    vector<int> result = {};
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            result.push_back(i);
        }
    }
    return result;
}

// check if number is perfect
class TProgram14 {
public:
    void run(int num) {
        vector<int> divs = divisors(num);
        int sum = 0;
        for (const int &i : divs) {
            sum += i;
        }

        cout << num << " - ";
        if (sum == num) {
            cout << "совершенное.";
        } else {
            cout << "не совершенное";
        }
        cout << endl;
    }
};

// check if two numbers are simple to each other
class TProgram15 {
public:
    void run(int n, int m) {
        // get all divisors of n and m
        vector<int> divs_n = divisors(n);
        vector<int> divs_m = divisors(m);

        // then make sets from them
        set<int> divs_n_set(divs_n.begin(), divs_n.end());
        set<int> divs_m_set(divs_m.begin(), divs_m.end());

        set<int> res;
        // count intersection of two sets
        set_intersection(divs_n_set.begin(), divs_n_set.end(), divs_m_set.begin(), divs_m_set.end(),
                         inserter(res, res.begin()));

        // if intersection contains only one number then it always will be "1"
        // that means our numbers are simple to each other.
        cout << n << "и" << m << " - ";
        if (res.size() == 1) {
            cout << "взаимно простые.";
        } else {
            cout << "не взаимно простые";
        }
        cout << endl;
    }
};

class TProgram16 {
public:
    void run(int num) {
        cout << num << " - ";
        if (is_palindrome(num)) {
            cout << "палиндром";
        } else {
            cout << "не палиндром";
        }
        cout << endl;
    }

protected:
    bool is_palindrome(int num) {
        if (num < 0) {
            // numbers lower then 0 cannot be palindrome because of "-" at the beginning of the string.
            return false;
        }
        // make string stream
        stringstream ss;
        // input our number to stream
        ss << num;
        // and save it as string
        string strnum = ss.str();
        size_t length = strnum.length();
        if (length == 1) {
            // strings with only one letter are always palindromes
            return true;
        }

        // make two iterators from our string
        auto left = strnum.begin();
        // the last one is '\0', so we should skip that.
        auto right = strnum.end() - 1;

        // then iterate while we do not reach the middle of the string
        while (right > left) {
            // check if the letter of the left iterator equals the letter of the right iterator
            if (*left != *right) {
                return false;
            }
            // move iterators to the neighbour symbol
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    cout << "Program #1 - сумма двух функций (15)" << endl;
    double res = TProgram1().run(15);
    cout << "Результат: " << res;
    cout << endl << endl;

    cout << "Program #2 - целая часть" << endl;
    cout << "Целая часть - " << TProgram2().run(res);
    cout << endl << endl;

    cout << "Program #3 - сумма объемов шаров (R=10, delta=0.5, k=5)" << endl;
    TProgram3().run(10.0, 0.5, 5);
    cout << endl << endl;

    cout << "Program #4 - максимум и положительность" << endl;
    TProgram4().run(9, 2, 15);
    cout << endl << endl;

    cout << "Program #5 - значение переменных L1, L2, L3" << endl;
    TProgram5().run();
    cout << endl << endl;

    cout << "Program #6 - значение выражения" << endl;
    TProgram6().run();
    cout << endl << endl;

    cout << "Program #7 - алфавит" << endl;
    TProgram7().run();
    cout << endl << endl;

    cout << "Program #8 - кол-во символов (\"London is the capital of Great Britain\", 'i')" << endl;
    TProgram8().run("London is the capital of Great Britain", 'i');
    cout << endl << endl;

    cout << "Program #9 - простое число (27, 10)" << endl;
    TProgram9 prog9;
    prog9.run(27);
    prog9.run(10);
    cout << endl << endl;

    cout << "Program #10 - простые числа < N (100)" << endl;
    TProgram10().run(100);
    cout << endl << endl;

    cout << "Program #11 - разложение на простые множители (50)" << endl;
    TProgram11().run(50);
    cout << endl << endl;

    cout << "Program #12 - простые числа (N, M) - (5 - 40)" << endl;
    TProgram12().run(5, 40);
    cout << endl << endl;

    cout << "Program #13 - простое число < N (100)" << endl;
    TProgram13().run(100);
    cout << endl << endl;

    cout << "Program #14 - совершенное число (496, 50)." << endl;
    TProgram14 prog14;
    prog14.run(496);
    prog14.run(50);
    cout << endl << endl;

    cout << "Program #15 - взаимно простые числа ((14, 27), (100, 420))" << endl;
    TProgram15 prog15;
    prog15.run(14, 27);
    prog15.run(100, 420);
    cout << endl << endl;

    cout << "Program #16 - палиндром (1052, 176671, 88988)" << endl;
    TProgram16 prog16;
    prog16.run(1052);
    prog16.run(176671);
    prog16.run(88988);

    return 0;
}