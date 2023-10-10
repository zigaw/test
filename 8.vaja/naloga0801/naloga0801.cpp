#include "LinearQueue.h"

using namespace std;


int main() {
    cout << "Empty nad praznimi vektorji" << endl;
    LinearQueue<int> intVector({});
    LinearQueue<float> floatVector({});
    LinearQueue<Time> timeVector({});

    cout << intVector.empty() << endl;
    cout << floatVector.empty() << endl;
    cout << timeVector.empty() << endl;

    cout << "Empty nad polnimi vektorji" << endl;
    intVector.add(1);
    floatVector.add(1.8f);
    Time time1 = Time(22, 11, 33);
    timeVector.add(time1);

    cout << intVector.empty() << endl;
    cout << floatVector.empty() << endl;
    cout << timeVector.empty() << endl;

    cout << "Size" << endl;

    Time time2 = Time(12, 21, 3);
    Time time3 = Time(11, 10, 23);

    LinearQueue<int> intVector2({1, 2, 3, 4, 5});
    LinearQueue<float> floatVector2({1.1f, 2.2f, 3.3f, 4.4f});
    LinearQueue<Time> timeVector2({time1, time2, time3});


    cout << intVector2.size() << endl;
    cout << floatVector2.size() << endl;
    cout << timeVector2.size() << endl;

    cout << "element" << endl;

    cout << intVector2.element() << endl;
    cout << floatVector2.element() << endl;
    cout << timeVector2.element().toString() << endl;

    cout << "remove" << endl;

    cout << intVector.remove() << endl;
    cout << floatVector.remove() << endl;
    cout << timeVector.remove() << endl;
    cout << "remove again" << endl;
    cout << intVector.remove() << endl;
    cout << floatVector.remove() << endl;
    cout << timeVector.remove() << endl;

    cout << "to string" << endl;

    cout << intVector2.toString() << endl;
    cout << floatVector2.toString() << endl;
    cout << timeVector2.toString() << endl;

    cout << "reverse" << endl;
    intVector2.reverse();
    floatVector2.reverse();
    timeVector2.reverse();
    cout << intVector2.toString() << endl;
    cout << floatVector2.toString() << endl;
    cout << timeVector2.toString() << endl;

    cout << "get max" << endl;

    cout << intVector2.getMax() << endl;
    cout << floatVector2.getMax() << endl;
    cout << timeVector2.getMax().toString() << endl;

    cout << "insert at" << endl;

    intVector2.insertAt(7, 3);
    floatVector2.insertAt(9.9f, 9);
    timeVector.insertAt(time1, 2);
    cout << intVector2.toString() << endl;
    cout << floatVector2.toString() << endl;
    cout << timeVector2.toString() << endl;

    cout << "before unique" << endl;

    intVector2.insertAt(7, 3);
    intVector2.insertAt(7, 3);
    intVector2.insertAt(7, 3);
    floatVector2.insertAt(9.9f, 3);
    floatVector2.insertAt(9.9f, 1);
    timeVector2.insertAt(time1, 1);
    timeVector2.insertAt(time1, 6);
    cout << intVector2.toString() << endl;
    cout << floatVector2.toString() << endl;
    cout << timeVector2.toString() << endl;
    cout << "after unique" << endl;
    intVector2.unique();
    floatVector2.unique();
    timeVector2.unique();
    cout << intVector2.toString() << endl;
    cout << floatVector2.toString() << endl;
    cout << timeVector2.toString() << endl;
    cout << "Capasity"<<endl;
    cout<< intVector2.getCapacity() << endl;
    cout << intVector2.toString() << endl;
    intVector2.changeCapacity(4);
    cout << intVector2.toString() << endl;
    cout << timeVector2.toString() << endl;
    timeVector2.changeCapacity(1);
    cout << timeVector2.toString() << endl;
    timeVector2.add(time1);
    return 0;
}