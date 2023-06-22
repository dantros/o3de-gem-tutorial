
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/EjemploSystemComponent.h>

namespace Ejemplo
{
    /// System component for Ejemplo editor
    class EjemploEditorSystemComponent
        : public EjemploSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = EjemploSystemComponent;
    public:
        AZ_COMPONENT(EjemploEditorSystemComponent, "{DB8B9C11-5538-4B90-951A-406A5F0F0D81}", BaseSystemComponent);
        static void Reflect(AZ::ReflectContext* context);

        EjemploEditorSystemComponent();
        ~EjemploEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace Ejemplo
