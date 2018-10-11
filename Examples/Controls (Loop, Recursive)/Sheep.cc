#include <iostream>
#include <cstdlib>
#include <ctime>

int main(){

  int right_choice = 0, total_no = 1000000;
  int i, j, car_door, guest_door, sheep_door, last_door;

  srand( static_cast<unsigned int>( time(NULL) ) );

  for ( i = 0; i < total_no; ++i ){
    car_door = rand() % 3 + 1;
    guest_door = rand() % 3 + 1;

    do {
      j = rand() % 3 + 1;
    } while ( j == guest_door || j == car_door );
    sheep_door = j;

    do {
      j = rand() % 3 + 1;
    } while ( j == guest_door || j == sheep_door );
    last_door = j;

    if ( last_door == car_door ) {
      ++right_choice;
    }
  }

  std::cout << (right_choice*1.0/total_no) << std::endl;

  return 0;
}
