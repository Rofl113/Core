#include "ManagerDescriptionScene.h"
#include <cassert>
#include "IDescriptionScene.h"



void ManagerDescriptionScene::registerDescription(const std::string& name, const std::shared_ptr<IDescriptionScene>& description)
{
	m_descriptions[name] = description;
}

const std::shared_ptr<IDescriptionScene>& ManagerDescriptionScene::getDescription(const std::string& name) const
{
	if (m_descriptions.count(name) != 0)
	{
		return m_descriptions.at(name);
	}
	static const std::shared_ptr<IDescriptionScene> emptyData;
	return emptyData;
}
