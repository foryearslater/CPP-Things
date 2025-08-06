#include <iostream>
#include <memory> 

#include "Light.hpp"
#include "GarageDoor.hpp"


#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "GarageDoorOpenCommand.hpp"

#include "RemoteControl.hpp"

int main() 
{
   
    std::unique_ptr<RemoteControl> remote = std::make_unique<RemoteControl>();

    std::unique_ptr<Light> livingRoomLight = std::make_unique<Light>("Living Room");
    std::unique_ptr<Light> kitchenLight = std::make_unique<Light>("Kitchen");
    std::unique_ptr<GarageDoor> garageDoor = std::make_unique<GarageDoor>("Garage");

    std::unique_ptr<Command> livingRoomLightOn = std::make_unique<LightOnCommand>(livingRoomLight.get());
    std::unique_ptr<Command> livingRoomLightOff = std::make_unique<LightOffCommand>(livingRoomLight.get());
    std::unique_ptr<Command> kitchenLightOn = std::make_unique<LightOnCommand>(kitchenLight.get());
    std::unique_ptr<Command> kitchenLightOff = std::make_unique<LightOffCommand>(kitchenLight.get());
    std::unique_ptr<Command> garageDoorOpen = std::make_unique<GarageDoorOpenCommand>(garageDoor.get());

    remote->SetCommand(0, std::move(livingRoomLightOn), std::move(livingRoomLightOff)); 
    remote->SetCommand(1, std::move(kitchenLightOn), std::move(kitchenLightOff));   
    remote->SetCommand(2, std::move(garageDoorOpen), std::make_unique<NoCommand>());

    std::cout << "\n--- Pressing Buttons ---" << std::endl;

    remote->OnButtonWasPressed(0);  
    remote->OffButtonWasPressed(0); 
    remote->UndoButtonWasPressed(); 

    remote->OnButtonWasPressed(1);  
    remote->OffButtonWasPressed(1); 
    remote->UndoButtonWasPressed(); 

    remote->OnButtonWasPressed(2);  
    remote->UndoButtonWasPressed();

    remote->OnButtonWasPressed(3); 
    remote->UndoButtonWasPressed(); 

    std::cout << "\nProgram finished." << std::endl;
    
    return 0;
}