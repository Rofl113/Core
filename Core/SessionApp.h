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
	void setSizeDesign(const std::pair<size_t, size_t>& size);
	void setResizable(const bool resizable);

public:
	const std::string& getPath() const;
	const std::string& getName() const;
	const std::pair<size_t, size_t>& getSize() const;
	const std::pair<size_t, size_t>& getSizeDesign() const;
	bool getResizable() const;

private:
	const std::string m_path;
	std::string m_name;
	std::pair<size_t, size_t> m_size;
	std::pair<size_t, size_t> m_sizeDesign;
	bool m_resizable = false;
};
