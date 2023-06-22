#pragma once

#include <AzCore/Component/Component.h>
#include <Ejemplo/ProjectileComponentBus.h>

namespace Ejemplo
{
	// An example of the simplest O3DE component
	class ProjectileComponent
		: public AZ::Component
		, public ProjectileComponentRequestBus::Handler
	{
	public:
		AZ_COMPONENT(ProjectileComponent, "{AFA63BD7-5BA6-4846-B350-5FAE922775A4}");

		// AZ::Component overrides
		void Activate() override;
		void Deactivate() override;

		// Provide runtime reflection, if any
		static void Reflect(AZ::ReflectContext* reflection);

		// Hacer override de los metodos a reflejar en Script Canvas. declarados en el EBus
		//void example() override;

		// Que otros componentes necesita este componente
		//static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& req);
;
	};
}