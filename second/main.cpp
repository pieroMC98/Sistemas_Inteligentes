#include "../HEADER_H.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#define WIDTH 420
#define HEIGHT 360
#define BPP 24
struct nave{
    int x,y;
} minave;

int main(int argc, char *argv[])
{
    // retutns zero on success else non-zero 
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) { 
        printf("error initializing SDL: %s\n", SDL_GetError()); 
    } 
    SDL_Window* win = SDL_CreateWindow("GAME", // creates a window 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       1000, 1000, 0); 
  
    // triggers the program that controls 
    // your graphics hardware and sets flags 
    Uint32 render_flags = SDL_RENDERER_ACCELERATED; 
  
    // creates a renderer to render our images 
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags); 
  
    // creates a surface to load an image into the main memory 
    SDL_Surface* surface; 
  
    // please provide a path for your image 
    surface = IMG_Load("~/Imágenes/Aquarius-Star-Trek-Starfleet-logo-magnet-small.jpg ");
  
  
    // loads image to our graphics hardware memory. 
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface); 
  
    // clears main-memory 
    SDL_FreeSurface(surface); 
  
    // let us control our image position 
    // so that we can move it with our keyboard. 
    SDL_Rect dest; 
  
    // connects our texture with dest to control position 
    SDL_QueryTexture(tex, NULL, NULL, &dest.w, &dest.h); 
  
    // adjust height and width of our image box. 
    dest.w /= 6; 
    dest.h /= 6; 
  
    // sets initial x-position of object 
    dest.x = (1000 - dest.w) / 2; 
  
    // sets initial y-position of object 
    dest.y = (1000 - dest.h) / 2; 
  
    // controls annimation loop 
    int close = 0; 
  
    // speed of box 
    int speed = 300; 
  
    // annimation loop 
    while (!close) { 
        SDL_Event event; 
  
        // Events mangement 
        while (SDL_PollEvent(&event)) { 
            switch (event.type) { 
  
            case SDL_QUIT: 
                // handling of close button 
                close = 1; 
                break; 
  
            case SDL_KEYDOWN: 
                // keyboard API for key pressed 
                switch (event.key.keysym.scancode) { 
                case SDL_SCANCODE_W: 
                case SDL_SCANCODE_UP: 
                    dest.y -= speed / 30; 
                    break; 
                case SDL_SCANCODE_A: 
                case SDL_SCANCODE_LEFT: 
                    dest.x -= speed / 30; 
                    break; 
                case SDL_SCANCODE_S: 
                case SDL_SCANCODE_DOWN: 
                    dest.y += speed / 30; 
                    break; 
                case SDL_SCANCODE_D: 
                case SDL_SCANCODE_RIGHT: 
                    dest.x += speed / 30; 
                    break; 
                } 
            } 
        } 
  
        // right boundary 
        if (dest.x + dest.w > 1000) 
            dest.x = 1000 - dest.w; 
  
        // left boundary 
        if (dest.x < 0) 
            dest.x = 0; 
  
        // bottom boundary 
        if (dest.y + dest.h > 1000) 
            dest.y = 1000 - dest.h; 
  
        // upper boundary 
        if (dest.y < 0) 
            dest.y = 0; 
  
        // clears the screen 
        SDL_RenderClear(rend); 
        SDL_RenderCopy(rend, tex, NULL, &dest); 
  
        // triggers the double buffers 
        // for multiple rendering 
        SDL_RenderPresent(rend); 
  
        // calculates to 60 fps 
        SDL_Delay(1000 / 60); 
    } 
  
    // destroy texture 
    SDL_DestroyTexture(tex); 
  
    // destroy renderer 
    SDL_DestroyRenderer(rend); 
  
    // destroy window 
    SDL_DestroyWindow(win); 
    return 0; 
}
