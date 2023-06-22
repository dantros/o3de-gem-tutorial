#include "ProjectileComponent.h"

#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

using namespace Ejemplo;

void ProjectileComponent::Reflect(AZ::ReflectContext* reflection)
{
	if (AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection))
	{
		serializeContext->Class<ProjectileComponent, Component>() // No tiene propiedades
			// serialize variables
			->Version(1);

		if (auto editContext = serializeContext->GetEditContext())
		{
			editContext->Class<ProjectileComponent>("Projectile Component", "[Componente que simula la fisica del disparo de un proyectil]") // Nombre, descripcion
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game")) // Necesario para que funcione el componente
				->Attribute(AZ::Edit::Attributes::Category, "Gem Ejemplo") // Categoria del componente que se muestra en el buscador de componentes
				// expose the setting to the editor
				;
			;
		}

	}
	return;
}

void ProjectileComponent::Activate()
{
	AZ_Printf("ProjectileComponent", "Iniciando Componente:");

	// We must connect, otherwise OnTick() will never be called.
	// Forgetting this call is the common error in O3DE!
	//AZ::TickBus::Handler::BusConnect();

	// Hay que conectar el bus del componente
	ProjectileComponentRequestBus::Handler::BusConnect(GetEntityId());
}

void ProjectileComponent::Deactivate()
{
	AZ_Printf("ProjectileComponent", "Finalizando Component");

	// good practice on cleanup to disconnect
	//AZ::TickBus::Handler::BusDisconnect();

	ProjectileComponentRequestBus::Handler::BusDisconnect(GetEntityId());
}

// Implementar los metodos a reflejar en Script Canvas. declarados en el EBus
//void ProjectileComponent::example() {}

//void ProjectileComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& req)
//{
	// Declarar las componentes que requerimos
//}