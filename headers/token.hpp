#pragma once
#include<optional>

enum class TokenType {
    Number,
    Right_Bracket,
    Left_Bracket,
    Plus,
    Minus,
    Multiply,
    Divide 
};

struct Token {
    TokenType type;
    std::optional<double> value;
};
