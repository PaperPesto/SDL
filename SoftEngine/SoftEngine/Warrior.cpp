#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"



Warrior::Warrior(Properties* props) : Character(props){
	m_Row = 5;
	m_ColumnOffset = 3;
	m_FrameCount = 4;
	m_AnimSpeed = 170;
}

void Warrior::Draw() {
	TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
}

void Warrior::Update(float dt) {
	m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount + m_ColumnOffset;
}

void Warrior::Clean() {
	TextureManager::GetInstance()->Clean();
}