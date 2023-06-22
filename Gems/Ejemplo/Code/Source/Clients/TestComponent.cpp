#include "TestComponent.h"
#include <AzCore/Serialization/EditContext.h>

using namespace Ejemplo;

void TestComponent::Reflect(AZ::ReflectContext* reflection)
{
	AZ_UNUSED(reflection); // TODO provide reflection

	auto sc = azrtti_cast<AZ::SerializeContext*>(reflection);
	if (!sc) return;

	sc->Class<TestComponent, Component>() // No tiene propiedades
		->Version(1);                     // Numero de version

	AZ::EditContext* ec = sc->GetEditContext();
	if (!ec) return;

	using namespace AZ::Edit::Attributes;
	// reflection of this component for O3DE Editor
	ec->Class<TestComponent>("Test Component", "[Componente para testear]") // Nombre, descripcion
		->ClassElement(AZ::Edit::ClassElements::EditorData, "")
		->Attribute(AppearsInAddComponentMenu, AZ_CRC("Game")) // Necesario para que funcione el componente
		->Attribute(Category, "Gem Ejemplo"); // Categoria del componente que se muestra en el buscador de componentes
}