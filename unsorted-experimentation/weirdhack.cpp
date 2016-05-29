#include <iostream>
template<typename T>
struct Check_If_T_Is_Class_Type
{
    template<typename C> static char func (char C::*p);
    template<typename C> static int func (...);
    enum{val = sizeof (func<T>(0)) == 1};
};
class empty{};
int main()
{   
    std::cout<<Check_If_T_Is_Class_Type<empty>::val; // 1
    std::cout<<Check_If_T_Is_Class_Type<char>::val; // 0
    std::cout<<Check_If_T_Is_Class_Type<int>::val; // 0
    std::cout<<Check_If_T_Is_Class_Type<std::string>::val; //1
}
