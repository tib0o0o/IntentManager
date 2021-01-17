#include <chrono>
#include <iostream>
#include <vector>
#include "IntentManager.hpp"

IntentManager* IntentManager::instance = 0;

IntentManager& IntentManager::getInstance()
{
    if (instance == 0)
    {
        instance = new IntentManager();
    }

    return * instance;
}
IntentManager::~IntentManager()
{
  for (IntentItem* x: intents)
  {
    delete x;
  }
  intents.clear();
}

void IntentManager::createIntent(std::string regex, std::string action)
{
  intents.push_back(new IntentItem(regex, action));
}
std::string IntentManager::validateInput(std::string input)
{
  std::string result = "NONE";
  for (IntentItem* x: intents)
  {
    if (x->validate(input))
    {
      result = x->action;
      break;
    }
  }
  return result;
}



  