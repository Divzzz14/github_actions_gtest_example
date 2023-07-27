#include "gtest/gtest.h"
class C{};

class B
{
   C* ptr;
   public:
   //universal object creation
   B(C* addressofObject): ptr(addressofObject){
   }
};

class A
{
   B* ptr;
   public:
   //universal object creation
   A(B* addressofObject): ptr(addressofObject){
   }
   bool operation(){
     return true;
   }
  
};

TEST(TestFixtureObject, operationTest)
{
    //Arrange
   C cObj;
   B bObj(&cObj);
   A aObj(&bObj);
   //Act and assert
   ASSERT_TRUE(aObj.operation());
}

TEST(TestFixtureObject, operationFalseTest)
{
    //Arrange
   C cObj;
   B bObj(&cObj);
   A aObj(&bObj);
   //Act and assert
   ASSERT_FALSE(aObj.operation());
}

