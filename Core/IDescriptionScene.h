#pragma once
#include <string>



class IDescriptionScene
{
public:
	virtual ~IDescriptionScene() = default;
	// Имя сцены
	virtual const std::string& getName() const = 0;
	// Тип сцены (логический класс)
	virtual const std::string& getType() const = 0;
};
