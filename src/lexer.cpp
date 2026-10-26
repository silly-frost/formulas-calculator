#include"lexer.hpp"
#include<cctype>
#include<stdexcept>

std::vector<Token> tokenize(const std::string& expr){
    std::vector<Token> tokens;
    size_t i = 0;

    while(i < expr.length()){
        char ch = expr[i];

        if(std::isspace(ch)){
            i++;
            continue;
        }

        if(ch == '+') {
            tokens.push_back({TokenType::Plus, std::nullopt});
            i++;
            continue;
        }
        else if(ch == '-') {
            tokens.push_back({TokenType::Minus, std::nullopt});
            i++;
            continue;
        }
        else if(ch == '/') {
            tokens.push_back({TokenType::Divide, std::nullopt});
            i++;
            continue;
        }
        else if(ch == '*') {
            tokens.push_back({TokenType::Multiply, std::nullopt});
            i++;
            continue;
        }
        else if(ch == '(') {
            tokens.push_back({TokenType::Left_Bracket, std::nullopt});
            i++;
            continue;
        }
        else if(ch == ')') {
            tokens.push_back({TokenType::Right_Bracket, std::nullopt});
            i++;
            continue;
        }

        if(std::isdigit(ch) || ch == '.'){
            std::string temp;
            while(i < expr.length() && (std::isdigit(expr[i]) || expr[i] == '.')){
                temp.push_back(expr[i]);
                i++;
            }
            double value = std::stod(temp);
            tokens.push_back({TokenType::Number, value});
            continue;
        }

        throw std::runtime_error("Неизвестный символ в строке");
    }

return tokens;
}
