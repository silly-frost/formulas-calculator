#include"parser.hpp"
#include<stack>
#include<stdexcept>

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
            operators.pop();
        }
        else if(token.type == TokenType::Plus || token.type == TokenType::Minus || token.type == TokenType::Divide || token.type == TokenType::Multiply){
            int current_priority = static_cast<int>(token.type);
            while(!operators.empty() && static_cast<int>(operators.top().type) >= current_priority){
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
