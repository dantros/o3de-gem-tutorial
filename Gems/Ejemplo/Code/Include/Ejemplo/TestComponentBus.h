#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Component/ComponentBus.h>

namespace Ejemplo
{
	class TestComponentBus
		: public AZ::ComponentBus
	{
	public:
		//static const AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
		
		// Imprime en consola el valor dado, la idea es que sea invocable desde ScriptCanvas
		virtual void dummyPrint(const char* value) = 0;
	};

	using TestComponentRequestBus = AZ::EBus<TestComponentBus>;
}