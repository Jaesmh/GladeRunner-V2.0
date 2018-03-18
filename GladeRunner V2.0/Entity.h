#ifndef ENTITY_H
#define ENTITY_H

#include "Objects.h"
#include <vector>

class Entity : public Objects
{
public:
	void SetHealth(int H) { Health = H; }
	void SetMaxHealth(int H) { MaxHealth = H; }
	inline int GetHealth() { return Health; }
	inline int GetMaxHealth() { return MaxHealth; }
	void StartCycle(int Row, int Column, int W, int H);
	void SetCurAnimation(int Animation) { CurAnim = Animation; }
	void UpdateAnimations();
	Entity(){}
	~Entity();
private:
	int Health, MaxHealth = NULL;
	int CurAnim;
};

#endif //ENTITY_H