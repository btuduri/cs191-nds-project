#include "ProjectLib.h"

bool CPhysics::gravity() {
	
	cVelocity.vy = cVelocity.vy + GRAVITY;
	//throw check here for collisions...
	
}
