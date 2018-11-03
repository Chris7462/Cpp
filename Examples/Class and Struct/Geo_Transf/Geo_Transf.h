#ifndef _GEO_TRANSF_H_
#define _GEO_TRANSF_H_

typedef double Distance;

enum Trans_Type { SHF, ROT, REF };

class Geo_Transf {
  protected:
    double M[2][3];
  public:
    void update_transf_mat( double a[2][3] );
    virtual Trans_Type get_transf_type() const = 0;
};

std::ostream& operator<<(std::ostream& out, const Geo_Transf& foo){
  return out << foo.get_transf_type();
}

class Shift : public Geo_Transf {
  private:
    Distance dx, dy;
  public:
    Shift(Distance x, Distance y) : dx(x), dy(y) {
      M[0][0]=1.0; M[0][1]=0.0; M[0][2]=dx;
      M[1][0]=0.0; M[1][1]=1.0; M[1][2]=dy;
    }
    Trans_Type get_transf_type() const { 
      return Trans_Type(SHF);
    }
};

class Rotation : public Geo_Transf {
};

class Reflection : public Geo_Transf {
};

#endif
