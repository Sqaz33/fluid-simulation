#include "../include/material-point.hpp"

#include <utility>

namespace material {
    
MaterialPoint::MaterialPoint(std::pair<double, double> startPos,
                             std::pair<double, double> startSpeed,
                             std::pair<double, double> startAcceleration,
                             double weight,
                             MaterialType materialType)
    : 
    pos_(startPos)
    , speed_(startSpeed)
    , acceleration_(startAcceleration)
    , weight_(weight)
    , materialType_(materialType) 
{}

MaterialPoint::MaterialPoint(const MaterialPoint& oth) 
    : 
    pos_(oth.pos_)
    , speed_(oth.speed_)
    , acceleration_(oth.acceleration_)
    , weight_(oth.weight_)
    , materialType_(oth.materialType_) 
{}

MaterialPoint::MaterialPoint(MaterialPoint&& oth) 
    : 
    pos_(std::move(oth.pos_))
    , speed_(std::move(oth.speed_))
    , acceleration_(std::move(oth.acceleration_))
    , weight_(std::move(oth.weight_))
    , materialType_(std::move(oth.materialType_)) 
{}

MaterialPoint& MaterialPoint::operator=(const MaterialPoint& rhs) {
    pos_ = rhs.pos_;
    speed_ = rhs.speed_;
    acceleration_ = rhs.acceleration_;
    weight_ = rhs.weight_;
    materialType_ = rhs.materialType_;
    return *this;
}

MaterialPoint& MaterialPoint::operator=(MaterialPoint&& rhs) {
    pos_ = std::move(rhs.pos_);
    speed_ = std::move(rhs.speed_);
    acceleration_ = std::move(rhs.acceleration_);
    weight_ = std::move(rhs.weight_);
    materialType_ = std::move(rhs.materialType_);
    return *this;
}

std::pair<double, double> MaterialPoint::pos() const { return pos_; }
std::pair<double, double> MaterialPoint::speed() const { return speed_; }
std::pair<double, double> MaterialPoint::acceleration() const { return acceleration_; }
double MaterialPoint::weight() const { return weight_; }

void MaterialPoint::setPos(const std::pair<double, double> pos) { pos_ = pos; }
void MaterialPoint::setSpeed(const std::pair<double, double> speed) { speed_ = speed; }
void MaterialPoint::setAcceleration(const std::pair<double, double> acceleration) { acceleration_ = acceleration; }
void MaterialPoint::setWeight(double weight) { weight_ = weight; }

}  // namespace material