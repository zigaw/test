#include "Date.h"
#include "SmartPointer.h"
#include "memory"

using namespace std;

int main() {


    SmartPointer<Date> date1(new Date(1, 5, 2023));
    std::cout << "Date 1: " << *date1 << std::endl;
    std::cout << "Reference count: " << date1.useCount() << std::endl;

    {
        SmartPointer<Date> date2(date1);
        std::cout << "Date 2: " << *date2 << std::endl;
        std::cout << "Reference count: " << date1.useCount() << std::endl;
    }

    std::cout << "Date 1: " << *date1 << std::endl;
    std::cout << "Reference count: " << date1.useCount() << std::endl;

    SmartPointer<Date> date3(new Date(2, 5, 2023));
    std::cout << "Date 3: " << *date3 << std::endl;
    std::cout << "Reference count: " << date3.useCount() << std::endl;

    date1 = date3;
    std::cout << "Date 1: " << *date1 << std::endl;
    std::cout << "Date 3: " << *date3 << std::endl;
    std::cout << "Reference count: " << date3.useCount() << std::endl;


    cout << "operator ==" << endl ;
    if(date1 == date3){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    };

    cout << "operator !=" << endl;
    if(date1 != date3){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    };

    cout << "operator == nullptr" << endl;
    if (date1 == nullptr){
        cout << "true" << endl;
    }else{
        cout << "false" << endl;
    };

    return 0;
}