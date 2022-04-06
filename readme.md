::gyronimo::
============

*- gyromotion for the people, by the people -*

*An object-oriented library for gyromotion applications in plasma physics.*

Philosophy, purpose, and other useless matters:
-----------------------------------------------

Have you ever had a bright and promising idea about gyromotion in
plasmas that just faded away the moment you realised the amount of
non-trivial, tedious, unrewarding, non-physics details you would have to
implement before you could get a simple glimpse over the results?

`gyronimo` was designed to address this problem. It provides a library
of objects that take care of most tedious tasks in gyromotion
simulations, allowing developers to quickly implement and test their
ideas in order to understand if further work and optimisation really
worth the trouble. Built over object-oriented programming concepts like
inheritance, polymorphism, and specialisation, `gyronimo` provides
abstract algorithms to many tasks that developers may take advantage of,
either by employing ready-to-use objects or by deriving new ones adapted
to their own needs, in order to quickly finish a "working" workflow. In
a later stage, derived objects and procedures may be specialised and
further optimised for performance, without the need to significantly
change the logic structure of the initial code.

In brief, the goal of `gyronimo` is to keep maintenance efforts to a
minimum, code readability to its best, and performance to the level that
is really needed by each specific gyromotion application.

###### "What's in a name?", wondered Juliet...

Quite obviously, `gyronimo` is an acronym for GYRO-MOtion. To those with
a sharp eye and an inquisitive mind, the author must confess that he has
absolutely No Idea on how the `ni` managed to sneak into the middle.

Once, in the wild west of yore, Apache warriors were said to charge
their foes shouting "Geronimo!", the nickname of their fierce leader;
Other sources say the same cry was uttered instead by the fleeing
Mexican soldiers, invoking their saint protector "Santo Geronimo";
Whichever the actual cause might have been, library users are expected
to occasionally shout an enthusiastic "gyronimo!" while happily coding
their favorite gyromotion application.

Contents:
---------

#### Licensing and terms of use:

::gyronimo:: is free software: you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation, either version 3 of the License, or (at your
option) any later version.

This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
Public License for more details.

You should have received a copy of the GNU General Public License along
with this program. If not, see <https://www.gnu.org/licenses/>.

#### A word about code documentation:

The source code is extensively documented in order to allow tools like
`doxygen` to easily generate HTML-formatted documentation of the library
API. This procedure ensures up-to-date information at the users finger
tips and potential code contributors are kindly asked to keep it this
way, for the sake of everyone's mental sanity.

Besides the main HTML documentation, there are a number of text files
under the folder `misc/what-why-how` that provide information about some
particular features of `gyronimo` design. Each of these files is
organized in three main sections: what is it (the corresponding feature,
of course), why is it needed for, and how does it work.

#### Compiling and installing, a minimal and very optimistic howto:

The library requires `cmake` and a c++ compiler supporting the **c++20**
standard (e.g., gcc-10.1.0). HTML-formatted documentation can be
generated from the source code by `doxygen` if the latter is installed.

###### Basic build&install procedure:

1. Run `cmake [options] path/to/gyronimo/repository` on an build
   directory to configure the installation;
2. Run `cmake --build . [options]` to generate the shared library
   `libgyronimo` and the available apps;
3. Run `cmake --build . --target doc` to extract the API documentation
   from source files with `doxygen`;
4. Run `cmake --install . --prefix path/to/install/dir [options]` to
   install include files (prefix/include/gyronimo), shared library
   (prefix/lib), available apps (prefix/bin), and eventual HTML
   documentation (prefix/share/doc/gyronimo);

###### Some useful `cmake` options:
- `-DCMAKE_BUILD_TYPE={Release,Debug}` (default `Release`);
- `-DBUILD_VMEC_SUPPORT={ON,OFF}` (default `OFF`);

After installing and before using the library, make sure to update
relevant environment variables if the installation folder is not one of
the system's defaults.

#### External dependencies and other nightmares:

Applications developed using `gyronimo` may, eventually, have to be
compiled and/or linked against the following libraries:

- GNU Scientific Library [GSL](https://www.gnu.org/software/gsl);
- c++ extension to NetCDF-4
  [netcdf-cxx4](https://github.com/Unidata/netcdf-cxx4);
- odeint, an ODE c++ library distributed with
  [boost](https://www.boost.org);
