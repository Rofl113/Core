#pragma once
#include <list>
#include <memory>
#include "IManagerScene.h"


class IRender;


class ManagerScene : public IManagerScene
{
	ManagerScene() = delete;
public:
	ManagerScene(const IRender& render);
	virtual ~ManagerScene() override;
	// Получить сцену по имени
	virtual std::shared_ptr<IScene> loadScene(const std::string& name) const override;
	// Текущая сцена на экране
	virtual const std::shared_ptr<IScene>& top() override;
	// Добавления сцены на экран
	virtual bool push(const std::shared_ptr<IScene>& scene) override;
	// Удаление сцены с экрана
	virtual bool pop(const std::shared_ptr<IScene>& scene) override;

private:
	const IRender& m_render;
	std::list<std::shared_ptr<IScene>> m_scenesShow;
};
