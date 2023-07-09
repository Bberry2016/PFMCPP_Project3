 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
#include <cmath>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */

struct Limb 
{
    void stepForward(){}
    int stepSize(int strideLength)
    {
        return strideLength;
    }
};

struct Person 
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, int backFootLocation, int frontFootLocation, bool startWithLeftFoot);

    Limb leftFoot;
    Limb rightFoot;
};

void Person::run(int, int backFootLocation, int frontFootLocation, bool startWithLeftFoot)
{
    int strideLength = frontFootLocation - backFootLocation;
    
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize(strideLength) + rightFoot.stepSize(strideLength);
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

// 
// UDT No. 1 
// 

struct VolumeKnob
{
    int amountTurned;

    int turnRight(bool)
    {
        return amountTurned;
    }
};

struct Keyboard 
{
    std::string midiDevice = "akai";
    int volume = 9;
    float amtModulation = 2.f;
    int numKeys = 88;
    double amtSustain = 4.66663;
    
    void adjustVolume(int volumeKnobDiff);
    float pitchShift(float intendedPitch = 0);
    void sustian();

    VolumeKnob volumeKnob;
};

void Keyboard::adjustVolume(int volumeKnobDiff) 
{
    if(volumeKnob.turnRight(true) > 0)
    {
        volume += volumeKnobDiff;
    }
    else if(volumeKnob.turnRight(false) < 0)
    {
        volume -= volumeKnobDiff;
    }
}

// 
// UDT No. 2
// 

struct TremoloBar
{
    void lift(){}
    void depress(){}
};

struct ElectricGuitar 
{
    int amtPickups = 2;
    float tremoloBarPosition = 0.f;
    double stringVibration = 82.947;
    int toneKnobPosition = 0;
    int pickupSelection = 3;
    
    void captureStringVibrations();
    int dialInOutTrebleFreq(int initToneValue);
    float adjustStringTension(bool, float tremoloBarPositionDifference);

    TremoloBar tremoloBar;
};

float ElectricGuitar::adjustStringTension(bool tensionIncreased, float tremoloBarPositionDifference)
{
    if(tensionIncreased == true)
    {
        tremoloBar.lift();
    }
    else
    {
        tremoloBar.depress();
    }
    
    return tremoloBarPosition += tremoloBarPositionDifference;
}

// 
// UDT No. 3
// 

struct washerDryerDoor
{
    void hotAirGasketEngage(){}
    void waterGasketEngage(){}
};

struct hybridWasherDryer
{
    float powerInAmps = 13.f;
    int cycleSelection = 8;
    bool doorOpen = false;
    float waterTemperature = 77.f;
    double drumRotationSpeed = 27.6435;
     
    void sealInMoisture();
    int indicateTypeOfLaundry();
    float optimizeWaterTemp(int laundryType);

    washerDryerDoor doorWhenDryer;
    washerDryerDoor doorWhenWasher;
};

void hybridWasherDryer::sealInMoisture()
{
    if(cycleSelection < 4 && doorOpen == false)
    {
        doorWhenDryer.hotAirGasketEngage();
    }
    else if(cycleSelection >= 4 && doorOpen == false)
    {
        doorWhenWasher.waterGasketEngage();
    }
    else
    {
        std::cout << "Close the door.";
    }
}

// 
// UDT No. 4
// 

struct RefridgeratorDoor 
{
    void openDoor(){}
};

struct Refridgerator
{
    int amtIceCubesPerHour = 25;
    float crisperDrawerHumidity = 0.f;
    int waterTemp = 62;
    int iceType = 2;
    float fridgeTemp = 35.75;
    bool lightUp = false;
    
    float optimizeHumidityLevel();
    bool illuminateRefridgerator(bool);
    float indicateFridgeTemp();

    RefridgeratorDoor refridgeratorDoor;
};

bool Refridgerator::illuminateRefridgerator(bool lightOn)
{
    if(lightOn == false) refridgeratorDoor.openDoor();

    return lightUp = true;
}

// 
// UDT No. 5
// 

struct Display 
{
    double brightness = 87.35908;
    int colorMode = 3;
    int xScale = 10;
    int yScale = 15;
    double refreshRate = 200.0009;
    
    int selectColorMode(int hue, int saturation);
    double adjustIlluminationBasedOnRoom(double roomBrightness);
    int adjustDisplayCharacteristics(int textSize, int orientation, float screenArea);
    void storeItemInArcadeBox(){}
};

struct Controls 
{
    double xAxis = 0;
    double yAxis = 0;
    char button = 'B';
    int buttonFunction = 9;

    // 
    // UDT No. 6
    // 

    struct JoyStick
    {
        int directionalScope = 0;    // Can the joystick move 360 degrees, or just UDLR   
        double xPosition = 0.0;
        double yPosition = 0.0;
        std::string knobType = "Sphere";
        float height = 4.f;
        int cursorSpeed = 1;

        double returnToCenter(double xActivePosition, double yActivePosition, bool release = true);
        void moveVertically(double yActivePosition);
        void moveHorizontally(double xActivePosition);
        int getActiveCursorSpeed()
        {
            return cursorSpeed;
        }
    };

    void assignButtonFunctionality();
    float delayCompensation(float timeButtonPressed, float timeActionExecuted, JoyStick activeJoystick);
    double adjustDistanceTraveled(int adjustmentAmount, double xPointA, double yPointA, double xPointB, double yPointB, JoyStick activeJoystick);
    void storeItemInArcadeBox(){}
};

double Controls::adjustDistanceTraveled(int adjustedCursorSpeed, double xPointA, double yPointA, double xPointB, double yPointB, JoyStick activeJoystick)
{
    double totalDifference = fabs((xPointB - xPointA) - (yPointB - yPointA));
    
    int activeCursorSpeed = activeJoystick.getActiveCursorSpeed();

    return totalDifference *= (1 + (adjustedCursorSpeed - activeCursorSpeed));
}

// 
// UDT No. 8
// 

struct Speakers 
{
    float volume = 9.f;
    int inputDevice = 0;
    double SpeakerLOutput = 5.0;
    double SpeakerROutput = 5.0;
    int monoAudio = 0;
    
    double adjustVolume(double volumeKnobDiff);
    void changeInputDevice();
    double combineSound(double SpeakerL, double SpeakerR);
    void storeItemInArcadeBox(){}
};

double Speakers::combineSound(double SpeakerL, double SpeakerR)
{
    double combinedOutput = 0.0;
    
    if(monoAudio == 1) combinedOutput = 0.5 * (SpeakerL + SpeakerR);

    return combinedOutput;
}



// 
// UDT No. 9
// 

struct Coin 
{
    double coinDiameter = 0.0;
    double coinWeight = 0.0;

    bool inserted()
    {
        return true;
    }
};

struct CoinBox 
{
    bool coinReturn = false;
    int amtCoinStored = 134;
    double coinSlotSize = 0.958;
    int amtBackedUpChange = 2;
    bool quarterDetected = true;

    // 
    // UDT No. 10
    // 

    struct CoinSensor
    {
        bool isAQuarter = true;
        int amountInCents = 0;
        double coinDiameter = 0.00;
        double coinWeight = 0.00;
        int creditToPlay = 3;

        int detectTypeOfCoinInserted(double coinDiameterInches, double coinWeightGrams)
        {
            int coinType = 0;
            
            if((coinDiameterInches >= 0.74 || coinDiameterInches <= 0.76) && (coinWeightGrams >= 2.4 || coinWeightGrams <= 2.6))
            {
                coinType = 1;
            }
            else if((coinDiameterInches >= 0.695 || coinDiameterInches <= 0.715) && (coinWeightGrams >= 2.168 || coinWeightGrams <= 2.368))
            {
                coinType = 2;
            }
            else if((coinDiameterInches >= 0.825 || coinDiameterInches <= 0.845) && (coinWeightGrams >= 4.9 || coinWeightGrams <= 5.1))
            {
                coinType = 3;
            }
            else if((coinDiameterInches >= 0.945 || coinDiameterInches <= 0.965) && (coinWeightGrams >= 5.57 || coinWeightGrams <= 5.77))
            {
                coinType = 4;
            }

            return coinType;
        }
        bool acceptCoin(int coinType)
        {
            if(coinType == 0) return false;
            else return true;
        }
        int creditApplied(int amountPerCredit, int amountSinceLastGameFinished, int currentCredit);     
    };

    bool storeChange(CoinSensor coinSensor);
    void returnCoinsWhenNotAccepted(CoinSensor coinSensor);
    void storeItemInArcadeBox(){}

    Coin coin;
};

bool CoinBox::storeChange(CoinSensor coinSensor)
{
    bool acceptCoin = false;
    if (coin.inserted()) acceptCoin = coinSensor.acceptCoin(coinSensor.detectTypeOfCoinInserted(coin.coinWeight, coin.coinDiameter));

    return acceptCoin;
}

// 
// UDT No. 7
// 

struct ArcadeBox 
{
    int numOpenings = 4;
    float weight = 123.f;
    std::string style = "Upright";
    int numPanels = 5;
     
    void storeItemHere(std::string storeableItem, int storageLocation);
    void openArcadeBoxBackPanel();
    void disassembleAndTransport();

    CoinBox coinBox;
    Display display;
    Speakers speakers;
    Controls controls;    
};

void ArcadeBox::storeItemHere(std::string storeableItem, int storageLocation)
{
    if(storageLocation >= 0 && storageLocation <= 3)
    {
        if(storageLocation == 0) 
        {
            coinBox.storeItemInArcadeBox();
        }
        else if(storageLocation == 1)
        {
            display.storeItemInArcadeBox();
        }
        else if(storageLocation == 2)
        {
            speakers.storeItemInArcadeBox();
        }
        else
        {
            controls.storeItemInArcadeBox();
        }
        std::cout << storeableItem + "successfully stored in location" + std::to_string(storageLocation);
    }
    else 
    {
        std::cout << "You can't store that here.";
    }
}







int main()
{
    std::cout << "good to go!" << std::endl;
}
