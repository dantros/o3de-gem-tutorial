
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "DinosaurExampleSystemComponent.h"

namespace DinosaurExample
{
    class DinosaurExampleModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(DinosaurExampleModule, "{35366838-9D6E-4462-A0DC-A3A883FA3938}", AZ::Module);
        AZ_CLASS_ALLOCATOR(DinosaurExampleModule, AZ::SystemAllocator, 0);

        DinosaurExampleModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                DinosaurExampleSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<DinosaurExampleSystemComponent>(),
            };
        }
    };
}// namespace DinosaurExample

AZ_DECLARE_MODULE_CLASS(Gem_DinosaurExample, DinosaurExample::DinosaurExampleModule)
