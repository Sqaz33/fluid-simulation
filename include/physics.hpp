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

#include "material.hpp"

namespace physics {

class dummy {
    // do physics
    void dummyF(double g, double k, double dt, material::MaterialPoint& mpoint);
};

} // namespace physics

#endif // INCLUDE_PHYSICS_HPP