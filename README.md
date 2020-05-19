# GameOfLife
Shortly about code.

Any of living cells which has less than two living neighbours (up/down, left/right and diagonals) will die of loneliness.
    
Any of living cells which has more than three living neighbours dies of starvation due to a lack of sufficient resources.
    Any of dead cells with exactly three living neighbours will come to life through reproduction.

Our program is working in two different styles.(circular and clipped).Both of them work through CMakeLists.txt, and code that
is inside First DEfaultposition tested with the help of unit testing,and both of codes has Doxygen documentations.

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
