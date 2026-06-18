#include "Rune.h"
#include "DxLib.h"

Rune::Rune()
{
	type = RUNE_ATTACK;

	level = 0;

	cost = 100;
}

void Rune::Init(RuneType type)
{
	this->type = type;

	switch (type)
	{
	case RUNE_ATTACK:
		cost = 100;
		break;
	case RUNE_HP:
		cost = 100;
		break;
	case RUNE_GOLD:
		cost = 200;
		break;
	case RUNE_EXP:
		cost = 250;
		break;
	}

	level = 1;
}
