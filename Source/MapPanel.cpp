#include "MapPanel.h"
#include <Engine/Renderer.h>
#include <string>
const std::string map =
R"(
MAP


       |[ ]|
   ---      ---
   |[!] [*] [!]|
   ---      ---
       |[ ]|



[EXITS: N E S W]
)";

void MapPanel::render(ASGE::Renderer* renderer)
{
	UIPanel::render(renderer);
	renderer->renderText(map.c_str(), getPosX() + 25, getPosY());
}
