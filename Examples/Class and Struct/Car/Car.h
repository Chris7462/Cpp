#ifndef _CAR_H_
#define _CAR_H_

#include <iostream>
#include <vector>
#include <string>

typedef std::string Name;
typedef std::string Location;

class Car {
  public:
    virtual Car& operator=( const Car& foo ) = 0;
    virtual std::ostream& print( std::ostream& out ) const = 0;
    int passenger() const;
    virtual ~Car();
  protected:
    int passenger_no;
    Car( int n = 0 );
};

std::ostream& operator<<( std::ostream& out, const Car& foo);

class RV : public Car {
  public:
    RV( Location p, int no = 0 );
    RV& operator=(const RV& foo);
    RV& operator=(const Car& foo);
    std::ostream& print( std::ostream& out ) const;
  private:
    Location place;
};

class Limousine : public Car {
  public:
    Limousine( Name d, int no = 0 );
    Limousine& operator=(const Car& foo);
    std::ostream& print( std::ostream& out ) const;
  private:
    Name driver;
};

int total_RV_passengers( const std::vector<Car*>& foo );

void setup_RV_data( std::vector<Car*>& foo, Location place );

#endif
