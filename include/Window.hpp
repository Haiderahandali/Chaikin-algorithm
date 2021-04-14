#pragma once
#include <SDL2/SDL.h>
#include <vector>
#define WINDOW_WIDTH 480
#define WINDOW_HEIGHT 480

class WindowWidget
{
public:
    WindowWidget() { }
    ~WindowWidget() { }

    virtual void Render()    = 0;
    virtual void eventLoop() = 0;
    virtual void Update()    = 0;
};

class Window
{

private: //-------- Singleton class---------//
    Window();

public:
    ~Window()
    {
        close();
    }

public:
    void Update();
    bool isRunning() const { return running; }
    void eventLoop();
    void Render();

    static Window& instance()
    {
        static Window instance;
        return instance;
    }
    //----------------------------------------------------------------//

public:
    inline void quit()
    {
        running = false;
    }

public:
    inline void addWindowWidget(WindowWidget* wg)
    {
        windowWidgets.push_back(wg);
    }

public: // interacting with other classes functions;
    inline SDL_Renderer* getRenderer() const { return renderer; }
    inline SDL_Window* getWindow() const { return gWindow; }

private:
    bool running = true;

private:
    std::vector<WindowWidget*> windowWidgets;

private: //SDL_Variables
    SDL_Window* gWindow        = NULL;
    SDL_Surface* screenSurface = NULL; //temporary write to it when needed
    SDL_Renderer* renderer     = NULL;
    SDL_Texture* screenTexture = NULL;

private: //class specific functions
    bool init();
    void close();
};