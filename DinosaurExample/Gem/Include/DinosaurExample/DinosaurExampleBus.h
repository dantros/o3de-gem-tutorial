
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace DinosaurExample
{
    class DinosaurExampleRequests
    {
    public:
        AZ_RTTI(DinosaurExampleRequests, "{034DEB9B-5E95-48F9-A43A-B37E0AE58350}");
        virtual ~DinosaurExampleRequests() = default;
        // Put your public methods here
    };

    class DinosaurExampleBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using DinosaurExampleRequestBus = AZ::EBus<DinosaurExampleRequests, DinosaurExampleBusTraits>;
    using DinosaurExampleInterface = AZ::Interface<DinosaurExampleRequests>;

} // namespace DinosaurExample
