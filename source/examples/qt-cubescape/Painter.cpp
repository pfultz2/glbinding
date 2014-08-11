
#include "Painter.h"

#include <glbinding/Binding.h>
#include <glbinding/ContextInfo.h>

#include "../cubescape/CubeScape.h"


Painter::Painter()
: m_cubescape(nullptr)
, m_initialized(false)
{
}

Painter::~Painter()
{
    delete m_cubescape;
}

void Painter::initialize()
{
    if (m_initialized)
        return;

    glbinding::Binding::initialize(false); // only resolve functions that are actually used (lazy)

    m_cubescape = new CubeScape();

    m_initialized = true;

    // print some gl infos (query)

    //std::cout << std::endl
    //    << "OpenGL Version:  " << glbinding::ContextInfo::version() << std::endl
    //    << "OpenGL Vendor:   " << glbinding::ContextInfo::vendor() << std::endl
    //    << "OpenGL Renderer: " << glbinding::ContextInfo::renderer() << std::endl << std::endl;
}

void Painter::resize(int width, int height)
{
    m_cubescape->resize(width, height);
}

void Painter::draw()
{
    m_cubescape->draw();
}

void Painter::setNumCubes(int numCubes)
{
    m_cubescape->setNumCubes(numCubes);
}

int Painter::numCubes() const
{
    return m_cubescape->numCubes();
}