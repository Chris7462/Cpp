#ifndef _CAR_H_
#define _CAR_H_

#include <vector>

typedef std::string Name;
typedef std::string Location;

class Car {
  protected:
    int passenger_no;
    Car( int n=0 ) : passenger_no(n) {}
  public:
    virtual Car& operator=( const Car& foo ) = 0;
    virtual std::ostream& print( std::ostream& out ) const = 0;
    int passenger() const { return passenger_no; }
    virtual ~Car(){}
};

std::ostream& operator<<(std::ostream& out, const Car& foo ){
  return foo.print(out);
}

class RV : public Car {
  private:
    Location place;
  public:
    RV(Location p, int no=0) : Car(no), place(p) {}

    RV& operator=(const RV& foo){
      place = foo.place;
      passenger_no = foo.passenger_no;
      return *this;
    }

    RV& operator=(const Car& foo){
      return operator=( dynamic_cast<const RV&>(foo) );
    }

    std::ostream& print( std::ostream& out ) const {
      return out << "RV car - Passanger no: " << passenger_no << " - Place: " << place;
    }
};

class Limousine : public Car {
  private:
    Name driver;
  public:
    Limousine(Name d, int no=0) : Car(no), driver(d) {}

    Limousine& operator=(const Car& foo){
      const Limousine *lm = dynamic_cast<const Limousine*>(&foo);
      if(lm){
        driver = lm->driver;
        passenger_no = lm->Car::passenger_no;
      }
      return *this;
    }
    std::ostream& print( std::ostream& out ) const {
      return out << "Limousine - Passanger no: " << passenger_no << " - Driver: " << driver;
    }

};

int total_RV_passengers( const std::vector<Car*>& foo ){
  RV* rv;
  int no = 0;

  for( int i=0 ; i<foo.size() ; ++i ){
    rv = dynamic_cast<RV*>(foo[i]);
    if(rv){
      no += foo[i]->passenger();
    }
  }
  return no;
}

void steup_RV_data( std::vector<Car*>& foo, Location place ){
  Car *new_rv = new RV(place);

  for( int i=0 ; i<foo.size() ; ++i ){
    *foo[i] = *new_rv;
  }
  delete new_rv;
}

#endif
