# gloomhaven

## gloom.cpp : 
  Simulates attack deck drawing with basic set of cards + personalized deck given in input
  Outputs the total number of times each card was drawn + average attack value

#### example
```
echo 10000000 2 3 1 5 1 6 1 1 1 1| ./gloom
*** GLOOMHAVEN ATTACK DECK CARDS SIMULATOR ***

Please enter the following (one line input) :
  Number of : SimulationTurn , attack, -1 , -2 , +1 , +2 , +0 , Miss , x2 , Draw , +1&Draw

SIMU FOR [-1,-1,-1,-1,-1,-2,+1,+1,+1,+1,+1,+2,+0,+0,+0,+0,+0,+0,MISS,x2,]
  >> -1         -2         +1         +2         +0         Miss       x2         Draw       +1&Draw
  >> 2380507    475999     2379725    477067     2858474    714664     713564     0          0          
  >> 23.81%     4.76%      23.80%     4.77%      28.58%     7.15%      7.14%      0.00%      0.00%      
average attack = 1.99992

SIMU FOR [-1,-1,-1,-2,+1,+1,+1,+1,+1,+2,+0,+0,+0,+0,+0,+0,MISS,x2,Draw,+1&Draw,]
  >> -1         -2         +1         +2         +0         Miss       x2         Draw       +1&Draw
  >> 1579826    525629     2630273    526259     3158868    788722     790423     526506     526894     
  >> 14.29%     4.76%      23.80%     4.76%      28.58%     7.14%      7.15%      4.76%      4.77%      
average attack = 2.15824
```
