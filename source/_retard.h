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

#ifndef _RETARD_H
#define _RETARD_H

enum __DragFunctions {G1=1,G2,G3,G4,G5,G6,G7,G8};

// A function to calculate ballistic retardation values based on standard drag functions.
// Source is in "_retard.c"
double retard(int DragFunction, double DragCoefficient, double Vi);
/* Arguments:
		DragFunction:  G1, G2, G3, G4, G5, G6, G7, or G8.  All are enumerated above.
		DragCoefficient:  The coefficient of drag for the projectile for the given drag function.
		Vi:  The Velocity of the projectile.
	
	Return Value: 
		The function returns the projectile drag retardation velocity, in ft/s per second.
		
*/

#endif