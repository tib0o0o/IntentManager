#pragma once
#include <regex>
class IntentItem{
public:
  IntentItem(std::string action, std::string regex);
  std::string action;
  std::regex regex;
  bool validate(std::string input);
private:
};