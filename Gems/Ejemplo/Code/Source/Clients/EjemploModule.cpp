

#include <EjemploModuleInterface.h>
#include "EjemploSystemComponent.h"

namespace Ejemplo
{
    class EjemploModule
        : public EjemploModuleInterface
    {
    public:
        AZ_RTTI(EjemploModule, "{37EE4F2A-E321-4415-BBD1-95BD9CE80B45}", EjemploModuleInterface);
        AZ_CLASS_ALLOCATOR(EjemploModule, AZ::SystemAllocator, 0);
    };
}// namespace Ejemplo

AZ_DECLARE_MODULE_CLASS(Gem_Ejemplo, Ejemplo::EjemploModule)
