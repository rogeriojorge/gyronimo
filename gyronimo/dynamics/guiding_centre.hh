// ::gyronimo:: - gyromotion for the people, by the people -
// An object-oriented library for gyromotion applications in plasma physics.
// Copyright (C) 2021-2023 Paulo Rodrigues.

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

// @guiding_centre.hh, this file is part of ::gyronimo::

#ifndef GYRONIMO_GUIDING_CENTRE
#define GYRONIMO_GUIDING_CENTRE

#include <array>
#include <gyronimo/fields/IR3field_c1.hh>

namespace gyronimo {

//! Guiding-centre equations of motion on a background electromagnetic field.
/*!
    Defines the equations of motion for the guiding-centre [R. Littlejohn, J.
    Plasma Phys. **29**, 111 (1983)],
    @f{gather*}{
      \biggl[ 1 + \frac{\tilde{v}_\parallel}{\tilde{\Omega}}
        \Bigl( \mathbf{b} \cdot \tilde{\nabla} \times \mathbf{b} \Bigr) \biggr]
          \frac{d\mathbf{X}}{d\tau} =
      \tilde{v}_\parallel \mathbf{b} + \frac{1}{\tilde{\Omega}} \biggl[
        \tilde{v}_\parallel^2 \tilde{\nabla} \times \mathbf{b} +
        \mathbf{b}\times\Bigl(
          \tilde{v}_\parallel\partial_\tau\mathbf{b} +
          \frac{1}{2}\tilde{\mu}\tilde{\nabla}\tilde{B} -
            \tilde{\mathbf{E}} \Bigr)\biggr]
      \quad \mathrm{and}\\
      \biggl[ 1 + \frac{\tilde{v}_\parallel}{\tilde{\Omega}}
        \Bigl( \mathbf{b} \cdot \tilde{\nabla} \times \mathbf{b} \Bigr) \biggr]
          \frac{d\tilde{v}_\parallel}{d\tau} = -\biggl(
        \mathbf{b} + \frac{\tilde{v}_\parallel}{\tilde{\Omega}}
          \tilde{\nabla}\times\mathbf{b} \biggr) \cdot \Bigl(
            \frac{1}{2}\tilde{\mu}\tilde{\nabla}\tilde{B} +
              \tilde{v}_\parallel\partial_\tau\mathbf{b} -
                \tilde{\mathbf{E}} \Bigr).
    @f}
    All variables are adimensional: the position `X` of the guiding centre is
    normalised to a reference length `Lref`, the time to `Tref`, and the
    parallel velocity to `Vref`=`Lref`/`Tref`. Reference length and velocity are
    supplied to the constructor in SI units, further normalisations are done
    internally assuming *bona-fide* electromagnetic fields derived from
    `IR3field`: @f$\tilde{B} = B/B_{ref}@f$ and @f$\tilde{\mathbf{E}} =
    \tilde{E}_{ref} (\mathbf{E}/E_{ref})@f$, with @f$\tilde{E}_{ref} =
    \tilde{\Omega}_{ref} (E_{ref} V_{ref}^{-1} B_{ref}^{-1})@f$ an adimensional
    constant. Other normalisations are @f$\tilde{\Omega} = \Omega T_{ref} =
    \tilde{\Omega}_{ref} \tilde{B}@f$, while the magnetic moment is normalised
    to the ratio `Uref`/`Bref` and `Uref` is the kinetic energy corresponding to
    `Vref`.  Moreover, @f$\tilde{\nabla} = L_{ref} \nabla@f$ and @f$\mathbf{b} =
    \mathbf{B}/B@f$.

    The equations are implemented in a coordinate-invariant form and will work
    out-of-the-box with any coordinates defined in the `metric_covariant` object
    pointed to by the electromagnetic fields. This approach takes advantage of
    all tensor and differential calculus machinery already implemented in
    `metric_covariant`, `IR3field`, and `IR3field_c1`, which can eventually be
    specialised and optimised in further derived classes. The type
    `guiding_centre::state` implements the state of the dynamical system,
    storing the three contravariant components of the normalised guiding-centre
    position @f$\mathbf{X}@f$ and the normalised parallel velocity. Member
    functions are provided to convert between `state` values, `IR3` positions,
    and parallel velocities [`get_position(state)`, `get_vpp(state)`,
    `generate_state(...)`].
*/
class guiding_centre {
 public:
  typedef std::array<double, 4> state;
  enum vpp_sign : int {minus = -1, plus = 1};

  guiding_centre(
      double Lref, double Vref, double qom, double mu,
      const IR3field_c1* B, const IR3field* E = nullptr);
  ~guiding_centre() {};

  state operator()(const state& x, double t) const;

  double get_vpp(const state& s) const;
  IR3 get_position(const state& s) const;
  double energy_parallel(const state& s) const;
  double energy_perpendicular(const state& s, double time) const;
  state generate_state(
      const IR3& position,
      double energy_tilde, vpp_sign sign, double time = 0) const;

  double Lref() const {return Lref_;};
  double Tref() const {return Tref_;};
  double Vref() const {return Vref_;};
  double mu_tilde() const {return mu_tilde_;};
  double qom_tilde() const {return qom_tilde_;};
  double Eref_tilde() const {return Eref_tilde_;};
  double Oref_tilde() const {return 1.0/iOref_tilde_;};
  const IR3field* electric_field() const {return electric_field_;};
  const IR3field_c1* magnetic_field() const {return magnetic_field_;};

 private:
  const IR3field* electric_field_;
  const IR3field_c1* magnetic_field_;
  const double qom_tilde_, mu_tilde_;
  const double Lref_, Vref_, Tref_;
  const double Bfield_time_factor_, Efield_time_factor_;
  double iOref_tilde_, Eref_tilde_;
};

} // end namespace gyronimo.

#endif // GYRONIMO_GUIDING_CENTRE.
