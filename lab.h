//
// Created by Danila Gvozdikov on 04.01.2021.
//

#ifndef LAB2_LAB_H
#define LAB2_LAB_H

//
// Created by Danila Gvozdikov on 24.12.2020.
//

#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <regex>

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

double inputNum(const string& err_desc = "") {
    string input;
    cin >> input;

    basic_regex numreg("[-]?\\d+(\\.\\d+)?", regex_constants::ECMAScript);
    if (!regex_match(input.begin(), input.end(), numreg)) {
        throw runtime_error("Неверный формат числа.");
    }

    double result = 0;
    try {
        result = stod(input);
    } catch (exception) {
        throw runtime_error(err_desc);
    }
    return result;
}

double inputDouble(const string& err_desc = "") {
    return inputNum(err_desc);
}

int inputInt(const string& err_desc = "") {
    return int(inputNum(err_desc));
}


// Base class for program
// All programs below inherits base program but should provide:
//  - variables to input and variables for results
//  - method InputValues() to input required data
//  - method ValidateValues() to validate input that throws runtime_error when data is incorrect.
//  - method ProcessValues() to cound result
//  - const method OutputResult() to print result
class TProgram {
public:
    void run() {
        while (true) {
            try {
                this->InputValues();  // input required variables
            } catch (runtime_error) {
                cout << "Некорректный тип введенных данных, ожидалось целое число." << endl
                     << "Попробуйте еще раз." << endl;
                continue;
            }

            try {
                this->ValidateData();
            } catch (runtime_error err) {
                cout << "Введеные данные некорректны, ошибка: \"" << err.what() << "\"" << endl
                     << "Попробуйте ввести новые данные." << endl;
                continue;
            }

            break;
        }

        this->ProcessValues(); // count result from input
        cout << endl;  // just one empty string between input and output

        // Print fixed float values with 4 numbers after the comma.
        cout << fixed;
        cout.precision(4);
        this->OutputResult();  // print results
    };

protected:
    virtual void InputValues() {};
    virtual void ValidateData() const {};
    virtual void ProcessValues() {};
    virtual void OutputResult() const {};
};


#endif //LAB2_LAB_H
