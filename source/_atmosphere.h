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

#ifndef _ATMOSPHERE_H
#define _ATMOSPHERE_H

// A function to correct a "standard" Drag Coefficient for differing atmospheric conditions.
// Returns the corrected drag coefficient for supplied drag coefficient and atmospheric conditions.
// Source is in "_atmosphere.c"
double AtmCorrect(double DragCoefficient, double Altitude, double Barometer, double Temperature, double RelativeHumidity);
/* Arguments:
		DragCoefficient:  The coefficient of drag for a given projectile.
		Altitude:  The altitude above sea level in feet.  Standard altitude is 0 feet above sea level.
		Barometer:  The barometric pressure in inches of mercury (in Hg).
					This is not "absolute" pressure, it is the "standardized" pressure reported in the papers and news.
					Standard pressure is 29.53 in Hg.
		Temperature:  The temperature in Fahrenheit.  Standard temperature is 59 degrees.
		RelativeHumidity:  The relative humidity fraction.  Ranges from 0.00 to 1.00, with 0.50 being 50% relative humidity.
							Standard humidity is 78%

	Return Value:
		The function returns a ballistic coefficient, corrected for the supplied atmospheric conditions.
*/

#endif