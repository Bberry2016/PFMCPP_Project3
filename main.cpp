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
    bool stepForward();
    int stepSize();
};

struct Person 
{
    Limb leftFoot;
    Limb rightFoot;

    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
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
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
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


struct Keyboard 
{
    std::string midiDevice = "akai";
    double volume = 9.797;
    float amtModulation = 2.f;
    int numKeys = 88;
    double amtSustain = 4.66663;
    
    double adjustVolume(double volumeKnobDiff);
    float pitchShift(float intendedPitch = 0);
    void sustian();
};

struct ElectricGuitar 
{
    int amtPickups = 2;
    int tremoloBarPosition = -2;
    double stringVibration = 82.947;
    int toneKnobPosition = 0;
    int pickupSelection = 3;
    
    void captureStringVibrations();
    int dialInOutTrebleFreq(int initToneValue);
    float adjustStringTension(float initStringTension);
};

struct WashingMachine 
{
    float powerInAmps = 13.f;
    int cycleSelection = 8;
    bool doorOpen = false;
    float waterTemperature = 77.f;
    double drumRotationSpeed = 27.6435;
     
    void sealInMoisture();
    int indicateTypeOfLaundry();
    float optimizeWaterTemp(int laundryType);
};

struct Refridgerator
{
    int amtIceCubesPerHour = 25;
    float crisperDrawerHumidity = 0.f;
    int waterTemp = 62;
    int iceType = 2;
    float fridgeTemp = 35.75;
    
    float optimizeHumidityLevel();
    void illuminateRefridgerator(bool openDoor);
    float indicateFridgeTemp();
};

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
};

struct Controls 
{
    float xAxis = 12.f;
    float yAxis = 12.f;
    double cursorSpeed = 10.956;
    char button = 'B';
    int buttonFunction = 9;

    struct JoyStick
    {
        int directionalScope = 0;    // Can the joystick move 360 degrees, or just UDLR   
        double xPosition = 0.0;
        double yPosition = 0.0;
        std::string knobType = "Sphere";
        float height = 4.f;

        double returnToCenter(double xActivePosition, double yActivePosition, bool release = true);         void moveVertically(double yActivePosition);
        void moveHorizontally(double xActivePosition);
    };

    void assignButtonFunctionality();
    float delayCompensation(float timeButtonPressed, float timeActionExecuted, JoyStick activeJoystick);
    double adjustDistanceTraveled(int xPointA, int yPointA, int xPointB, int yPointB, JoyStick activeJoystick);
};

struct ArcadeBox 
{
    int storageLocation = 0;
    int numOpenings = 4;
    float weight = 123.f;
    std::string style = "Upright";
    int numPanels = 5;
     
    void storeItemHere(std::string storeableItem);
    void openArcadeBoxBackPanel();
    void disassembleAndTransport();
};

struct Speakers 
{
    float volume = 9.f;
    int inputDevice = 0;
    double SpeakerL = 5.0;
    double SpeakerR = 5.0;
    int monoAudio = 0;
    
    double adjustVolume(double volumeKnobDiff);
    void changeInputDevice();
    double combineSound(double SpeakerL, double SpeakerR);
};

struct CoinBox 
{
    bool coinReturn = false;
    int amtCoinStored = 134;
    double coinSlotSize = 0.958;
    int amtBackedUpChange = 2;
    bool quarterDetected = true;

    struct CoinSensor
    {
        bool isAQuarter = true;
        int amountInCents = 0;
        float coinDiameter = 0.f;
        float coinWeight = 0.f;
        int creditToPlay = 3;

        void inserted();
        void acceptCoin(int country, bool isDirty = false);
        int creditApplied(int amountPerCredit, int amountSinceLastGameFinished, int currentCredit);     };

    int detectTypeOfCoinInserted(int coinHeight, int coinWeight);
    void storeChange();
    void returnCoinsWhenNotAccepted(CoinSensor penny);
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
