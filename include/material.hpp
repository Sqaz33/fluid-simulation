/**
 * @file material.hpp
 * @author Matveev Stepan (mset321@gmailc.com)
 * @brief a file with declaration of material classes.
 * @version 0.1
 * @date 2025-01-17
 *
 * @copyright Copyright (c) 2025
 *
 */

#ifndef INCLUDE_MATERIAL_HPP
#define INCLUDE_MATERIAL_HPP

#include <utility>

namespace material {

enum class MaterialType : int { 
    LIQUID = 0, 
    SOLID 
};

class MaterialPoint {
    public:
    MaterialPoint(std::pair<double, double>& startPos,
                   std::pair<double, double>& startSpeed,
                   std::pair<double, double>& startAcceleration,
                   MaterialType materialType);

    MaterialPoint(const MaterialPoint& oth);
    MaterialPoint(MaterialPoint&& oth);

    MaterialPoint& operator=(const MaterialPoint& rhs);
    MaterialPoint& operator=(MaterialPoint&& rhs);

    public:
    const std::pair<double, double>& pos() const;
    const std::pair<double, double>& speed() const;
    const std::pair<double, double>& acceleration() const;

    void setPos(const std::pair<double, double>& pos);
    void setSpeed(const std::pair<double, double>& speed);
    void setAcceleration(const std::pair<double, double>& acceleration);

    private:
    std::pair<double, double> pos_          = { 0, 0 }; // x, y
    std::pair<double, double> speed_        = { 0, 0 }; // Vx, Vy
    std::pair<double, double> acceleration_ = { 0, 0 }; // ax, ay
    MaterialType materialType_              = MaterialType::SOLID;
};

} // namespace material

#endif // INCLUDE_MATERIAL_HPP