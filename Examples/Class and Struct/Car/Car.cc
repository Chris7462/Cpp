#include "Car.h"

std::ostream& operator<<( std::ostream& out, const Car& foo ){
  return foo.print(out);
}

Car::Car( int n ) : passenger_no(n) {}

int Car::passenger() const {
  return passenger_no;
}

Car::~Car(){}

RV::RV( Location p, int no ) : Car(no), place(p) {}

RV& RV::operator=( const RV& foo ){
  place = foo.place;
  passenger_no = foo.passenger_no;
  return *this;
}

RV& RV::operator=( const Car& foo ){
  return operator=( dynamic_cast<const RV&>(foo) );
}

std::ostream& RV::print( std::ostream& out ) const {
  return out << "RV\t" << "pass_no: " << passenger_no << ", loc: " << place;
}

Limousine::Limousine( Name d, int no ) : Car(no), driver(d) {}

Limousine& Limousine::operator=( const Car& foo ){
  const Limousine *lm = dynamic_cast<const Limousine*>(&foo);
  if ( lm ){
    driver = lm->driver;
    passenger_no = lm->passenger_no;
  }
  return *this;
}

std::ostream& Limousine::print( std::ostream& out ) const {
  return out << "Limousine\t" << "pass_no: " << passenger_no << ", driver: " << driver;
}

int total_RV_passengers( const std::vector<Car*>& foo ){
  RV* rv;
  int no = 0;
  for ( int i = 0 ; i < foo.size() ; ++i ){
    rv = dynamic_cast<RV*>(foo[i]);
    if ( rv ){
      no += rv->passenger();
    }
  }
  return no;
}

void setup_RV_data( std::vector<Car*>& foo, Location place ){
  Car *new_rv = new RV(place);
  for ( int i = 0 ; i < foo.size() ; ++i ){
    *(foo[i]) = *new_rv;
  }
  delete new_rv;
}
