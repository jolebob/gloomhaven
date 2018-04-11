# gloomhaven

## gloom.cpp : 
  Simulates attack deck drawing with basic set of cards + personalized deck given in input
  Outputs the total number of times each card was drawn + average attack value

#### example
```
echo 10000000 3 1 5 1 6 1 1 1 1| ./gloom
*** GLOOMHAVEN ATTACK DECK CARDS SIMULATOR ***

Simulation will be done with basic Attack +2 action
Please enter the following (one line input) :
  Number of : SimulationTurn , -1 , -2 , +1 , +2 , +0 , Miss , x2 , Draw , +1&Draw

SIMU FOR [-1,-1,-1,-1,-1,-2,+1,+1,+1,+1,+1,+2,+0,+0,+0,+0,+0,+0,MISS,x2,]
  >> 2380507 475999 2379725 477067 2858474 714664 713564 0 0 
average attack = 1.99992
 
SIMU FOR [-1,-1,-1,-2,+1,+1,+1,+1,+1,+2,+0,+0,+0,+0,+0,+0,MISS,x2,Draw,+1&Draw,]
  >> 1579826 525629 2630273 526259 3158868 788722 790423 526506 526894 
average attack = 2.15824
```
