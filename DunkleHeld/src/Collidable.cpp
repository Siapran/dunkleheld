/* 
 * File:   Collidable.cpp
 * Author: siapran
 * 
 * Created on February 5, 2015, 9:17 AM
 */

#include "Collidable.h"

bool Collidable::collidesWithCircle(sf::Vector2f pos, float radius) {
    return squareDistance(pos, m_position) <= radius * radius;
}

sf::Vector2f Collidable::resoleCollision(sf::Vector2f pos, float radius) {
    auto len = distance(pos, m_position);
    auto normal = (pos - m_position) / len;
    auto penetration = radius - len;
    return (len > 0) ? len : 0;
}

float Collidable::distance(sf::Vector2f a, sf::Vector2f b) {
    return std::sqrt(squareDistance(a, b));
}

float Collidable::squareDistance(sf::Vector2f a, sf::Vector2f b) {
    auto tmp = (a - b);
    return (tmp.x * tmp.x + tmp.y * tmp.y);
}

bool Collidable::collidesBoxVSCircle(sf::FloatRect box, sf::Vector2f pos, float radius) {
    // Setup a couple pointers to each object

    // Vector from A to B
    auto n = pos - getCentre(box);

    // Closest point on A to center of B
    auto closest = n;

    // Calculate half extents along each axis
    float x_extent = box.width / 2;
    float y_extent = box.height / 2;

    // Clamp point to edges of the AABB
    closest.x = clamp(-x_extent, x_extent, closest.x);
    closest.y = clamp(-y_extent, y_extent, closest.y);

    bool inside = n == closest;

    float d = squareDistance(n, closest); //normal.LengthSquared()
    float r = radius;

    return !inside && d > r * r;
}

sf::Vector2f Collidable::resolveBoxVSCircle(sf::FloatRect box, sf::Vector2f pos, float radius) {

    // Vector from A to B
    auto n = pos - getCentre(box);

    // Closest point on A to center of B
    auto closest = n;

    // Calculate half extents along each axis
    float x_extent = box.width / 2;
    float y_extent = box.height / 2;

    // Clamp point to edges of the box
    closest.x = clamp(-x_extent, x_extent, closest.x);
    closest.y = clamp(-y_extent, y_extent, closest.y);

    bool inside = false;

    // Circle is inside the AABB, so we need to clamp the circle's center
    // to the closest edge
    if (n == closest) {
        inside = true;

        // Find closest axis
        if (abs(n.x) > abs(n.y)) {
            // Clamp to closest extent
            if (closest.x > 0)
                closest.x = x_extent;
            else
                closest.x = -x_extent;
        }// y axis is shorter
        else {
            // Clamp to closest extent
            if (closest.y > 0)
                closest.y = y_extent;
            else
                closest.y = -y_extent;
        }
    }

    auto normal = n - closest;
    float d = squareDistance(normal); //normal.LengthSquared()
    float r = radius;

    // Early out of the radius is shorter than distance to closest point and
    // Circle not inside the AABB
    if (!inside && d > r * r)
        return sf::Vector2f();

    // Avoided sqrt until we needed
    d = sqrt(d);

    // Collision normal needs to be flipped to point outside if circle was
    // inside the AABB
    if (inside) return (-n / d) * (r + d);
    else return (n / d) * (r + d);

}

sf::Vector2f Collidable::getCentre(sf::FloatRect box) {
    return sf::Vector2f(box.left + box.width / 2, box.top + box.width / 2);
}

float Collidable::clamp(float a, float b, float z) {
    if (z - a < b - z)
        return (z < a) ? a : z;
    else
        return (z > b) ? b : z;
}
