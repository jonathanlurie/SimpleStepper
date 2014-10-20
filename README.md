-------------------------------------------------------------------
SimpleStepper
=============

Copyright (c) 2013, Jonathan LURIE, All rights reserved.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3.0 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library.

-------------------------------------------------------------------



SimpleStepper is a simple library for running a stepper engine on an
Arduino board. Il was tested with the EasyDriver from Sparkfun.


Here is how to start with it:
<ol>
<li>install it as a regular Arduino library</li>

<li>In your Arduino sketch, include SimpleStepper</li>
```cpp
 #include "SimpleStepper.fr"
```

<li>Initialize some values before constructing an object:</li>

```cpp
 // the pin for direction
 const int motorDirPin = 5;

 // the pin asking to perform a step
 const int motorStepPin = 6;

 // number of step in one entire revolution
 // note: this is not mandatory when performing solo steps
 const int totalNbStep360 = 200;

 // define the speed of rotation in RPM
 // note: this is not mandatory when performing solo steps
 const float speedRP = 0.25;
```

<li>Construct your SimpleStepper object and initialize it:</li>

```cpp
 // Construct, using the values defined previously
 SimpleStepper m_motor(motorDirPin, motorStepPin);

 // defining the direction
 // note : not only for init, can be change later
 m_motor.setDirectionCounterClockWise();
 // OR
 m_motor.setDirectionClockWise();

// defining the number of step in an entire revolution
// note : not only for init, can be change later
m_motor.setTotalNbSteps(totalNbStep360);

// defining the speed in RPM
// note : not only for init, can be change later
m_motor.setRPM(speedRP);
```

<li>Let's spin it!</li>

You have several way of spinning:

```cpp
// spin with an angle in degree.
// It will use the speed defined above (if possible), use:
void rotationDegrees(float nbDegrees);

// spin over a number of steps.
// It will use the speed defined above (if possible), use:
void rotationSteps(long int nbSteps);

// perform just one single step. Does not depend on the speed (RPM) neither
// on the total number of steps in an entire revolution.
// Useful for precision work:
void renegateStep();
```

<li>A bit further, for experts</li>

Other modes are possible for an independant movement, but they are less precise
than renegateStep(). They are based on the fact that a renegateStep is actually
composed of 8 micro steps.

Micro steps can be used independently but the heigh of them are not equal in
term of degrees. Anyway, you can use those ones:

```cpp
// performs half a step (4 micro steps)
void renegateHalfStep();

// performs a quarter of step (2 micro steps)
void  renegateQuarterStep();
```

If you think (or know) your stepper motor does not count 8 micro steps for
one step, you can go to the top of the file SimpleStepper.h and edit
the following line:

```cpp
#define _MICROSTEP_ 8
```

</ol>
