# Robowars 2025
This project was accomplished in collaboration with my friend Arielle Wong. Our main aim was to make a simple sumo bot which is designed to protect itself from heavy attacks and stay inside the arena for as long as possible 
(Arena in robowars is also called Dohyo). We used the following materials to build the sumo bot. We initially planned on using a PCB (printed circuit board) but ended up making the bot without it.

# Strategy.
Our bot Seiko's main strategy was to find the target and attack at full speed and if that target cannot be found then it starts spinning ( in our code you will find that the wheel rotates at maximum rpm)



### **Tools and Components Needed**

- **Breadboard**: Used for prototyping before finalizing the wiring.
- **Jumper Wires**: Male-to-male and male-to-female for connecting components.
- **ESP32**: Chosen microcontroller and brain of our bot.
- **L298N Motor Driver**: To control the motors.
  - https://youtu.be/2JTMqURJTwg?si=t44kl5HtpXeHMQLd (The best video , Robojax really helped us )
- **DC Geared Motors**: 2 units.
- **TCRT5000 IR Sensors**: 2 units.
      -  https://avinya-networks.com/tcrt5000-infrared-ir-proximity-obstacle-sensor-interfacing-with-arduino-node-mcu-esp32/
      -  We used 2 of these sensors to detect the white rim/boundary of the dohyo
- **VL53L0X ToF Sensors**: 1 units.
      - https://www.electronicwings.com/esp32/vl53l0x-sensor-interfacing-with-esp32 
- **6 Triple AAA batteries**: For power.
- **Buck Converter**: To step down the battery voltage to 5V for the ESP32.
- **Resistors**: 10kΩ (6 units) and 220Ω (2 units, optional).
- **Capacitors**: 100nF (2 units), 10µF (2 units), and 100µF (1 unit).
- **Multimeter**: To check voltages and connections.

In our bot, we did not use any resistors or capacitors.
As for the body of our bot, we modified an existing 3D model of a sumo bot body in TinkerCad 
The stl file of our sumo bot body is in this repository. 
