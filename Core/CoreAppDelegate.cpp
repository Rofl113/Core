#include "CoreAppDelegate.h"
// StateMachine lib
#include <StateMachine/ManagerMessages.h>
// Core
#include "SessionApp.h"
#include "ManagerDescriptionScene.h"
#include "ManagerScene.h"



std::unique_ptr<SessionApp> CoreAppDelegate::createSessionApp(const int /*argc*/, const char* argv[])
{
	return std::unique_ptr<SessionApp>(new SessionApp(argv[0]));
}

std::unique_ptr<IManagerDescriptionScene> CoreAppDelegate::createManagerDescriptionScene(const SessionApp& /*sessionApp*/)
{
	// TODO: надо сделать оригинал для Cocos2d
	return std::unique_ptr<IManagerDescriptionScene>(new ManagerDescriptionScene(std::map<std::string, std::shared_ptr<IDescriptionScene>>{}));
}

std::unique_ptr<IManagerScene> CoreAppDelegate::createManagerScene(const SessionApp& /*sessionApp*/, const IRender& render)
{
	return std::unique_ptr<IManagerScene>(new ManagerScene(render));
}

std::unique_ptr<ManagerMessages> CoreAppDelegate::createManagerMessages(const SessionApp& /*sessionApp*/)
{
	return std::unique_ptr<ManagerMessages>(new ManagerMessages());
}
