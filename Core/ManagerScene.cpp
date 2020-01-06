#include "ManagerScene.h"
#include <algorithm>
#include "IRender.h"


ManagerScene::ManagerScene(const IRender& render)
    : m_render(render)
{

}

ManagerScene::~ManagerScene()
{
	while (not this->m_scenesShow.empty())
	{
		const auto& scene = this->m_scenesShow.front();
		this->pop(scene);
	}
}

std::shared_ptr<IScene> ManagerScene::loadScene(const std::string& name)
{
	return m_render.loadScene(name);
}

const std::shared_ptr<IScene>& ManagerScene::top()
{
	static const std::shared_ptr<IScene> emptyScene;
	return m_scenesShow.empty() ? emptyScene : m_scenesShow.front();
}

bool ManagerScene::push(const std::shared_ptr<IScene>& scene)
{
	if (scene == nullptr)
	{
		return false;
	}
	const auto& sceneShowOld = this->top();
	if (sceneShowOld == scene)
	{
		return true;
	}
	// Remove Old
	{
		const auto it = std::find(m_scenesShow.begin(), m_scenesShow.end(), scene);
		if (it != m_scenesShow.end())
		{
			if (it == m_scenesShow.begin())
			{
				return true;
			}
			m_scenesShow.erase(it);
		}
	}
	// Add Top
	{
		m_scenesShow.push_front(scene);
	}
	// Check Top Scene
	{
		const auto& sceneShowNew = this->top();
		if (sceneShowOld != sceneShowNew)
		{
			return m_render.showScene(sceneShowNew);
		}
	}
	return true;
}

bool ManagerScene::pop(const std::shared_ptr<IScene>& scene)
{
	if (scene == nullptr)
	{
		return false;
	}
	const auto& sceneShowOld = this->top();
	// Remove Old
	if (sceneShowOld == scene)
	{
		m_scenesShow.pop_front();
	}
	else
	{
		const auto it = std::find(m_scenesShow.begin(), m_scenesShow.end(), scene);
		if (it != m_scenesShow.end())
		{
			if (it == m_scenesShow.begin())
			{
				return true;
			}
			m_scenesShow.erase(it);
		}
	}
	// Check Top Scene
	{
		const auto& sceneShowNew = this->top();
		if (sceneShowOld != sceneShowNew)
		{
			return m_render.showScene(sceneShowNew);
		}
	}
	return true;
}
