#include <gtest/gtest.h>

//code under test
int div_fun(int numerator, int denominator)
{
   if(denominator==0 || denominator < 0) {return 0;}
   return numerator/denominator;
}

class DivfunctionalityTestSuite: public::testing::TestWithParam<std::tuple<int,int,int>>
{
  //code
  Protected:
  DivfunctionalityTestSuite(){}
  ~DivfunctionalityTestSuite(){}
};
//Unit Test code
// Testsuite =[Testcase, Testcase...]
TEST_P(DivfunctionalityTestSuite, testForValidInputs)
{
	//Arrange (Given)
	int numerator =  std::get<0>(GetParam());
	int denominator = std::get<1>(GetParam());
	int Expected_Output = std::get<2>(GetParam());
	//Act
	int actual_Value = div_fun(numerator,denominator);
	//Assert (Then)
	ASSERT_EQ(actual_Value,Expected_Output);
}

/*TEST(DivfunctionalityTestSuite, testForNegativeInput)
{
	//Arrange (Given)
	int numerator = 6;
	int denominator = -5;
	int Expected_Output = 0;
	//Act
	int actual_Value = div_fun(numerator,denominator);
	//Assert (Then)
	ASSERT_EQ(actual_Value,Expected_Output);
}*/

INSTANTIATE_TEST_SUITE_P(divFun,
                         DivfunctionalityTestSuite,
                         ::testing::Values(
                         std::make_tuple(10, 5, 2),
                         std::make_tuple(10, 0, 0),
                         std::make_tuple(10, -5, 0)));

