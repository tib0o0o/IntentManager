#include "gtest/gtest.h"
#include "IntentManager.hpp"

TEST(IntentManagerUT, getInstance_1)
{
    ///////////////////////Setup////////////////////////////
    IntentManager& intentManagerClownOne = IntentManager::getInstance();
    IntentManager& intentManagerClownTwo = IntentManager::getInstance();
    ///////////////////////Test////////////////////////////
    ASSERT_EQ(&intentManagerClownOne, &intentManagerClownTwo);
    ///////////////////////Cleanup////////////////////////////
    intentManagerClownOne.~IntentManager();
    intentManagerClownTwo.~IntentManager();
}

TEST(IntentManagerUT, createIntent_1)
{
    ///////////////////////Setup////////////////////////////
    IntentManager& intentManager = IntentManager::getInstance();
    intentManager.createIntent("([W|w]hat)(.*)(weather )(?!in )(.*)", "Get Weather");
    intentManager.createIntent("([W|w]hat)(.*)(weather )(in)(.*)", "Get Weather City");
    ///////////////////////Test////////////////////////////
    ///////////////////////Cleanup////////////////////////////
    intentManager.~IntentManager();
}

TEST(IntentManagerUT, validateInput_1)
{
    ///////////////////////Setup////////////////////////////
    IntentManager& intentManager = IntentManager::getInstance();
    intentManager.createIntent("([W|w]hat)(.*)(weather )(?!in )(.*)", "Get Weather");
    intentManager.createIntent("([W|w]hat)(.*)(weather )(in)(.*)", "Get Weather City");
    std::string resultCity = "";
    std::string resultGlobal = "";
    ///////////////////////Test////////////////////////////
    resultCity = intentManager.validateInput("What is the weather in Paris?");
    ASSERT_EQ(resultCity, "Get Weather City");
    resultGlobal = intentManager.validateInput("What is the weather here?");
    ASSERT_EQ(resultGlobal, "Get Weather");
    ///////////////////////Cleanup////////////////////////////
    intentManager.~IntentManager();
}

TEST(IntentManagerUT, validateInput_2)
{
    ///////////////////////Setup////////////////////////////
    IntentManager& intentManager = IntentManager::getInstance();
    intentManager.createIntent("([A|a]m)(.*)( free)(.*)", "Check calendar");
    intentManager.createIntent("([T|t]ell)(.*)(fact)", "Get Fact");
    std::string resultCity = "";
    std::string resultGlobal = "";
    ///////////////////////Test////////////////////////////
    resultCity = intentManager.validateInput("Am i free?");
    ASSERT_EQ(resultCity, "Check calendar");
    resultGlobal = intentManager.validateInput("m i free?");
    ASSERT_EQ(resultGlobal, "NONE");
    ///////////////////////Cleanup////////////////////////////
    intentManager.~IntentManager();
}

TEST(IntentManagerUT, distractorIntentManager_1)
{
    ///////////////////////Setup////////////////////////////
    IntentManager& intentManager = IntentManager::getInstance();
    intentManager.createIntent("([W|w]hat)(.*)(weather )(?!in )(.*)", "Get Weather");
    std::string resultCity = "";
    resultCity = intentManager.validateInput("What is the weather in Paris?");
    ///////////////////////Test////////////////////////////
    intentManager.~IntentManager();
    ///////////////////////Cleanup////////////////////////////
}