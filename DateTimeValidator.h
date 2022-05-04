#pragma once

class CDateTimeValidator
{
public:
	CDateTimeValidator();
	static void Validate(int day, int month, int year, int hour, int minute);
	static void Validate(TimeStemp timeStemp);
};

