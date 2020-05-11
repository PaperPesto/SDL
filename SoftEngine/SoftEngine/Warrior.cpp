#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"



Warrior::Warrior(Properties* props) : Character(props){
	/*m_Row = 5;
	m_ColumnOffset = 3;
	m_FrameCount = 4;
	m_AnimSpeed = 170;*/

	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureID, 5, 4, 170, 3);
}

void Warrior::Draw() {
	//TextureManager::GetInstance()->DrawFrame(m_TextureID, m_Transform->X, m_Transform->Y, m_Width, m_Height, m_Row, m_Frame);
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt) {
	//m_Frame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount + m_ColumnOffset;
	m_RigidBody->Update(0.01);
	m_RigidBody->ApplyForceX(0);

	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Animation->Update();
}

void Warrior::Clean() {
	TextureManager::GetInstance()->Clean();
}