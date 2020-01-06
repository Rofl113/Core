#pragma once
#include <memory>


class SessionApp;
class IFactoryScene;
class IManagerDescriptionScene;
class IRender;
class IManagerScene;
class ManagerMessages;
class StateMachineBase;

class Core;


class ICoreAppDelegate
{
public:
	virtual ~ICoreAppDelegate() = default;

	virtual std::unique_ptr<SessionApp> createSessionApp(const int argc, const char* argv[]) = 0;
	virtual std::unique_ptr<IFactoryScene> createFactoryScene(const SessionApp& sessionApp) = 0;
	virtual std::unique_ptr<IManagerDescriptionScene> createManagerDescriptionScene(const SessionApp& sessionApp) = 0;
	virtual std::unique_ptr<IRender> createRender(const SessionApp& sessionApp, const IFactoryScene& factoryScene, const IManagerDescriptionScene& managerDescriptionScene) = 0;
	virtual std::unique_ptr<IManagerScene> createManagerScene(const SessionApp& sessionApp, const IRender& render) = 0;
	virtual std::unique_ptr<ManagerMessages> createManagerMessages(const SessionApp& sessionApp) = 0;
	virtual std::unique_ptr<StateMachineBase> createStateMachine(Core& core) = 0;
};
