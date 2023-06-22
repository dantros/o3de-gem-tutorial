#include "TestComponent.h"

#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/BehaviorContext.h>

using namespace Ejemplo;

void TestComponent::Reflect(AZ::ReflectContext* reflection)
{
	if (AZ::SerializeContext* serializeContext = azrtti_cast<AZ::SerializeContext*>(reflection))
	{
		serializeContext->Class<TestComponent, Component>() // No tiene propiedades
			// serialize variable
			->Field("To Print", &TestComponent::m_toPrint)
			->Version(4);

		if (auto editContext = serializeContext->GetEditContext())
		{
			editContext->Class<TestComponent>("Test Component", "[Componente para testear]") // Nombre, descripcion
				->ClassElement(AZ::Edit::ClassElements::EditorData, "")
				->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("Game")) // Necesario para que funcione el componente
				->Attribute(AZ::Edit::Attributes::Category, "Gem Ejemplo") // Categoria del componente que se muestra en el buscador de componentes
				// expose the setting to the editor
				->DataElement(nullptr, &TestComponent::m_toPrint, "To Print", "[Float a printear al principio]");
				;
		}

	}	

	
	// Se expone el metodo para scripting
	if (AZ::BehaviorContext* behaviorContext = azrtti_cast<AZ::BehaviorContext*>(reflection))
	{
		behaviorContext->EBus<TestComponentRequestBus>("Test Co", "TestComponentRequestBus")
			->Attribute(AZ::Script::Attributes::Category, "Gem ejemplo")
			->Event("dummyPrint1", &TestComponentRequestBus::Events::dummyPrint);

		//behaviorContext->Class<TestComponent>()->RequestBus("TestComponentRequestBus");
	}

	return;
}

void TestComponent::Activate()
{
	AZ_Printf("TestComponent", "Iniciando Test Component con float: %f", m_toPrint);

	// We must connect, otherwise OnTick() will never be called.
	// Forgetting this call is the common error in O3DE!
	AZ::TickBus::Handler::BusConnect();

	// Hay que conectar el bus del componente
	TestComponentRequestBus::Handler::BusConnect(GetEntityId());
}

void TestComponent::Deactivate()
{
	AZ_Printf("TestComponent", "Finalizando Test Component");

	// good practice on cleanup to disconnect
	AZ::TickBus::Handler::BusDisconnect();

	TestComponentRequestBus::Handler::BusDisconnect(GetEntityId());
}

// Se ejecuta en cada frame
void TestComponent::OnTick(float dt, AZ::ScriptTimePoint)
{
	AZ_Printf("TestComponent", "-> Imprimiendo en cada frame, dt: %f", dt);
}

// Implementacion de metodo test para ser llamado desde ScriptCanvas
void TestComponent::dummyPrint(const char* value)
{
	AZ_Printf("TestComponent", "-> Imprimiendo desde Script Canvas, valor: %s", value);
}