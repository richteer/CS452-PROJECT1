#ifndef _renderobject_h_
#define _renderobject_h_

#include <stdlib.h>
#include "bulletmap.h"

#define COORD_TYPE float

struct point {
	COORD_TYPE x;
	COORD_TYPE y;
};

struct motion {
	float x;
	float y;
};

class RenderObject {
	public:
		RenderObject(COORD_TYPE* points, int sz);
		~RenderObject();

		void setPosition(point other) { this->pos = other; }
		void modPosition(float);
		void modPosition(motion);
		point getPosition(void) { return this->pos; }

		void setAngle(float other) { this->angle = other; }
		float getAngle(void) { return this->angle; }
		void modAngle(float other) { this->angle += other; } 
	
		void modMotion(motion other) { this->mot.x += other.x; this->mot.y += other.y; }
		void modMotion(float);
		void setMotion(motion other) { this->mot = other; }

		void move(void);
		void shoot(BulletMap*);


		COORD_TYPE* data;
		int size;

//	private:
		point pos;
		float angle;
		motion mot;
		float weight;
		float color[4];

};

#endif
