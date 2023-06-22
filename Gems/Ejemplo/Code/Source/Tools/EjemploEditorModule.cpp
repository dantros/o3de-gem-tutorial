
#include <EjemploModuleInterface.h>
#include "EjemploEditorSystemComponent.h"

namespace Ejemplo
{
    class EjemploEditorModule
        : public EjemploModuleInterface
    {
    public:
        AZ_RTTI(EjemploEditorModule, "{37EE4F2A-E321-4415-BBD1-95BD9CE80B45}", EjemploModuleInterface);
        AZ_CLASS_ALLOCATOR(EjemploEditorModule, AZ::SystemAllocator, 0);

        EjemploEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                EjemploEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<EjemploEditorSystemComponent>(),
            };
        }
    };
}// namespace Ejemplo

AZ_DECLARE_MODULE_CLASS(Gem_Ejemplo, Ejemplo::EjemploEditorModule)
