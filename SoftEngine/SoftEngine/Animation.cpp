#include "Animation.h"
#include "TextureManager.h"

void Animation::Update() {
	m_SpriteFrame = (SDL_GetTicks() / m_AnimSpeed) % m_FrameCount + m_SpriteColumn;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight) {
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spriteWidth, spriteHeight, m_SpriteRow, m_SpriteFrame, m_Flip);
}

void Animation::SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed, int spriteColumn, SDL_RendererFlip flip) {
	m_TextureID = textureID;
	m_SpriteRow = spriteRow;
	m_SpriteColumn = spriteColumn;
	m_FrameCount = frameCount;
	m_AnimSpeed = animSpeed;
	m_Flip = flip;
}