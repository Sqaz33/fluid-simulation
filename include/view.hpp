#ifndef INCLUDE_VIEW_HPP
#define INCLUDE_VIEW_HPP

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

namespace view {

class IDrawable {
public:
    virtual void draw(sf::RenderWindow& window, sf::Vector2f start) = 0;
    virtual ~IDrawable() {
    }
};

class DrawableComposite : public IDrawable {
public:
    void pushComponent(std::shared_ptr<IDrawable> comp);
    virtual void draw(sf::RenderWindow& window, sf::Vector2f start) = 0;

private:
    std::vector<std::shared_ptr<IDrawable>> components_;
};

/**
 * @brief 
 * 
 */
class DrawableFrame final : public IDrawable {
public:
    DrawableFrame(float width, float height, float thickness);

public:
    void draw(sf::RenderWindow& window, sf::Vector2f start) override;
    float thickness() const;

private:
    float thickness_;
    sf::RectangleShape externalRect_;
    sf::RectangleShape internalRect_;
};

/**
 * @brief
 *
 */
class DrawableFramedWindow final : public DrawableComposite {
public:
    DrawableFramedWindow(sf::RenderWindow& window, float thickness);
    void draw(sf::RenderWindow& window, sf::Vector2f start = { 0, 0 }) override;

private:
    DrawableFrame frame_;

private:
    void drawComponents_(sf::RenderWindow& window, sf::Vector2f start);
};

/**
 * @brief
 *
 */
class DrawableCanvas final : public IDrawable {
public:
    DrawableCanvas(float width, float height);

public:
    void draw(sf::RenderWindow& window, sf::Vector2f start) override;
    void addPointForDraw(sf::Vector2f point);

private:
    float width_;
    float height_;
    std::vector<sf::Vector2f> pointsForDraw_;

private:
    void clear_(sf::RenderWindow& window, sf::Vector2f start);
    void drawPoints_(sf::RenderWindow& window, sf::Vector2f start);
};

} // namespace view

#endif // INCLUDE_VIEW_HPP