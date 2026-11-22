#include"evaluator.hpp"
#include<stack>
#include<stdexcept>

double evaluate(const std::vector<Token>& rpn_tokens){
    std::stack<double> values;

    for(const auto& token : rpn_tokens) {
        if(token.type == TokenType::Number){
            values.push(token.value.value()); 
        }
        else {
            if(values.size() < 2) throw std::runtime_error("Ошибка: Недостаточно операндов для операции");

            double right = values.top();
            values.pop();

            double left = values.top();
            values.pop();

            double result = 0.0;

            switch(token.type){
                case TokenType::Plus:
                    result = left + right;
                    break;
                case TokenType::Minus:
                    result = left - right;
                    break;
                case TokenType::Multiply:
                    result = left * right;
                    break;
                case TokenType::Divide:
                    if(right == 0.0) throw std::runtime_error("Ошибка: нельзя делить на ноль");
                    else result = left / right;
                    break;
                default:
                    throw std::runtime_error("Ошибка: неизвестный оператор");
                    break;
            }
            values.push(result);
        }
    }

    if(values.size() != 1) throw std::runtime_error("Ошибка: некорректное выражение");
    return values.top();
}
