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

// Specialty angular conversion functions
double DegtoMOA(double deg)
{
	return deg*60;
}

double DegtoRad(double deg)
{
	return deg*M_PI/180;
}

double MOAtoDeg(double moa)
{
	return moa/60;
}

double MOAtoRad(double moa)
{
	return moa/60*M_PI/180;
}

double RadtoDeg(double rad)
{
	return rad*180/M_PI;
}

double RadtoMOA(double rad)
{
	return rad*60*180/M_PI;
}

