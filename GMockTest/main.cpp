// #include "tst_gmocktestcase.h"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    std::cout << "Current C++ Standard No. = " << __cplusplus << std::endl;
    std::cout << "Current program is " << sizeof(void*) * 8 << "-bit\n" << std::endl;

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
