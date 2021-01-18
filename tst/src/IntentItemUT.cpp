#include "gtest/gtest.h"
#include "IntentItem.hpp"

TEST(IntentItemUT, validate_1)
{
    ///////////////////////Setup////////////////////////////
    IntentItem item("([W|w]hat)(.*)(weather )(?!in )(.*)", "Get Weather");
    std::regex regEx("([W|w]hat)(.*)(weather )(?!in )(.*)");
    ///////////////////////Test////////////////////////////
    ASSERT_FALSE(item.validate("What is the weather today?"));
    ASSERT_TRUE(item.validate("What is the weather in Berlin?"));
    ///////////////////////Cleanup////////////////////////////
}
