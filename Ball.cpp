#include "Ball.hpp"
#include <cmath>


Ball::Ball(const Point& center, const Velocity& velocity, const Color& color) {
    setCenter(center);
    setVelocity(velocity);
    setColor(color);
}

/**
 * Задает скорость объекта
 * @param velocity новое значение скорости
 */
void Ball::setVelocity(const Velocity& velocity) {
    this->velocity = velocity;
}

/**
 * @return скорость объекта
 */
Velocity Ball::getVelocity() const {
    return this->velocity;
}

/**
 * @brief Выполняет отрисовку объекта
 * @details объект Ball абстрагирован от конкретного
 * способа отображения пикселей на экране. Он "знаком"
 * лишь с интерфейсом, который предоставляет Painter
 * Рисование выполняется путем вызова painter.draw(...)
 * @param painter контекст отрисовки
 */
void Ball::draw(Painter& painter) const {
    // TODO: место для доработки
    Point* topLeft = new Point(center.x - radius, center.y - radius);
    Point* bottomRight = new Point(center.x + radius, center.y + radius);
    Color* color = new Color(0.2, 0.5, 0.1);
    painter.draw(*topLeft, *bottomRight, *color);
}

/**
 * Задает цвет объекта
 * @param color цвет объекта
 */
void Ball::setColor(const Color& color) {
    this->color = color;
}

/**
 * Задает координаты центра объекта
 * @param center новый центр объекта
 */
void Ball::setCenter(const Point& center) {
    this->center = center;
}

/**
 * @return центр объекта
 */
Point Ball::getCenter() const {
    // TODO: место для доработки
    return this->center;
}

/**
 * @brief Возвращает радиус объекта
 * @details обратите внимание, что метод setRadius()
 * не требуется
 */
double Ball::getRadius() const {
    return Ball::radius;
}

/**
 * @brief Возвращает массу объекта
 * @details В нашем приложении считаем, что все шары
 * состоят из одинакового материала с фиксированной
 * плотностью. В этом случае масса в условных единицах
 * эквивалентна объему: PI * radius^3 * 4. / 3.
 */
double Ball::getMass() const {
    return 4. / 3 * M_PI * std::pow(Ball::getRadius(), 3);
}
