#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

int main() {

    Time time1(0, 5, 30);
    Time time2(30, 14, 20);

    Time *time3 = new Time(20, 55, 59);
    string time4 = "33:22:11";
    string time5 = "00:12:06";
    Time time6 = Time::parse(time4);
    Time time7 = Time::parse(time5);

    cout << time1.toString() << endl;
    cout << time2.toString() << endl;
    cout << time3->toString() << endl;
    cout << time6.toString() << endl;
    cout << time7.toString() << endl;

    cout << time7.toStringGmt();


    delete time3;

    return 0;
}