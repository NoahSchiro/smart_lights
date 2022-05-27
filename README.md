# smart_lights
Code for smartbulb made from scratch based around the ESP32 board

High level idea: Create a centralized server. Each bulb will act as a client node. 

 - [ ] Write tester
    - [ ] Unit tests
    - [ ] Traces
    - [ ] CLI flag that allows for testing mode

 - [ ] Networking
    - [x] Write client
        - [x] Bulb "driver" software
    - [ ] Write server
        - [ ] Just get it to talk to client
        - [ ] Implement threading
    - [ ] Design packet structure
        - [ ] Write documentation for packet
        - [ ] Implement a function for creating a packet

---
Long term:
 - [ ] Write android app to interface with server.
    - [ ] Color wheel input
    - [ ] Ability to rename lightbulbs to something more understandable to a human
