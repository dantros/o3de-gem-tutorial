
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "DinosaurExampleSystemComponent.h"

namespace DinosaurExample
{
    void DinosaurExampleSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<DinosaurExampleSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<DinosaurExampleSystemComponent>("DinosaurExample", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void DinosaurExampleSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("DinosaurExampleService"));
    }

    void DinosaurExampleSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("DinosaurExampleService"));
    }

    void DinosaurExampleSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void DinosaurExampleSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    DinosaurExampleSystemComponent::DinosaurExampleSystemComponent()
    {
        if (DinosaurExampleInterface::Get() == nullptr)
        {
            DinosaurExampleInterface::Register(this);
        }
    }

    DinosaurExampleSystemComponent::~DinosaurExampleSystemComponent()
    {
        if (DinosaurExampleInterface::Get() == this)
        {
            DinosaurExampleInterface::Unregister(this);
        }
    }

    void DinosaurExampleSystemComponent::Init()
    {
    }

    void DinosaurExampleSystemComponent::Activate()
    {
        DinosaurExampleRequestBus::Handler::BusConnect();
    }

    void DinosaurExampleSystemComponent::Deactivate()
    {
        DinosaurExampleRequestBus::Handler::BusDisconnect();
    }
}
