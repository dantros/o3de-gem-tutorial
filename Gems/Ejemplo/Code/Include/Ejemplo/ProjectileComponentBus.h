#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Component/ComponentBus.h>

namespace Ejemplo
{
	class ProjectileComponentBus
		: public AZ::ComponentBus
	{
	public:

		// Poner aca la declaracion de los metodos a reflejar en Script Canvas

		virtual void ThrowEntity() = 0;
	};

	using ProjectileComponentRequestBus = AZ::EBus<ProjectileComponentBus>;
}