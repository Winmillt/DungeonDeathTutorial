#pragma once
#include <Engine/OGLGame.h>

class Player;
class UIPanel;
struct Font;

class DungeonDeathGame:
	public ASGE::OGLGame
{
public:
	DungeonDeathGame();
	~DungeonDeathGame();

	// Inherited via OGLGame
	virtual bool init();

private:
	UIPanel* panels[5];
	Player*	 player_one;

	// Inherited via OGLGame
	virtual void update(const ASGE::GameTime &);
	virtual void render(const ASGE::GameTime &);
};

