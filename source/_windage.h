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

#ifndef _WINDAGE_H
#define _WINDAGE_H

// A function to compute the windage deflection for a given crosswind speed,
// given flight time in a vacuum, and given flight time in real life.
// Returns the windage correction needed in inches.
// Source is in "_windage.c"
double Windage(double WindSpeed, double Vi, double x, double t);
/* Arguments:
		WindSpeed:  The wind velocity in mi/hr.
		Vi:  The initial velocity of the projectile (muzzle velocity).
		x:  The range at which you wish to determine windage, in feet.
		t:  The time it has taken the projectile to traverse the range x, in seconds.
	
	Return Value:
		Returns the amount of windage correction, in inches, required to achieve zero on a target at the given range.
		
*/

// Functions to resolve any wind / angle combination into headwind and crosswind components.
// Source is in "_windage.c"
double HeadWind(double WindSpeed, double WindAngle);
double CrossWind(double WindSpeed, double WindAngle);
/* Arguments:
		WindSpeed:  The wind velocity, in mi/hr.
		WindAngle:  The angle from which the wind is coming, in degrees.
					0 degrees is from straight ahead
					90 degrees is from right to left
					180 degrees is from directly behind
					270 or -90 degrees is from left to right.
	
	Return value:
		Returns the headwind or crosswind velocity component, in mi/hr.
*/

#endif
