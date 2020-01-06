#pragma once
#include <vector>
#include <map>
#include "IManagerDescriptionScene.h"



class ManagerDescriptionScene : public IManagerDescriptionScene
{
	ManagerDescriptionScene() = delete;
public:
	explicit ManagerDescriptionScene(const std::map<std::string, std::shared_ptr<IDescriptionScene>>&& descriptions);
	// Получить данные по сцене
	virtual const std::shared_ptr<IDescriptionScene>& getDescriptionScene(const std::string& name) const override;

private:
	const std::map<std::string, std::shared_ptr<IDescriptionScene>> m_descriptions;
};
