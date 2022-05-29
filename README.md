# Smart Lightbulbs
Code for smartbulb made from scratch based around the ESP32 board

High level idea: Create a centralized server. Each bulb will act as a client node. 

## Table of Contents:
1. [To do](#to-do)
2. [Packet details](#packet-info)
3. [Long term plans](#long-term-vision)

## To do:
 - [ ] Write tester
    - [ ] Unit tests
    - [ ] Traces
    - [ ] CLI flag that allows for testing mode

 - [ ] Networking
    - [x] Write client
        - [x] Bulb "driver" software
    - [ ] Write server
        - [x] Just get it to talk to client
        - [ ] Implement threading
    - [ ] Design packet structure
        - [x] Write documentation for packet
        - [ ] Implement a function for creating a packet

## Packet info:
In order for our smart lights to be able to communicate with any other computer, we need to define a common language between our lights and the centralized computer. In our setup, the lights take on the role of the client and the centalized computer will act as the server.

Packets will have a size of 256 bytes (extremely excessive for the purposes of lighting, but later on we may want to add other kinds of devices). The following table describes the packet structure:

| Byte number (in host byte order) | Device type | Description |
| ----------- | ----------- | ----------- |
| 0           | Any         | Which device is this message meant for? 8 bits gives us 256 potential clients |
| 1-254       | Any         | Message (different devices will interpret this message differently) |
| 255         | Any         | If any of the values in this byte are 1, it will send a shutdown message to the client (the only case where a client can break from it's main loop) |
| 1           | Smart Lights| In an RGB lightbulb, the (R) value |
| 2           | Smart Lights| In an RGB lightbulb, the (G) value |
| 3           | Smart Lights| In an RGB lightbulb, the (B) value |

In the case of smart lights, we can control everything we need to about the light by controlling these variables alone. Turning to a simple white light or turning the device off is as turning the RGB to (255,255,255) or (0,0,0), respectively.



## Long term vision:
 - [ ] Write android app to interface with server.
    - [ ] Color wheel input
    - [ ] Ability to rename lightbulbs to something more understandable to a human
 - [ ] Voice control
