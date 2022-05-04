#include "stdafx.h"
#include "Hour.h"



CHour::CHour(int hour)
{
	m_hour = hour;
}


int CHour::GetSeconds() const
{
	return m_hour * 60 * 60;
}
