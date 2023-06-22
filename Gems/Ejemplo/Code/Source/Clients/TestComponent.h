#pragma once
#include <AzCore/Component/Component.h>
#include <AzCore/Component/TickBus.h>

namespace Ejemplo
{
	// An example of the simplest O3DE component
	class TestComponent 
		: public AZ::Component
		, public AZ::TickBus::Handler
	{
	public:
		AZ_COMPONENT(TestComponent, "{1305451B-4248-48A9-B73E-90A4F008F286}");
		
		// AZ::Component overrides
		void Activate() override;
		void Deactivate() override;

		// AZ::TickBus overrides
		void OnTick(float dt, AZ::ScriptTimePoint) override;
		
		// Provide runtime reflection, if any
		static void Reflect(AZ::ReflectContext* reflection);

	private:
		float m_toPrint;
	};
}