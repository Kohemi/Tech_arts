# Real-Time Rendering Fundamentals

## Two ways of rendering

* Deferred Rendering and Forward Rendering 

* Unreal Engine 4 is Deferred by default but can also do Forward 

* Deferred works best for the majority of content 

  |                      Deferred Rendering                      |                      Forward Rendering                       |
  | :----------------------------------------------------------: | :----------------------------------------------------------: |
  | Gives stable and better performance for more demanding applications | Gives faster performance for simpler uses or when the hardware is limited(mobile, VR) |
  |          Deferred supports more rendering features           |          MSAA in Forward gives better anti-aliasing          |
  | Most documentation, tutorials and other content will be based on deferred rendering |                                                              |

  

* TAA(Temporal Anti-Aliasing) is what causes the slight amount of ghosting you see in the frames 

## GBuffer

* A deferred renderer will use a GBuffer - a set of images for each frame 
* These images contain all the information required for the later stages of the render process  essentially
  real-time compositing
* This happens entirely in the background, but understanding what it gives perspective on why real-time
  rendering is good or not so good at some things



## Pixel and Vertex Shaders

* During rendering often fairly simple calculations must be repeated a huge number of times 
* This is slow to process on regular processors so hardware and software dedicated to this was introduced
* The various types of shaders are essentially small calculations run again and again on a dedicated part of the GPU Architecture 
* Are the very heart of how we render in real-time and have a significant impact on how we render and where performance is lost 
* An input Value is taken for example the current color of a pixel, a calcuation is applied, and a new value is output
* Pixel Shaders work per pixel, vertex shaders per vertex of the model
* All real-time lighting, shading, the rendering of the materials, fog, post process effects and a great many things more are Pixel Shaders



In result, Unreal Engine uses Deferred Rendering as a default and in limited situation like platforms, VR, Mobile, able to use Forward rendering because it gives faster rendering than deferred rendering.

And GBuffer is a set of various layers that consist of color layer and light layer etc. Finally it combine a set of layers and make result. 

Real-time rendering uses pixel shaders. 



## Underneath the surface

* A mix of different solutions
* Scalability
* Deferred/Forward rendering
* GBuffer
* Vertex and Pixel Shader basics 



## Real-Time Rendering Performance

* Target frame rate and MS
* Frame time and GPU/CPU
* Profiling basics
* The 4 most common performance issues
  * intro to draw calls
  * pixel/vertex shader impact
  * intro to translucency rendering
  * Shadows



## Frame time is in milliseconds(ms)

* 1000 ms per second
* so 30 frames per seconds equals 1000/30 = 33.3ms perframe
* Frame time is a better way of measuring performance
* Inputting tilde key ' ` ', you can enter to cmd console and you can also open console window in window tap in menu bar 
* The way : Window -> Developer Tools -> Output Log 
* t.maxfps <int> : you can removes the cap on the frame rate.
* stat unit : pop up the information of Frame, game, Draw GPU etc. in your screen
* stat rhi, stat scene rendering 



| CPU                                                        | GPU                                   |
| ---------------------------------------------------------- | ------------------------------------- |
| Animations                                                 | Lighting                              |
| Physics                                                    | Rendering of models                   |
| Collision                                                  | Reflections                           |
| AI                                                         | Shaders and more                      |
| Spawning/Destroying And more                               | => Anything that relates to rendering |
| => Anything that alters the position/rotation of something |                                       |



## Draw Calls

* If the environment is rendered, it will not render it pixel by pixel but render it object per object.
* So How many separate models are forming the environment is very important question. 
* the expense of scene can be calculated by the number of Draw Calls 



## Translucency 

If Translucent material is used, Frame drop can happen. the reason is every material have to calculate a pixel in behind of material and layer that must be blended is added 



## Dynamic Shadows 



Think about my learning process and work flow, how to apply the thing that i learned to my work flow. 