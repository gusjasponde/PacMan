#include <utils.h>

void Utils::showError(std::string msg) {
  msg.append(SDL_GetError());
  SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Init Failed", msg.c_str(), nullptr);
}

SDL_Surface* Utils::loadSDLSurface(const char* file) {
  SDL_Surface* loadedSurface = SDL_LoadBMP(file);
  if (loadedSurface == NULL) {
    showError("");
  }

  SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0, 0));
  return loadedSurface;
}

SDL_Texture* Utils::loadSDLTexture(SDL_Renderer* renderer, const char* file) {
  return SDL_CreateTextureFromSurface(renderer, loadSDLSurface(file));
}

int Utils::getTens(int num) {
  int len = log10(num);
  float div = pow(10, len);
  return floor(num / div) * div;
}
