#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

#define PI 3.14159265

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    // todo: add a wind force here
    // hint: use the windAngle variable
    Vector2 windPosition = Vector2::right();

    windPosition = windPosition.Rotate(windAngle*(180/PI));

    return Vector2::normalized(windPosition);
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}