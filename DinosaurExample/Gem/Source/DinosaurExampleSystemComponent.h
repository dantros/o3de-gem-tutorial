
#pragma once

#include <AzCore/Component/Component.h>

#include <DinosaurExample/DinosaurExampleBus.h>

namespace DinosaurExample
{
    class DinosaurExampleSystemComponent
        : public AZ::Component
        , protected DinosaurExampleRequestBus::Handler
    {
    public:
        AZ_COMPONENT(DinosaurExampleSystemComponent, "{6E0D42B4-D60A-4574-8D9E-10AF97882C09}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        DinosaurExampleSystemComponent();
        ~DinosaurExampleSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // DinosaurExampleRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
