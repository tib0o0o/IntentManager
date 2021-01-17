#pragma once
#include <vector>
#include "IntentItem.hpp"

class IntentManager{
private:
  /* Here will be the instance stored. */
  static IntentManager* instance;
  std::vector <IntentItem*>intents;

  /* Private constructor to prevent instancing. */
  IntentManager()= default;

public:
    /* Static access method. */
  static IntentManager& getInstance();
  void createIntent(std::string regex, std::string action);
  std::string validateInput(std::string input);
  virtual ~IntentManager();
};