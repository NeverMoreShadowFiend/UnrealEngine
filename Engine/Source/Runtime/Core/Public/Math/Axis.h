// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once


// Generic axis enum (mirrored for property use in Object.h)
namespace EAxis
{
	enum Type
	{
		None,
		X,
		Y,
		Z,
	};
}


// Extended axis enum for more specialized usage
namespace EAxisList
{
	enum Type
	{
		None		= 0,
		X			= 1,
		Y			= 2,
		Z			= 4,

		Screen		= 8,
		XY			= X | Y,
		XZ			= X | Z,
		YZ			= Y | Z,
		XYZ			= X | Y | Z,
		All			= XYZ | Screen,
		//alias over Axis YZ since it isn't used when the z-rotation widget is being used
		ZRotation	= YZ,
	};
}
