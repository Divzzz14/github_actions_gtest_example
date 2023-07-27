#include <gtest/gtest.h>

using testing::Types;
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
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address}{} //counstructor Injection principle
    void regulateTemp()
    {
      this->tempSensorPtr->getOutsideTemp();
    }
};

// Note: If you are adding more sensor means you have to add more fixtures and test cases. 
// in this case you can use type parametarized 
// All classes should use the same method, Interface.
// Method can be different[strategy]

// ModelATempTempSensorFixture --> High level module
// objUnderTest ---> Low level module
// objUnderTest depends on ModelATempSensor
// Instead of ModelATempSensor, the objUnderTest(Low level module) should depend on Abstraction (ITempSensor/Interface)


template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* creatObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* creatObject<ModelBTempSensor>() { return new ModelBTempSensor(); }


class TempSensorFixture:public testing::Test{
    protected:
    //Arrange
     ITempSensor* objUnderTest;
     TempSensorFixture():objUnderTest{createObject<T>()} {} // T can be either ModelATempSensor or ModelBTempSensor
     
};

typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture, GetTempTest)
{
   ASSERT_EQ(this->objUnderTest->getOutsideTemp(),23);
}




