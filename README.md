# GameOfLife
Shortly about code.

Any of living cells which has less than two living neighbours (up/down, left/right and diagonals) will die of loneliness.
    
Any of living cells which has more than three living neighbours dies of starvation due to a lack of sufficient resources.
    Any of dead cells with exactly three living neighbours will come to life through reproduction.

Our program is working in two different styles.(circular-DefaultPosition and clipped-RandomPosition). Both of them work through CMakeLists.txt, and code that
is inside First DefaultPosition tested with the help of unit testing,and both of codes has Doxygen documentations.



For running the 2 nd code we use:
mkdir build
cd build
cmake ..
make
./GameOfLife

For the 1 st one :
mkdir build
cd build
cmake ../
make
./pract_cm   
./unit_test   for testing



Also we have tried SDL on both codes and for the circular one we replased in tried_sdl2 directory. However the program is not working correctly it shows initial state of table, then doesn't change and stay same. Also happens displacement of grapics. 
