//
// Created by Elias Aggergaard Larsen on 20/12/2024.
//

#include "UI.h"

UI::UI(std::shared_ptr<EngineBase>& engineBase) : hotbar_(std::make_shared<Hotbar>(engineBase))
{
}

void UI::updateLocationInCaseOfResize()
{
    hotbar_->updateLocationInCaseOfResize();
}
