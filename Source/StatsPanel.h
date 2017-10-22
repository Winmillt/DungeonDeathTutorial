#pragma once
#include "Panel.h"
#include "Player.h"
#include <memory>

class Player;

class StatsPanel: public UIPanel
{
public:
	StatsPanel() = default;
	~StatsPanel();

	void init(Player* player);
	virtual void render(ASGE::Renderer* renderer) override;

private:
	void renderStats(ASGE::Renderer* renderer);
	void renderTitle(ASGE::Renderer* renderer);
	void renderHealth(ASGE::Renderer* renderer);

	Player* player_ptr = nullptr;
};