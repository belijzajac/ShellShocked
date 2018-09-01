# ShellShocked

## About

ShellShocked is an aim helper for the game ShellShock Live 1 (flash version), written purely in C++14 and Qt5 framework. The game can be played from various platforms, such as shellshocklive, armorgames, kongregate or facebook. This project was intended for educational purposes only, therefore I'm not responsible for any damage that might happen to your account, this includes getting banned from the game itself and even losing your account.

## Screenshot

![ShellShocked-screenshot-01](/img/preview.png)

## Controls

| Numpad Key                     | Action                        |
| ------------------------------ | ----------------------------- |
| [4] or [6]                     | Descrease or inscrease power  |
| [2] or [8]                     | Descrease or inscrease angle  |
| [5]                            | Change aim direction          |

## In Action

[![ShellShocked-video-gameplay](https://i.imgur.com/SXnQS7H.png)](https://www.youtube.com/watch?v=Y8vYkNeAsbE)

## The math behind ShellShocked

![ShellShocked-parabola](/img/parabola_graph.png)

A parabola formula looks like <img src="http://latex.codecogs.com/gif.latex?f(x)=a(x-b)^{2}&plus;k" title="f(x)=a(x-b)^{2}+k" /> where vertex is (b,k).

When I put vertex (d, h) and then vertex (0,0), I get that variable <img src="http://latex.codecogs.com/gif.latex?a=-\frac{h}{d^{2}}" title="a=-\frac{h}{d^{2}}" /> and so my parabola equations becomes
<img src="http://latex.codecogs.com/gif.latex?f(x)=-\frac{h}{d^{2}}\cdot&space;(x-d)^{2}&plus;h" title="f(x)=-\frac{h}{d^{2}}\cdot (x-d)^{2}+h" />.

<img src="http://latex.codecogs.com/gif.latex?d=\frac{h}{tan(\beta&space;)}" title="d=\frac{h}{tan(\beta )}" />

<img src="http://latex.codecogs.com/gif.latex?h=\frac{v^{2}\cdot&space;(sin(\beta&space;))^{2}}{2\cdot&space;g}" title="h=\frac{v^{2}\cdot (sin(\beta ))^{2}}{2\cdot g}" />

