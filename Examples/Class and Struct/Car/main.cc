#include <iostream>
#include "Car.h"

int main(){

  int i;

  std::vector<Car*> cars;
  cars.push_back( new RV("AA",5) );
  cars.push_back( new Limousine("aa",4) );
  cars.push_back( new RV("BB",5) );
  cars.push_back( new RV("CC",3) );
  cars.push_back( new Limousine("bb",8) );

  for ( i = 0 ; i < cars.size() ; ++i ){
    std::cout << *(cars[i]) << std::endl;
  }

  std::cout << total_RV_passengers(cars) << std::endl;

  setup_RV_data( cars, "" );
  for ( i = 0 ; i < cars.size() ; ++i ){
    std::cout << *(cars[i]) << std::endl;
  }

  for ( i = 0 ; i < cars.size() ; ++i ){
    delete cars[i];
  }

  return 0;
}
