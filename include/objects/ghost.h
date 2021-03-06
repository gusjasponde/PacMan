#pragma once

#include <deleters.h>
#include <entity.h>
#include <input.h>
#include <input/actions.h>
#include <objects/pacman.h>
#include <render/masterrenderer.h>
#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <utils.h>

#include <algorithm>
#include <memory>
#include <vector>

#define GHOST_ANIMATION_STATES 12
#define MAX_VULNERABILITY_COUNTER 768
#define BLINK_VULNERABILITY 512

namespace Objects {
  enum GhostType { BLINKY, PINKY, INKY, CLYDE };
  enum GhostState { BLOCKED, DEAD, CHASING, VULNERABLE };

  class Ghost : public Entity {
  public:
    Ghost(GhostType t, std::shared_ptr<Render::MasterRenderer> renderer, const glm::vec2& pos);
    void update(float dt);
    void checkDirection(std::vector<Direction> directions);
    void setState(GhostState s);
    GhostState getState();

    void draw();

  private:
    void changeDirection(Direction dir);
    void updateVelocity(glm::vec2 vel);

    GhostState m_state = BLOCKED;
    GhostType m_type;
    Direction m_direction = NONE;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_none;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_down;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_left;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_right;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_up;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_vulnerable;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_dead_down;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_dead_left;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_dead_right;
    std::vector<std::shared_ptr<SDL_Texture>> m_textures_dead_up;
    std::shared_ptr<Render::MasterRenderer> m_renderer;
    int m_animation_state = 0;
    int m_vulnerable_counter = 0;
    float dt;
  };
}  // namespace Objects