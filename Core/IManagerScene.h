#pragma once
#include <string>
#include <memory>



class IScene;


class IManagerScene
{
public:
	virtual ~IManagerScene() = default;
	// Получить сцену по имени
	virtual std::shared_ptr<IScene> loadScene(const std::string& name) = 0;
	// Текущая сцена на экране
	virtual const std::shared_ptr<IScene>& top() = 0;
	// Добавления сцены на экран
	virtual bool push(const std::shared_ptr<IScene>& scene) = 0;
	// Удаление сцены с экрана
	virtual bool pop(const std::shared_ptr<IScene>& scene) = 0;
};
