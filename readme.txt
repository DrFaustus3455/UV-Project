#PROJECT-DESCRIPTION
~Basically i have a set-up of RO-Plant and in that setup there is UV-light connected
~UV-light stays open for far too long making its life-span shortened
~Thats why there needs to be a smart switch that opens and closes the light after some delay
~It only happens whenever water flows from the chamber killing bacteria from the water
~It closes when there is no movement in certain delay period 
~Also sustaining the life of the UV-Light   
#FOR-SETUP
1.Arduino Nano or Arduino Uno --> Nano is preferable because of place capacity
2.SSR Relay
3.Water Flow Sensor (YF-S204) --> Perferable because it gives Digital signals
4.BreadBoard(optional) --> Preferable for more clean build
5.6 Male to Male jumper wires
6.4 Male to Female jumper wires
#CONNECTIONS
-Connected live wire of 5V(Arduino) to breadboard at the hard-right section of the board making the whole coloumn live
-Connected GND(Arduino) wire to breadboard at the hard-right section of the board but left coloum right after live wire
-connected the waterflow sensor live and GND wire to the breadboard at the hard-right sections
-Connected the Signal pin of the sensor at the middle of the board and in the same row connected digital sensor pin from D2(Arduino)
-Connected the Signal pin from D13(Arduino) to the relay at the CH1 for getting sinal output
-Connected the DC+ and DC- wires to the hard right section of 5V live and GND section of the board connecting the circuit
-Install the software of Arduino and upload the code
                                        (Important Note: Dont forget to change the board in the software and also select the old bootloader in tools section)
    
