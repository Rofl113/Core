#pragma once
#include <memory>


class IDescriptionScene;



class IManagerDescriptionScene
{
public:
	virtual ~IManagerDescriptionScene() = default;
	// Получить данные по сцене
	virtual const std::shared_ptr<IDescriptionScene>& getDescriptionScene(const std::string& name) const = 0;
};
