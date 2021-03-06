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
#include "RNG.h"
#include "Controller.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- RULES            -----------------------------//

//---------------------------------------------------------------------------//
// Class: RuleStartPortPlacement
// 
// Prepares data for initial port placement.  Sets the
// current player to a random value and updates the
// <PlayerUIs>.
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
// Transmits To:
//     eventPlayerUI
//
class RuleStartPortPlacement : public Rule
{
public:
	virtual void Execute(const DataObject &)
	{
		//start off by picking a random starting player for
		//placing ports
		gameData<wxInt32>(shCurrentPlayer) = 
			RAND.pooled(numPlayers());

		//update the UI
		Controller::get().Transmit(shEventPlayerUI, 
			DataObject(GetGame(), -2));

		//let the rule chain continue on
	}
};

IMPLEMENT_RULE(RuleStartPortPlacement, PORT_PLACEMENT)
