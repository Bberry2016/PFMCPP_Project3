/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




// 
// UDT No. 1 
// 

struct VolumeKnob
{
    int amountTurned = 0;

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

struct WasherDryerDoor
{
    void engageHotAirGasket(){}
    void engageWaterGasket(){}
};

struct HybridWasherDryer
{
    float powerInAmps = 13.f;
    int cycleSelection = 8;
    bool doorOpen = false;
    float waterTemperature = 77.f;
    double drumRotationSpeed = 27.6435;
     
    void sealInMoisture();
    int indicateTypeOfLaundry();
    float optimizeWaterTemp(int laundryType);

    WasherDryerDoor doorWhenDryer;
    WasherDryerDoor doorWhenWasher;
};

void HybridWasherDryer::sealInMoisture()
{
    if(cycleSelection < 4 && doorOpen == false)
    {
        doorWhenDryer.engageHotAirGasket();
    }
    else if(cycleSelection >= 4 && doorOpen == false)
    {
        doorWhenWasher.engageWaterGasket();
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
    
    if(monoAudio == 1) 
    {
        combinedOutput = 0.5 * (SpeakerL + SpeakerR);
    }
    
    return combinedOutput;
}



// 
// UDT No. 9
// 

struct Coin 
{
    double diameter = 0.0;
    double weight = 0.0;
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
            if(coinType == 0) 
            {
                return false;
            }
            return true;
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
    acceptCoin = coinSensor.acceptCoin(coinSensor.detectTypeOfCoinInserted(coin.weight, coin.diameter));

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
    Example::main();

    
    std::cout << "good to go!" << std::endl;
}
