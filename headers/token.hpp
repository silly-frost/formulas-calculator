#pragma once

#include<optional>

enum class TokenType {
    Plus,
    Minus,
    Right_Bracket,
    Left_Bracket,
    Multiply,
    Divide,
    Number,
};

struct Token {
    TokenType type;
    std::optional<double> value;
};
