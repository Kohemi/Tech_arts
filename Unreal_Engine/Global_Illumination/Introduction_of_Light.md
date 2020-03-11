# Introduction of Light

## Lighting Essential Concepts

### Lighting Basics

* 4 types of light actors
* Common properties
* Light intensity units
* Concepts of dynamic and static lighting
* Light Mobility

### Baked Lighting - Lightmass

* How to bake lighting
* Lightmass
* Baked lighting performance
* Baked lighting quality and settings
* Importance Volume
* Lightmass Portals



![image-20200302190822874](C:\Users\gosto\AppData\Roaming\Typora\typora-user-images\image-20200302190822874.png)

​									"This is a picture that show you how to work volumetric lightmaps."

In baked lightmaps, Movable mesh can't be captured and calculated, so we need another method to calculate that. we use this volumetric lightmaps to calculate that 

### Dynamic Lighting

#### Indoor and Basics

* Dynamic Light doesn't need any baking process
* Doesn't have Bounce
* Regular dynamic lights / shadows
* Stationary and Movable
* Brief worth about different types of shadows
* Performance basics
* Quality



If You have too many stationary lights within the same area, you will have a red sign on light. Because of the problem of casting shadow. Dynamic Shadowing is really heavy 



#### Outdoor

* CSM(Cascaded Shadow Maps)

![image-20200305154046475](D:\Project\tech_arts\Images\image-20200305154046475.png)

CSM essentially renders three dynamic shadows, each with a different quality. One is high, One is medium, One is low.

* Distance Field
  * it is not default. so you have to check out this function in project settings. 
  * A distance field is an approximate of the model that is stored in a volumetric texture. 
  * The shadow use the distance field information and not the model, geometry anymore. 
  * This speeds up performance a lot
  * This is a way of optimizing the environment
  * Usually you use a combination of both CSM and Distance Field for outdoor dynamic lighting 

* DFAO (Distance Field Ambient Occlusion)
  * is created by Sky Light
  * What DFAO tries to do is, fake the bouncing of the 
  * light
* Conclusion 
  * you should put the directional lights to stationary for best possible results.

#### Combining Static and Dynamic Lighting

* When to use static and when dynamic
  * If the light affects the world so much, you set it to stationary. If not, to static is better 

* Common ways of combining the two 

Please Only set the most and largest models to large size of light map resolution 

## Lighting Effects and Reflections

### Lighting Effects

* Source Radius and Size
* IES
* Light Functions

------

#### Source Radius and Size

The Source is the object, model in a sense that emits the light

![image-20200305181839804](D:\Project\tech_arts\Images\image-20200305181839804.png)

* Source Radius
* Source Length

#### IES

![image-20200305182008263](D:\Project\tech_arts\Images\image-20200305182008263.png)

* This is very well performed on Spot Light
* First you set this to movable or stationary and move this to static and bake!

#### Light Function 

* means that you blend a material with a light 
* The light that is being cast is actually a blend between the material and the light 

![image-20200305182722264](D:\Project\tech_arts\Images\image-20200305182722264.png)

Change Surface on Material Domain to Light Function. You can modify this in material editor.

* Light Functions are ideal for anything that requires advanced light animation 

### Reflections

#### Screen Space Reflections

![image-20200305184817457](D:\Project\tech_arts\Images\image-20200305184817457.png)

#### Reflection Captures

* They are not real-time

#### Planar Reflections

* If you want to use this function, you go to project settings and make this enabled 
* ![image-20200305185921349](D:\Project\tech_arts\Images\image-20200305185921349.png)

#### A quick look at Capture to 2D/Cube

### Fog and Volumetric Light

#### Atmospheric Distance Fog

* does not create a layer of fog in the enviornment
* Actually creates the horizon as well 
* This is more complex and advanced fog of the two 

#### Exponential Height Fog

* Height!

#### Light Shaft Bloom and Light Shaft Occlusion

* Only with Fog
* Godrays

![image-20200305191723573](D:\Project\tech_arts\Images\image-20200305191723573.png)

#### Volumetric Fog and Lighting 

* there is in Exponential Height Fog

![image-20200305192015681](D:\Project\tech_arts\Images\image-20200305192015681.png)

![image-20200305192308083](D:\Project\tech_arts\Images\image-20200305192308083.png)

* In Spot Light, you can modify. 