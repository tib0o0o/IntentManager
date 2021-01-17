#include <iostream>
#include "IntentItem.hpp"

IntentItem::IntentItem(std::string __regex, std::string __action)
{
  action = __action;
  regex = std::regex(__regex);
}

bool IntentItem::validate(std::string input)
{
    return std::regex_match(input, this->regex);
}
