
#include "EjemploSystemComponent.h"

#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

namespace Ejemplo
{
    void EjemploSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<EjemploSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<EjemploSystemComponent>("Ejemplo", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void EjemploSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("EjemploService"));
    }

    void EjemploSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("EjemploService"));
    }

    void EjemploSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void EjemploSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    EjemploSystemComponent::EjemploSystemComponent()
    {
        if (EjemploInterface::Get() == nullptr)
        {
            EjemploInterface::Register(this);
        }
    }

    EjemploSystemComponent::~EjemploSystemComponent()
    {
        if (EjemploInterface::Get() == this)
        {
            EjemploInterface::Unregister(this);
        }
    }

    void EjemploSystemComponent::Init()
    {
    }

    void EjemploSystemComponent::Activate()
    {
        EjemploRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void EjemploSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        EjemploRequestBus::Handler::BusDisconnect();
    }

    void EjemploSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace Ejemplo
