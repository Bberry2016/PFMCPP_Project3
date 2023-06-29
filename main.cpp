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
    //5 properties:
    //    - midi device (std::string)
    std::string midiDevice = "akai";
    //    - volume (double)
    double volume = 9.797;
    //    - amount of modulation (float)
    float amtModulation = 2.f;
    //    - number of keys (int)
    int numKeys = 88;
    //    - sustain (double)
    double amtSustain = 4.66663;
    //3 things it can do:
    //    - adjust volume   // Difference in initial volume setting and volume end value
    double adjustVolume(double volumeKnobDiff);
    //    - pitch shift    // Shirt from initial pitch based on note played with no modulation
    float pitchShift(float intendedPitch = 0);
    //    - sustain
    void sustian();
};

struct ElectricGuitar 
{
    //5 properties:
    //    - amount of pickups (int) 
    int amtPickups = 2;
    //    - tremolo bar position (int)
    int tremoloBarPosition = -2;
    //    - string vibration (double)
    double stringVibration = 82.947;
    //    - tone knob (int)
    int toneKnobPosition = 0;
    //    - pickup selector (int)
    int pickupSelection = 3;
    //3 things it can do:
    //    - capture string vibrations
    void captureStringVibrations();
    //    - dial in/out treble frequencies    // Select treble frequency level
    int dialInOutTrebleFreq(int initToneValue);
    //    - adjust string tension    // Returns difference of string tension before and after use of tremolo bar
    float adjustStringTension(float initStringTension);
};

struct WashingMachine 
{
    //5 properties:
    //    - power supply (float)
    float powerInAmps = 13.f;
    //    - cycle selection (int)
    int cycleSelection = 8;
    //    - door open/closed (bool)
    bool doorOpen = false;
    //    - amount of cold/hot water (float)
    float waterTemperature = 77.f;
    //    - drum rotation speed (double)
    double drumRotationSpeed = 27.6435;
    //3 things it can do:
    //    - seal in moisture 
    void sealInMoisture();
    //    - indicate type of laundry    // Indicates load characteristics
    int indicateTypeOfLaundry();
    //    - optimize water temperature   // Adjusts water temperature based on load type
    float optimizeWaterTemp(int laundryType);
};

struct Refridgerator
{
    //5 properties:
    //    - amount of ice cubes produced (int)
    int amtIceCubesPerHour = 25;
    //    - crisper drawer humidity (float)
    float crisperDrawerHumidity = 0.f;
    //    - water temperature (int)
    int waterTemp = 62;
    //    - type of ice dispensed (int)
    int iceType = 2;
    //    - thermostat set value (float)
    float fridgeTemp = 35.75;
    //3 things it can do:
    //    - optimize humidity level    // Adjusts crisper drawer humidity to optimum level for produce
    float optimizeHumidityLevel();
    //    - illuminate refridgerator   
    void illuminateRefridgerator(bool openDoor);
    //    - indicate fridge temperature 
    float indicateFridgeTemp();
};

struct Display 
{
    //5 properties:
    //    - brightness (double)
    double brightness = 87.35908;
    //    - color mode (int)
    int colorMode = 3;
    //    - x-scale (int)
    int xScale = 10;
    //    - y-scale (int)
    int yScale = 15;
    //    - refresh rate (double)
    double refreshRate = 200.0009;
    //3 things it can do:
    //    - select color mode    // Selects from array of color modes
    int selectColorMode(int hue, int saturation);
    //    - adjust illumination based on room     // Modifys display brightenss based on brightness in room
    double adjustIlluminationBasedOnRoom(double roomBrightness);
    //    - adjust display characteristics    // Selects display preset based on desired screen settings (size of text, display size and other items)
    int adjustDisplayCharacteristics(int textSize, int orientation, float screenArea);
};

struct Controls 
{
    //5 properties:
    //    - x-axis calibration (float)
    float xAxis = 12.f;
    //    - y-axis calibration (float)
    float yAxis = 12.f;
    //    - cursor speed (double)
    double cursorSpeed = 10.956;
    //    - button (char)
    char button = 'B';
    //    - button function assignment (int)
    int buttonFunction = 9;

    struct JoyStick
    {
        int directionalScope = 0;    // Can the joystick move 360 degrees, or just UDLR   
        double xPosition = 0.0;
        double yPosition = 0.0;
        std::string knobType = "Sphere";
        float height = 4.f;

        double returnToCenter(double xActivePosition, double yActivePosition, bool release = true);    // Return joystick to center position when released
        void moveVertically(double yActivePosition);
        void moveHorizontally(double xActivePosition);
    };

    //3 things it can do:
    //    - assign button functionality
    void assignButtonFunctionality();
    //    - delay compensation    // Calibrates control to combat latency
    float delayCompensation(float timeButtonPressed, float timeActionExecuted, JoyStick activeJoystick);
    //    - adjust distance traveled    // Defines amount of movement needed to get from point A to point B based on amount of joystick movement
    double adjustDistanceTraveled(int xPointA, int yPointA, int xPointB, int yPointB, JoyStick activeJoystick);
};

struct ArcadeBox 
{
    //5 properties:
    //    - storage location (int)
    int storageLocation = 0;
    //    - number of openings (int)
    int numOpenings = 4;
    //    - weight (float)
    float weight = 123.f;
    //    - style (std::string)
    std::string style = "Upright";
    //    - number of panels (int)
    int numPanels = 5;
    //3 things it can do:
    //    - store item here 
    void storeItemHere(std::string storeableItem);
    //    - open arcade box back panel
    void openArcadeBoxBackPanel();
    //    - disassemblable and transport
    void disassembleAndTransport();
};

struct Speakers 
{
    //5 properties:
    //    - volume (float)
    float volume = 9.f;
    //    - input device (int)
    int inputDevice = 0;
    //    - left speaker output (double)
    double SpeakerL = 5.0;
    //    - right speaker output (double)
    double SpeakerR = 5.0;
    //    - mono audio (int)
    int monoAudio = 0;
    //3 things it can do:
    //    - adjust volume    // Difference in initial volume setting and volume end value
    double adjustVolume(double volumeKnobDiff);
    //    - change input device
    void changeInputDevice();
    //    - combine sound     // volume output mono-audio
    double combineSound(double SpeakerL, double SpeakerR);
};

struct CoinBox 
{
    //5 properties:
    //    - coin return (bool)
    bool coinReturn = false;
    //    - amount of coin stored (int)
    int amtCoinStored = 134;
    //    - coin slot size (float)
    double coinSlotSize = 0.958;
    //    - amount of change backed-up (int)
    int amtBackedUpChange = 2;
    //    - coin detector switch (bool)
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
        int creditApplied(int amountPerCredit, int amountSinceLastGameFinished, int currentCredit);    // Updates credits based on amount of coin inserted
    };

    //3 things it can do:
    //    - detect type of coin inserted    // Indicate what type of coin was inserted based on height and weight
    int detectTypeOfCoinInserted(int coinHeight, int coinWeight);
    //    - store change
    void storeChange();
    //    - return coins when not accepted
    void returnCoinsWhenNotAccepted(CoinSensor penny);
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
