#ifndef _BUCKET_H_
#define _BUCKET_H_

class Bucket {
  public:
    Bucket( int m );
    void fill_up();
    void empty();
    int water_height() const;
    int bucket_height() const;
    void filled_from( Bucket& a );
    void pour_to( Bucket& b );
  private:
    int max_height;     
    int current_height;
};

Bucket::Bucket( int m ){
  max_height = m;
  current_height = 0;
}

void Bucket::fill_up(){
  current_height = max_height;
}

void Bucket::empty(){
  current_height = 0;
}

int Bucket::water_height() const {
  return current_height;
}

int Bucket::bucket_height() const {
  return max_height;
}

void Bucket::pour_to( Bucket& b ){
  int b_free_height = b.bucket_height()-b.water_height();
  if ( current_height >= b_free_height ){
    b.current_height += b_free_height;
    current_height -= b_free_height;
  } else {
    b.current_height += current_height;
    current_height = 0;
  }
}

#endif
