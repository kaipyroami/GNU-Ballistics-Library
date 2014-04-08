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

#ifndef _ANGLE_H
#define _ANGLE_H

// Angular conversion functions to make things a little easier. 
// Source is in _angle.c
double DegtoMOA(double deg); // Converts degrees to minutes of angle
double DegtoRad(double deg); // Converts degrees to radians
double MOAtoDeg(double moa); // Converts minutes of angle to degrees
double MOAtoRad(double moa); // Converts minutes of angle to radians
double RadtoDeg(double rad); // Converts radians to degrees
double RadtoMOA(double rad); // Converts radiants to minutes of angle

#endif