#include "Object.h"

using namespace game;

Object::Object(const std::string &name)
{
	setName(name);
}

Object::Object()
{
	setName("Object");
}