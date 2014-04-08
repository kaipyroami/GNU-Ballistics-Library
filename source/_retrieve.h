/*
GNU Ballistics Library 
Originally created by Derek Yates
Copyright (C) 2014 Kyle Crockett


This file is part of the GNU Ballistics Library.


The GNU Ballistics Library is free software: you can redistribute it 
and/or modify it under the terms of the GNU General Public License as 
published by the Free Software Foundation, either version 2 of the 
License, or (at your option) any later version.


The GNU Ballistics Library is distributed in the hope that it will 
be useful, but WITHOUT ANY WARRANTY; without even the implied warranty 
of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.


You should have received a copy of the GNU General Public License
along with the GNU Ballistics Library. If not, 
see <http://www.gnu.org/licenses/>. 
*/

#ifndef _RETRIEVE_H
#define _RETRIEVE_H

// Functions for retrieving data from a solution generated with SolveAll()
double GetRange(double* sln, int yardage); // Returns range, in yards.
double GetPath(double* sln, int yardage); // Returns projectile path, in inches, relative to the line of sight.
double GetMOA(double* sln, int yardage); // Returns an estimated elevation correction for achieving a zero at this range.
											// this is useful for "click charts" and the like.
double GetTime(double* sln, int yardage);// Returns the projectile's time of flight to this range.
double GetWindage(double* sln, int yardage); // Returns the windage correction in inches required to achieve zero at this range.
double GetWindageMOA(double* sln, int yardage); // Returns an approximate windage correction in MOA to achieve a zero at this range.
double GetVelocity(double* sln, int yardage); // Returns the projectile's total velocity (Vector product of Vx and Vy)
double GetVx(double* sln, int yardage); // Returns the velocity of the projectile in the bore direction.
double GetVy(double* sln, int yardage); // Returns the velocity of the projectile perpendicular to the bore direction.

// For very steep shooting angles, Vx can actually become what you would think of as Vy relative to the ground, 
// because Vx is referencing the bore's axis.  All computations are carried out relative to the bore's axis, and
// have very little to do with the ground's orientation.

#endif