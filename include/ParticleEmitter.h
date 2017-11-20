#pragma once

#include <glm/glm.hpp>

// Params for each particle
// Note: this is a bare minimum particle structure
// Add any properties you want to control here
struct Particle
{
	// Physics properties
	// Position is where the particle currently is
	// Velocity is the rate of change of position
	// Acceleration is the rate of change of velocity
	// p' = p + v*dt
		//	current position is the previous position plus the change in position multiplied by the amount of time passed since we last calculated position
	// v' = v + a*dt
	glm::vec3 position;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	glm::vec3 force;
	float mass;

	// Visual Properties
	float size;
	glm::vec4 colour;
	// Other properties... 
	// ie. sprite sheet

	float life;
};

// Emitter is responsible for emitting (creating, dispatching) particles
class ParticleEmitter
{
public:
private:
	unsigned int m_pNumParticles;
	Particle* m_pParticles;

public:
	ParticleEmitter();
	~ParticleEmitter();

	void initialize(unsigned int numParticles);
	void freeMemory();

	void update(float dt);
	void draw();

	void applyForceToParticle(unsigned int idx, glm::vec3 force);

	unsigned int getNumParticles() { return m_pNumParticles; }

	glm::vec3 getParticlePosition(unsigned int idx);

	///// Playback properties
	bool playing;

	//// Update flags
	bool interpolateColour;

	///// Initial properties for newly spawned particles

	glm::vec3 emitterPosition;

	// Storing ranges for each property so each particle has some randomness
	glm::vec3 velocity0;
	glm::vec3 velocity1;

	// these properties are single floats, so we can pack the min and max into a vec2, just data!
	glm::vec2 lifeRange;
	glm::vec2 sizeRange;
	glm::vec2 massRange;

	glm::vec4 colour0;
	glm::vec4 colour1;

	// ... other properties
	// ... what would be a better way of doing this?
	// Make a keyframe controller for each property! this gives you max control!!
	// (this is what full out particle editors do, ie popcorn fx)
};