#include "VectorUtil.h"

using namespace std;

int main() {

    vector<Point> list;
    cout << "Default generator of 3 objects" << endl;
    fillDefault(list, 3);
    print(list);

    vector<float> list2 = {1.1f, 1.2f, 1.3f};
    vector<float> list3 = reverse(list2);
    cout << "Reverse:" << endl;
    print(list3);

    vector<vector<float>> listOfLists = {list2, list3};
    cout << "Merge vectors:" << endl;
    print(mergeVectors(listOfLists));

    vector<int> listInt;
    cout << "Default generator of 3 objects" << endl;
    fillDefault(listInt, 3);
    print(listInt);


    vector<Point> listSecond;
    cout << "Default generator of 20 objects" << endl;
    fillDefault(listSecond, 20);
    print(listSecond);

    vector<float> list4 = {1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.8f, 1.9f, 2.0f, 2.1f, 2.2f, 2.3f, 2.4f, 2.5f};
    vector<float> list5 = reverse(list4);
    cout << "Reverse:" << endl;
    print(list5);

    vector<vector<float>> secondListOfLists = {list4, list5};
    cout << "Merge vectors:" << endl;
    print(mergeVectors(secondListOfLists));

    vector<int> listIntiger;
    cout << "Default generator of 20 objects (int)" << endl;
    fillDefault(listInt, 20);
    print(listInt);

    vector<Point> list10;
    cout << "Default generator of 1000 objects" << endl;
    fillDefault(list10, 10);
    print(list10);

    return 0;

}