#pragma once
#include <memory>


class IDescriptionScene;
class IScene;



class IFactoryScene
{
public:
	virtual ~IFactoryScene() = default;

	virtual std::shared_ptr<IScene> createScene(const std::shared_ptr<IDescriptionScene>& description) const = 0;
};
