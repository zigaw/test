#include "VerticalPictograph.h"
#include "HorizonatalPictograph.h"
int main() {
    using namespace std::string_literals;
    system(("chcp "s + std::to_string(65001)).c_str());

    VerticalPictograph vp1("Pictograph", std::vector<int>{5, 1, 3, 4}, '*');
    std::cout << vp1.getSymbol() << std:: endl;
    std::cout << vp1.getTitle() << std:: endl;
    vp1.setTitle("First Pictograph");
    vp1.show(ColorCode::Blue);

    VerticalPictograph vp2("Pictograph", std::vector<int>{1, 2, 3, 4}, 'o');
    vp2.show(ColorCode::Red);

    VerticalPictograph vp3("Pictograph", std::vector<int>{3, 2, 6, 4, 2}, 'X');
    vp3.show(ColorCode::Green);

    VerticalPictograph vp4("Pictograph", std::vector<int>{9, 6, 3}, '+');
    vp4.show(ColorCode::Deafult);

    HorizonatalPictograph hg1("Horizontal Graph",std::vector<int>{5,1,5,1},'#');
    hg1.show(ColorCode:: Blue);

    HorizonatalPictograph hg2("Horizontal Graph",std::vector<int>{1,3,2,4},'.');
    hg2.show(ColorCode:: Red);

    HorizonatalPictograph hg3("Horizontal Graph",std::vector<int>{1,2,3,4,5,4,3,2,1},'%');
    hg3.show(ColorCode::Green);
    return 0;
}