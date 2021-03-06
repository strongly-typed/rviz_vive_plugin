/*******
This Plugins allows RVIZ to render to the HTC Vive
Copyright (C) 2017 Andre Gilerson

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*******/



/************************************************************************
This file is heavily influeced (and partly lifted) from the VRUI Toolkit
by Olive Kreylos. Check out http://idav.ucdavis.edu/~okreylos/ResDev/Vrui/
***********************************************************************/

#ifndef VIVE_DRIVER_H
#define VIVE_DRIVER_H

#include "openvr_driver.h"
#include <iostream>
#include <cstring>

class DriverLog:public vr::IDriverLog
{
public:
	DriverLog();
	
	virtual void Log(const char* pchLogMessage);
};

class VRSettings:public vr::IVRSettings
{
public:
	VRSettings();
	
	/* Methods from vr::IVRSettings: */
	virtual const char* GetSettingsErrorNameFromEnum(vr::EVRSettingsError eError);
	virtual bool Sync(bool bForce,vr::EVRSettingsError* peError);
	virtual void SetBool(const char* pchSection,const char* pchSettingsKey,bool bValue,vr::EVRSettingsError* peError);
	virtual void SetInt32(const char* pchSection,const char* pchSettingsKey,int32_t nValue,vr::EVRSettingsError* peError);
	virtual void SetFloat(const char* pchSection,const char* pchSettingsKey,float flValue,vr::EVRSettingsError* peError);
	virtual void SetString(const char* pchSection,const char* pchSettingsKey,const char* pchValue,vr::EVRSettingsError* peError);
	virtual bool GetBool(const char* pchSection,const char* pchSettingsKey,vr::EVRSettingsError* peError);
	virtual int32_t GetInt32(const char* pchSection,const char*pchSettingsKey,vr::EVRSettingsError* peError);
	virtual float GetFloat(const char* pchSection,const char* pchSettingsKey,vr::EVRSettingsError* peError);
	virtual void GetString(const char* pchSection,const char* pchSettingsKey,char* pchValue,uint32_t unValueLen,vr::EVRSettingsError* peError);
	virtual void RemoveSection(const char* pchSection,vr::EVRSettingsError* peError);
	virtual void RemoveKeyInSection(const char* pchSection,const char* pchSettingsKey,vr::EVRSettingsError* peError);
};

#endif
