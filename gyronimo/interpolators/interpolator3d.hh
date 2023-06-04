
#ifndef GYRONIMO_INTERPOLATOR3D
#define GYRONIMO_INTERPOLATOR3D

#include <gyronimo/core/dblock.hh>

namespace gyronimo {

class interpolator3d {
 public:
  virtual ~interpolator3d() {};
  virtual double operator()(double x, double y, double z) const = 0;
  virtual double partial_u(double x, double y, double z) const = 0;
  virtual double partial_v(double x, double y, double z) const = 0;
  virtual double partial_w(double x, double y, double z) const = 0;
  virtual double partial2_uu(double x, double y, double z) const = 0;
  virtual double partial2_uv(double x, double y, double z) const = 0;
  virtual double partial2_vv(double x, double y, double z) const = 0;
  virtual double partial2_uw(double x, double y, double z) const = 0;
  virtual double partial2_vw(double x, double y, double z) const = 0;
  virtual double partial2_ww(double x, double y, double z) const = 0;
};

class interpolator3d_factory {
 public:
  virtual interpolator3d* interpolate_data(
      const dblock& x_range,
      const dblock& y_range,
      const dblock& z_range) const = 0;
};

} // end namespace gyronimo.

#endif // GYRONIMO_INTERPOLATOR3D
