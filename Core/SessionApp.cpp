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
