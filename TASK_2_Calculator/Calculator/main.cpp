#include <iostream>

int16_t Calculator(int16_t num1, int16_t num2, int8_t operation)
{
   int16_t result=0;
    switch(operation)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            std::cerr << "Error: Division by zero\n";
        }
        break;
    default:
        std::cerr << "Error: Unknown operation\n";

    }
    return result;
}

int main()
{
    std::cout << "Welcome to Calculator: \n";
    std::cout << "Please Enter the first number: \n";
    int32_t num1;
    std::cin >> num1;

    std::cout << "Please Enter the second number: \n";
    int32_t num2;
    std::cin >> num2;

    std::cout << "Great! , Now Enter The operation ('+'  '-'  '*'  '/'): \n";
    int8_t operation;
    std::cin >> operation;

    int32_t result = Calculator(num1, num2, operation);
    std::cout << num1 << ' ' << operation << ' ' << num2 << " = " << result<< '\n';
}
