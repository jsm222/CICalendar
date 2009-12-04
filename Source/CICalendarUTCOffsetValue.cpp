/*
    Copyright (c) 2007 Cyrus Daboo. All rights reserved.
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/*
	CICalendarUTCOffsetValue.cpp

	Author:
	Description:	<describe the CICalendarUTCOffsetValue class here>
*/

#include "CICalendarUTCOffsetValue.h"

#include <cstdlib>
#include <iomanip>

using namespace iCal;

void CICalendarUTCOffsetValue::Parse(const cdstring& data)
{
	// Must be of specific lengths
	if ((data.length() != 5) && (data.length() != 7))
	{
		mValue = 0;
		return;
	}

	const char* p = data.c_str();

	// Get sign
	bool plus = (*p++ == '+');

	// Get hours
	char buf[3];
	buf[0] = *p++;
	buf[1] = *p++;
	buf[2] = 0;

	int32_t hours = atol(buf);

	// Get minutes
	buf[0] = *p++;
	buf[1] = *p++;
	buf[2] = 0;

	int32_t mins = atol(buf);

	// Get seconds if present
	int32_t secs = 0;
	if (*p)
	{
		buf[0] = *p++;
		buf[1] = *p++;
		buf[2] = 0;

		secs = atol(buf);
	}


	mValue = ((hours * 60) + mins) * 60 + secs;
	if (!plus)
		mValue = -mValue;
}

void CICalendarUTCOffsetValue::Generate(std::ostream& os) const
{
	int32_t abs_value = mValue;
	if (mValue < 0)
	{
		os << '-';
		abs_value = -mValue;
	}
	else
		os << '+';

	int32_t secs = abs_value % 60;
	int32_t mins = (abs_value / 60) % 60;
	int32_t hours = abs_value / (60 * 60);

	os << std::setfill('0') << std::setw(2) << hours << std::setw(2) << mins << std::setfill(' ');
	if (secs != 0)
		os << std::setfill('0') << std::setw(2) << secs << std::setfill(' ');
}
