#include <gtest/gtest.h>

//code under test
int div_fun(int numerator, int denominator)
{
   if(denominator==0 || denominator < 0) {return 0;}
   return numerator/denominator;
}

//Unit Test code
// Testsuite =[Testcase, Testcase...]
TEST(DivfunctionalityTestSuite, testForValidInputs)
{
	//Arrange (Given)
	int numerator = 6;
	int denominator = 2;
	int Expected_Output = 3;
	//Act
	int actual_Value = div_fun(numerator,denominator);
	//Assert (Then)
	ASSERT_EQ(actual_Value,Expected_Output);
}

TEST(DivfunctionalityTestSuite, testForNegativeInput)
{
	//Arrange (Given)
	int numerator = 6;
	int denominator = -5;
	int Expected_Output = 0;
	//Act
	int actual_Value = div_fun(numerator,denominator);
	//Assert (Then)
	ASSERT_EQ(actual_Value,Expected_Output);
}


//Run Test Runner
int main()
{
	::testing::InitGoogleTest();
	return RUN_ALL_TESTS();
}
