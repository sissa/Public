#include "gtest/gtest.h"

//the names are usually "test suite name" and "test name"
TEST(SampleTest, Equality) {
    EXPECT_EQ(1 + 1, 2);
}

TEST(HelloTest, MyTestName){
   EXPECT_EQ("Hello, World!", "Hello, World!");
}

//this is the toy function we are testing
std::vector<int> getVector() {
    return {1, 2, 3};
}

//here we are checking if the vector the function returns is {1,2,3}
TEST(FunctionTest, ChekingOutput) {

    // Act: Call the function.
    std::vector<int> result = getVector();

    // Assert: Check the result.
    EXPECT_EQ(result, std::vector<int>({1, 2, 3}));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

