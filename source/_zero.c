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

#include "ballistics.h"

double ZeroAngle(int DragFunction, double DragCoefficient, double Vi, double SightHeight, double ZeroRange, double yIntercept)
{
	// Numerical Integration variables
	double t=0;
	double dt=1/Vi; // The solution accuracy generally doesn't suffer if its within a foot for each second of time.
	double y=-SightHeight/12;
	double x=0;
	double da; // The change in the bore angle used to iterate in on the correct zero angle.

	// State variables for each integration loop.
	double v=0, vx=0, vy=0; // velocity
	double vx1=0, vy1=0; // Last frame's velocity, used for computing average velocity.
	double dv=0, dvx=0, dvy=0; // acceleration
	double Gx=0, Gy=0; // Gravitational acceleration

	double angle=0; // The actual angle of the bore.

	int quit=0; // We know it's time to quit our successive approximation loop when this is 1.

	// Start with a very coarse angular change, to quickly solve even large launch angle problems.
	da=DegtoRad(14);


	// The general idea here is to start at 0 degrees elevation, and increase the elevation by 14 degrees
	// until we are above the correct elevation.  Then reduce the angular change by half, and begin reducing
	// the angle.  Once we are again below the correct angle, reduce the angular change by half again, and go
	// back up.  This allows for a fast successive approximation of the correct elevation, usually within less
	// than 20 iterations.
	for (angle=0;quit==0;angle=angle+da)
	{
		vy=Vi*sin(angle);
		vx=Vi*cos(angle);
		Gx=GRAVITY*sin(angle);
		Gy=GRAVITY*cos(angle);

		for (t=0,x=0,y=-SightHeight/12;x<=ZeroRange*3;t=t+dt)
		{
			vy1=vy;
			vx1=vx;
			v=pow((pow(vx,2)+pow(vy,2)),0.5);
			dt=1/v;
			
			dv = retard(DragFunction, DragCoefficient, v);
			dvy = -dv*vy/v*dt;
			dvx = -dv*vx/v*dt;

			vx=vx+dvx;
			vy=vy+dvy;
			vy=vy+dt*Gy;
			vx=vx+dt*Gx;
			
			x=x+dt*(vx+vx1)/2;
			y=y+dt*(vy+vy1)/2;
			// Break early to save CPU time if we won't find a solution.
			if (vy<0 && y<yIntercept) 
			{
				break;
			}
			if (vy>3*vx) 
			{ 
				break;
			}
		}
	
		if (y>yIntercept && da>0)
		{
			da=-da/2;
		}

		if (y<yIntercept && da<0)
		{
			da=-da/2;
		}

		if (fabs(da) < MOAtoRad(0.01)) quit=1; // If our accuracy is sufficient, we can stop approximating.
		if (angle > DegtoRad(45)) quit=1; // If we exceed the 45 degree launch angle, then the projectile just won't get there, so we stop trying.

	}


	return RadtoDeg(angle); // Convert to degrees for return value.
}


