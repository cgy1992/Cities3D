/*
 *  Cities3D - Copyright (C) 2001-2009 Jason Fugate (saladyears@gmail.com)
 * 
 *  This program is free software; you can redistribute it and/or modify it 
 *  under the terms of the GNU General Public License as published by the Free 
 *  Software Foundation; either version 2 of the License, or (at your option) 
 *  any later version.
 * 
 *  This program is distributed in the hope that it will be useful, but 
 *  WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 *  or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License 
 *  for more details.
 */
#include "stdwx.h"
#include "style.h"	//READ THIS BEFORE MAKING ANY CHANGES TO THIS FILE!!!

//---------------------------- SYSTEM INCLUDES  -----------------------------//

//---------------------------- USER INCLUDES    -----------------------------//
#include "RuleSetDatabase.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- PUBLIC           -----------------------------//
#ifdef __WIN32__
wxBOOL APIENTRY DllMain(HANDLE, DWORD, LPVOID)
{
    return TRUE;
}
#endif

//---------------------------------------------------------------------------//
// Topic: NetworkRules
// 

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXPORT const RuleSetMap& ProvideRuleSets()
{
	return RuleSetDatabase::get().map();
}

DLL_EXPORT void ProvideModuleInfo(wxString& module, wxInt32& priority)
{
	module = stNetwork;
	priority = 40;
}

#ifdef __cplusplus
}
#endif

//---------------------------- PROTECTED        -----------------------------//

//---------------------------- PRIVATE          -----------------------------//

