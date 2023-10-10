#include "Printer.h"

using namespace std;

int main() {

    Printer printer({});
    printer.add("prviElement");
    cout << printer.toString() << endl;
    printer.add(2, 3, 4, "five", 6.6f);
    cout << printer.toString() << endl;

    printer.addMultiple(std::vector<int>{12, 45});

    cout << printer.toString() << endl;

    printer.remove([](string &element) {
        return element.size() == 1;
    });

    std::vector<std::string> vec = {"prog", "prog2"};
    printer.addMultiple(vec);
    cout << printer.toString() << endl;

    printer.remove([vec](string &element) {
        for (int i = 0; i < vec.size(); ++i) {
            if (element == vec[i]){
                return true;
            }
        }
    });

    cout << printer.toString() << endl;

    printer.sort([](string &elementOne, string &elementTwo) {
        if (elementOne.size() < elementTwo.size()) {
            return true;
        }
    });
    cout << printer.toString() << endl;

    printer.checkAndCorrect([](const std::string& element) {
        return std::islower(element[0]);
    }, [](std::string& element) {
        element[0] = std::toupper(element[0]);
    });

    printer.applyToAll([](std::string& element){
        element = element + "TEST";
    });
    cout << printer.toString() << endl;

    printer.removeJobs(2,1,0);


    printer.print();
    return 0;
}