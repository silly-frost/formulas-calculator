#include"evaluator.hpp"
#include"lexer.hpp"
#include"parser.hpp"
#include<iostream>
#include<exception>

int main(){
    std::cout << "Введите выражение или слово \'exit\', чтобы завершить работу. \n";

    while(true){
        std::string user_input;
        std::getline(std::cin, user_input);

        if(user_input.empty()) continue;
        else if(user_input == "exit") return 0;

        try { 
            double result = evaluate(parse(tokenize(user_input)));
            std::cout << " = " << result << "\n";
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
        catch(...) {
            std::cerr << "Неизвестная ошибка \n";
        }
    }
}
