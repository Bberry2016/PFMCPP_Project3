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
#include <cmath>
#include <vector>
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


// ONCE REVISITING
// 1. Fill out remaining member functions
// 2. Figure out how to instantiate member variables of a UDT within a UDT
// (See 'Controls' struct)

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

struct PitchShifter
{
    int amountPushPull = 0;

    int push(bool)
    {
        return amountPushPull;
    }
};

struct SustainPedal
{
    bool pedalDepressedOrReleased(std::string pedalPosition)
    {
        if(pedalPosition == "depressed")
        {
            return true;
        }
        return false;
    }
    
    int fadeOut(int volume, int fadeTimeInSeconds)
    {
        int volumeIncrements = volume / fadeTimeInSeconds;
        while(volume > 0)
        {
            volume -= volumeIncrements;
        }
        return volume;
    }
};

struct Keyboard 
{
    std::string midiDevice = "akai";
    int pitch = 0, volume = 0, amtSustain = 0, numKeys = 88;
    
    void adjustVolume(int volumeKnobDiff);
    void pitchShift(int pitchDiff);
    void sustain();

    VolumeKnob volumeKnob;
    PitchShifter pitchShifter;
    SustainPedal sustainPedal;
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

void Keyboard::pitchShift(int pitchDiff)
{
    if(pitchShifter.push(true) > 0)
    {
        pitch += pitchDiff;
    }
    else if(pitchShifter.push(false) < 0)
    {
        pitch -= pitchDiff;
    }
}

void Keyboard::sustain()
{
    if(sustainPedal.pedalDepressedOrReleased("depressed"))
    {
        amtSustain += 1;
    }
    else if(sustainPedal.pedalDepressedOrReleased("released"))
    {
        sustainPedal.fadeOut(volume, amtSustain);
    }
}

// 
// UDT No. 2
// 

struct TremoloBar
{
    float amountTension = 0.f;
    
    float lift(float adjustedTension);
    float depress(float adjustedTension);
};

float TremoloBar::lift(float adjustedTension)
{
    amountTension += adjustedTension;
    return amountTension;
}

float TremoloBar::depress(float adjustedTension)
{
    amountTension -= adjustedTension;
    return amountTension;
}

struct Strings
{
    double stringVibration = 0.0;
};

struct Pickup
{
    Strings lowEString, aString, dString, gString, bString, highEString;
    
    std::vector<double> arrOfStringVibrationValues;

    void captureStringVibrations();
};

void Pickup::captureStringVibrations()
{
    arrOfStringVibrationValues.push_back(lowEString.stringVibration);
    arrOfStringVibrationValues.push_back(aString.stringVibration);
    arrOfStringVibrationValues.push_back(dString.stringVibration);
    arrOfStringVibrationValues.push_back(gString.stringVibration);
    arrOfStringVibrationValues.push_back(bString.stringVibration);
    arrOfStringVibrationValues.push_back(highEString.stringVibration);
}

struct ElectricGuitar 
{
    int amtPickups = 2;
    float tremoloBarPosition = 0.f;
    int toneKnobPosition = 0;
    int pickupSelection = 3;

    void strum();
    int dialInOutTrebleFreq(int toneAdjustmentValue);
    float adjustStringTension(bool, bool, float adjustedTremoloBarPosition, float amountTension);

    TremoloBar tremoloBar;
    Pickup singleCoil;
};

void ElectricGuitar::strum()
{
    singleCoil.captureStringVibrations();
}

int ElectricGuitar::dialInOutTrebleFreq(int toneAdjustmentValue)
{
    toneKnobPosition += toneAdjustmentValue;
    return toneKnobPosition;
}

float ElectricGuitar::adjustStringTension(bool tensionIncreased, bool tensionDecreased, float adjustedTremoloBarPosition, float amountTension)
{
    if(tensionIncreased == true)
    {
        adjustedTremoloBarPosition += tremoloBar.lift(amountTension);
    }
    else if(tensionDecreased == true)
    {
        adjustedTremoloBarPosition -= tremoloBar.depress(amountTension);
    }
    else
    {
        adjustedTremoloBarPosition = 0;
    }

    return adjustedTremoloBarPosition;
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
    int cycleSelection;
    float powerInAmps, waterTemperature;
    double drumRotationSpeed;
    bool doorOpen;

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
    int amtIceCubesPerHour, waterTemp, iceType;
    float crisperDrawerHumidity, fridgeTemp;
    bool lightUp;
    
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
    int colorMode, xScale, yScale;
    double refreshRate, brightness;
    
    int selectColorMode(int hue, int saturation);
    double adjustIlluminationBasedOnRoom(double roomBrightness);
    int adjustDisplayCharacteristics(int textSize, int orientation, float screenArea);
    void storeItemInArcadeBox(){}
};

struct Controls 
{
    double xAxis, yAxis;
    char button;
    int buttonFunction;

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
