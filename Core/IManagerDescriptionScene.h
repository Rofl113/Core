#pragma once
#include <memory>


class IDescriptionScene;



class IManagerDescriptionScene
{
public:
	virtual ~IManagerDescriptionScene() = default;
	// Установка данных по сцене
	virtual void registerDescription(const std::string& name, const std::shared_ptr<IDescriptionScene>& description) = 0;
	// Получить данные по сцене
	virtual const std::shared_ptr<IDescriptionScene>& getDescription(const std::string& name) const = 0;
};
