// ::gyronimo:: - gyromotion for the people, by the people -
// An object-oriented library for gyromotion applications in plasma physics.
// Copyright (C) 2022-2023 Manuel Assunção and Paulo Rodrigues.

// ::gyronimo:: is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// ::gyronimo:: is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with ::gyronimo::.  If not, see <https://www.gnu.org/licenses/>.

// @morphism_cylindrical.hh, this file is part of ::gyronimo::

#ifndef GYRONIMO_MORPHISM_CYLINDRICAL
#define GYRONIMO_MORPHISM_CYLINDRICAL

#include <gyronimo/metrics/morphism.hh>

namespace gyronimo {

//! Morphism from cylindrical coordinates @f$\{r, \phi, z\}@f$.
/*!
    The contravariant coordinates are the distance to the axis (normalised to
    `Lref` in SI units), the angle measured counterclockwise when seen from the
    top of the axis (in rads), and the length measured along the latter (also
    normalised to `Lref`).
*/
class morphism_cylindrical : public morphism {
 public:
  morphism_cylindrical(const double& Lref)
    : morphism(), Lref_(Lref), iLref_(1 / Lref), Lref3_(Lref * Lref * Lref) {};
  virtual ~morphism_cylindrical() override {};

  virtual IR3 operator()(const IR3& q) const override;
  virtual IR3 inverse(const IR3& x) const override;
  virtual dIR3 del(const IR3& q) const override;
  virtual ddIR3 ddel(const IR3& q) const override;

  virtual double jacobian(const IR3& q) const override;
  virtual dIR3 del_inverse(const IR3& q) const override;

  double Lref() const { return Lref_; };
 private:
  const double Lref_, iLref_, Lref3_;
};

}  // end namespace gyronimo

#endif  // GYRONIMO_MORPHISM_CYLINDRICAL
