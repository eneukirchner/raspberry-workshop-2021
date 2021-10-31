#!/usr/bin/env python3
import paho.mqtt.client as mqtt
from gpiozero import LEDBoard, ButtonBoard
from time import sleep

BROKER = "test.mosquitto.org"
TOPIC = "meinraspi/edgar/"
LEDS = LEDBoard(18, 23, 24, 25)
BUTTONS = ButtonBoard(22, 27, 17)
connected = False

# The callback for when the client receives a CONNACK response from the server.
def on_connect(client, userdata, flags, rc):
    global connected
    connected = True

    # Subscribing in on_connect() means that if we lose the connection and
    # reconnect then subscriptions will be renewed.
    client.subscribe(TOPIC + "led/+")

# The callback for when a PUBLISH message is received from the server.
def on_message(client, userdata, msg):
    # print(msg.topic+" "+str(msg.payload))
    number = int(msg.topic.split("/")[3])
    value = int(msg.payload.decode("utf-8"))
    LEDS[number].value = value

def publish():
    if connected:
        for pin, button in enumerate(BUTTONS):
            client.publish(TOPIC + "button/" + str(pin), str(button.value))
        for pin, led in enumerate(LEDS):
            client.publish(TOPIC + "led/" + str(pin), str(led.value))
            

client = mqtt.Client()
client.on_connect = on_connect
client.on_message = on_message
client.connect(BROKER, 1883, 60)

client.loop_start()
while True:
    publish()
    sleep(1)
