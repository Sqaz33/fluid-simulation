/**
 * @file physics.hpp
 * @author Matveev Stepan (mset321@gmailc.com)
 * @brief a file with declarations of physics classes.
 * @version 0.1
 * @date 2025-01-17
 *
 * @copyright Copyright (c) 2025
 *
 */


#ifndef INCLUDE_PHYSICS_HPP
#define INCLUDE_PHYSICS_HPP

#include <cmath>

#include "material-point.hpp"

namespace physics {

class dummyPhysics {
public:
    // do physics
    void dummyF(double g, double k, double dt, material::MaterialPoint& mpoint) {
        auto pos          = mpoint.pos();
        auto speed        = mpoint.speed();
        auto acceleration = mpoint.acceleration();
        auto weight       = mpoint.weight();

        acceleration.first  = (-k * speed.first) / weight;
        acceleration.second = g - (speed.second * k) / weight;
        
        pos.first  += speed.first * dt;
        pos.second += speed.second * dt;

        speed.first  += acceleration.first * dt;
        speed.second += acceleration.second * dt;

        auto dtsquare = dt * dt;
        pos.first += 0.5 * acceleration.first * dtsquare;
        pos.second += 0.5 * acceleration.second * dtsquare;
        if (pos.first >= 774.) {
            speed.first = 10;
            acceleration.first = 10;
            pos.first = 15;
        }
        if (pos.second >= 574.) {
            speed.second = 10;
            acceleration.second = 10;
            pos.second = 15;
        }

        mpoint.setAcceleration(acceleration);
        mpoint.setSpeed(speed);
        mpoint.setPos(pos);
    }
};



} // namespace physics

#endif // INCLUDE_PHYSICS_HPP