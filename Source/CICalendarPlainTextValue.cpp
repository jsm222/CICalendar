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
	CICalendarPlainTextValue.cpp

	Author:
	Description:	<describe the CICalendarPlainTextValue class here>
*/

#include "CICalendarPlainTextValue.h"

#include "CICalendarUtils.h"

using namespace iCal;

void CICalendarPlainTextValue::Parse(const cdstring& data)
{
	// No decoding required
	mValue = data;
}

void CICalendarPlainTextValue::Generate(std::ostream& os) const
{
	// No encoding required
	os << mValue;
}

