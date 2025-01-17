#include "../include/material.hpp"

#include <utility>

namespace material {
    
MaterialPoint::MaterialPoint(std::pair<double, double>& startPos,
                             std::pair<double, double>& startSpeed,
                             std::pair<double, double>& startAcceleration,
                             MaterialType materialType)
    : 
    pos_(startPos)
    , speed_(startSpeed)
    , acceleration_(startAcceleration)
    , materialType_(materialType) 
{}

MaterialPoint::MaterialPoint(const MaterialPoint& oth) 
    : 
    pos_(oth.pos_)
    , speed_(oth.speed_)
    , acceleration_(oth.acceleration_)
    , materialType_(oth.materialType_) 
{}

MaterialPoint::MaterialPoint(MaterialPoint&& oth) 
    : 
    pos_(std::move(oth.pos_))
    , speed_(std::move(oth.speed_))
    , acceleration_(std::move(oth.acceleration_))
    , materialType_(std::move(oth.materialType_)) 
{}

MaterialPoint& MaterialPoint::operator=(const MaterialPoint& rhs) {
    pos_ = rhs.pos_;
    speed_ = rhs.speed_;
    acceleration_ = rhs.acceleration_;
    materialType_ = rhs.materialType_;
}

MaterialPoint& MaterialPoint::operator=(MaterialPoint&& rhs) {
    pos_ = std::move(rhs.pos_);
    speed_ = std::move(rhs.speed_);
    acceleration_ = std::move(rhs.acceleration_);
    materialType_ = std::move(rhs.materialType_);
}

const std::pair<double, double>& MaterialPoint::pos() const { return pos_; }
const std::pair<double, double>& MaterialPoint::speed() const { return speed_; }
const std::pair<double, double>& MaterialPoint::acceleration() const { return acceleration_; }

void MaterialPoint::setPos(const std::pair<double, double>& pos) { pos_ = pos; }
void MaterialPoint::setSpeed(const std::pair<double, double>& speed) { speed_ = speed; }
void MaterialPoint::setAcceleration(const std::pair<double, double>& acceleration) { acceleration_ = acceleration; }

}  // namespace material