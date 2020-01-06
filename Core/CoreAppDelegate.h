#pragma once
#include "ICoreAppDelegate.h"


class CoreAppDelegate : public ICoreAppDelegate
{
public: /// ICoreAppDelegate
	virtual std::unique_ptr<SessionApp> createSessionApp(const int argc, const char* argv[]) override;
	virtual std::unique_ptr<IManagerDescriptionScene> createManagerDescriptionScene(const SessionApp& sessionApp) override;
	virtual std::unique_ptr<IManagerScene> createManagerScene(const SessionApp& sessionApp, const IRender& render) override;
	virtual std::unique_ptr<ManagerMessages> createManagerMessages(const SessionApp& sessionApp) override;
};
