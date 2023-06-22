
#include <AzCore/Serialization/SerializeContext.h>
#include "EjemploEditorSystemComponent.h"

namespace Ejemplo
{
    void EjemploEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<EjemploEditorSystemComponent, EjemploSystemComponent>()
                ->Version(0);
        }
    }

    EjemploEditorSystemComponent::EjemploEditorSystemComponent() = default;

    EjemploEditorSystemComponent::~EjemploEditorSystemComponent() = default;

    void EjemploEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("EjemploEditorService"));
    }

    void EjemploEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("EjemploEditorService"));
    }

    void EjemploEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void EjemploEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void EjemploEditorSystemComponent::Activate()
    {
        EjemploSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void EjemploEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        EjemploSystemComponent::Deactivate();
    }

} // namespace Ejemplo
