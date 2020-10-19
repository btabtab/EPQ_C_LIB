/*
|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|
This header includes functions and structs relating to
how physics within the game engine would work.

The current structs are:

Point2D

PhysObject

The curent functions are:

void updatePhysObject(PhysObject* ptr_PhysObject)


|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|_|#|
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Point2D
{
    float x, y;
} Point2D;

/*
This is going to be a struct will hold information about an object 
*/
typedef struct PhysObject
{
    /*
    This is where the object is in 2D space.
    */
    Point2D position;
    /*
    This is the current
    direction of the object
    */
    Point2D direction;
    /*
    This is how much the fall_speed
    will increase by per frame.
    */
    float weight;
    /*
    This is the current speed
    the object is falling at.
    */
    float fall_speed;
} PhysObject;

/*
This is a function that is meant to be called every frame that a
"PhysObject" is going to have it's position updated.
*/
void updatePhysObject(PhysObject* ptr_PhysObject)
{
    ptr_PhysObject->position.y -= ptr_PhysObject->fall_speed;
    ptr_PhysObject->fall_speed += ptr_PhysObject->weight / 1.5;
    ptr_PhysObject->position.x += ptr_PhysObject->direction.x;
    ptr_PhysObject->position.y += ptr_PhysObject->direction.y;
}

/*

*/
void bounceHorizontally(PhysObject* ptr_object)
{
	ptr_object->direction.x += -(ptr_object->direction.x * 2);
}

/*

*/
void bounceVertically(PhysObject* ptr_object)
{
	ptr_object->fall_speed = (ptr_object->fall_speed * -1);
}