
# Smart Pest Detection and Repellent for Rats (SPEAR)

SPEAR is an automatic rats detection and repellent system with additional real time monitoring dashboard to help KP staff control pest population.


## Authors

| Author                 | Team           | Role                                                                                                                              |
| ---------------------- | -------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| Reinaldo Samuel Sihite | EIC Technology | Electrical Engineer, Embedded System Engineer                                                                                     |
| Muhammad Verly         | EIC Technology | Embedded System Engineer, Software Engineer, Software Architect, Infrastructure Engineer, Devops, Quality Assurance Engineer (QA) |
| TBA                    | TBA            | TBA                                                                                                                               |

## License

[GNU v3](https://choosealicense.com/licenses/gpl-3.0/)


## Background
Rats are rodents that cause harm, both at home and in industry. Rats and other species of rodents can have a devastating impact on businesses, particularly like those operating within the steel manufacturing industry. Not only can they cause a damage for electrical parts, but they can also cause production downtime due to broken on critical system. 

In an effort to
reduce the the use of dangerous and toxic chemicals and poison that may be harmful to household pets and even humans, using high-frequency noise is applied as a natural rats repeller. Ultrasonic waves also low-cost solution and it can be used continously in critical electrical areas such ac culvert cable, tray, panel, etc.


## Current Status & Problem

Several known ways to
repel and eradicate rodents such as rat poison, mouse picker, and electric rat repellent are spread out across the plants in both outdoor and indoor place. However, team don’t know for sure how many rats in plants.
## Proposed Solution
Build rats detection and repellent system to help prevent rats broke the system. This automatic rats detection and repellent consists of two main parts, hardware system 
(hardware) and software system (software). The hardware system consists of a series of sensor circuit 
system and Arduino Uno microcontroller circuit system. The software is using C++ language 
programming. And Software system as the monitoring dashboard.

Using the sensor that will monitor, detect, and repel rats 24/7 in critical areas such as electrical rooms, culvert cable, tray, panel. And also a monitoring dashboard to analyze rats activities in each plants (total detected and time rats detected).

### - Flowchart
the diagram below shows how the system works in arranging ultrasonic sensors on the prototype.
![Flowchart](https://github.com/verlym/rat-detect/blob/main/drawio-EIC%20Rat%20Detection%20Flowchart.png)

There are two sensors on the system, first PIR sensor will be located in ground floor, this sensor is used for detecting rats motion. second ultrasonic sensor will be located in middle area, this sensor is used for detecting human movement to prevent misdetection between rats and human. 

PIR sensor will be the first layer of checking whether human or rats are currently detected. if the sensor is detected something, the checking is continue to ultrasonic sensor, if ultrasonic sensor is detected something then the system will decide that is human and do nothing. Else, rats is detected then system counting and also record it by publish the data (counts and detection time) to message queue (MQTT).

### - System Architecture
![System Architecture](https://github.com/verlym/rat-detect/blob/main/drawio-EIC%20Rat%20Pest%20Detection%20Architecture.png)

Above diagram shows overview of the end-to-end system. Data gathering will be done by collecting data from entire microcontroller (node) from each plants. Each node will send the data to central message collection (MQTT). Then EIC server will get data collected in MQTT to be used as a monitoring dashboard.

### - Data Communitation Flow
![Data Communitation](https://github.com/verlym/rat-detect/blob/main/drawio-EIC%20Rat%20Pest%20Detection%20Architecture%20Data%20Flow.png)

Data communication between nodes and dashboard is bridged by Message Queue (MQTT). MQTT (Message Queue Telemetry Transport) is a Publish-Subscribe based "lightweight" messaging protocol for use on top of the TCP/IP stack. Please read detail here.

1. Microcontroller publish data to topic rat-detect to MQTT broker located in data center (EIC Server 1)
2. EIC Server 2 will subscribe to topic rat-detect to consume microcontroller data
3. Consumed data will be used as monitoring dashboard.

Data Example:

detect_time        |	node_id
| ---------------------- | -------------- |
2023-05-12 11:00:50	 | SMP-ELC_R-01
2023-05-12 11:05:50	 | SMP-ELC_R-01
2023-05-12 10:05:50	 | SMP-ELC_R-02
2023-05-12 3:05:50	 | PM-ELC_R-02


## Feedback and Contributing

Contributions are always welcome! Please reach out to us

If you have any feedback or ideas, do not hesitate to share.
