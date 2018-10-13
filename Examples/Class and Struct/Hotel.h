#ifndef _HOTEL_H_
#define _HOTEL_H_

using namespace std;

class Hotel{
  public:
    Hotel();
    Hotel(int no);
    ~Hotel();

    bool check_in(int no);
    int get_empty_room_no() const ;

  private:
    enum { SIZE = 30 };
    enum Status { empty, occupied };
    Status status[SIZE];
    int empty_room_no;
};

Hotel::Hotel(){
  for ( int i = 0 ; i < SIZE ; ++i ){
    status[i] = empty;
  }
  empty_room_no = SIZE;
}

Hotel::Hotel(int no){
  for ( int i = 0 ; i < SIZE ; ++i ){
    if ( i < no ){
      status[i] = occupied;
    } else {
      status[i] = empty;
    }
  }
  empty_room_no = SIZE-no;
}

Hotel::~Hotel(){}

bool Hotel::check_in(int no){
  if ( empty_room_no == 0 ){
    cout << "rooms are full. Can't check-in anymore." << endl;
    return false;
  }
}

int Hotel::get_empty_room_no() const {
  return empty_room_no;
}

#endif
