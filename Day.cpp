#include "stdafx.h"
#include "Day.h"


CDay::CDay(int day)
{
	m_day = day;
}


int CDay::GetSeconds() const
{
	return m_day * 24 * 60 * 60;
}
