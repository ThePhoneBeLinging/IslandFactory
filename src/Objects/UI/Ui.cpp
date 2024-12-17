//
// Created by Elias Aggergaard Larsen on 17/12/2024.
//

#include "Ui.h"

Ui::Ui(std::shared_ptr<EngineBase>& engineBase) : hotbar_(std::make_shared<Hotbar>(engineBase))
{
}
