#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>



class IScene;



/**
 * @brief Интерфейс управления отрисовкой (мост с графической либой)
 */
class IRender
{
public:
	virtual ~IRender() = default;
	// Загрузка сцены
	virtual std::shared_ptr<IScene> loadScene(const std::string& name) const = 0;
	// Добавления сцены на экран
	virtual bool showScene(const std::shared_ptr<IScene>& scene) const = 0;
	// Запуск GUI
	virtual int run(const std::function<void()>& preTick, const std::function<void()>& postTick) = 0;
};
