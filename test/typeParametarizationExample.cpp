#include <gtest/gtest.h>

//code under test

// Interface
class ITempSensor{
    public:
    virtual int getOutsideTemp()=0;
};

class ModelATempSensor:public ITempSensor{
    public:
    int getOutsideTemp() { return 23;}
};

class ModelBTempSensor:public ITempSensor{
    public:
    int getOutsideTemp() { return 23;}
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegular(ITempSensor* address):tempSensorPtr(address){} //counstructor Injection principle
    void regulateTemp()
    {
      this->tempSensorPtr->getOutsideTemp();
    }
};

// ModelATempTempSensorFixture --> High level module
// objUnderTest ---> Low level module
// objUnderTest depends on ModelATempSensor
// Instead of ModelATempSensor, the objUnderTest(Low level module) should depend on Abstraction (ITempSensor/Interface)
class ModelATempTempSensorFixture:public::testing::Test{
    protected:
    //Arrange
    ModelATempSensor objUnderTest;
};

TEST_F(ModelATempTempSensorFixture, GetTempTest)
{
   ASSERT_EQ(objUnderTest.getOutsideTemp(),23);
}

class ModelBTempTempSensorFixture:public::testing::Test{
    protected:
    //Arrange
    ModelBTempSensor objUnderTest;
};

TEST_F(ModelBTempTempSensorFixture, GetTempTest)
{
   ASSERT_EQ(objUnderTest.getOutsideTemp(),23);
}


// Note: If you are adding more sensor means you have to add more fixtures and test cases. 
// in this case you can use type parametarized 
// All classes should use the same method, Interface.
// Method can be different[strategy]
