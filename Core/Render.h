#pragma once
#include <functional>
#include "IRender.h"


class IFactoryScene;
class IManagerDescriptionScene;

class EventListenerCustom;


class Render : public IRender
{
	Render() = delete;
public:
	explicit Render(const IFactoryScene& factoryScene, const IManagerDescriptionScene& managerDescriptionScene);
	// Загрузка сцены
	virtual std::shared_ptr<IScene> loadScene(const std::string& name) const override;
	// Добавления сцены на экран
	virtual bool showScene(const std::shared_ptr<IScene>& scene) const override;

protected:
	virtual void handleLoadScene(const std::shared_ptr<IScene>& scene) const = 0;
	virtual void handleShowScene(const std::shared_ptr<IScene>& scene) const = 0;

private:
	const IFactoryScene& m_factoryScene;
	const IManagerDescriptionScene& m_managerDescriptionScene;
};
