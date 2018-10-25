#include "Timer.h"

Timer::Timer() : min(0), sec(0) {}
Timer::Timer( unsigned int t ) : min(0), sec(0) {
  if ( t < 600 ){
    min = t / 60;
    sec = t % 60;
  }
}

Timer::~Timer(){}

unsigned int Timer::get_min() const {
  return min;
}

unsigned int Timer::get_sec() const {
  return sec;
}

Timer& Timer::operator++(){
  if ( ++sec / 60 ){
    ++min;
    sec = 0;
  }
  return *this;
}

const Timer Timer::operator--( int a ){
  Timer tmp(*this);
  if ( sec > 0 ){
    --sec;
  } else {
    --min;
    sec = 59;
  }
  return tmp;
}


std::ostream& operator<<( std::ostream& out, const Timer& timer ){
  out << timer.min << " minutes " << timer.sec << " seconds";
  return out;
}

Timer operator+( const Timer& timer, const unsigned int t ){
  return Timer(timer.get_min()*60+timer.get_sec() + t);
}

Timer operator+( const unsigned int t, const Timer& timer ){
  return Timer(timer.get_min()*60+timer.get_sec() + t);
}
