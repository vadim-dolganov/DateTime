#pragma once
class CMinute
{
public:
	CMinute(int minute);
	int GetSeconds() const;
private:
	int m_minute;
};

