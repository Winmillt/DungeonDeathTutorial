#include <iostream>
#include <sstream>

#include <Engine/Input.h>
#include <Engine/Sprite.h>

#include "Game.h"
#include "Constants.h"
#include "Font.h"
#include "Player.h"

//USER INTERFACE
#include "Panel.h"
#include "InputPanel.h"
#include "GamePanel.h"
#include "MapPanel.h"
#include "ViewportPanel.h"
#include "StatsPanel.h"

DungeonDeathGame::DungeonDeathGame()
{

}

DungeonDeathGame::~DungeonDeathGame()
{
	for (auto& panel : panels)
	{
		delete panel;
		panel = nullptr;
	}
	
	for (auto& font : Font::fonts)
	{
		delete font;
		font = nullptr;
	}

	if (player_one)
	{
		delete player_one;
		player_one = nullptr;
	}
}

bool DungeonDeathGame::init()
{
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	if (!initAPI())
	{
		return false;
	}

	// load fonts
	Font::fonts[0] = new Font(renderer->loadFont("Resources\\Fonts\\DroidSansMono.ttf", 18), "default", 18);
	Font::fonts[1] = new Font(renderer->loadFont("Resources\\Fonts\\comic.ttf", 32), "heading", 32);
	Font::fonts[2] = new Font(renderer->loadFont("Resources\\Fonts\\comic.ttf", 16), "small", 16);

	renderer->setClearColour(ASGE::COLOURS::BLACK);

	//create player 
	Player* player_one = new Player(Player::PlayerClass::BARBARIAN);
	player_one->loadAvatar(renderer.get());
	
	GamePanel* game_panel = new GamePanel;
	game_panel->setPosX(1);
	game_panel->setPosY(70);
	game_panel->setHeight(35);
	game_panel->setWidth(35);
	panels[0] = game_panel;

	ViewportPanel* viewport_panel = new ViewportPanel;
	viewport_panel->setPosX((game_panel->getPosX() + (game_panel->getWidth() * BORDER_CELL_WIDTH) + PANEL_PADDING));
	viewport_panel->setPosY(340);
	viewport_panel->setWidth(20);
	viewport_panel->setHeight(20);
	panels[1] = viewport_panel;

	StatsPanel* stats_panel = new StatsPanel();
	stats_panel->setPosX(viewport_panel->getPosX());
	stats_panel->setPosY(game_panel->getPosY());
	stats_panel->setWidth(static_cast<int>(viewport_panel->getWidth()*1.8f));
	stats_panel->setHeight(game_panel->getHeight() - viewport_panel->getHeight());
	stats_panel->init(player_one);
	panels[2] = stats_panel;

	MapPanel* map_panel = new MapPanel;
	map_panel->setPosX(viewport_panel->getPosX() + (viewport_panel->getWidth() * BORDER_CELL_WIDTH));
	map_panel->setPosY(viewport_panel->getPosY());
	map_panel->setWidth(stats_panel->getWidth() - viewport_panel->getWidth());
	map_panel->setHeight(game_panel->getHeight() - stats_panel->getHeight());
	panels[3] = map_panel;

	InputPanel* input_panel = new InputPanel;
	input_panel->setPosX(0);
	input_panel->setPosY(700);
	panels[4] = input_panel;

	auto callbackid = this->inputs->addCallbackFnc(ASGE::EventType::E_KEY, &InputPanel::input, input_panel);
	return true;
}

void DungeonDeathGame::update(const ASGE::GameTime &)
{
	return;
}

void DungeonDeathGame::render(const ASGE::GameTime &)
{
	renderer->setFont(Font::fonts[1]->id);
	renderer->renderText("Dungeon Death 2017", 0, 30, 1.0, ASGE::COLOURS::DARKORANGE);

	renderer->setFont(Font::fonts[0]->id);
	for (auto panel : panels)
	{
		panel->render(renderer.get());
	}
}
