#include "bge.h"
Line* Line::transformation(const std::vector<Geometric_Transformation*>& geotrs ) const {
  return new Line( p.transformation(geotrs), q.transformation(geotrs) );
}
