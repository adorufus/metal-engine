#pragma once
//#include "ECS/ECS.h"
#include "Vector2D.h"
#include <stdio.h>

#define UNIT_MASS 1.0f
#define GRAVITY 9.0f

class PhysicsBody : public Component {
public:

	PhysicsBody(float mass, float gravity) {
		mMass = mass;
		mGravity = gravity;
	}

	//setter mass & gravity
	inline void SetMass(float mass) { mMass = mass; }
	inline void SetGravity(float gravity) { mGravity = gravity; }

	virtual ~PhysicsBody() {}

	inline void ApplyForce(Vector2D F) { mForce = F; }
	inline void ApplyForceX(float x) { mForce.x = x; }
	inline void ApplyForceY(float y) { mForce.y = y; }
	inline void DestroyForce() { mForce = Vector2D().Zero(); }

	inline void ApplyFriction(Vector2D friction) { mFriction = friction; }
	inline void DestroyFriction() { mFriction = Vector2D().Zero(); }

	inline float GetMass() { return mMass; }
	inline Vector2D Position() { return mPosition; }
	inline Vector2D Acceleration() { return mAcceleration; }

	void init() {
		printf("Rigidbody running\n");
	}

	void update() {
		mAcceleration.x = (mForce.x + mFriction.x) / mMass;
		mAcceleration.y = mGravity + mForce.y / mMass;

		//TODO: times by Delta Time;
		mVelocity = mAcceleration;
		mPosition = mVelocity;
	}

private:
	float mMass;
	float mGravity;

	Vector2D mForce;
	Vector2D mFriction;

	Vector2D mPosition;
	Vector2D mVelocity;
	Vector2D mAcceleration;
};