#include "InputHandler.hpp"
#include "SDL2/SDL_events.h"
#include "SDL2/SDL_scancode.h"
#include "Window.hpp"

InputHandler::InputHandler()
{
    m_keystates = SDL_GetKeyboardState(0);
    m_mouseButtonStates.reserve(3);
    for (int i = 0; i < 3; ++i)
        m_mouseButtonStates.emplace_back(false);
}

bool InputHandler::onKeyDown(SDL_Scancode key)
{
    if (m_keystates)
        if (m_keystates[key])
            return true;
    return false;
}

bool InputHandler::onKeyUp(SDL_Scancode key)
{
    if (m_keystates)
        if (!m_keystates[key])
            return true;
    return false;
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
        m_mouseButtonStates[LEFT] = true;

    if (event.button.button == SDL_BUTTON_MIDDLE)
        m_mouseButtonStates[MIDDLE] = true;
    if (event.button.button == SDL_BUTTON_RIGHT)
        m_mouseButtonStates[RIGHT] = true;
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if (event.button.button == SDL_BUTTON_LEFT)
        m_mouseButtonStates[LEFT] = false;

    if (event.button.button == SDL_BUTTON_MIDDLE)
        m_mouseButtonStates[MIDDLE] = false;
    if (event.button.button == SDL_BUTTON_RIGHT)
        m_mouseButtonStates[RIGHT] = false;
}
void InputHandler::onMouseMove(SDL_Event& event)
{
    m_mousePosition.setX(event.motion.x);
    m_mousePosition.setY(event.motion.y);
}

InputHandler::~InputHandler() { }

void InputHandler::update()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        // -------- mouse event Hanlder ----------//
        switch (event.type)
        {
        case SDL_QUIT:
            Window::instance().quit();
            break;

        case SDL_MOUSEBUTTONDOWN:

            InputHandler::onMouseButtonDown(event);
            break;

        case SDL_MOUSEBUTTONUP:

            InputHandler::onMouseButtonUp(event);
            break;
        case SDL_MOUSEMOTION:

            InputHandler::onMouseMove(event);
            break;
        case SDL_KEYDOWN:
            onKeyDown(event.key.keysym.scancode);
            break;

        case SDL_KEYUP:
            onKeyUp(event.key.keysym.scancode);
            break;
        default:
            break;
        }

        /*















        */
    }
}