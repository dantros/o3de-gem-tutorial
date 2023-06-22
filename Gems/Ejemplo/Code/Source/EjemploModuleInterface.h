
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>
#include <Clients/EjemploSystemComponent.h>

namespace Ejemplo
{
    class EjemploModuleInterface
        : public AZ::Module
    {
    public:
        AZ_RTTI(EjemploModuleInterface, "{F606B0EB-2D3C-4C4B-B2FA-E05335A952C9}", AZ::Module);
        AZ_CLASS_ALLOCATOR(EjemploModuleInterface, AZ::SystemAllocator, 0);

        EjemploModuleInterface()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                EjemploSystemComponent::CreateDescriptor(),
                });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<EjemploSystemComponent>(),
            };
        }
    };
}// namespace Ejemplo
