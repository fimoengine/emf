# emf-core

The first, and most important, interface is ***emf-core***.
It is the foundation on which all the other interfaces and modules are built on.

## Motivation

Nowadays, many games are built on top of an existing game engine. Modern game engines are very complex libraries. Much of this complexity stems from adapting the engine to a wide variety of platforms and game types. The reality of the matter is, that one size does not fit all. Because of that, many teams decide that it is appropriate to modify the engine, or in some extreme cases, even write a new one.

## Goals

The goal of ***emf-core*** is to specify the foundation of a plug-and-play modular game engine. The engine in it self is composed of multiple, indipendent or loosely coupled, modules. These modules communicate with each other by using the interfaces they expose.
