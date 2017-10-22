#pragma once
#include "Panel.h"
#include <memory>

namespace ASGE
{
	class Renderer;
}

class ViewportPanel: public UIPanel
{

public:
	virtual void render(ASGE::Renderer* renderer) override;
	
};