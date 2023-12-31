#include "headers/Rect.h"

Rect::Rect() : x(0.0f), y(0.0f), w(0.0f), h(0.0f) { }

Rect::Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h) { }

Rect Rect::operator+(const Vec2& vec) const {
    return Rect(x + vec.x, y + vec.y, w, h);
}

Rect Rect::operator-(const Vec2& vec) const {
    return Rect(x - vec.x, y - vec.y, w, h);
}

Rect Rect::operator+=(const Vec2& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Rect Rect::operator-=(const Vec2& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

void Rect::SetCenter(Vec2 newCenter) {
    newCenter = newCenter - Vec2(w / 2.0f, h / 2.0f);
    x = newCenter.x;
    y = newCenter.y;
}

Vec2 Rect::Center() const {
    return Vec2(x + w / 2.0f, y + h / 2.0f);
}

bool Rect::Contains(const Vec2& point) const {
    return (point.x >= x && point.x <= x + w && point.y >= y && point.y <= y + h);
}

float Rect::Distance(const Rect& other) const {
    return Center().Distance(other.Center());
}