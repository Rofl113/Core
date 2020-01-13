#include "SessionApp.h"



SessionApp::SessionApp(const std::string& path)
    : m_path(path)
{

}

void SessionApp::setName(const std::string& name)
{
	m_name = name;
}

void SessionApp::setSize(const std::pair<size_t, size_t>& size)
{
	m_size = size;
}

void SessionApp::setResizable(const bool resizable)
{
	m_resizable = resizable;
}

const std::string& SessionApp::getPath() const
{
	return m_path;
}

const std::string& SessionApp::getName() const
{
	return m_name;
}

const std::pair<size_t, size_t>& SessionApp::getSize() const
{
	return m_size;
}

bool SessionApp::getResizable() const
{
	return m_resizable;
}
