#pragma once

enum RuneType
{
	RUNE_ATTACK,
	RUNE_HP,
	RUNE_GOLD,
	RUNE_EXP
};

class Rune
{
private:

	RuneType type;

	int level;

	int cost;
public:
	Rune();

	void Init(RuneType type);
};

