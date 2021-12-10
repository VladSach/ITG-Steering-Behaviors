#ifndef ENTITY_H
#define ENTITY_H

class Entity {
private:
    float radius = 15.f;
    vector2f position;
public:
    virutal void move(float x, float y);
};

#endif // ENTITY_H