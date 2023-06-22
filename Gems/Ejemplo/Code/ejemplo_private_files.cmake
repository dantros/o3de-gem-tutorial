
set(FILES
    Include/Ejemplo/EjemploBus.h
    Source/EjemploModuleInterface.h
    Source/Clients/EjemploSystemComponent.cpp
    Source/Clients/EjemploSystemComponent.h

    Source/Clients/TestComponent.cpp # New
    Source/Clients/TestComponent.h   # New
    Include/Ejemplo/TestComponentBus.h  # New

    Source/Clients/ProjectileComponent.cpp # New for second component
    Source/Clients/ProjectileComponent.h   # New for second component
    Include/Ejemplo/ProjectileComponentBus.h  # New for second component
)
