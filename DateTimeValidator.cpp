#include "stdafx.h"
#include "DateTimeValidator.h"
#include "Utils.h"


CDateTimeValidator::CDateTimeValidator()
{
}

void CDateTimeValidator::Validate(int day, int month, int year, int hour, int minute)
{
	auto daysForManths = GetDaysForManths(year);
	if (daysForManths.find(month) == daysForManths.end())
	{
		throw new std::exception("Month is not valid");
	}
	int daysForManth = daysForManths[month];
	if (day > daysForManth || day <= 0)
	{
		throw new std::exception("Day is not valid");
	}
	if (hour < 0 || hour > 24)
	{
		throw new std::exception("Hour is not valid");
	}
	if (minute < 0 || minute > 60)
	{
		throw new std::exception("Minute is not valid");
	}
	if (1970 > year || year > 2032)
	{
		throw new std::exception("Year is not valid");
	}
}

void CDateTimeValidator::Validate(TimeStemp timeStemp)
{
	if (0 > timeStemp || timeStemp > (END_YEAR-START_YEAR) * COUNT_SECONDS_IN_YEAR)
	{
		throw new std::exception("timeStemp is not valid");
	}
}
