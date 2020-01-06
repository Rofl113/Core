#include "ManagerDescriptionScene.h"
#include <cassert>
#include "IDescriptionScene.h"



ManagerDescriptionScene::ManagerDescriptionScene(const std::map<std::string, std::shared_ptr<IDescriptionScene> >&& descriptions)
    : m_descriptions(std::move(descriptions))
{

}

const std::shared_ptr<IDescriptionScene>& ManagerDescriptionScene::getDescriptionScene(const std::string& name) const
{
	if (m_descriptions.count(name) != 0)
	{
		return m_descriptions.at(name);
	}
	static const std::shared_ptr<IDescriptionScene> emptyData;
	return emptyData;
}
