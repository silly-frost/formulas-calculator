#include"parser.hpp"
#include<stack>
#include<stdexcept>

int getPriority(TokenType type) {
    if(type == TokenType::Plus || type == TokenType::Minus){
        return 1;
    }
    else if(type == TokenType::Divide || type == TokenType::Multiply){
        return 2;
    }
    return 0;
}

std::vector<Token> parse(const std::vector<Token>& tokens){
    std::vector<Token> output;
    std::stack<Token> operators;
    
    for(const auto& token : tokens) {
        if(token.type == TokenType::Number) {
            output.push_back(token);
        }
        else if(token.type == TokenType::Left_Bracket) {
            operators.push(token);
        }
        else if(token.type == TokenType::Right_Bracket) {
            while(!operators.empty() && operators.top().type != TokenType::Left_Bracket){
                output.push_back(operators.top());
                operators.pop();
            }
            if (operators.empty()) {
               throw std::runtime_error("Ошибка: пропущена открывающая скобка");
            }
            operators.pop();
        }
        else if(token.type == TokenType::Plus || token.type == TokenType::Minus || token.type == TokenType::Divide || token.type == TokenType::Multiply){
            int current_priority = getPriority(token.type);
            while(!operators.empty() && getPriority(operators.top().type) >= current_priority){
                output.push_back(operators.top());
                operators.pop();
            }

            operators.push(token);
        }
    }

    while(!operators.empty()){
        if(operators.top().type == TokenType::Left_Bracket){
            throw std::runtime_error("Ошибка: пропущена закрывающая скобка");
        }
            output.push_back(operators.top());
            operators.pop();
        }

    return output;
}
