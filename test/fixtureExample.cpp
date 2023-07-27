
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

