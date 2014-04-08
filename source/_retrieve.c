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

double GetRange(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage];
	}
	else return 0;
}

double GetPath(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+1];
	}
	else return 0;
}

double GetMOA(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+2];
	}
	else return 0;
}


double GetTime(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+3];
	}
	else return 0;
}

double GetWindage(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+4];
	}
	else return 0;
}

double GetWindageMOA(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+5];
	}
	else return 0;
}

double GetVelocity(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+6];
	}
	else return 0;
}

double GetVx(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+7];
	}
	else return 0;
}

double GetVy(double* sln, int yardage)
{
	double size=sln[__BCOMP_MAXRANGE__*10+1];
	if (yardage<size)
	{
		return sln[10*yardage+8];
	}
	else return 0;
}

