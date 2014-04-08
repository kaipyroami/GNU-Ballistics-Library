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

#ifndef _ZERO_H
#define _ZERO_H

// A function to determine the bore angle needed to achieve a target zero at Range yards
// (at standard conditions and on level ground.)
// Source is in "_zero.c"
double ZeroAngle(int DragFunction, double DragCoefficient, double Vi, double SightHeight, double ZeroRange, double yIntercept); 
/*  Arguments: 
		DragFunction:  The drag function to use (G1, G2, G3, G5, G6, G7, G8)
		DragCoefficient:  The coefficient of drag for the projectile, for the supplied drag function.
		Vi:  The initial velocity of the projectile, in feet/s
		SightHeight:  The height of the sighting system above the bore centerline, in inches. 
					  Most scopes fall in the 1.6 to 2.0 inch range.
		ZeroRange:  The range in yards, at which you wish the projectile to intersect yIntercept.
		yIntercept:  The height, in inches, you wish for the projectile to be when it crosses ZeroRange yards.
					This is usually 0 for a target zero, but could be any number.  For example if you wish
					to sight your rifle in 1.5" high at 100 yds, then you would set yIntercept to 1.5, and ZeroRange to 100
					
	Return Value:
		Returns the angle of the bore relative to the sighting system, in degrees.
*/

#endif