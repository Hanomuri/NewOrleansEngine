#pragma once

#include "glfw/glfw3.h"
#include "Core.h"
#include <string>

namespace NOE {
  class Window
  {
  public:
    Window(std::string Title, unsigned int Width, unsigned int Height);
    ~Window();

    void Update();
    unsigned int GetWidth();
    unsigned int GetHeight();

    void SetVSync(bool enabled);
    bool IsVSync(); 

    bool WindowShouldClose();
  private:
    void Close();
  private:
    GLFWwindow* m_Window;

    std::string m_Title;
    unsigned int m_Width;
    unsigned int m_Height;
    bool m_vSync;
  };
}