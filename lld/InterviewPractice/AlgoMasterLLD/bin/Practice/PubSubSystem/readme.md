The Pub-Sub system should allow publishers to publish messages to specific topics.
Subscribers should be able to subscribe to topics of interest and receive messages published to those topics.
The system should support multiple publishers and subscribers.
Messages should be delivered to all subscribers of a topic in real-time.
The system should handle concurrent access and ensure thread safety.
The Pub-Sub system should be scalable and efficient in terms of message delivery.

Pub Sub System

Publisher
Broker
Topics
Subscribers

publisher publish messages to topics, subscriber listen to that topic

so it is kind of observer design pattern

client.send("topic", "message string")

client.subscribe("topic", message String)

producer.addTopic("topic"); ---add topic , delete topic

so Observer design pattern, observable (producer), broker(client) --- reverse of observer , broker will notify all of subscriber

entities
Broker
Subscriber
Topics
publisher
