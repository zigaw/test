#include "Date.h"
#include "SmartPointer.h"
#include "memory"

using namespace std;
int main(){

    Date d1(1, 1, 2020);
    Date d2(1, 1, 2020);
    Date d3(2, 1, 2020);

    cout << "oprerator <:" << endl;
    cout << "d1 < d2: " << (d1 < d2) << endl;
    cout << "d1 < d3: " << (d1 < d3) << endl;


    cout << "friend function:" << endl;
    cout << "Datum d1: " << d1 << endl;

    cout << "oprerator ==:" << endl;
    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 == d3: " << (d1 == d3) << endl;

    cout << "oprerator ++:" << endl;
    cout << "Datum d1: " << d1 << endl;
    cout << "New date d1: " << d1++ << endl;
    cout << "New date d1: " << ++d1 << endl;

    cout << "oprerator ++ (dummy):" << endl;
    cout << "Datum d2: " << d2 << endl;
    d2++;
    cout << "New date d2: " << d2 << endl;

    SmartPointer<Date> date1(new Date(6, 5, 2020));
    cout << "Smart pointer: " << *date1 << endl;

    unique_ptr<Date> date2(new Date(2, 2, 2020));
    cout << "Smart pointer: " << *date2<< endl;
/*
    SmartPointer<Date> d1(new Date(1, 2, 2021));
    SmartPointer<Date> d2(new Date(1, 1, 2022));
    cout << "Is " << (*d1) << " earlier than " << (*d2) << "? " << ((*d1 < *d2) ? "Yes." : "No.") << endl;
*/
    return 0;
}