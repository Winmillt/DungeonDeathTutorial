#include <algorithm>
#include <sstream>

#include <Engine/Keys.h>
#include <Engine/Renderer.h>
#include <Engine/InputEvents.h>

#include "InputPanel.h"

void InputPanel::render(ASGE::Renderer* renderer)
{
	std::stringstream ss;
	ss << "> " << str;

	renderer->setFont(0);
	renderer->renderText(ss.str().c_str(), getPosX(), getPosY(), 1.0, ASGE::COLOURS::FORESTGREEN);
}

void InputPanel::input(ASGE::SharedEventData data)
{
	auto key_event = static_cast<ASGE::KeyEvent*>(data.get());
	auto action = key_event->action;
	auto key = key_event->key;

	if (action == ASGE::KEYS::KEY_PRESSED)
	{
		if (key == ASGE::KEYS::KEY_DELETE ||
			key == ASGE::KEYS::KEY_BACKSPACE && 
			str.size() )
		{
			str.pop_back();
		}
		else if (key == ASGE::KEYS::KEY_ENTER)
		{
			str.clear();
		}
		else
		{
			str += key;
			return;
		}
	}
}
