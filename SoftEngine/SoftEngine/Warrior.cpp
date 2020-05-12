#include "Warrior.h"
#include "TextureManager.h"
#include "SDL.h"
#include "Input.h"


Warrior::Warrior(Properties* props) : Character(props) {
	/*m_Row = 5;
	m_ColumnOffset = 3;
	m_FrameCount = 4;
	m_AnimSpeed = 170;*/

	m_RigidBody = new RigidBody();
	m_Animation = new Animation();
	m_Animation->SetProps(m_TextureID, 1, 5, 170, 1);	// Run
}

void Warrior::Draw() {
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);
}

void Warrior::Update(float dt) {

	m_Animation->SetProps(m_TextureID, 5, 4, 170, 3);	// IDLE
	m_RigidBody->UnSetForce();

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A)) {
		m_RigidBody->ApplyForceX(5 * BACKWARD);
		m_Animation->SetProps(m_TextureID, 1, 5, 170, 1, SDL_FLIP_HORIZONTAL);	// RUN
	};

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D)) {
		m_RigidBody->ApplyForceX(5 * FORWARD);
		m_Animation->SetProps(m_TextureID, 1, 5, 170, 1);	// RUN
	};


	m_RigidBody->Update(0.6);

	m_Transform->TranslateX(m_RigidBody->Position().X);
	//m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Animation->Update();
}

void Warrior::Clean() {
	TextureManager::GetInstance()->Clean();
}