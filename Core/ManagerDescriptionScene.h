#pragma once
#include <vector>
#include <map>
#include "IManagerDescriptionScene.h"



class ManagerDescriptionScene : public IManagerDescriptionScene
{
public:
	// Установка данных по сцене
	virtual void registerDescription(const std::string& name, const std::shared_ptr<IDescriptionScene>& description) override;
	// Получить данные по сцене
	virtual const std::shared_ptr<IDescriptionScene>& getDescription(const std::string& name) const override;

private:
	std::map<std::string, std::shared_ptr<IDescriptionScene>> m_descriptions;
};
