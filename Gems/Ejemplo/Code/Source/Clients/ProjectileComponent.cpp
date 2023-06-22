#include "ProjectileComponent.h"

#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>
#include <AzFramework/Physics/RigidBodyBus.h>

using namespace Ejemplo;

void ProjectileComponent::Reflect(AZ::ReflectContext* reflection)
{
	if (AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection))
	{
		serializeContext->Class<ProjectileComponent, Component>() // No tiene propiedades
			// serialize variables
			->Field("Throw direction", &ProjectileComponent::mThrowDirection)
			->Field("Throw force", &ProjectileComponent::mForce)
			->Version(1);

		if (auto editContext = serializeContext->GetEditContext())
		{
			editContext->Class<ProjectileComponent>("Projectile Component", "[Componente que simula la fisica del disparo de un proyectil]") // Nombre, descripcion
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game")) // Necesario para que funcione el componente
				->Attribute(AZ::Edit::Attributes::Category, "Gem Ejemplo") // Categoria del componente que se muestra en el buscador de componentes
				// expose the setting to the editor
				->DataElement(nullptr, &ProjectileComponent::mThrowDirection, "Throw direction", "[Direccion en la que se lanzara la entidad]")
				->DataElement(nullptr, &ProjectileComponent::mForce, "Throw force", "[Fuerza con la que se lanzara la entidad]")
				;
			;
		}

	}

	// Se expone el metodo para scripting
	if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(reflection))
	{
		behaviorContext->EBus<ProjectileComponentRequestBus>("Projectile Component", "ProjectileComponentRequestBus")
			->Attribute(AZ::Script::Attributes::Category, "Gem ejemplo")
			->Event("ThrowEntity", &ProjectileComponentRequestBus::Events::ThrowEntity);

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

void ProjectileComponent::ThrowEntity() 
{
	AZ_Printf("ProjectileComponent", "Lanzando entidad");
	Physics::RigidBodyRequestBus::Event(GetEntityId(), &Physics::RigidBodyRequestBus::Events::ApplyLinearImpulse, mThrowDirection.GetNormalized() * mForce);
}

void ProjectileComponent::GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& req)
{
	// Declarar las componentes que requerimos
	req.push_back(AZ_CRC_CE("PhysicsRigidBodyService"));
}