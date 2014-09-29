#include "AABB.h"
#include <d3dx9.h>
using namespace DoMaRe;
AABB::AABB()	:	m_pkOffset( new D3DXVECTOR3() ){
	for(int i=0; i < 8; i++){
		m_pkCorners[i]	= new D3DXVECTOR3();
	}
}
AABB::~AABB(){
	for(int i=0; i < 8; i++){
		delete m_pkCorners[i];
		m_pkCorners[i]	= NULL;
	}

	delete m_pkOffset;
	m_pkOffset = NULL;
}
void AABB::setData(float fWidth, float fHeight, float fDepth, float fOffsetX, float fOffsetY, float fOffsetZ){
	// REVISAR LOGICA... I DONT HAVE A FUCKING IDEA OF WHAT I'M DOING.
	m_pkOffset->x = fOffsetX;
	m_pkOffset->y = fOffsetY;
	m_pkOffset->z = fOffsetZ;

	m_pkCorners[0]->x = +fWidth;	m_pkCorners[0]->y = +fHeight;	m_pkCorners[0]->z = +fDepth;
	m_pkCorners[0]->x = +fWidth;	m_pkCorners[0]->y = +fHeight;	m_pkCorners[0]->z = -fDepth;
	m_pkCorners[0]->x = +fWidth;	m_pkCorners[0]->y = -fHeight;	m_pkCorners[0]->z = +fDepth;
	m_pkCorners[0]->x = +fWidth;	m_pkCorners[0]->y = -fHeight;	m_pkCorners[0]->z = -fDepth;
	m_pkCorners[0]->x = -fWidth;	m_pkCorners[0]->y = +fHeight;	m_pkCorners[0]->z = +fDepth;
	m_pkCorners[0]->x = -fWidth;	m_pkCorners[0]->y = +fHeight;	m_pkCorners[0]->z = -fDepth;
	m_pkCorners[0]->x = -fWidth;	m_pkCorners[0]->y = -fHeight;	m_pkCorners[0]->z = +fDepth;
	m_pkCorners[0]->x = -fWidth;	m_pkCorners[0]->y = -fHeight;	m_pkCorners[0]->z = -fDepth;

	m_fWidth = fWidth;
	m_fHeight = fHeight;
	m_fDepth = fDepth;

}

const Vector3& AABB::offset() const{
	return m_pkOffset;
}

const Vector3* AABB::corners() const{
	return m_pkCorners;
}

float AABB::width()	const{
	return m_fWidth;
}

float AABB::height() const{
	return m_fHeight;
}

float AABB::depth() const{
	return m_fDepth;
}
