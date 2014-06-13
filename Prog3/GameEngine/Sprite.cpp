
#include <SDL_image.h>
#include <iostream>
#include "Sprite.h"
#include "GameEngine.h"

Sprite::Sprite() {}

Sprite *Sprite::getInstance(Image *i, std::string name) {
  return new Sprite(i, name);
}

Sprite *Sprite::getInstance() { return new Sprite(); }

Sprite::Sprite(Image *i, const std::string name) : m_image(i) {
  m_texture = SDL_CreateTextureFromSurface(
      GameEngine::getInstance()->getRenderer(), m_image->getSurface());
  int w, h;
  SDL_QueryTexture(m_texture, NULL, NULL, &w, &h);
  setW(w);
  setH(h);
  setName(name);

  toggle_collidable();
}

void Sprite::render() {
  SDL_Rect dst;
  SDL_QueryTexture(m_texture, NULL, NULL, &dst.w, &dst.h);
  dst.x = getX();
  dst.y = getY();

  SDL_RenderCopyEx(GameEngine::getInstance()->getRenderer(), m_texture,
                   NULL /*&src*/, &dst, 0.0, NULL, SDL_FLIP_NONE);
}
