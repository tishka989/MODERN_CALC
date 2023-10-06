#include "Calc.h"
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char op) {
    if (op == '*' || op == '/') 
    {
        return 2;
    }
        
    else if (op == '+' || op == '-') 
    {
        return 1;
    }
        
    else 
    {
        return 0;
    }
        
}

int executeOperation(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}

int Calculator::evaluateExpression(const string& expression) {
    int len = expression.length();
    int i = 0;

    int* values = new int[len];
    char* operators = new char[len];
    int valIndex = 0;
    int opIndex = 0;

    while (i < len) {
        if (expression[i] == ' ') {
            i++;
            continue;
        }

        if (isdigit(expression[i])) {
            int num = 0;
            while (i < len && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            values[valIndex++] = num;
        }
        else if (expression[i] == '(') {
            operators[opIndex++] = expression[i];
            i++;
        }
        else if (expression[i] == ')') {
            while (opIndex > 0 && operators[opIndex - 1] != '(') {
                int b = values[--valIndex];
                int a = values[--valIndex];
                char op = operators[--opIndex];
                values[valIndex++] = executeOperation(a, b, op);
            }
            opIndex--;  
            i++;
        }
        else if (isOperator(expression[i])) {
            while (opIndex > 0 && getPriority(operators[opIndex - 1]) >= getPriority(expression[i])) {
                int b = values[--valIndex];
                int a = values[--valIndex];
                char op = operators[--opIndex];
                values[valIndex++] = executeOperation(a, b, op);
            }
            operators[opIndex++] = expression[i];
            i++;
        }
    }

    while (opIndex > 0) {
        int b = values[--valIndex];
        int a = values[--valIndex];
        char op = operators[--opIndex];
        values[valIndex++] = executeOperation(a, b, op);
    }

    int result = values[0];
    delete[] values;
    delete[] operators;
    return result;
}