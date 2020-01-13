#pragma once
#include <string>
#include <utility>


class SessionApp
{
	SessionApp() = delete;

public:
	SessionApp(const std::string& path);

public:
	void setName(const std::string& name);
	void setSize(const std::pair<size_t, size_t>& size);
	void setResizable(const bool resizable);

public:
	const std::string& getPath() const;
	const std::string& getName() const;
	const std::pair<size_t, size_t>& getSize() const;
	bool getResizable() const;

private:
	const std::string m_path;
	std::string m_name;
	std::pair<size_t, size_t> m_size;
	bool m_resizable = false;
};
