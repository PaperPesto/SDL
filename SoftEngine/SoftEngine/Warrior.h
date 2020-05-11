#pragma once
#include "Character.h"

class Warrior : public Character
{
public:
	Warrior(Properties* props);
	
	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	int m_Row, m_Frame, m_FrameCount;
	int m_AnimSpeed;
	int m_ColumnOffset;
};

