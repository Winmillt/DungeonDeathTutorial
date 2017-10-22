#pragma once
#include "Panel.h"
#include <memory>
#include <string>
namespace ASGE
{
	class Renderer;
}

class InputPanel : public UIPanel
{
public:
	InputPanel() = default;
	~InputPanel() = default;

	virtual void render(ASGE::Renderer* renderer) override;
	void input(ASGE::SharedEventData data);

private:
	std::string str = "";
};