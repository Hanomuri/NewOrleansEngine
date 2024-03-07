#include <iostream>
#include "glad/glad.h"
#include "Window.h"

NOE::Window::Window(std::string Title, unsigned int Width, unsigned int Height)
{
  m_Title  = Title;
  m_Width  = Width;
  m_Height = Height;

  if(!glfwInit()) {
    std::cout<<"GLFW Not initialize"<<std::endl;
  }

  m_Window = glfwCreateWindow(Width, Height, Title.c_str(), nullptr, nullptr);
  glfwMakeContextCurrent(m_Window);
  SetVSync(true);
}

NOE::Window::~Window()
{
  Close();
}

void NOE::Window::Update()
{
  glfwPollEvents();
  glfwSwapBuffers(m_Window);
}

unsigned int NOE::Window::GetWidth()
{
  return m_Width;
}

unsigned int NOE::Window::GetHeight()
{
  return m_Height;
}

void NOE::Window::SetVSync(bool enabled)
{
  if(enabled) 
  {
    glfwSwapInterval(1);
  }
  else 
  {
    glfwSwapInterval(0);
  }
  m_vSync = enabled;
}

bool NOE::Window::IsVSync()
{
  return m_vSync;
}

void NOE::Window::Close()
{
  glfwDestroyWindow(m_Window);
}

bool NOE::Window::WindowShouldClose()
{
  return glfwWindowShouldClose(m_Window);
}