#include <gtest/gtest.h>
#include "Hello.h"

TEST(HelloTest, ReturnsExpectedMessage) {
    EXPECT_EQ(getHelloMessage(), "Hello, C++ in VS Code!");
}

TEST(HelloTest, MessageIsNotEmpty) {
    EXPECT_FALSE(getHelloMessage().empty());
}