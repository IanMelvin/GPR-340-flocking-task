#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    Vector2 centerOfMass;
    for (Boid* neighbor : neighborhood)
    {
        if (boid != neighbor)
        {
            centerOfMass += neighbor->getPosition();
        }
    }
    centerOfMass /= neighborhood.size();

    if (neighborhood.size() > 0)
    {
        Vector2 diffInPos = centerOfMass - boid->getPosition();
        float distance = Vector2::getDistance(centerOfMass, boid->getPosition());
        cohesionForce = diffInPos.normalized() * (distance / boid->getDetectionRadius());
    }
    else 
    {
        cohesionForce = Vector2::zero();
    }

    return cohesionForce.normalized();
}