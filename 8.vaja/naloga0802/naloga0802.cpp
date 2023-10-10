#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> linkedList;
    cout << linkedList.isEmpty() << endl;
    linkedList.add(1);
    cout << linkedList.isEmpty() << endl;
    linkedList.add(2);
    linkedList.add(3);
    linkedList.add(4);
    cout << linkedList.getSize() << endl;
    cout << linkedList.at(3) << endl;

    Node<int> node(5);
    node.setValue(6);
    cout << node.getValue() << endl;
    cout << node.getNext() << endl;
    linkedList.add(node.getValue());
    linkedList.add(7);
    cout << linkedList.getSize() << endl;
    linkedList.insertAt(2,0);
    linkedList.insertAt(10,1);
 //   linkedList.insertAt(5,1000);
    for (int i = 0; i < linkedList.getSize(); ++i) {
        cout << linkedList.at(i) <<  " ";
    }
    cout << endl <<linkedList.getSize() << endl;
    return 0;
}
