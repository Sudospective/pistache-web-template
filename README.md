# Pistache Web Template
###### Created by Sudospective

## What is this?
This is a template for creating websites in C++ using the Pistache framework.

## Why the heck would I want that?
Well, maybe you wouldn't. I know I definitely do. I'm a very object oriented person, and have always disliked the rigidness of HTML/XML. I found the [Pistache framework](https://pistacheio.github.io/pistache/) and was thrilled with the speed of it, but felt it lackluster to deal with strings of HTML code. So, I built this template to help creating websites using this framework a bit easier.

## How do I use it?
Firstly, make sure you have both the g++ compiler and the Pistache libraries installed. This works best with a Debian machine or WSL on Windows. Install the Pistache library package for Debian:
```sh
$ sudo apt install libpistache-dev
```
You can then compile the project using this command:
```sh
$ g++ src/main.cpp -o my-website -lpistache
```
From there, you can run the website locally:
```sh
$ ./my-website 8080
```
After that, navigate your browser to `localhost:8080` to view the website.
