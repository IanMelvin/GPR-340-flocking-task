#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 separatingForce = Vector2::zero();

    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them

    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;
        Vector2 centerOfMass;
        int countCloseFlockmates = 0;

        for (Boid* neighbor : neighborhood)
        {
            centerOfMass += neighbor->getPosition();
        }
        centerOfMass /= neighborhood.size();

        Vector2 direction = centerOfMass - boid->getPosition();
        float distance = sqrt((direction.x * direction.x) + (direction.y * direction.y));

        if (distance < desiredDistance)
        {
            float strength = (1 / (distance * distance));

            direction = Vector2::normalized(direction);
            separatingForce += strength * direction;
        }
    }

    separatingForce = Vector2::normalized(separatingForce);
    separatingForce *= -1;

    return separatingForce;
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
