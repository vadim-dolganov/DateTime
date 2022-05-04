#include "stdafx.h"
#include "DateTime.h"
#include "Utils.h"
#include "DateTimeValidator.h"

CDateTime::CDateTime(int year, int month, int day, int hour, int minute)
{
	CDateTimeValidator::Validate(day, month, year, hour, minute);

	m_timestamp = ConvertToTimestamp(year, month, day,  hour, minute);
}

CDateTime::CDateTime(TimeStemp timeStemp)
{
	CDateTimeValidator::Validate(timeStemp);
	m_timestamp = timeStemp;
}

TimeStemp CDateTime::ConvertToTimestamp(int year, int month, int day, int hour, int minute) const
{
	TimeStemp result = 0;
	result += minute * 60;
	result += hour * 60 * 60;
	result += (day + GetCountDaysBeforeMonth(month) + (year - START_YEAR) * 365) * 24 * 60 * 60;

	return result;
}


int CDateTime::GetDay() const
{
	int countDay = m_timestamp % COUNT_SECONDS_IN_YEAR / COUNT_SECONDS_IN_DAY - GetCountDaysBeforeMonth(GetMonth());
	return countDay;
}

int CDateTime::GetMonth() const
{
	int countDay = m_timestamp % COUNT_SECONDS_IN_YEAR / COUNT_SECONDS_IN_DAY - 1;
	return GetCountMonthFromDays(countDay);
}

int CDateTime::GetYear() const
{
	return START_YEAR + m_timestamp / COUNT_SECONDS_IN_YEAR;
}

int CDateTime::GetHour() const
{
	int countHour = m_timestamp % COUNT_SECONDS_IN_YEAR % COUNT_SECONDS_IN_DAY / 60 / 60;
	return countHour;
}

int CDateTime::GetMinute() const
{
	int countMinute = m_timestamp % COUNT_SECONDS_IN_YEAR % COUNT_SECONDS_IN_DAY / 60 % 60;
	return countMinute;
}

TimeStemp CDateTime::GetTimeStemp() const
{
	return m_timestamp;
}

/*boost::regex CDateTime::ConvertDateFormatToRegex(std::string format)
{
	boost::replace_all(format, "%y", "(\\d{4})");
	boost::replace_all(format, "%m", "(\\d{2})");
	boost::replace_all(format, "%d", "(\\d{2})");
	boost::replace_all(format, "%h", "(\\d{2})");
	boost::replace_all(format, "%i", "(\\d{2})");
	return boost::regex(format);
}*/

std::string CDateTime::ToString(CDateTime const & date)
{
	return std::string();
}

std::ostream & operator <<(std::ostream &stream, CDateTime const& date)
{
	stream << date.GetYear() << ":" << date.GetMonth() << ":" << date.GetDay() << " " << date.GetHour() << ":" << date.GetMinute();
	return stream;
}

bool operator==(CDateTime const & date1, CDateTime const & date2)
{
	return date1.GetTimeStemp() == date2.GetTimeStemp();
}

bool operator!=(CDateTime const & date1, CDateTime const & date2)
{
	return !(date1 == date2);
}

bool operator<(CDateTime const & date1, CDateTime const & date2)
{
	return date1.GetTimeStemp() < date2.GetTimeStemp();
}

bool operator>(CDateTime const & date1, CDateTime const & date2)
{
	return date1.GetTimeStemp() > date2.GetTimeStemp();
}

bool operator<=(CDateTime const & date1, CDateTime const & date2)
{
	return !(date1 > date2);
}

bool operator>=(CDateTime const & date1, CDateTime const & date2)
{
	return !(date1 < date2);
}

CDateTime const operator-(CDateTime const & date, CMinute const & minute)
{
	return CDateTime(date.GetTimeStemp() - minute.GetSeconds());
}

CDateTime const operator-(CDateTime const & date, CHour const & hour)
{
	return CDateTime(date.GetTimeStemp() - hour.GetSeconds());
}

CDateTime const operator-(CDateTime const & date, CDay const & day)
{
	return CDateTime(date.GetTimeStemp() - day.GetSeconds());
}

CDateTime const operator+(CDateTime const & date, CMinute const & minute)
{
	return CDateTime(date.GetTimeStemp() + minute.GetSeconds());
}

CDateTime const operator+(CDateTime const & date, CHour const & hour)
{
	return CDateTime(date.GetTimeStemp() + hour.GetSeconds());
}

CDateTime const operator+(CDateTime const & date, CDay const & day)
{
	return CDateTime(date.GetTimeStemp() + day.GetSeconds());
}
