#include "stdafx.h"
#include "Minute.h"

CMinute::CMinute(int minute)
	:m_minute(minute)
{
}

int CMinute::GetSeconds() const
{
	return m_minute * 60;
}
