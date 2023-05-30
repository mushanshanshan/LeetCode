class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small): numBig(big), numMedium(medium), numSmall(small){}
    
    bool addCar(int carType) {
        if (carType == 3 && numSmall > 0) {
            numSmall--;
            return true;
        }
        if (carType == 2 && numMedium > 0) {
            numMedium--;
            return true;
        }
        if (carType == 1 && numBig > 0) {
            numBig--;
            return true;
        }
        return false;
    }

private:
    int numBig;
    int numMedium;
    int numSmall;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */