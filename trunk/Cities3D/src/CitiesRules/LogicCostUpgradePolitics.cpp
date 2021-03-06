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
#include "Logic.h"
#include "RuleSetDatabase.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- LOGIC            -----------------------------//

//---------------------------------------------------------------------------//
// Class: LogicCostUpgradePolitics
// 
// Returns the cost in resources to upgrade politics.
//
// Derived From:
//     <Logic>
//
// Project:
//     <CitiesRules>
//
// RuleSet:
//     <Cities>
//
class LogicCostUpgradePolitics : public Logic
{
public:
	virtual void Decide(const DataObject &, DataObject &output)
	{
		typedef std::map<HashString, wxInt32> ResourceMap;
		ResourceMap resources;

		// It always costs one more than their current level, unless
		// they are maxed out in which case they can't advance further.
		wxInt32 cost = playerGameData<wxInt32>(shPoliticsLevel) + 1;

		if(6 <= cost)
		{
			cost = 0;
		}

		// Politics requires coin to upgrade.
		wxInt32 free = playerGameData<wxInt32>(shFreeCityUpgrades);
		free = std::min(1, free);
		cost = std::max(0, cost - free);

		resources[shCoin] = cost;

		output = DataObject(resources);
	}
};

IMPLEMENT_LOGIC(LogicCostUpgradePolitics, CITIES)
