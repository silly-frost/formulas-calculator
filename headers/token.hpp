#pragma once
#include<optional>

enum class TokenType {
    Number = 0,
    Right_Bracket = 0,
    Left_Bracket = 0,

    Plus = 1,
    Minus = 1,

    Multiply = 2,
    Divide = 2 
};

struct Token {
    TokenType type;
    std::optional<double> value;
};
