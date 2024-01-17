#include "CppUTest/TestHarness.h"
#include "../src/main.cpp"

TEST_GROUP(HelloWorld) {
};

TEST(HelloWorld, PrintHello) {
    std::stringstream output;
    std::streambuf* coutBuf = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());  // Redirect cout to capture the output

    main();  // Call the main function

    std::cout.rdbuf(coutBuf);  // Restore cout to its normal state
    STRCMP_EQUAL("Hello, World!\n", output.str().c_str());
}
