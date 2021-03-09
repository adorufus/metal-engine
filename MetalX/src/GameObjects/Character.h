#pragma once
#include "../Object/GameObject.h"

class Character : public GameObject {
	
public:
	Character() = default;
	Character(Properties* props) : GameObject(props) {

	}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	std::string mName;

private:
};