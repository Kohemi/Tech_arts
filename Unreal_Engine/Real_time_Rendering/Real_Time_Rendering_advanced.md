# Real Time Rendering in UE 4

Explain and visualize the entire rendering process

Develop an overview over all features, challenges and solutions

Understand the big picture and performance/workflow implications. 

## 1. Intro 

* RTR is at its most efficient when there is nothing 

* RTR is about managing losses 

* Identify the target framerate

* Aim your approach on hitting that target framerate

* Get as much return for each expense as you can
* You cannot do RTR perfect 
* It is always a compromise between losses and gains 
* You will always lose one thing to gain another 



each vertex of RTR triangle is Quality, Features, Performance

* you will almost never have all three of them 
* But you can find the perfect balance between all considerations 



* Be aware that you will sacrifice something 
* know how the load is distributed
* Adjust your approach to distribute the road 



### Reality is very complex

1. Everything needs to be efficient as possible
2. We need rigid pipelines and restrictions
3. We need to offload parts to pre-calculations
4. We need a mix of solutions 



### CPU vs GPU

1. handle different parts of the rendering in sync
2. Can bottleneck each other
3. Know how the load is distributed between the 2



### Deferred vs Forward

#### Deferred

1. Shading happens in deferred passes
2. Works compositing based using the GBuffer
3. Good at rendering dynamic lighting
4. Good at stable predictable high end performance
5. More flexible when it comes to disabling features, less flexible when it comes to surface attributes
6. No MSAA possible, relies on TAA 



#### Forward

1. Computes shading in the same pass as geometry/materials
2. More flexible in how lighting/materials are computed but less flexible when many features are mixed
3. Good at translucent surface rendering
4. Faster for simpler uses
5. Dynamic lighting has a big performance impact
6. MSAA possible 



## 2. Before Rendering and Occlusion 

![image-20200225183447665](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200225183447665.png)

* There is a gap time between CPU and GPU because CPU have to know what happens next beforehand.

### 1. Frame 0 - Time 0 - CPU 

Before we can render anything we first need to know where everything is  

#### calcuate all logic and transforms

1. Animations
2. Positions of models and objects
3. Physics
4. AI
5. Spawn and destroy, Hide and Unhide 

Anything that relates to the positions of objects to change 

#### RESULT : 

<u>UE4 now knows all transforms of all models</u> 



### 2. Frame 1 - Time 33ms - Draw Thread(mostly CPU)

Before we can use the transforms to render the image we need to know what to include in the rendering

This is mostly run on the the CPU but some parts are GPU handled 

#### Occlusion Process

Builds up a list of all visible models/objects Happens per object - Not per polygon 

4 Stage processes - in order of execution

1.  Distance Culling
   - Distance culling removes any objects further than X from the camera 

2. Frustum Culling
   - Frustum Culling checks what is in front of the camera

3. Precomputed Visibility
   - Precomputed visibility divides the scene into grid, each grid cell remembers what is visible at that location 
4. Occlusion culling 
   - Accurately checks the visibility state on every model. This is heavy
   - Use "Freezerendering" visualize this
   - Stat Initviews shows the costs
   - 1000 + objects to check begins having an impact. 



![image-20200225193244688](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200225193244688.png)



Show Initviews : the expense can be seen here 

#### Result 

UE4 Now has a list of models to render

Example : 

Model A - Visible

Model B - Not visible

Model C - Visible

Model D - Visible 

=> Model A, B, C are passed on to the GPU







## 3. Geometry Rendering

### Frame 2 - Time 66 ms - GPU

#### Prepass/Early Z pass

The GPU now has a list of models and transforms but if we'd just render this info out we would cause a lot of redundant pixel rendering

Thus we need to figure out which models will be displayed where in advance 

render object per object 



### Drawcalls

The GPU now starts to render. It renders drawcall per drawcall

A group of polygons sharing the same properties is a drawcall

Measure with "stat RHI"

2000 - 3000 is reasonable(VR Around 10000 is reasonable)

More than 5000 is getting high

More than 10,000 is probably a problem

On mobile this number is far lower (few hundred max)



#### Drawcalls Performance Implications 

1. The cost to rendering many polygons is often lower than the expense
2. 50,000 triangles can run worse than 50 million dependent on implementation
3. Drawcalls have a base expense thus optimizing low poly to super low poly may make zero difference



The BasePass is the big pass, which is rendering the geometry



4. Components = drawcalls too
5. Components occlude one by one, and render one by one 
6. Merging into a single actor makes no difference usually for rendering 

7. To lower drawcalls it is better to use fewer larger models than many small ones

8. You cannot do that too much however, it impacts everything else negatively

   a. worse for occlusion

   b. worse for lightmapping

   c. worse for collision calcuation

   d. worse for memory



9. A common technique is Modular Meshes

   a. Saves work time and memory

   b. Improves lighting, occlusion, collision, lodding

   c. Increases drawcalls however 

   

10. Using a modular(Maybe Middle?) mesh workflow you can always mefge meshes later on if needed and if the content is near final

11. Use the Statistics and Stat commands to find the best candidates merging

12. Once merged, you cannot easily go back. Only do this at the end(You have to this at Final time)

    ------

    

13. You can merge by exporting from UE4 to FBX and then using a 3D program, or using the Merge Actors tool

    ------

    

14. How much to merge and exactly how to is greatly dependent on many factors

15. Often there is no need to merge anything. The majority of content knows no or little merging

16. On very low end hardware you might merge almost everything

    ------

17. As with everything a balance between all extremes is usually the best way forward 

18. Some modular content, some merged content, and some unique models

* By default in UE4, meshes are instanced in memory, but they are not instanced in rendering

------



19. You can also do instanced Rendering

* Automatically groups models together into single drawcalls(So you have to Groups!!! and make folder, put into similar models and manage them! Please)

* Not enabled standard because it gives overhead 

  ------

  

20. And Finally there is Lodding - Level Of Detail

* Simplifies a model or bunch of models in given conditions
* Usually means a model becomes lower poly in the distance
* Essentially swaps one model for another simpler model
* HLOD is a bigger version, it groups models together in the distance to lower drawcalls 
  * What an HLOD does is it groups things together and replaces groups of object with a single model form distance 





##### If you merge meshes following rules make better candidates(Keep in mind!) :

1. The more common a mesh AND the lower poly the better
2. Merge only meshes within the same area
3. Merge only meshes sharing the same material
4. Meshes with no or simple collision are better for merging
5. Smaller meshes or meshes receiving only dynamic are better candidates 
6. Distant geometry is usually great to merge 



## 4. Vertex Shaders

There are different types of Shaders 

A shader performs calculations on its input variables 

Shaders are very efficient

Vertex Shader is the first one in the process

#### process

1. Converts local vertex positions to world position 

------

<u>Practical examples of world position offset vertex shaders are</u> 

1. cloth
2. Water displacement
3. Foliage wind animation 

------

Shaders are super optimized - it is why they are central to the rendering pipeline start to end

A CPU with its all purpose architecture is unable to deal with this much data 

Imagine a forest, it could involve millions of vertices to animate 

------

Vertex Shaders do not modify the actual model, it is purely a visual effect

The CPU is not aware of what the vertex shaders do

Thus things like physics or collisions will not take it into account

* Vertex Shaders only can be used as a visual effect, cannot be used as a physics and collisions because it is only VFX!!!

#### Vertex Shaders Performance Implications

1. The more complex the animations performed the slower
2. The more Vertices affected the slower
3. Thus high poly objects should have simpler vertex shaders
4. Disable the vertex shaders on distant geometry 



Disabling World position offset in the distance makes your project more efficient



## 5. Rasterisation, Overshading, and the GBuffer 

### Rasterizing and Overshading

To render out the information to a grid of pixels(an image)

Done drawcall by drawcall 

![image-20200227152007131](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227152007131.png)

The blue line is a polygon. If you render a polygon, we have to figure out which pixel or which squares behind the triangle are going to to be colored or not because of that triangle.

=> The math to figure this out is called the rasterization process. 

Rasterization doesn't impact much on you 

You have to consider Overshading 

------

A pixel can only ever show 1(or part of 1) polygon at the same time 

Thus we know with absolute certainty that 1 pixel ne ver represents more than 1 polygon 

![image-20200227153739162](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227153739162.png)

You can see it doesn't blend together. You might expect the colors to blend together where a pixel shows just a blend of different colors from these different polygons. It doesn't happen

The colors very strictly stay divided. 

------

A 100,000 polygon model seen from so far away that it would be 1 pixel big would process 100,000 polygons but display only 1 polygon 

But it is still processed as 100,000 polygons, so performance wise this makes no difference. 

------

As it renders out the pixel it uses a Pixel Shader to calculate the precise shading 

For this it needs to have information from that polygon(texture, shading)

Shading means we have to tint it or give it a color 

Therefore, that polygon has to tell us what kind of texture is on it, any information on the shading from the vertices. 

------

Due to hardware design, it always uses a 2x2 pixel quad for processing [^1]

If a polygon is very small or very thin then it means it might shade 4 pixels while only 1 pixel is actually filled

This is overshading in its first stage 



[^1]:3D CG have to go with Hardware and Software 

![image-20200227181446620](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227181446620.png)

The grey lines are the pixels, The orange line are the quads, These 4 pixels are calculated together 

![image-20200227181715639](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227181715639.png)

![image-20200227181812718](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227181812718.png)

![image-20200227181849819](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227181849819.png)New triangle added and needed to be recalculated 

![image-20200227181907678](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227181907678.png)

It actually recalculated 2 groups of 4 pixels on red box above image

------

Objects seen from very far away are actually slower to render because there are more polygons covering a small number of pixels. 

#### Rasterization and Overshading Performance Implications(Keep in mind!!)

1. Polygons are more expensive to render in great density
2. When seen at a distance the density increases
3. Thus reduce polygon count at a distance(lodding/culling) is critical 
   * Maybe lodding is LOD
4. The more complex the initial pixel shader pass it the more expensive overshading is. Thus forward rendering receives a bigger hit on performance from this than deferred. 

6. Very thin triangles affect overshading because they pass through many 2x2 pixel quads

####  Result 

As it rasterizes the rendering it writes it out to the GBuffer

### GBuffer 

Means : The images will be rendered after rasterization

The frame rendered out in multiple different images

These images are then used for positing in anything ranging from materials to lighting to fog and so forth 

The type of GBuffer

1. GBufferA : The World Normal allows us to record information on which direction, simply store the information of all the different axes

2. GBuffer B : combination of metallic

 ![image-20200227183729994](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227183729994.png)

In channels tap, there are RGB Buttons

a. G : Shows the specular

b. B : Shows the roughness

3.  GBuffer C : the result without any lighting 
4. Custom Depth : Allows for rendering out an additional mask which in turn can be used for chromakeying 

#### GBuffer Performance Implications(Keep In mind!!)

1. The GBuffer takes up a lot of memory and bandwidth and thus has a limit on how many different GBuffer images you can render out 



## 6. Rendering and Texture

### Texture 

Texture are compressed on import 

Compression differs per platform. BC(DXTC by its old name) is used for PC

BC(Block Compression) has many different compression settings not exposed by UE4

Normal maps use the special BC5 which saves only Red/Green(removing blue color), do a great job of switching between red and green 

Normal maps are nothing but gradients between red, green, and blue

Normal maps do a couple of tricks. It recalculates to, 1 to -1 so the range is different as well.

 BC is weak when it comes to gradients between red and green. 

Similar to JPEG

Can be disabled if needed

BC3 (DXTC5) = Texture with alpha - BC1(DXTC1) = Textures = without alpha 

------

Limited memory and bandwidth - thus we must compress

Shaders have a max number of texture samplers per shader 

Texture resolution affects memory and bandwidth, not rendering performance. They will cause lag and freezes instead. 

------

To maximize memory efficiency and smooth out the image we use mipmaps

Mipmaps is to As it is be seen more far, it decrease its size(measures : /2^n)



![image-20200227211449718](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227211449718.png)

![image-20200227211644728](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227211644728.png)

------

Texture Streaming is the process of determining when the engine needs which texture and which mip

It only loads what it needs when it needs it

------

To facilitate mip maps and streaming textures must be power of 2

1x1, 2x2, 4x4, 8x8 ...

Combinations(rectangular) are ok - 16x4096- and so far 

A texture not a power of 2 will not receive mip maps



## 7. Shaders And Materials 

### Pixel Shaders

A pixel shader is similar to a vertex shader 

Set of calculations ran by the GPU to modify the colors of pixels

Very central to the rendering pipeline, used for calculating and applying every step of the rendering 

Pixel Shaders are what drives the entire material system

It also drives lighting, fog, reflections, post process, color correction, and so forth 

![image-20200227214237189](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227214237189.png)

------

You can selectively apply pixel shaders pixel per pixel 

Hence why having mask images allows you to select which pixels receive which operations 



### Shading Language

Pixel shaders are written in shader language - differs per platform

On DirextX it uses HLSL - High Level Shader Language 

```HLSL
float4 normal = mul(IN.Normal, ModelViewIT);
normal.w = 0.0;
normal = normalize(normal);
float4 light = normalize(lightVec);
float4 eye = float4 (1.0, 1.0, 1.0, 0.0);
float4 vhalf = normalize(light + eye);
```

------

![image-20200227215110387](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227215110387.png)

------

![image-20200227215836841](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200227215836841.png)

------

### Materials

A big portion of the material pipeline is PBR based

Physical Based Rendering uses Specular/Metallic/Roughness to handle all shading 

------

PBR is unified shading - some exceptions aside it is used for almost everything 

1. In order to get max efficiency we focus all out on only PBR
2. PBR improves art pipeline by being predictable
3. We face inherit restrictions due to the GBuffer and compositing based workflow 

------

Shading Model is a number of masks that identifies which pixels use other shading models than PBR

These pixels then take an alternative rendering path forward 

------

Before we can render out the PBR materials we first need to know the world reflections

### Perfomance Implications(Keep in mind!!)

1. Material/shader has a max number of textures samplers it can look up. Usually 16, of which usually 13 can be used. You can use shared samplers up to 128 but only on DX11
2. Texture size mostly causes lag and freezes, not framerate loss 
3. Pixel shaders have a big impact, because we do so much with them 
4. The higher the resolution, the bigger an impact more complex materials have
5. A complex material is more expensive the more pixels it covers on the screen
6. Material Complexity shows the pixel shader cost from materials 

The expense of pixel shading comes down to how many pixels are actually covered on the screen. 

Therefore it is more reasonable to have a very complex material on an object in the distance than it is to have a complex material on an object right in front of you  



## 8. Reflections

### Basic

Reflections are very hard to calculate real time

Thus we use 3 different technique, each with pros/cons

The 3 are rendered and blended together in order

Once ready, they are in turn blended with the rest of the rendering 

------

### Reflection Captures

Captures a static cubemap at a specific location

Precalculated

Very fast

Inaccurate

Local effect near the capture location 

------

### Planar Reflections

Not Common. Captures from and to a plane. Restrained to that plane

Can be heavy

Great for flat surfaces that need accurate reflections

Unsuitable for everything else

Only works on a limited area 

Dynamic(Not Static)

(Using this to create a ocean is really difficult or impossible, but to create a mirro in the room is much easier)

------

### Screen Space Reflections(SSR)

Default reflection system 

Affects everything and is real time

Accurate

Outputs noisy result and is medium heavy(Turn off this setting in VR project)

Can only show reflections of geometry currently visible

------

### Result

All three methods together result in the reflection environment 

The reflection environment is then blended with the Roughness, Specular, and Metallic masks



Add.

Reflections have a hierarchy 

First

SSR -> Planar Reflections -> Reflection Captures 

 

------

### Reflections Performance Implications(Keep In Mind!!)

1. Reflection Captures are captured on level loading when a project is not cooked for distribution, thus having many will slow down the loading some and having thousands is likely not going to work great until the final cook
2. Reflection Captures get heavier when many overlap, due to pixel shading operations running over and over on the same pixels - More than 8 overlapping is not the best idea usually 
3. Reflection Capture sharpness can be set via its resolution 

4. A skylight will provide a low cost back up Reflection Capture for the entire world 
5. Planar should only be used when absolutely needed 
6. Turn off SSR if hardware power is limited
7. You can increase SSR quality above standard if power is not an issue 

```UE4
#3 is standard, above 4 is better thing
r.SSR.Quality <int> 
```



## 9. Static Lighting 

### Basics

Like reflections lighting and shadows are very hard to calculate in real time

Thus part of it is offloaded to pre-calculations/pre-rendering

And also therefore there are many dozens of different lighting and shadow features, each with a specialized purpose

There are two main ways of handling Light/Shadow : Static and Dynamic - or in other words Pre-Rendered/Real time

Lighting and Shadows are often split of each other 

------

Process Pros/Cons

1. Is precalculated in the editor and stored into (mostly) lightmaps
2. Super fast for performance, but increases memory
3. Takes a long time to precalculate the lighting
4. Each time something is changed, it must be re-rendered again
5. Models require lightmap UVs, this additional prep step takes time 

------

Quality Pros/Cons

1. Handles Radiosity and Global Illumination
2. Renders realistic shadows including soft shadows
3. Quality is dependent on lightmap resolution and UV layout
4. May have seams in the lighting due to the UV layout
5. Lightmap resolution has an upper limit
6. Very large models won't have enough Lightmap UV space
7. Once calculated, light and shadow cannot be moved or altered during run time 

------

### Lightmaps

A lightmap is a texture with the lighting and shadows baked into it

This texture is then multiplied on top of the basecolor

A model requires UV lightmap coordinates for this to work 

![](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200228173749557.png)

------

Lightmaps are generated by UE4 using Lightmass during the rebuild

It packs many lightmpas together in atlasses 

------

### Lightmass

Stand alone application that handles the light rendering and baking to lightmaps

Supports distributed rendering over a network

Bake quality is determined by Light Build Quality as well as settings in the Lightmass section of each level

Requires a Lightmass importance Volume arounds parts of the world

------

### Indirect Lighting Cache

To handle precalculated lighting on dynamic models the ILC is used

The ILC distributes a 3D grid of vectors within the LI volume

Each vector stores the light intensity at that location

The nearest or nearest 5x5x5 vectors are then read and used to light up the dynamic model 

If you need the best possible performance, set 

![image-20200228180626204](D:\Project\tech_arts\Unreal_Engine\Real_time_Rendering\upload\image-20200228180626204.png)

