#include "../include/view.hpp"

namespace view {
void DrawableComposite::pushComponent(std::shared_ptr<IDrawable> comp) {
    components_.emplace_back(comp);
}

void DrawableComposite::draw(sf::RenderWindow& window, sf::Vector2f start) {
    for (auto comp : components_) {
        comp->draw(window, start);
    }
}


// #######################################
DrawableFrame::DrawableFrame(float width, float height, float thickness) :
        thickness_(thickness)
        , externalRect_({width, height})
{
    if (thickness > std::min(width, height)) {
        throw std::logic_error("thickness > min(width, height)");
    }
        
    auto interWidth = width - thickness * 2;
    auto interHeigh = height - thickness * 2;
    internalRect_ = sf::RectangleShape({interWidth, interHeigh});

    externalRect_.setFillColor(sf::Color::Black);
}

void DrawableFrame::draw(sf::RenderWindow& window, sf::Vector2f start) {
    sf::Vector2f interPos(
        start.x + thickness_,
        start.y + thickness_  
    );
    externalRect_.setPosition(start);
    internalRect_.setPosition(interPos);
    window.draw(externalRect_);
    window.draw(internalRect_);
}

float DrawableFrame::thickness() const { return thickness_; }


// #######################################
DrawableFramedWindow::DrawableFramedWindow(sf::RenderWindow& window, float thickness) :
    frame_(window.getSize().x, window.getSize().y, thickness)
{}

void DrawableFramedWindow::draw(sf::RenderWindow& window, sf::Vector2f start) {
    frame_.draw(window, start);
    drawComponents_(window, start);
}

void DrawableFramedWindow::drawComponents_(sf::RenderWindow& window, sf::Vector2f start) {
    auto thickness = frame_.thickness();
    sf::Vector2f compStart(
        start.x + thickness,
        start.y + thickness
    );
    DrawableComposite::draw(window, compStart);
} 


// #######################################
DrawableCanvas::DrawableCanvas(float width, float height) : 
    width_(width)
    , height_(height) 
{}

void DrawableCanvas::draw(sf::RenderWindow& window, sf::Vector2f start) {
    clear_(window, start);
    drawPoints_(window, start);
}

void DrawableCanvas::addPointForDraw(sf::Vector2f point) {
    pointsForDraw_.emplace_back(std::move(point));
}

void DrawableCanvas::clear_(sf::RenderWindow& window, sf::Vector2f start) {
    sf::RectangleShape cleaningArea({width_, height_});
    cleaningArea.setPosition(start);
    cleaningArea.setFillColor(sf::Color::White);
    window.draw(cleaningArea);
}

void DrawableCanvas::drawPoints_(sf::RenderWindow& window, sf::Vector2f start) {
    sf::RectangleShape point({5, 5});
    point.setFillColor(sf::Color::Red);
    for (const auto& p : pointsForDraw_) {
        point.setPosition({
            p.x + start.x,
            p.y + start.y
        });
        window.draw(point);
    }
    pointsForDraw_.clear();
}


} // namespace view