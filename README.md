Main idea of game:

FOR FUN DEVELOPMENT!

# Gameplay concept

The 2D world with real phisics. Player have in control some units (tanks, cars, robots). 
He can write scripts for his units to to stuff.
There are some other units\players in the world.
The open protocol make it possible to use client-side scripts to control units.

# Basic architecture

The Universe of game is computed by Server.
The server connects to each client using open protocol.


SERVER ---> CLIENT (human)
		...
		--> CLIENT (AI)
		--> CLIENT (AI)
		--> CLIENT (AI)
		--> VIEW (js on the web(!) / bin)


Each t milliseconds server send current state of observed universe to all clients.
Client can response with command to Bot wich will be executed by server.

# Development

STEP 1:

Writing simple rendering and server side

STEP 2:

Chose phisics engine and try to use it.

view -- req data from --> model

controller -- rule --> TWorlds

STEP 3:

Go to Kickstarter for money to rent cloud.

##DONE:

* graphical engine is linking and show something
* phisiks engine is linking and do the work
* basic architecture of project (MVC, etc.)

##TO BE DONE:

* Creating of objects & units from JSON\SVG
* Advance controling of units
* Concept art
* More advanced phisics
	* explosions
	* damage models
* Networking
* Protocol description


# Dependensies

* Box2d
* SFML graphic library
* JSON parser https://github.com/miloyip/rapidjson
