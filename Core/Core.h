#pragma once
#include <memory>
#include <functional>



class Message;
class StateMachine;
class ICoreAppDelegate;
class ILocalizer;
class IVisualizationRegistry;
class IVisualizationManager;


class SessionApp;
class IFactoryScene;
class IManagerDescriptionScene;
class IRender;
class IManagerScene;
class ManagerMessages;


class Core
{
	Core() = delete;
    Core(const Core&) = delete;
    Core& operator= (const Core&) = delete;
public:
	Core(std::unique_ptr<ICoreAppDelegate>&& appDelegate);
    virtual ~Core();

	bool initialize(const int argc, const char* argv[]);
	int run();

	IManagerScene* getManagerScene() const;

private:
	std::unique_ptr<ICoreAppDelegate> m_appDelegate;
	std::unique_ptr<SessionApp> m_sessionApp;
	std::unique_ptr<IFactoryScene> m_factoryScene;
	std::unique_ptr<IManagerDescriptionScene> m_managerDescriptionScene;
	std::unique_ptr<IRender> m_render;
	std::unique_ptr<IManagerScene> m_managerScene;
	std::unique_ptr<ManagerMessages> m_managerMessages;

    bool m_run = false;
};
