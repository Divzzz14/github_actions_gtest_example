#include "gtest/gtest.h"

//code under Test
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


// Unit Test Code

//Fixture class that is derived from google test class
class TestFixtureTestSuite: public testing::Test{
//anything we write under this comes under protected
protected:
A* aPtr;
B* bPtr;
C* cPtr;
TestFixtureTestSuite(){
  //Initialization
}
~TestFixtureTestSuite(){
   //Releasing the resources
}
void SetUp()
{
   //Arrange
   this->cPtr = new C();
   this->bPtr = new B(cPtr);
   this->aPtr = new A(bPtr);
}

void TearDown()
{
  //delete resources
   delete cPtr;
   delete bPtr;
   delete aPtr;
}

};

TEST_F(TestFixtureTestSuite, operationTest)
{
   //Act and assert
   ASSERT_TRUE(aPtr->operation());//stack object 
}

TEST_F(TestFixtureTestSuite, operationFalseTest)
{
   //Act and assert
   ASSERT_FALSE(aPtr->operation());
}

/*TEST(TestFixtureObject, operationTest)
{
    //Arrange
   C cObj;
   B bObj(&cObj);
   A aObj(&bObj);
   //Act and assert
   ASSERT_TRUE(aObj.operation());//stack object 
}

TEST(TestFixtureObject, operationFalseTest)
{
    //Arrange
   C cObj;
   B bObj(&cObj);
   A aObj(&bObj);
   //Act and assert
   ASSERT_FALSE(aObj.operation());
}*/

