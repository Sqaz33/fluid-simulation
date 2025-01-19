#include <memory>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "../include/material-point.hpp"
#include "../include/physical-model.hpp"
#include "../include/view.hpp"

namespace {

std::mutex mut;
std::vector<material::MaterialPoint> materialPoints;
auto windowWidth = 800u;
auto windowHeight = 600u;
sf::RenderWindow window(sf::VideoMode({windowWidth, windowHeight}), "My window");

//TODO:
void dummyUpdatePhysics() {
    physics::dummyPhysics physics;
    while (window.isOpen()) {
        {
            std::lock_guard<std::mutex> lk{mut};
            for (auto& p : materialPoints) {
                physics.dummyF(10, -5, 0.01, p);
            }
        }
        std::this_thread::sleep_for(std::chrono::microseconds(10));
    }

}

//TODO:
void dummyUpdateWindow(sf::RenderWindow& window, view::DrawableFramedWindow& frame) {
    window.clear(sf::Color::White);
    frame.draw(window);
    window.display();
}

void handleCloseEvent(sf::RenderWindow& window) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
} 

//TODO:
void dummyRenderWindow(sf::RenderWindow& window, std::shared_ptr<view::DrawableCanvas> canvas) {
    std::lock_guard<std::mutex> lk{mut};
    for (const auto& p : materialPoints) {
        auto pos = p.pos();
        sf::Vector2f v{(float)pos.first, (float) pos.second};
        canvas->addPointForDraw(v);
    }    
}

} // namespace

int main() {
    using namespace view;

    float frameThickness = 10.f;
    DrawableFramedWindow frame(window, frameThickness);

    auto canvas = std::make_shared<DrawableCanvas>(
        windowWidth - frameThickness * 2,
        windowHeight - frameThickness * 2
    );
    frame.pushComponent(canvas);

    materialPoints.emplace_back(
        std::pair<double, double>(40., 40.), 
        std::pair<double, double>(20., 20.), 
        std::pair<double, double>(0., 0.), 
        3., 
        material::MaterialType::SOLID
    );

    std::thread updater(dummyUpdatePhysics);

    while (window.isOpen()) {
        handleCloseEvent(window);
        dummyRenderWindow(window, canvas);
        dummyUpdateWindow(window, frame);
    }

    updater.join();
}