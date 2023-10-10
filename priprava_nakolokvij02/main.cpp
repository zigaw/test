#include "Fuel.h"
using namespace std;

bool ascendingPricesPerLiter(const Fuel &refuel1,const Fuel &refuel2){
    if( refuel1.getPricePerLiter() < refuel2.getPricePerLiter()){
        return true;
    }
    return false;
}

bool descendingPricesPerLiter(const Fuel &refuel1,const Fuel &refuel2){
    if( refuel1.getPricePerLiter() < refuel2.getPricePerLiter()){
        return false;
    }
    return true;
}

int main(){
try {
    std::vector<Fuel> fuelLog = Fuel::loadFromFile("refuel.csv");
    for (int i = 0; i < fuelLog.size(); ++i) {
        cout << fuelLog[i].toString();
    }

    Fuel::sortRefulesvector(fuelLog,descendingPricesPerLiter);
    Fuel::sortRefulesvector(fuelLog,ascendingPricesPerLiter);

    try{
        Fuel::saveToFile(fuelLog,"outRefules.txt");
    }catch (FileNotFound &ex){
        cout << ex.what();
    }

}catch(FileNotFound &e){
    cout<< e.what();
}


    return 0;
}