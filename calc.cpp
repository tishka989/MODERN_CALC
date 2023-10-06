
#include <iostream>

#include <windows.h>

#include "Calc.h"

using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    system("color 0d");

    cout << "Введите выражение: ";
    string expression;
    getline(cin, expression);

    Calculator calculator;
    int result = calculator.evaluateExpression(expression);

    cout << "Результат: " << result << endl;

    return 0;
}

