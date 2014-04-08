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

double Windage(double WindSpeed, double Vi, double xx, double t)
{
	double Vw = WindSpeed*17.60; // Convert to inches per second.
	return (Vw*(t-xx/Vi));
}


// Headwind is positive at WindAngle=0
double HeadWind(double WindSpeed, double WindAngle)
{
	double Wangle = DegtoRad(WindAngle);
	return (cos(Wangle)*WindSpeed);
}

// Positive is from Shooter's Right to Left (Wind from 90 degree)
double CrossWind(double WindSpeed, double WindAngle)
{
	double Wangle = DegtoRad(WindAngle);
	return (sin(Wangle)*WindSpeed);
}


