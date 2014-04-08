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

#ifndef _SOLVE_H
#define _SOLVE_H

// A function to generate a ballistic solution table in 1 yard increments, up to __BCOMP_MAXRANGE__.
// Source is in "_solve.c"
int SolveAll(int DragFunction, double DragCoefficient, double Vi, double SightHeight, \
			double ShootingAngle, double ZeroAngle, double WindSpeed, double WindAngle, double** Solution);
/* Arguments:
		DragFunction:  The drag function you wish to use for the solution (G1, G2, G3, G5, G6, G7, or G8)
		DragCoefficient:  The coefficient of drag for the projectile you wish to model.
		Vi:  The projectile initial velocity.
		SightHeight:  The height of the sighting system above the bore centerline.  
						Most scopes are in the 1.5"-2.0" range.
		ShootingAngle:  The uphill or downhill shooting angle, in degrees.  Usually 0, but can be anything from
						90 (directly up), to -90 (directly down).
		ZeroAngle:  The angle of the sighting system relative to the bore, in degrees.  This can be easily computed
					using the ZeroAngle() function documented above.
		WindSpeed:  The wind velocity, in mi/hr
		WindAngle:  The angle at which the wind is approaching from, in degrees.
					0 degrees is a straight headwind
					90 degrees is from right to left
					180 degrees is a straight tailwind
					-90 or 270 degrees is from left to right.
		Solution:	A pointer provided for accessing the solution after it has been generated.
					Memory for this pointer is allocated in the function, so the user does not need
					to worry about it.  This solution can be passed to the retrieval functions to get
					useful data from the solution.
	Return Value:
					This function returns an integer representing the maximum valid range of the
					solution.  This also indicates the maximum number of rows in the solution matrix,
					and should not be exceeded in order to avoid a memory segmentation fault.
*/

#endif