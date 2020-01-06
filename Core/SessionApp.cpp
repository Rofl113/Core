#include "SessionApp.h"



SessionApp::SessionApp(const std::string& path)
    : m_path(path)
{

}

const std::string& SessionApp::getPath() const
{
	return m_path;
}
