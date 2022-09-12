#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    Vector2 centerOfMass;
    for (Boid* neighbor : neighborhood)
    {
        centerOfMass += neighbor->getPosition();
    }
    centerOfMass /= neighborhood.size();

    cohesionForce = centerOfMass - boid->getPosition();
    cohesionForce = Vector2::normalized(cohesionForce);

    return cohesionForce;
}