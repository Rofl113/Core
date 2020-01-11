#include "Render.h"
#include "IManagerDescriptionScene.h"
#include "IFactoryScene.h"
#include "IDescriptionScene.h"



Render::Render(const SessionApp& sessionApp, const IFactoryScene& factoryScene, const IManagerDescriptionScene& managerDescriptionScene)
    : m_sessionApp(sessionApp)
    , m_factoryScene(factoryScene)
    , m_managerDescriptionScene(managerDescriptionScene)
{

}

std::shared_ptr<IScene> Render::loadScene(const std::string& name) const
{
	if (const auto& description = m_managerDescriptionScene.getDescriptionScene(name))
	{
		if (const auto& scene = m_factoryScene.createScene(description))
		{
			this->handleLoadScene(scene);
			return scene;
		}
	}
	return {};
}

bool Render::showScene(const std::shared_ptr<IScene>& scene) const
{
	// Show
	if (scene)
	{
		this->handleShowScene(scene);
		// Good
		return true;
	}
	// Bad
	return false;
}
