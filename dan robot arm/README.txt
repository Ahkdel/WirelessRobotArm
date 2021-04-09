                   .:                     :,                                          
,:::::::: ::`      :::                   :::                                          
,:::::::: ::`      :::                   :::                                          
.,,:::,,, ::`.:,   ... .. .:,     .:. ..`... ..`   ..   .:,    .. ::  .::,     .:,`   
   ,::    :::::::  ::, :::::::  `:::::::.,:: :::  ::: .::::::  ::::: ::::::  .::::::  
   ,::    :::::::: ::, :::::::: ::::::::.,:: :::  ::: :::,:::, ::::: ::::::, :::::::: 
   ,::    :::  ::: ::, :::  :::`::.  :::.,::  ::,`::`:::   ::: :::  `::,`   :::   ::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  :::::: ::::::::: ::`   :::::: ::::::::: 
   ,::    ::.  ::: ::, ::`  :::.::    ::.,::  .::::: ::::::::: ::`    ::::::::::::::: 
   ,::    ::.  ::: ::, ::`  ::: ::: `:::.,::   ::::  :::`  ,,, ::`  .::  :::.::.  ,,, 
   ,::    ::.  ::: ::, ::`  ::: ::::::::.,::   ::::   :::::::` ::`   ::::::: :::::::. 
   ,::    ::.  ::: ::, ::`  :::  :::::::`,::    ::.    :::::`  ::`   ::::::   :::::.  
                                ::,  ,::                               ``             
                                ::::::::                                              
                                 ::::::                                               
                                  `,,`


https://www.thingiverse.com/thing:2984487
Dans 9g Micro Servo Robot Arm by tetsuharu is licensed under the BSD License license.
http://creativecommons.org/licenses/BSD/

# Summary

Dan's Robot Arm
===============

Github: https://github.com/tetsuharu/dans_robot_arm

A simple desktop robot arm using typical 9g microservos.

**Height:** 280mm

**Base width:** 120mm

**Reach:** 160mm


BOM
----

Bill of materials for building the robot arm.

- 230g of filament
- 6x 9g microservos
- 5x servo cable extenders
- arduino with 7 servo pins (I used a mega)
- raspberry pi (or similar)
- usb power supply
- 3mm ball bearings


Build Instructions
---

1. Print out all parts (base, base-joint, arm-joint, arm-joint-2, arm-joint-3)
2. Clear out servo-cable holes with some kind of metal pick
3. Screw servos into servo spots
4. Screw servo horns into servo-horn spots
5. Plug servos into arduino, set their positions to be half-range
6. Press base-joint servo horn into base servo gear, use long screwdriver to attach
7. Press other joint servo horns into their servo gears, screw in
8. Attach servo cable extenders to servos far from the base
9. Hot glue servo cables to one side of the robot arm, giving slack around joints
10. Connect servos to arduino



Developing
---
SolveSpace was chosen as the CAD tool for this project. The STL files are included for convenience.

You can download solvespace at http://solvespace.com/download.pl , the latest windows version can be found at https://ci.appveyor.com/project/whitequark/solvespace/build/artifacts .

**long_servo_horn.slvs** and **9gmicroservo.slvs** are shared libraries, used as "hole" pieces in the other SLVS files.

The arm-joint pieces are similar, but they don't share a base object. Any of these pieces can be redseigned at any time as long as you follow these constraints:

- arm-joint-1: 59mm in, 40mm out, 8mm hole for axle
- arm-joint-2: 39mm in, 30mm out, 8mm hole for axle
- arm-joint-3: 29mm in, perpendicular axis out, 8mm hole for axle

I've run into rendering problems when extending the lengths of the arms, but ideally those would be parametric. 


Usage
---

TBD


Hi There
---

I made this. I'm Dan. That's why it's called Dan's Robot Arm. I hope you understand this now.

Please build this. It's easy. Peace and love!