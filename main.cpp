// DateTime.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "DateTime.h"
#include "Minute.h"
#include "Hour.h"
#include "Day.h"


int main()
{
	try
	{
		auto date1 = CDateTime(1971, 2, 28, 23, 60);
		std::cout << "date1: " << date1 << std::endl;

		auto date2 = CDateTime(1980, 9, 24, 8, 0);
		std::cout << "date3: " << date2 - CDay(30) << std::endl;
		//std::cout << "date4: " << date2 - CMinute(121) << std::endl;
		//std::cout << "date4: " << date2 - CDay(31) << std::endl;
		//std::cout << "date4: " << date2 - CHour(31) << std::endl;
	}
	catch (const std::exception&)
	{
		std::cout << 'sfsf' << std::endl;
	}
    return 0;
}

