#ifndef _TIMER_H_
#define _TIMER_H_

#include <iostream>

class Timer {
  public:
    Timer();
    Timer(unsigned int t);
    ~Timer();

    unsigned int get_min() const;
    unsigned int get_sec() const;

    Timer& operator++();
    const Timer operator--( int a );
    friend std::ostream& operator<<( std::ostream& out, const Timer& timer );

  private:
    unsigned int min, sec;
};

Timer operator+( const Timer& timer, const unsigned int t );
Timer operator+( const unsigned int t, const Timer& timer );

#endif
