#pragma once
#include <string>


class SessionApp
{
	SessionApp() = delete;

public:
	SessionApp(const std::string& path);

	const std::string& getPath() const;

private:
	const std::string m_path;
};
