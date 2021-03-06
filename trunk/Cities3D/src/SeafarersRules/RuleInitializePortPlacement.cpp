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
#include "Rule.h"
#include "RuleSetDatabase.h"

//---------------------------------------------------------------------------//
// Class: RuleInitializePortPlacement
// 
// Mixes into <RuleInitializeData>.  Initializes
// <PortPlacement> data.
//
// Derived From:
//     <Rule>
//
// Project:
//     <SeafarersRules>
//
// RuleSet:
//     <PortPlacement>
//
// Mixin To:
//     <RuleInitializeData>
//
class RuleInitializePortPlacement : public Rule
{
public:
	virtual void Execute(const DataObject &)
	{
		//initialize game data needed
		gameData<wxInt32>(shInitialPortTile) = -1;
		gameData<wxInt32>(shInitialPortCount) = 0;
	}
};

IMPLEMENT_RULE_MIXIN(RuleInitializePortPlacement, RuleInitializeData, 
					 PORT_PLACEMENT)
