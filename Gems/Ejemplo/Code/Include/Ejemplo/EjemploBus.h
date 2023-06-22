
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Ejemplo
{
    class EjemploRequests
    {
    public:
        AZ_RTTI(EjemploRequests, "{85F2726D-A44B-43EC-ABC2-2B9FDAF3E924}");
        virtual ~EjemploRequests() = default;
        // Put your public methods here
    };
    
    class EjemploBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using EjemploRequestBus = AZ::EBus<EjemploRequests, EjemploBusTraits>;
    using EjemploInterface = AZ::Interface<EjemploRequests>;

} // namespace Ejemplo
