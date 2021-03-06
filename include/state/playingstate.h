#pragma once

#include <application.h>
#include <audio/manager.h>
#include <input/keyboard.h>
#include <objects/ghost.h>
#include <objects/level.h>
#include <objects/pacman.h>
#include <objects/score.h>
#include <render/masterrenderer.h>
#include <state/basestate.h>
#include <state/deathstate.h>

#include <memory>

#define MAX_CICLE_COUNT_PLAYING 256

namespace State {
  class PlayingState : public BaseState {
  public:
    PlayingState(Application &app);
    ~PlayingState();

    void handleEvent(SDL_Event &e) override;
    void handleInput() override;
    void update(float dt) override;
    void render(std::shared_ptr<Render::MasterRenderer> renderer) override;
    void onOpen() override;
    void onSwitchBack() override;

  private:
    int peletsEaten = 0;
    int cycleCount = 0;
    bool deathStateSwitched = false;
    std::shared_ptr<Audio::Manager> m_audio_manager;
    std::shared_ptr<Input::Input> m_input;
    Objects::Level m_level;
    Objects::Pacman m_pacman;
    Objects::Score m_score;
    std::vector<Objects::Ghost> m_ghosts;

    void switchToDeathState();
    void resetLevel(Application &app);
  };
}  // namespace State