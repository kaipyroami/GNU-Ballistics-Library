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


#include <stdio.h>
#include "ballistics.h"

int main(void)
{
	int k=0;
	double* sln;// A pointer for receiving the ballistic solution.
	double bc=0.5; // The ballistic coefficient for the projectile.
	double v=1200; // Intial velocity, in ft/s
	double sh=1.6; // The Sight height over bore, in inches.
	double angle=0; // The shooting angle (uphill / downhill), in degrees.
	double zero=100; // The zero range of the rifle, in yards.
	double windspeed=0; // The wind speed in miles per hour.
	double windangle=0; // The wind angle (0=headwind, 90=right to left, 180=tailwind, 270/-90=left to right)
	
	// If we wish to use the weather correction features, we need to 
	// Correct the BC for any weather conditions.  If we want standard conditions,
	// then we can just leave this commented out.
	
	// bc=AtmCorrect(bc, 0, 29.59, 100,.7);
	
	
	// First find the angle of the bore relative to the sighting system.
	// We call this the "zero angle", since it is the angle required to 
	// achieve a zero at a particular yardage.  This value isn't very useful
	// to us, but is required for making a full ballistic solution.
	// It is left here to allow for zero-ing at altitudes (bc) different from the
	// final solution, or to allow for zero's other than 0" (ex: 3" high at 100 yds)
	double zeroangle=0;
	zeroangle=ZeroAngle(G1,bc,v,1.6,zero,0);
	
	// Now we have everything needed to generate a full solution.
	// So we do.  The solution is stored in the pointer "sln" passed as the last argument.
	// k has the number of yards the solution is valid for, also the number of rows in the solution.
	k=SolveAll(G1,bc,v,sh,angle,zeroangle,windspeed,windangle,&sln);
	
	// Now print a simple chart of X / Y trajectory spaced at 10yd increments
	int s=0;
	for (s=0;s<=100;s++)
	{
		printf("\nX: %.0f     Y: %.2f",GetRange(sln,s*10), GetPath(sln,s*10));
	}
		

	
	return 0;
}

