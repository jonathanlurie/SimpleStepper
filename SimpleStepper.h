
#define _MICROSTEP_ 8

class SimpleStepper{
  public:
  
  //  constructor
  SimpleStepper(int dirPin, int stepPin);
  
  // destructor
  virtual ~SimpleStepper();
  
  // set the direction
  void setDirectionClockWise();
  void setDirectionCounterClockWise();
  
  // set the total number of step for a rotation (default: 200);
  // since it works with microstepping, this value will be multiplied by _MICROSTEP_
  void setTotalNbSteps(int nbSteps);
  
  // set the number of rotations per minute
  void setRPM(float rpm);
  
  // run a microstep in accordance to the speed needed
  void runOneMicrostep();
  
  // perform a specific number of microsteps  in accordance to the speed
  void rotationMicrosteps(long int nbMicrosteps);
  
 // perform a specific number of steps in accordance to the speed
  void rotationSteps(long int nbSteps);
  
  // turn of a number of degrees in accordance to the speed
  void rotationDegrees(float nbDegrees);
  
  // perform a micro step, rather fast, not related with the speed computation from setRPM().
  // used in the need of triggering an independent micro step, but not suitable for constant revolution
  void renegateMicroStep();
  
  // performs _MICROSTEP_ renegate micro steps ( see renegateMicroStep() for further details)
  void renegateStep();
  
  // performs _MICROSTEP_/2 renegate micro steps ( see renegateMicroStep() for further details)
  void renegateHalfStep();
  
  // performs _MICROSTEP_/4 renegate micro steps ( see renegateMicroStep() for further details)
void  renegateQuarterStep();
  
  
  void turn();
  
  private:
  
  void updateRotationDirection();
  
  // private: run a microstep in accordance to the speed needed (in case of quite fast speed)
  void runOneQuickMicrostep();
  
  // private: run a microstep in accordance to the speed needed (in case of quite low speed)
  void runOneSlowMicrostep();
  
  
  
  int m_dirPin;  // pin to plug for direction
  int m_stepPin;  // pin to plug for doing a step
  int m_direction;  // HIGH is counter clock wise and LOW is clock wise
  long int m_nbSteps;  // number of step for one rotation
  long int m_intervaluSec; //speed management: intervale in micro seconds
  long int m_intervalmSec; // speed management: intevale in milli seconds
  int m_LIMIT_OF_DELAY_USECONDS;
  
  bool m_isTurning;
  
};






