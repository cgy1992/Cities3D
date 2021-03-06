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
#include "RuleExtensionMixin.h"
#include "RuleSetDatabase.h"
#include "Controller.h"
#include "Utility.h"
#include "CornerObject.h"

//---------------------------- TYPEDEFS         -----------------------------//
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//---------------------------- STATICS          -----------------------------//

//---------------------------- RULES            -----------------------------//

//---------------------------------------------------------------------------//
// Class: RulePlaceSettlementReduced
// 
// Places a settlement on a reduced city spot.
//
// Derived From:
//     <Rule>
//     <RuleExtensionMixin>
//
// Project:
//     <StandardRules>
//
// RuleSet:
//     <Standard>
//
//
class RulePlaceSettlementReduced 
	: public Rule
	, public RuleExtensionMixin
{
public:
	virtual void Execute(const DataObject &object)
	{
		RULE.Execute(shRulePlaceSettlementCommon, object);
		ExecuteExtensions(object);
	}
};

IMPLEMENT_RULE(RulePlaceSettlementReduced, STANDARD)
