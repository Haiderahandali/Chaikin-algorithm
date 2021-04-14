#include "Window.hpp"
#include "InputHandler.hpp"

Window::Window()
{

    if (!init())
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    }
}
void Window::close()
{

    SDL_DestroyTexture(screenTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gWindow);
    SDL_Log("%s\n", SDL_GetError());

    SDL_Quit();
}

bool Window::init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        success = false;
    }
    else
    {
        gWindow = SDL_CreateWindow(
            "SDL APP", // window title
            SDL_WINDOWPOS_UNDEFINED, // initial x position
            SDL_WINDOWPOS_UNDEFINED, // initial y position
            WINDOW_WIDTH, // width, in pixels
            WINDOW_HEIGHT, // height, in pixels
            SDL_WINDOW_SHOWN // flags - see below
        );
        // windowSurface = SDL_GetWindowSurface(gWindow);
        if (!gWindow)
        {
            SDL_Log("UNABLE TO CREATE WINDOW: %s", SDL_GetError());
            success = false;
        }
        renderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    }

    //---creating screen surface---//
    screenSurface = SDL_CreateRGBSurface(0, WINDOW_WIDTH, WINDOW_HEIGHT, 32, 0, 0, 0, 0);
    screenTexture = SDL_CreateTextureFromSurface(renderer, screenSurface);

    SDL_FreeSurface(screenSurface);

    return success;
}

void Window::eventLoop()
{

    InputHandler::instance().update(); // Only for keyboard and mouse events

    for (auto& x : windowWidgets)
    {
        x->eventLoop();
    }
}

void Window::Render()
{

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, screenTexture, NULL, NULL);

    for (auto& x : windowWidgets)
    {
        x->Render();
    }
}

void Window::Update()
{
    for (auto& x : windowWidgets)
    {
        x->Update();
    }
    SDL_RenderPresent(renderer);
}