#include"token.hpp"
#include<vector>

int getPriority(TokenType type);
std::vector<Token> parse(const std::vector<Token>& tokens);
