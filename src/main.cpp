#include <iostream>
#include <string>
#include "IntentManager.hpp"

int main() {
    std::string input = "";
    IntentManager& intentManager = IntentManager::getInstance();
    intentManager.createIntent("([W|w]hat)(.*)(weather )(?!in )(.*)", "Get Weather");
    intentManager.createIntent("([W|w]hat)(.*)(weather )(in)(.*)", "Get Weather City");
    intentManager.createIntent("([A|a]m)(.*)( free)(.*)", "Check calendar");
    intentManager.createIntent("([T|t]ell)(.*)(fact)", "Get Fact");
    
    while (input != "exit" || input != "Exit")
    {
        std::cout << "How can i help you?\n";
        std::getline(std::cin, input);
        std::cout << intentManager.validateInput(input) + "\n";
    }
    intentManager.~IntentManager();
    return 0;
}