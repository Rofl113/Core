#include "Core.h"
#include<mutex>
// Sm lib
#include <StateMachine/ManagerMessages.h>
#include <StateMachine/StateMachineBase.h>
// Core
#include "ICoreAppDelegate.h"
#include "IRender.h"
#include "SessionApp.h"
#include "IFactoryScene.h"
#include "IManagerDescriptionScene.h"
#include "IManagerScene.h"


Core::Core(std::unique_ptr<ICoreAppDelegate>&& appDelegate)
    : m_appDelegate(std::move(appDelegate))
{

}

Core::~Core()
{
	// Remove ManagerMessages
	m_managerMessages.reset();
	// Remove ManagerScenes
	m_managerScene.reset();
	// Remove Render
	m_render.reset();
	// Remove ManagerDescriptionScene
	m_managerDescriptionScene.reset();
	// Remove FactoryScene
	m_factoryScene.reset();
	// Remove SessionApp
	m_sessionApp.reset();
}

bool Core::initialize(const int argc, const char* argv[])
{
	// Check AppDelegate
	if (m_appDelegate == nullptr)
	{
		return false;
	}
	// Create SessionApp
	{
		m_sessionApp = m_appDelegate->createSessionApp(argc, argv);
		// Check Create
		if (m_sessionApp == nullptr)
		{
			return false;
		}
	}
	// Create FactoryScene
	{
		m_factoryScene = m_appDelegate->createFactoryScene(*m_sessionApp.get());
		// Check Create
		if (m_factoryScene == nullptr)
		{
			return false;
		}
	}
	// Create ManagerDescriptionScene
	{
		m_managerDescriptionScene = m_appDelegate->createManagerDescriptionScene(*m_sessionApp.get());
		// Check Create
		if (m_managerDescriptionScene == nullptr)
		{
			return false;
		}
	}
	// Create Render
	{
		m_render = m_appDelegate->createRender(*m_sessionApp.get(), *m_factoryScene.get(), *m_managerDescriptionScene.get());
		// Check Create
		if (m_render == nullptr)
		{
			return false;
		}
	}
	// Create ManagerScene
	{
		m_managerScene = m_appDelegate->createManagerScene(*m_sessionApp.get(), *m_render.get());
		// Check Create
		if (m_managerScene == nullptr)
		{
			return false;
		}
	}
	// Create ManagerMessages
	{
		m_managerMessages = m_appDelegate->createManagerMessages(*m_sessionApp.get());
		// Check Create
		if (m_managerMessages == nullptr)
		{
			return false;
		}
	}
	// Create StateMachineCore
	{
		auto stateMachine = m_appDelegate->createStateMachine(*this);
		// Check Create
		if (stateMachine == nullptr)
		{
			return false;
		}
		// Move To ManagerMessages
		m_managerMessages->setMachine(std::move(stateMachine));
	}
	// Finish
	return true;
}

int Core::run()
{
	// Post Tick
	const auto postTick = [this]
	{
		// Отправка сообщений (которые накопились)
		m_managerMessages->processMessages();
	};
	// Run
	return m_render->run(nullptr, postTick);
}

const IRender* Core::getRender() const
{
	return m_render.get();
}
