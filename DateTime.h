#pragma once


class CDateTime
{
public:
	CDateTime(int year, int month, int day, int hour, int minute);
	CDateTime(TimeStemp timeStemp);
	//static CDateTime GetFromString(std::string dateStr, std::string format = "%y:%m:%d %h:%i");

	int GetDay() const;
	int GetMonth() const;
	int GetYear() const;
	int GetHour() const;
	int GetMinute() const;

	TimeStemp GetTimeStemp() const;
private:
	TimeStemp m_timestamp;

	//static boost::regex ConvertDateFormatToRegex(std::string format);

	std::string ToString(CDateTime const& date);
	unsigned long long int ConvertToTimestamp(int year, int month, int day, int hour, int minute) const;
};

std::ostream & operator<<(std::ostream &stream, CDateTime const& date);


bool operator ==(CDateTime const& date1, CDateTime const& date2);
bool operator !=(CDateTime const& date1, CDateTime const& date2);


bool operator <(CDateTime const& date1, CDateTime const& date2);
bool operator >(CDateTime const& date1, CDateTime const& date2);
bool operator <=(CDateTime const& date1, CDateTime const& date2);
bool operator >=(CDateTime const& date1, CDateTime const& date2);

CDateTime const operator -(CDateTime const& date, CMinute const& minute);
CDateTime const operator -(CDateTime const& date, CHour const& hour);
CDateTime const operator -(CDateTime const& date, CDay const& day);

CDateTime const operator +(CDateTime const& date, CMinute const& minute);
CDateTime const operator +(CDateTime const& date, CHour const& hour);
CDateTime const operator +(CDateTime const& date, CDay const& day);