#include "TestComponent.h"
#include <AzCore/Serialization/EditContext.h>

using namespace Ejemplo;

void TestComponent::Reflect(AZ::ReflectContext* reflection)
{
	AZ_UNUSED(reflection); // TODO provide reflection

	auto sc = azrtti_cast<AZ::SerializeContext*>(reflection);
	if (!sc) return;

	sc->Class<TestComponent, Component>() // No tiene propiedades
		// serialize m_amplitude
		->Field("To Print", &TestComponent::m_toPrint)
		->Version(2);                  // Numero de version

	AZ::EditContext* ec = sc->GetEditContext();
	if (!ec) return;

	using namespace AZ::Edit::Attributes;
	// reflection of this component for O3DE Editor
	ec->Class<TestComponent>("Test Component", "[Componente para testear]") // Nombre, descripcion
		->ClassElement(AZ::Edit::ClassElements::EditorData, "")
		->Attribute(AppearsInAddComponentMenu, AZ_CRC("Game")) // Necesario para que funcione el componente
		->Attribute(Category, "Gem Ejemplo") // Categoria del componente que se muestra en el buscador de componentes
		// expose the setting to the editor
		->DataElement(nullptr, &TestComponent::m_toPrint, "To Print", "[Float a printear al principio]");
}

void TestComponent::Activate()
{
	AZ_Printf("TestComponent", "Iniciando Test Component con float: %f", m_toPrint);

	// We must connect, otherwise OnTick() will never be called.
	// Forgetting this call is the common error in O3DE!
	AZ::TickBus::Handler::BusConnect();
}

void TestComponent::Deactivate()
{
	AZ_Printf("TestComponent", "Finalizando Test Component");

	// good practice on cleanup to disconnect
	AZ::TickBus::Handler::BusDisconnect();
}

// Se ejecuta en cada frame
void TestComponent::OnTick(float dt, AZ::ScriptTimePoint)
{
	AZ_Printf("TestComponent", "-> Imprimiendo en cada frame, dt: %f", dt);
}